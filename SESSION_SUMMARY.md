# Session summary: force-driven conveyor and Jacobian tracking

This summary covers the work discussed and completed in this session: force-driven cube transport, robot following, debugging, testing, and documentation. The stationary pickup/place/return pipeline was the existing foundation; today's tracking work did not add a moving grasp.

## Outcome

The simulation now has a two-stage moving-cube follower:

1. Stop the belt and use MoveIt to plan and execute a collision-checked approach above the conveyor centerline.
2. Switch from the existing arm position trajectory controller to a separate joint velocity controller.
3. Start the cube moving at a nominal 0.10 m/s and follow it with the TCP 15 mm above its top.
4. Stop at the tested workspace boundary, command belt speed zero, and restore the original arm controller holding the current pose.

The tracker uses Gazebo ground-truth position and velocity, a short acceleration prediction from applied force divided by mass, and proportional position feedback. Pinocchio supplies the TCP pose and translational Jacobian from measured robot joints.

## Issues encountered, diagnosis, and solutions

| Issue | Evidence and debug method | Solution and tradeoff |
| --- | --- | --- |
| A stationary contact surface with friction alone did not provide the requested transport | Checked actual cube displacement and speed rather than accepting successful speed-topic publication | Used the explicitly requested external-force approximation: a dynamic cube on a stationary collidable belt, driven by a bounded horizontal force |
| Force was applied but the cube initially did not move as expected | Compared force telemetry with measured cube velocity; inspected the active Bullet physics configuration and collision friction fields | Added Bullet friction settings as well as ODE fields. Reduced belt friction while preserving cube/hand contact properties |
| Applied force divided by mass was easy to mistake for exact cube acceleration | Examined the complete force balance: conveyor forcing, contacts, friction, and gravity | Exposed F/m as the **forcing contribution**, used measured cube velocity, and limited acceleration prediction to a short horizon |
| The controller spawner rejected its initial command-line arguments | Read the launch error and the installed `controller_manager spawner --help` output | Replaced the unsupported `--controller-type` option with the installed version's parameter-file interface |
| TCP translation tracked while the fingers tilted into the cube | Inspected the full Gazebo run and logged TCP error alongside cube motion. Cube Y began drifting even though the commanded conveyor force was along X | Added downward orientation correction in the translational Jacobian's null space. Position remains the primary task; remaining joint freedom holds orientation |
| Conservative joint-speed limits caused increasing tracking lag after orientation hold was added | Compared recorded joint-rate vectors and position errors. Multiple samples reached the original 0.5 rad/s cap | Raised the cap to 1.5 rad/s, below FR3 URDF joint-speed limits. Kept a Cartesian speed cap and defensive native joint clamps |
| Tracking degraded farther along the belt with the tool held downward | Examined where error began growing and where rate limits constrained motion | Chose a tested default downstream cube limit of X=0.42 m. The arm follows approximately 0.27 m from the initial X=0.15 m, then stops. This is an operating bound, not a computed full reachability map |
| A velocity controller can keep its last command if its publisher dies | Deliberately killed the Python tracking process during actual simulation motion and measured subsequent joint velocities | Added a native ros2_control watchdog: commands older than 200 ms steady-clock time become zero. This works without Python cleanup |
| A stop request needed to work during both setup and tracking | Exercised cancellation during the MoveIt action and a separate stop request during velocity following | Added checks during action waits, action cancellation, zero-rate cleanup, and normal restoration of the original position controller |
| Frame or Jacobian convention mistakes could produce plausible but wrong motion | Independently perturbed each arm joint and compared numerical TCP-position derivatives with the analytic Jacobian | Used TCP-origin, world-aligned Jacobians and verified the first three linear-velocity rows on the actual robot URDF |
| Test runs could interfere with existing simulator discovery or leave processes behind | Inspected process lists, launch logs, and controller states | Used separate Gazebo partitions and ROS domains for automated tests, process-group cleanup, and explicit cleanup of an orphan from the initial manual run |

## Major design choices

### Preserve the working robot stack

Kept the robot description, gripper configuration, hardware interfaces, and existing stationary pickup launch unchanged. Added a separate tracking launch and native velocity-controller package. The force plugin was extended with telemetry and backed up before modification.

The same expanded simulation URDF is used by MoveIt and Pinocchio. This avoids introducing inconsistent robot geometry or TCP offsets into planning and control.

### Separate global planning from local following

MoveIt handles the initial route around the scene. A local Jacobian controller then supplies frequent corrections without repeatedly planning complete trajectories.

The belt is stopped during the initial approach. Planning a static approach while the cube keeps moving would require interception logic that is outside this implementation. The initial plan starts from measured joints; neutral is the usual fresh-simulation starting configuration, not an invented state substituted for measurements.

### Define the clearance at the TCP above the cube top

For the default 6 cm cube:

```text
belt top       ≈ 0.450 m
cube center    ≈ 0.480 m
cube top       ≈ 0.510 m
TCP target     ≈ 0.525 m
```

The live loop uses the cube's oriented vertical extent to calculate its top. A point clearance alone does not guarantee whole-finger clearance; that motivated the orientation hold.

### Combine measured-velocity feedforward and position feedback

The implemented horizontal law is approximately:

```text
h = state age + prediction horizon
predicted position = cube position + cube velocity*h + 0.5*a_force*h²
predicted velocity = cube velocity + a_force*h
TCP velocity = predicted velocity + K*(predicted position - TCP position)
```

Default K is 5/s and the additional prediction horizon is 10 ms. Vertical motion uses position feedback toward the measured cube top plus clearance, without vertical velocity/acceleration feedforward. This is tailored to a flat conveyor.

Velocity feedforward allows the TCP to keep moving when position error is zero. Position feedback corrects residual lag and model error. The robot position loop has no integral term; the separate cube speed loop uses PI control to address friction disturbances.

### Use a damped translational inverse with orientation in the null space

The primary conversion is:

```text
qdot_primary = Jv.T * (Jv*Jv.T + lambda²*I)^-1 * TCP_velocity
```

Damping, lambda=0.02, prevents the inverse from requesting unbounded rates near singular configurations, at the cost of exact Cartesian tracking.

The secondary orientation correction is projected through:

```text
N = I - pinv(Jv)*Jv
```

This uses joint motions that do not alter primary TCP translation, before final rate scaling. The desired hand rotation is fixed downward, including yaw. Relaxing yaw could provide more motion freedom, but that was not implemented or validated.

### Make command ownership explicit

The position trajectory controller owns the arm during approach. A strict ros2_control switch deactivates it and activates the velocity controller for tracking. A normal stop reverses that switch.

The new native controller claims the seven existing joint velocity interfaces. It does not calculate torque or implement Cartesian impedance.

### Use simulation time for motion and steady time for liveness

The Python loop runs on a nominal 100 Hz simulation-time timer; Gazebo telemetry is published at up to 100 Hz. Existing controller-manager configuration is 1000 Hz and physics uses a nominal 1 ms step.

Simulation timestamps support motion prediction and reset detection. Wall/steady clocks detect missing joint/state receipts and stale commands even when a process stalls. These configured rates are not hard real-time guarantees.

## Debug methods that proved useful

- **Read installed APIs before guessing:** spawner help, service definitions, native controller headers, and the actual hardware configuration resolved version-specific behavior.
- **Measure physical motion:** compare Gazebo cube position and velocity at simulation timestamps; a published command or loaded plugin is not proof of transport.
- **Record multiple signals together:** cube pose/velocity, TCP position, joint-rate commands, applied-force acceleration, and orientation error distinguished geometry/contact problems from gain problems.
- **Inspect saturation:** a growing position error with a joint repeatedly at its speed cap indicates limited motion authority; increasing feedback gain alone cannot fix it.
- **Use independent numerical checks:** finite differences caught potential Jacobian frame, point, row-order, and joint-column mistakes without relying on visually convincing motion.
- **Inject failures:** stopping during approach, stopping during tracking, and killing the command publisher tested behavior that a successful nominal run cannot establish.
- **Verify controller states after execution:** normal completion must leave the original arm controller and joint-state broadcaster active, with the velocity controller inactive.
- **Regression-test the existing behavior:** reran pickup unit tests and force-conveyor tests after adding telemetry and tracking.

## Tested results

The [latest full tracking metrics](src/franka_conveyor_sim/test/results/conveyor_tracking_tracking_validation.json) contain 49 samples over 2.73 s simulation time, with approximately 0.27 m cube travel.

| Measurement | Result |
| --- | --- |
| Maximum sampled absolute X error | 2.085 mm |
| Maximum sampled absolute Y error | 0.263 mm |
| Maximum sampled clearance/Z error | 0.295 mm |
| Cube lateral displacement check | Below 1 mm |
| Normal completion | Original arm controller restored; velocity controller inactive |
| Requested stop during tracking | Passed; original arm controller restored |
| Cancellation during MoveIt approach | Passed |
| Publisher-death watchdog | Passed; measured joint speeds below 0.00011 rad/s after allowing 0.7 s |
| New kinematics plus existing pickup unit tests | 13 passed |
| Force-conveyor regression | Positive, zero, reverse, pause, airborne cutoff, and off-belt cutoff passed |

The 200 ms watchdog threshold comes from the implementation. The process-death test measured the arm after a 0.7 s observation interval; it did not establish an exact 200 ms physical stopping time. TCP errors are sampled FK-based measurements, not independent optical measurements or continuous-time worst-case bounds.

## Files and documentation

| Artifact | Purpose |
| --- | --- |
| [conveyor_tracker.py](src/franka_conveyor_sim/franka_conveyor_sim/conveyor_tracker.py) | MoveIt coordination, prediction, feedback, kinematics, rate generation, stopping |
| [conveyor_tracking.launch.py](src/franka_conveyor_sim/launch/conveyor_tracking.launch.py) | Complete single-world tracking launch |
| [franka_tracking_controller](src/franka_tracking_controller) | New native watchdog-protected joint velocity controller |
| [tracking_controllers.yaml](src/franka_conveyor_sim/config/tracking_controllers.yaml) | Controller plugin configuration |
| [ConveyorForce.cc](src/franka_conveyor_force_system/src/ConveyorForce.cc) | Force-driven transport and stamped ground-truth telemetry |
| [test_tracking_kinematics.py](src/franka_conveyor_sim/test/test_tracking_kinematics.py) | Independent Jacobian, damping, and null-space checks |
| [tracking_smoke.py](src/franka_conveyor_sim/test/tracking_smoke.py) | Full simulation and failure-injection tests |
| [test/results](src/franka_conveyor_sim/test/results) | Durable metrics and sampled traces |
| [CONTROL_THEORY_IMPLEMENTATION.md](CONTROL_THEORY_IMPLEMENTATION.md) | Detailed theory-to-code explanation and design tradeoffs |
| [PIPELINE_EXPLAINED.md](PIPELINE_EXPLAINED.md) | Overall simulation and planning history, extended with tracking |
| [README.md](src/franka_conveyor_sim/README.md) | Build, launch, parameters, topics, troubleshooting, validation |
| [RESUME.md](src/franka_conveyor_sim/RESUME.md) | Current implementation checkpoint |

Package installation/dependency metadata was also updated for the new tracker, native controller, Pinocchio, messages, and tests.

## Current boundaries and next work

The implemented path follows a single known cube in the audited default FR3 scene. It does not continuously collision-check live velocity motion, update the moving cube in MoveIt's planning scene, follow the entire belt beyond arm reach, or perform a moving grasp. A normal tracking stop holds the current arm pose; it does not return to neutral.

If the Python tracker is killed, the native watchdog zeros joint commands, but cannot stop the belt or restore the position controller. The force-based conveyor remains an approximation of belt transport, and F/m remains only one contribution to physical acceleration.

Natural next steps are a constrained redundancy/limit strategy, broader reachable-region validation, synchronized state estimation for eventual vision input, and a separately designed transition from following to moving grasp. These are prospective changes, not features completed today.

To run the completed demonstration after building and sourcing:

```bash
source ./franka_sim_env.sh
ros2 launch franka_conveyor_sim conveyor_tracking.launch.py
```

To request a normal stop:

```bash
ros2 service call /conveyor_tracking/stop std_srvs/srv/Trigger '{}'
```
