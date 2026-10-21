// External-force approximation: no surface motion, joint rail, pose or velocity commands.
#include <algorithm>
#include <chrono>
#include <cmath>
#include <mutex>
#include <string>

#include <gz/common/Console.hh>
#include <gz/msgs/double.pb.h>
#include <gz/msgs/odometry.pb.h>
#include <gz/msgs/vector3d.pb.h>
#include <gz/msgs/Utility.hh>
#include <gz/plugin/Register.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Link.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/System.hh>
#include <gz/transport/Node.hh>

namespace franka_conveyor
{
class ConveyorForce final : public gz::sim::System,
                            public gz::sim::ISystemConfigure,
                            public gz::sim::ISystemPreUpdate
{
 public:
  void Configure(const gz::sim::Entity &_entity,
                 const std::shared_ptr<const sdf::Element> &_sdf,
                 gz::sim::EntityComponentManager &_ecm,
                 gz::sim::EventManager &) override
  {
    const gz::sim::Model model(_entity);
    this->link = gz::sim::Link(model.LinkByName(_ecm, "base_link"));
    if (!model.Valid(_ecm) || !this->link.Valid(_ecm))
    {
      gzerr << "[ConveyorForce] Requires a model with base_link\n";
      return;
    }
    auto value = [&](const std::string &key, double fallback)
    { return _sdf->Get<double>(key, fallback).first; };
    this->beltX = value("belt_x", .6);
    this->beltY = value("belt_y", 0.);
    this->beltTop = value("belt_top", .5);
    this->yaw = value("belt_yaw", 0.);
    this->length = value("belt_length", 2.);
    this->width = value("belt_width", .4);
    this->size = value("box_size", .1);
    this->kp = value("velocity_gain", 10.);
    this->ki = value("integral_gain", 2.);
    this->maxAcceleration = value("max_acceleration", 1.);
    this->heightTolerance = value("height_tolerance", .003);
    this->maxVerticalSpeed = value("max_vertical_speed", .03);
    this->maxSpeed = value("max_speed", 1.);
    this->target = value("initial_speed", .1);
    for (double v : {this->beltX, this->beltY, this->beltTop, this->yaw,
                     this->length, this->width, this->size, this->kp, this->ki,
                     this->maxAcceleration, this->heightTolerance,
                     this->maxVerticalSpeed, this->maxSpeed, this->target})
    {
      if (!std::isfinite(v))
      {
        gzerr << "[ConveyorForce] Nonfinite parameter; disabling system\n";
        return;
      }
    }
    if (this->length <= this->size || this->width <= this->size ||
        this->size <= 0 || this->kp <= 0 || this->ki < 0 ||
        this->maxAcceleration <= 0 || this->heightTolerance <= 0 ||
        this->maxVerticalSpeed <= 0 || this->maxSpeed <= 0)
    {
      gzerr << "[ConveyorForce] Invalid dimensions/gains/limits; disabling system\n";
      return;
    }
    this->target = std::clamp(this->target, -this->maxSpeed, this->maxSpeed);
    this->axis = gz::math::Vector3d(std::cos(this->yaw), std::sin(this->yaw), 0);
    this->link.EnableVelocityChecks(_ecm);
    const std::string topic = _sdf->Get<std::string>("velocity_topic", "/conveyor/cmd_vel").first;
    const double initialSpeed = this->target;
    if (!this->node.Subscribe(topic, &ConveyorForce::OnCommand, this))
    {
      gzerr << "[ConveyorForce] Could not subscribe to " << topic << "\n";
      return;
    }
    const auto prefix = "/model/" + model.Name(_ecm);
    this->forcePub = this->node.Advertise<gz::msgs::Double>(prefix + "/conveyor_force");
    this->velocityPub = this->node.Advertise<gz::msgs::Double>(prefix + "/conveyor_velocity");
    this->statePub = this->node.Advertise<gz::msgs::Odometry>(prefix + "/ground_truth");
    this->accelPub = this->node.Advertise<gz::msgs::Vector3d>(prefix + "/force_acceleration");
    this->enabled = true;
    gzmsg << "[ConveyorForce] Free-body force controller on " << model.Name(_ecm)
          << ", initial speed=" << initialSpeed << " m/s; max |F|=mass*"
          << this->maxAcceleration << " N/kg; external-force approximation\n";
  }

  void PreUpdate(const gz::sim::UpdateInfo &_info,
                 gz::sim::EntityComponentManager &_ecm) override
  {
    if (!this->enabled || _info.paused)
      return;
    const double dt = std::chrono::duration<double>(_info.dt).count();
    const double now = std::chrono::duration<double>(_info.simTime).count();
    if (dt <= 0 || now < this->lastTime)
    {
      this->integral = 0;
      this->lastPublish = -1;
      this->lastTime = now;
      return;
    }
    this->lastTime = now;
    const auto pose = this->link.WorldPose(_ecm);
    const auto velocity = this->link.WorldLinearVelocity(_ecm);
    const auto inertia = this->link.WorldInertial(_ecm);
    if (!pose || !velocity || !inertia)
      return;
    const auto position = pose->Pos();
    const double dx = position.X()-this->beltX;
    const double dy = position.Y()-this->beltY;
    const double localX = std::cos(this->yaw)*dx+std::sin(this->yaw)*dy;
    const double localY = -std::sin(this->yaw)*dx+std::cos(this->yaw)*dy;
    // Oriented cube's vertical half-extent. Height/velocity gating is a contact
    // proxy, not proof of contact or proof that the fingers have not grasped it.
    const auto rotation = pose->Rot();
    const double halfHeight = .5*this->size*(
        std::abs(rotation.RotateVector(gz::math::Vector3d::UnitX).Z())+
        std::abs(rotation.RotateVector(gz::math::Vector3d::UnitY).Z())+
        std::abs(rotation.RotateVector(gz::math::Vector3d::UnitZ).Z()));
    const bool onBelt = std::abs(localX) <= (this->length-this->size)/2 &&
        std::abs(localY) <= (this->width-this->size)/2 &&
        std::abs(position.Z()-halfHeight-this->beltTop) <= this->heightTolerance &&
        std::abs(velocity->Z()) <= this->maxVerticalSpeed;
    const double measured = velocity->Dot(this->axis);
    double commanded;
    {
      std::lock_guard<std::mutex> guard(this->mutex);
      commanded = this->target;
      if (this->changed)
      {
        this->integral = 0;
        this->changed = false;
      }
    }
    double force = 0;
    if (onBelt && std::isfinite(measured))
    {
      const double error = commanded-measured;
      const double candidate = this->integral+error*dt;
      const double raw = this->kp*error+this->ki*candidate;
      // Conditional integration prevents windup while acceleration saturates.
      if (std::abs(raw) <= this->maxAcceleration || raw*error < 0)
        this->integral = candidate;
      const double acceleration = std::clamp(this->kp*error+this->ki*this->integral,
                                            -this->maxAcceleration, this->maxAcceleration);
      force = inertia->MassMatrix().Mass()*acceleration;
      this->link.AddWorldForce(_ecm, this->axis*force);
    }
    else
    {
      this->integral = 0;
    }
    if (now-this->lastPublish >= .01)
    {
      gz::msgs::Odometry state;
      const auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(_info.simTime).count();
      state.mutable_header()->mutable_stamp()->set_sec(ns / 1000000000);
      state.mutable_header()->mutable_stamp()->set_nsec(ns % 1000000000);
      gz::msgs::Set(state.mutable_pose(), *pose);
      gz::msgs::Set(state.mutable_twist()->mutable_linear(), *velocity);
      this->statePub.Publish(state);
      gz::msgs::Vector3d acceleration;
      gz::msgs::Set(&acceleration, this->axis * (force / inertia->MassMatrix().Mass()));
      *acceleration.mutable_header()->mutable_stamp() = state.header().stamp();
      this->accelPub.Publish(acceleration);
      gz::msgs::Double message;
      message.set_data(force);
      this->forcePub.Publish(message);
      message.set_data(measured);
      this->velocityPub.Publish(message);
      this->lastPublish = now;
    }
  }

 private:
  void OnCommand(const gz::msgs::Double &_message)
  {
    if (!std::isfinite(_message.data()))
      return;
    std::lock_guard<std::mutex> guard(this->mutex);
    const double next = std::clamp(_message.data(), -this->maxSpeed, this->maxSpeed);
    if (std::abs(next-this->target) > 1e-9)
      this->changed = true;
    this->target = next;
  }

  bool enabled{false}, changed{false};
  double beltX{0}, beltY{0}, beltTop{0}, yaw{0}, length{0}, width{0}, size{0};
  double kp{0}, ki{0}, maxAcceleration{0}, heightTolerance{0}, maxVerticalSpeed{0};
  double maxSpeed{0}, target{0}, integral{0}, lastTime{0}, lastPublish{-1};
  std::mutex mutex;
  gz::math::Vector3d axis;
  gz::sim::Link link;
  // Destroy transport before the mutex/state used by its callbacks.
  gz::transport::Node node;
  gz::transport::Node::Publisher forcePub, velocityPub, statePub, accelPub;
};
}
GZ_ADD_PLUGIN(franka_conveyor::ConveyorForce, gz::sim::System,
              franka_conveyor::ConveyorForce::ISystemConfigure,
              franka_conveyor::ConveyorForce::ISystemPreUpdate)
GZ_ADD_PLUGIN_ALIAS(franka_conveyor::ConveyorForce, "franka_conveyor::ConveyorForce")
