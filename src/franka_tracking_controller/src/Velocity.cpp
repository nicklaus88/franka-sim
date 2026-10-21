#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <controller_interface/controller_interface.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
namespace franka_tracking_controller {
class Velocity : public controller_interface::ControllerInterface {
  std::array<std::atomic<double>,7> command{};
  std::atomic<int64_t> received{0};
  rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr sub;
  static int64_t now() { return std::chrono::duration_cast<std::chrono::nanoseconds>(
    std::chrono::steady_clock::now().time_since_epoch()).count(); }
public:
  controller_interface::CallbackReturn on_init() override {
    return controller_interface::CallbackReturn::SUCCESS;
  }
  controller_interface::InterfaceConfiguration command_interface_configuration() const override {
    controller_interface::InterfaceConfiguration c;
    c.type=controller_interface::interface_configuration_type::INDIVIDUAL;
    for(int i=1;i<=7;++i) c.names.push_back("fr3_joint"+std::to_string(i)+"/velocity");
    return c;
  }
  controller_interface::InterfaceConfiguration state_interface_configuration() const override {
    return {controller_interface::interface_configuration_type::NONE,{}};
  }
  controller_interface::CallbackReturn on_configure(const rclcpp_lifecycle::State &) override {
    sub=get_node()->create_subscription<std_msgs::msg::Float64MultiArray>("~/commands",1,
      [this](std_msgs::msg::Float64MultiArray::SharedPtr m) {
        if(m->data.size()!=7) {received=0;return;}
        for(double x:m->data) if(!std::isfinite(x)) {received=0;return;}
        for(size_t i=0;i<7;++i) command[i]=std::clamp(m->data[i],-1.5,1.5);
        received=now();
      });
    return controller_interface::CallbackReturn::SUCCESS;
  }
  controller_interface::CallbackReturn on_activate(const rclcpp_lifecycle::State &) override {
    received=0; return controller_interface::CallbackReturn::SUCCESS;
  }
  controller_interface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &) override {
    received=0;
    for(auto &c:command_interfaces_) (void)c.set_value(0.);
    return controller_interface::CallbackReturn::SUCCESS;
  }
  controller_interface::return_type update(const rclcpp::Time &,const rclcpp::Duration &) override {
    const auto age=now()-received.load();
    const bool fresh=received.load()>0 && age>=0 && age<200000000;
    for(size_t i=0;i<command_interfaces_.size();++i)
      (void)command_interfaces_[i].set_value(fresh ? command[i].load() : 0.);
    return controller_interface::return_type::OK;
  }
};
}
PLUGINLIB_EXPORT_CLASS(franka_tracking_controller::Velocity,controller_interface::ControllerInterface)
