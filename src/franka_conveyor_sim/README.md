# Franka conveyor simulation

ROS 2 Jazzy / Gazebo Harmonic environment package. Existing robot descriptions,
controllers, gripper and MoveIt files are unchanged. The stationary pickup phase now includes OpenCV pose estimation and MoveIt
trajectory generation and optional ros2_control pick-place-return execution.
MPC and moving-target interception are not implemented.

## Current status (2026-10-19)

**Native moving-surface transport works with DART. Native TrackController
transport in the existing Franka Bullet Featherstone world is blocked.** Do not switch the robot
to DART: its current launch uses Bullet Featherstone for the hand mimic joint.
The same box remains stationary under Bullet despite TrackController loading.
Upstream tracks contact-surface velocity support in
[gz-physics issue 569](https://github.com/gazebosim/gz-physics/issues/569).
A one-DOF slider approximation remains available. The new force-driven mode
works under Bullet with free boxes and is the current conveyor focus.
The original injection/standalone default remains TrackController mode. The combined
robot/conveyor wrapper now defaults to the force-driven free-box mode below.

Headless installed-model measurements (Gazebo Sim 8.15.0, Physics 7.8.0):

| Command m/s | DART measured box vx m/s | Bullet Featherstone vx m/s |
| --- | --- | --- |
| 0.10 | 0.10007 | 0.00000 |
| 0.20 | 0.20040 | 0.00000 |
| 0.00 | 0.00000 | 0.00000 |
| -0.10 | -0.09927 | 0.00000 |

Each measurement follows 0.5 seconds of settling/acceleration and spans about
1.5 simulation seconds. Cube center settles at z≈0.550 m. DART log:
`/tmp/conveyor_smoke_16750.log`; Bullet log: `/tmp/conveyor_smoke_16835.log`.
These are local temporary logs, not permanent assets.

Installed standalone launch + ROS spawner integration passed: observed first
appearances t=3.291, 6.306, 9.403 s; pause preserved time and box count; stopping
the belt gated further overlapping arrivals; time-only reset caused no burst;
resuming at 0.20 m/s removed downstream boxes. Log:
`/tmp/conveyor_flow_17166.log`. Headless testing does not verify GUI rendering.

Headless Franka baseline/injection also passed using the unchanged inner launch
with `load_gripper:=true controller:=fr3_arm_controller rviz:=false` and
`gz_args:='-s -r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf'`.
Services confirmed world `empty`. Injecting `add_conveyor` with boxes disabled
succeeded; `fr3_arm_controller` and `joint_state_broadcaster` stayed active before
and after, and `/joint_states` continued with seven arm joints and a finger joint.
Only the arm trajectory action was advertised; gripper action execution and
MoveIt were not verified in that historical injection trial. Log: `/tmp/franka_injection_trial.log`.

## Force-driven conveyor (current mode)

This mode keeps the belt static and applies a bounded horizontal force to each
free box, accelerating it toward the requested belt speed. It does not move the
surface, teleport boxes, set their velocities directly, constrain them to rails,
or alter the robot hardware. It is an **external-force conveyor approximation**,
not a validated material/contact model of a real moving belt.

For the existing FR3 + camera + yellow-table scene, with one 6 cm free cube:

```bash
# Stop any previous simulation first; this starts one Gazebo instance.
source franka_sim_env.sh
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py \
  motion_mode:=force belt_speed:=0.1
```

The scene keeps its original belt top 0.45 m, length 3 m, camera and table. It
starts no pickup planner or executor. `pickup_planning.launch.py` explicitly
keeps its stationary scene, since its estimator and saved paths assume a stationary
cube. Moving-target grasping remains future work.

For automatic flow with 10 cm free boxes and the unchanged Franka bringup:

```bash
ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py
# Force mode is now this wrapper's default, initial speed 0.1 m/s.
```

Standalone or injection alternatives:

```bash
ros2 launch franka_conveyor_sim conveyor_test.launch.py motion_mode:=force \
  gz_args:='-r -v 4 --physics-engine gz-physics-bullet-featherstone-plugin'
# Or inject into an existing world that does not already have a conveyor:
ros2 launch franka_conveyor_sim add_conveyor.launch.py \
  world:=empty motion_mode:=force belt_speed:=0.1
```

Confirm the actual world name before injection. These are alternative paths;
do not launch two servers for one experiment. To add force behavior to a previously
spawned stationary pickup cube, restart that scene in force mode: only force-model
boxes contain the controller plugin. Injection uses an absolute plugin filename,
so an existing server need not have inherited the new plugin search path.

Command the same **Gazebo Transport** speed topic after startup:

```bash
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.2'
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.0'
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: -0.1'
```

The last command persists; new flow boxes inherit it. Commands are limited to
±1 m/s and nonfinite values are ignored. Zero requests a deceleration to rest,
not an instantaneous stop. The PI controller can produce small transient
overshoot/reverse drift around zero (about 1.5 mm/s in the recorded stop window).

### Force implementation and choices

The added ament_cmake package `franka_conveyor_force_system` implements
`franka_conveyor::ConveyorForce` in `src/ConveyorForce.cc`. Its `Configure()`
subscribes to speed commands; `PreUpdate()` reads actual link velocity and applies
`Link::AddWorldForce()` at the center of mass on every running physics step:

```text
error = desired_speed - dot(world_velocity, belt_world_X_axis)
integral += error * simulation_dt          # conditional anti-windup
acceleration_command = clamp(Kp*error + Ki*integral, -a_max, +a_max)
world_force = actual_box_mass * acceleration_command * belt_world_X_axis
```

Default launch parameters are `force_velocity_gain:=10.0` (1/s),
`force_integral_gain:=2.0` (1/s²), and `force_max_acceleration:=1.0` (m/s²).
For the 0.20 kg boxes, the applied force is capped at **0.20 N**. That cap bounds
this controller's contribution, not acceleration caused by collisions/other forces.
The small integral term compensates residual friction. State resets on command
changes, leaving the belt region, or simulation time reversal; pause stops force
updates. The feedback loop runs in Gazebo, independently of ROS clock/message
latency. The existing Python package remains ament_python.

`models/conveyor_force` supplies a separate low-friction belt with both ODE
`mu/mu2` and Bullet `friction/friction2` set to 0.01. The original belt and all
robot/hand collision parameters are unchanged. `models/box_force` retains the
ordinary dynamic box's friction settings and adds only the force system, preserving
box/hand contact properties. The installed Bullet backend ignores the ODE tags;
its own friction tags were needed to overcome the unexpected default floor friction
without increasing force limits. The matching upstream APIs are
[Gazebo Sim 8 Link](https://raw.githubusercontent.com/gazebosim/gz-sim/gz-sim8/src/Link.cc)
and [Bullet Featherstone SDF friction loading](https://raw.githubusercontent.com/gazebosim/gz-physics/gz-physics7/bullet-featherstone/src/SDFFeatures.cc).

Force is applied only within the configured belt footprint, with the cube bottom
within 3 mm of the belt top and vertical speed below 0.03 m/s. Oriented cube height
is accounted for. This is a **geometric contact proxy**, not a contact sensor or
grasp detector. Once lifted or outside the belt, force is zero and the body remains
free to fall, rotate or collide. A grasped cube still touching the belt can continue
to receive force until it leaves that gate; future moving grasp integration should
add explicit grasp/contact state. Force is never applied vertically or laterally.

`force_model.configure_force_plugin()` shares geometry/configuration between the
single-cube scene and the flow spawner. Force is scoped per box and can load when
boxes are dynamically inserted into a running Harmonic world; no new world plugin
or robot-description edit is needed. Flow cleanup also removes owned boxes that
fall below the deck past the positive belt end, since a free box may stop on the
floor before reaching the older slider removal limit. Negative-flow cleanup
remains unimplemented; `max_boxes` bounds that case.

Telemetry is native Gazebo `gz.msgs.Double` at 20 simulation Hz:
`/model/<actual_box_name>/conveyor_force` in N and
`/model/<actual_box_name>/conveyor_velocity` in belt-local m/s. For the camera
scene, the model name is `box_pickup`. The applied velocity gain, integral gain,
initial speed, acceleration cap, box mass and belt geometry determine response.
This does not yet calibrate real belt traction, torque at the contact patch or slip.

### Tested force-mode behavior

Persistent results: [conveyor_force_validation.json](test/results/conveyor_force_validation.json).
Backups of edited environment launches/spawner are in `/tmp/conveyor_force_backups`;
original robot launches, URDF, hardware interfaces and controller files were not edited.

Under the installed Bullet Featherstone backend, standalone measurements after
settling gave 0.10139, 0.20147, -0.00150 and -0.10137 m/s for commands 0.10,
0.20, 0 and -0.10. The 90-degree rotated-belt test also passed. Force/airborne
checks confirmed finite acceleration, a 0.20 N force bound, pause, gravity-driven
free fall, and zero force off-belt/airborne. Test-only pose changes lift/reposition
the cube for those checks; runtime transport never changes poses.

The existing camera/robot scene passed with its 6 cm cube: 0.10190 and
0.20047 m/s for 0.10 and 0.20 commands; original arm controller and joint-state
broadcaster stayed active before/after. Flow tests passed unique births at roughly
3.1 s intervals, new-box speed inheritance, pause, stopped-belt spacing, time reset
without a spawn burst and downstream deletion. Moving grasp execution has not
been tested or implemented. Repeat the checks with:

```bash
python3 src/franka_conveyor_sim/test/force_conveyor_smoke.py
python3 src/franka_conveyor_sim/test/force_conveyor_smoke.py --pickup-scene
python3 src/franka_conveyor_sim/test/transport_smoke.py --motion-mode force \
  --engine gz-physics-bullet-featherstone-plugin --belt-yaw 1.5707963267948966
python3 src/franka_conveyor_sim/test/spawner_smoke.py --motion-mode force \
  --engine gz-physics-bullet-featherstone-plugin
```

## OpenCV pose estimation and MoveIt 2 pickup planning

This phase implements the user-requested perception and trajectory generation.
By default it **plans and previews only**. Enable the optional executor below to
send the planned arm and finger trajectories to ros2_control.
As approved, the pickup cube is now **6 cm** wide so it fits the existing hand's
8 cm maximum aperture. The original 10 cm conveyor box model is unchanged.

Start with no other Gazebo/MoveIt launch running:

```bash
cd ~/franka_ros2_ws
source franka_sim_env.sh
ros2 launch franka_conveyor_sim pickup_planning.launch.py
```

This starts the pickup simulation, one MoveIt `move_group`, OpenCV estimator,
planner and RViz with trajectory/scene/target/image displays. It does not start a
second hardware interface, controller manager, or robot-state publisher. It uses
the exact simulation xacro and existing FR3 semantics/kinematics/joint limits.
The wrapper fixes two mismatches **in memory only**: removes the SRDF virtual
joint for nonexistent link `base` (simulation already has a fixed world root),
and maps the existing OMPL `panda_arm` settings onto actual group `fr3_arm`.
Existing robot/controller/MoveIt files remain untouched. MoveIt trajectory
execution through MoveIt is disabled; the optional executor sends staged
FollowJointTrajectory goals directly to ros2_control.

To attach to an already running **6 cm** pickup scene instead:

```bash
ros2 launch franka_conveyor_sim pickup_planning.launch.py start_sim:=false
```

Do not start a second `move_group` unintentionally. Geometry arguments must match
the existing scene; restarting the combined launch is preferable after changing
cube size. Use `auto_plan:=false` to wait for a manual planning request:

```bash
ros2 service call /pickup/plan std_srvs/srv/Trigger '{}'
ros2 topic echo /pickup/planning_status --once --qos-durability transient_local
```

The Trigger response means queued; completion/failure is reported by status and
JSON. Replanning uses a fresh camera estimate. The default result file is
`/tmp/franka_pickup_plan.json`; set `output_path:=/your/path/plan.json` to keep it
elsewhere. Files are written atomically, and failures produce a reason rather
than a misleading partial plan. Pose and all trajectory fields/timestamps are
included for review. Standalone executables are `box_pose_estimator` and
`pickup_planner`; they require the camera/TF/MoveIt stack and `use_sim_time:=true`.

### What the camera estimator observes

`box_pose_estimator.py` synchronizes aligned RGB/depth, segments the red cube with
OpenCV HSV masks, back-projects finite depth through CameraInfo, and transforms
samples into `world` using timestamped optical TF. It fits a top-face rectangle
in world XY and subtracts half the known cube height to estimate its center.
Five consistent frames are required; invalid/stale depth, mismatched frames,
wrong height/size, unstable centers and missing detections are rejected.

This is a known-size upright red-cube estimator, not a general 6-DOF detector.
Roll/pitch are assumed upright on the stationary belt; square yaw is observable
only modulo 90°. No Gazebo entity pose or configured block XY is supplied to the
estimator/planner as a detection. Gazebo truth is read only by integration tests.
Occlusion, arbitrary colors/objects, real D435 calibration/noise and segmentation
robustness beyond this scene remain unverified.

Topics:

| Topic | Purpose |
| --- | --- |
| `/pickup/box_pose` | Stable estimated cube center/yaw, PoseStamped in world |
| `/pickup/detection` | Fitted dimensions, top height, pixel count and stability |
| `/pickup/detection_image` | RGB image with OpenCV contour overlay |
| `/pickup/pregrasp_pose`, `/pickup/grasp_pose` | Desired `fr3_hand_tcp` poses |
| `/pickup/targets` | Pre-grasp, grasp and yellow release position markers |
| `/pickup/display_trajectory` | Chained MoveIt DisplayTrajectory for RViz |
| `/pickup/planning_status` | Waiting/planning/success/failure JSON |

### Tool poses and trajectories

The tool link is the actual **`fr3_hand_tcp`** (not the flange). Desired tool +Z
points down, and local Y is the finger closing axis. Four cube-equivalent yaw
orientations are tried if necessary. With the default 6 cm cube and `grasp_insertion`
0.02 m, the grasp TCP is 2 cm below the detected cube top, and pre-grasp is
`pregrasp_clearance` 0.12 m above that. This gives approximately:

- estimated cube center `(0.14874, 0.50139, 0.48027)` m;
- pre-grasp TCP `(0.14874, 0.50139, 0.61027)` m;
- grasp TCP `(0.14874, 0.50139, 0.49027)` m.

The planner installs collision geometry for the conveyor, goal tabletop/legs,
floor and camera-estimated cube. Existing SRDF collision allowances are retained;
floor/base mounting contact is allowed. The preview now starts from configured
neutral (`home_joints`, SRDF ready values), with an 8 cm open hand:

1. Neutral → oriented pre-grasp, using collision-checked OMPL.
2. Vertical Cartesian approach at fixed downward TCP orientation (5 mm samples).
3. Symmetric finger closure to the cube width over 2 seconds, checked at 21 states.
   Only cube/finger contact is allowed during closure validation; the original
   collision matrix is restored afterward. Belt/palm/other collisions remain checked.

4. Attach the cube collision body to the TCP and lift vertically by 0.15 m.
5. Solve the low release IK first and compute its checked vertical ascent.
   Transfer with OMPL to the resulting above-target joint configuration.
6. Compute the downward Cartesian path from that same branch, with MoveIt
   retiming to zero terminal velocity. Stop with the cube bottom 1 cm above the
   tabletop.
7. Open fingers to 8 cm, detach, and model the cube settled upright on the circle.
8. Retreat vertically, then return to neutral with OMPL, avoiding the placed cube.

Equivalent grasp orientations are tested against the **entire** task; a feasible
pickup alone does not count as success. The attached cube participates in collision
checking throughout transport. Only finger links are touch links. The sensed world
cube is restored after planning, including failures, so replanning remains repeatable.
`stage_start_states` in the JSON records attachment transitions; `stage_targets`
records lift, transfer, release and retreat TCP poses.

Launch arguments `lift_clearance:=0.15` and `drop_height:=0.01` configure the lift
and short release gap. Destination uses `goal_table_x/y/top`, matching the yellow
circle at the table center. `closure_duration` controls both closing and opening
through the planner ROS parameters. All nine stages are included in the RViz arm
preview. A yellow release-position marker is published on `/pickup/targets`.
The single RViz DisplayTrajectory does not animate cube attachment/detachment;
attachment transitions are represented in the saved stage start states.

**Planning preview only:** no arm or gripper commands are sent. Neutral and the
open hand are start assumptions. Finger force, attachment and falling/settling are
not physics-tested; release assumes the upright cube lands directly below the TCP.
Revalidate the measured state and scene before any later execution.

### Validation and saved examples

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
python3 -m pytest -q src/franka_conveyor_sim/test/test_pickup_geometry.py
python3 src/franka_conveyor_sim/test/pickup_planning_smoke.py
```

Full pick-place-return validation passed in an isolated headless Gazebo/MoveIt
run: `/tmp/pickup_planning_15893.log` and `.json`. All nine stages have continuous
joint endpoints. TCP endpoint errors were below 0.697 mm, with complete Cartesian
paths. Cube center estimate error was 1.892 mm. The preview releases at
TCP `(-0.55, 0.15, 0.40)` m and predicts settled cube center
`(-0.55, 0.15, 0.38)` m. Final arm matches neutral within 0.002 rad and fingers
are open at 0.04 m per joint. Attachment metadata and fresh-pose replanning passed;
observed joint states confirm no execution. Three geometry unit tests also pass.
Older artifacts under `test/results/pickup_*` describe previous planner versions.
RViz playback appearance remains **UNVERIFIED**. Physical stationary pickup,
transport, release and neutral return have since passed the execution test below.

## Execute the pickup with ros2_control

Build and source the overlay:

```bash
source /opt/ros/jazzy/setup.bash
colcon build --packages-select franka_conveyor_force_system franka_conveyor_sim --symlink-install
source franka_sim_env.sh
```

For a new simulation, enable the optional executor alongside the planner:

```bash
ros2 launch franka_conveyor_sim pickup_planning.launch.py execution:=true
# In another sourced terminal, after planning succeeds:
ros2 service call /pickup/execute std_srvs/srv/Trigger '{}'
```

If the pickup simulation and planner are **already running**, add just the
controller and executor; this starts no Gazebo, MoveIt server or robot publisher:

```bash
ros2 launch franka_conveyor_sim pickup_execution.launch.py
ros2 service call /pickup/execute std_srvs/srv/Trigger '{}'
```

`auto_execute:=true` executes once after the plan succeeds. The executor consumes
`/tmp/franka_pickup_plan.json` (`plan_path` in the execution-only launch).
If the plan is older than 120 simulation seconds, regenerate it with
`ros2 service call /pickup/plan std_srvs/srv/Trigger '{}'` before execution.
It sends arm stages to `/fr3_arm_controller/follow_joint_trajectory` and finger
stages to `/pickup_hand_controller/follow_joint_trajectory`. The added hand
controller claims only existing `fr3_finger_joint1/position`; the existing 1:1 mimic
controls the other finger. No robot URDF, hardware interfaces or original
controller configuration is changed. For an existing compatible hand trajectory
controller, use `spawn_hand_controller:=false hand_controller:=YOUR_CONTROLLER`.

The executor opens the hand, then follows the nine stages sequentially. It checks
plan structure/timing, controller activation, measured neutral start, fresh cube
position/yaw and joint-state freshness. Arm stages are rechecked against the live
MoveIt collision scene. Contact closure adds configurable `grasp_compression`
(default 0.001 m per finger) to the nominal geometric-contact trajectory. This is
a position-controlled contact grip, not force control. Finger 2 is inferred from
the URDF mimic relationship when it is absent from `/joint_states`.

Attachment/detachment updates only MoveIt's collision scene. The executor does
not teleport, weld or otherwise attach the physical Gazebo cube. The actual cube
must be held by friction/contact. The return stage assumes it settles upright at
the target; the executor does not independently verify placement. Execution
success means controller stages completed, and reports
`physical_cube_placement_verified: false` explicitly.

```bash
ros2 topic echo /pickup/execution_status --qos-durability transient_local
ros2 service call /pickup/cancel std_srvs/srv/Trigger '{}'
ros2 control list_controllers
```

Cancellation or any controller/path/state failure stops later stages and cancels
an active trajectory. The hand is not automatically opened on failure. The
planner refuses replanning while execution is active. The executor refuses a
non-neutral initial arm; it never sends an unchecked homing move. Clock resets
abort execution. Pausing Gazebo pauses controller motion; the wall watchdog is
300 s per action, so cancel/replan after longer pauses. Restarting an executor
leaves controllers active and does not resume an interrupted task.
Execution results are saved to `/tmp/franka_pickup_execution.json`.

The environment wrapper now bridges `/world/franka_pickup/clock` to `/clock`
using Gazebo's `CLOCK` QoS (best effort, depth 1). An execution trial exposed a
stall of the original generic clock bridge; the wrapper redirects that bridge's
ROS output to `/pickup_legacy_clock` so there is exactly one `/clock` publisher.
Only the upstream node named `ros_gz_bridge` is remapped. The original robot
launch remains unchanged. Wrapper backup: `/tmp/franka_pickup_sim_before_execution_clock.py`.
Restart an older pickup simulation to receive this clock fix before execution.

Validation commands:

```bash
python3 -m pytest -q src/franka_conveyor_sim/test/test_pickup_executor.py
python3 src/franka_conveyor_sim/test/pickup_execution_smoke.py
python3 src/franka_conveyor_sim/test/pickup_execution_smoke.py --cancel --attach-executor
```

Physical execution validation passed with all nine controller stages completed.
The cube center rose from z=0.480 m to z=0.630 m and settled at
`(-0.55018, 0.15321, 0.38000)` m, **3.22 mm** from the yellow circle center.
Maximum final neutral joint error was **0.00082 rad**. Contact physics carried the
cube without a simulated weld or pose command. Cancellation, no later-stage
execution, stable stopped arm, planner interlock and rejection of a non-neutral
restart passed through the execution-only launch. Ten unit tests pass.
Persistent [execution validation](test/results/pickup_execution_validation.json)
records these measurements; logs are `/tmp/pickup_execution_22427.log` and
`/tmp/pickup_execution_20977.log`. These checks cover the default 6 cm static
cube and scene, not arbitrary grasps, real hardware or moving-target interception.

## Stationary pickup scene with overhead RGB-D camera

This separate launch leaves the moving-conveyor launch available:

```bash
cd ~/franka_ros2_ws
source franka_sim_env.sh
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py
```

Start with no other simulation running. This starts one Bullet Featherstone
Gazebo world (`franka_pickup`) with unchanged Franka/hand/arm-controller bringup,
a stationary conveyor, one free dynamic red cube, and an overhead D435-style
RGB-D camera. There is no box spawner or slider joint in this scene. In default stationary mode, publishing
the conveyor velocity topic does not move this block.

A collidable goal table is added rear-left of the robot at (-0.55,+0.15), with
its top at z=0.35 m. The 0.50×0.24 m tabletop leaves a 3 cm gap to the conveyor.
A yellow filled circle (radius 0.08 m) marks the placement destination; the
circle is visual-only, so it adds no collision bump. Four legs reach the floor.
`goal_destination` TF marks the circle center at the tabletop surface; a resting
6 cm cube center would be 0.03 m above that frame. This is a destination marker only,
with no automatic placement logic in this camera-only launch. The execution
launch above validates the default static scene and placement path.
Adjust `goal_table_x`, `goal_table_y`, `goal_table_top` if desired; overlapping
table/conveyor footprints are rejected. Restart the pickup launch to add it.

Defaults:

| Item | Geometry / placement |
| --- | --- |
| Conveyor | 3.0 × 0.4 × 0.1 m; center (0.1,0.5,0.40), top z=0.45 m |
| Upstream extension | Original X range [-0.4,1.6] becomes [-1.4,1.6]; downstream end unchanged |
| Free cube | 0.06 m, 0.20 kg, initially (0.15,0.5,0.50); settles to center z≈0.48 |
| Camera | Optical origin (0.15,0.2584,1.60) m; 12.5° from vertical, aimed in +Y away from robot |
| Image streams | Ideal aligned RGB/depth 848×480; configured 15 simulation Hz |

The surface is lowered 5 cm from the earlier 0.50 m top. The block sits on the conveyor centerline y=0.50 and is shifted toward the robot
along X to x=0.15. Its horizontal distance from the base is about 0.522 m
(originally 0.743 m). The camera follows the block automatically. Camera placement is computed to
aim at the settled cube top: tilt is from vertical, yaw selects tilt direction,
and camera XY is offset from the block accordingly. The camera views the pickup
region; the full extended 3 m belt need not fit inside its image.

The silver/black 90 mm housing approximates a D435. It uses Gazebo's native
`rgbd_camera` with approximately 87° horizontal FOV (depth-like optics) and ideal
aligned color/depth, based on the D435 depth FOV in the
[Intel D400 datasheet](https://www.intelrealsense.com/wp-content/uploads/2022/05/Intel-RealSense-D400-Series-Datasheet-April-2022.pdf).
It does not emulate separate RGB optics, IR stereo, projector, factory distortion,
RealSense firmware/SDK or depth noise. The simulated near/far clips are .1/5 m;
these are rendering settings, not claimed device performance. It does not need
`realsense2_camera` or physical camera hardware.

ROS topics (all bridges are Gazebo → ROS, sensor-data QoS):

| ROS topic | Type / frame |
| --- | --- |
| `/camera/color/image_raw` | Image, rgb8, `camera_optical_frame` |
| `/camera/depth/image_rect_raw` | Image, 32FC1 metres, `camera_optical_frame` |
| `/camera/color/camera_info` | CameraInfo, optical frame |
| `/camera/depth/camera_info` | CameraInfo, same ideal intrinsics |
| `/camera/depth/points` | PointCloud2, colored, `camera_link` |

TF: `world → camera_link → camera_optical_frame`. Camera-link convention is
+X forward, +Y left, +Z up; optical convention is +Z forward, +X right, +Y down.
The installed Harmonic sensor labels its cloud optical but its numeric coordinates
are camera-link coordinates. A **per-cloud bridge frame override** corrects this
without rotating the data. Images/intrinsics keep optical-frame IDs. The smoke
test verifies actual center cloud coordinates and their transform onto the block;
repeat it after changing Gazebo versions. Do not relabel the cloud optical.

The pickup world preserves Physics, UserCommands, SceneBroadcaster and Contact
systems from the original empty-world setup and adds Ogre2 Sensors plus Imu for
the camera/robot IMUs. No existing robot/world/MoveIt files are edited. Assets are
resolved through installed package shares; no Fuel/network model download is used.
RViz opens the robot, colored point cloud, RGB and depth panels with fixed frame
`world`. Its layout still needs a desktop visual check; camera RGB rendering was
inspected from the smoke-test image.

Example tuning and headless execution:

```bash
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py \
  belt_top:=0.43 upstream_extension:=1.0 camera_tilt_deg:=15 camera_z:=1.6
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py \
  rviz:=false gz_args:='-s -r -v 4 --headless-rendering'
```

Arguments: `rviz`, `gz_args` (flags only; world/physics selected by the launch),
`belt_top`, `belt_y`, `upstream_extension`, `block_size`, `block_x`, `block_y`, `camera_z`,
`camera_tilt_deg`, `camera_yaw_deg`, `camera_width`, `camera_height`, `camera_rate`,
`goal_table_x`, `goal_table_y`, `goal_table_top`.
Yaw 90° tilts toward world +Y; 0° tilts toward +X. Camera translation is recomputed
from the block location, height and tilt. Resolution/rate are adjustable together;
changing aspect ratio changes vertical FOV. Optical settings live in the D435 SDF.

Validation:

```bash
python3 src/franka_conveyor_sim/test/pickup_smoke.py
ros2 topic list | rg '^/camera/'
ros2 topic echo /camera/depth/camera_info --once --qos-reliability best_effort
ros2 run tf2_ros tf2_echo world camera_optical_frame
```

The headless smoke test launches its own isolated scene, checks live messages,
actual red-cube visibility/depth, TF/cloud alignment, controllers, settling and
free-fall after lifting the box through a pose service. It stops the scene after
testing. Historical result at the earlier block location (0.55,0.5): 1962 red pixels, cube median depth 1.0768 m,
center point in world (0.5512,0.4988,0.5500), box center after free fall z=0.5000.
Persistent [RGB preview](test/results/pickup_rgb.png) and
[validation data](test/results/pickup_validation.json) are in the source package.
Test-only NumPy/Pillow dependencies are declared. The saved preview/data now reflect the current 6 cm cube placement. The latest
camera/free-body regression passed: 672 red pixels, median cube depth 1.11758 m,
center cloud in world (0.15125,0.49872,0.51000), free-fall settling center z=0.48000.
Log: `/tmp/pickup_smoke_49772.log`.

The cube is physically unconstrained and collidable, so the rail restriction
has been removed. Physical closing, lift, transport, release and neutral return
are now tested through the optional executor described above. The basic camera-only launch does not insert Gazebo obstacles into MoveIt;
the new planning launch explicitly adds the static scene and detected cube. Validate hand action availability,
reach/collisions and add scene objects before planning grasps. The new planning launch implements the restricted red-cube estimator above;
real calibration and general perception remain future work.

## Start Franka and conveyor with one launch

In a configured terminal, with no other Franka/Gazebo instance running:

```bash
cd ~/franka_ros2_ws
source franka_sim_env.sh
ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py
```

This wrapper starts the unchanged Franka bringup with its hand, arm controller,
Bullet Featherstone physics and RViz, then injects a stationary conveyor and
force-driven free boxes into the same `empty` world. It starts one Gazebo server and
uses Franka's existing clock bridge. Creation waits for the world service;
box spawning starts only after the conveyor is created. Force mode is the wrapper's
default, at `belt_speed:=0.1`; `add_conveyor` and the standalone launch retain their
original physical default. Select `motion_mode:=slider` to reproduce the older
constrained-box trial. In another configured terminal:

```bash
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
```

Ctrl-C on the combined launch stops both robot simulation and conveyor nodes.
To add the conveyor to an already running robot, use `add_conveyor` instead.
Exposed settings include `rviz`, `gz_args`, `world`, `motion_mode`, `hover_gap`,
belt pose, `spawn_boxes`, `interval`, and `spawn_local_x`. If changing the world
through `gz_args`, set `world` to match. The default robot settings are unchanged.
The earlier combined wrapper, explicitly selecting slider mode, passed its headless test: measured slider speed
0.100725 m/s, active arm controller/state broadcaster, and joint_states present.
Log: `/tmp/franka_conveyor_wrapper_trial.log`. Headless launch/test:

```bash
ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py rviz:=false \
  gz_args:='-s -r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf'
python3 src/franka_conveyor_sim/test/franka_slider_smoke.py --combined-launch
```

## One-DOF moving boxes above a stationary belt (Bullet compatible)

Select `motion_mode:=slider` for the requested visual approximation. Each box has
an invisible anchor fixed to the world and a prismatic `slide` joint along its
local +X. Gazebo Harmonic's JointController commands the joint velocity; this is
joint-driven motion, not repeated pose teleportation. The conveyor has no
TrackController in this mode and remains stationary. A direct world-to-prismatic
joint is unsupported by this Bullet backend, so the hidden fixed anchor is required.

The cube bottom is 2 mm above the conveyor top (`hover_gap:=0.002`, adjustable
from 0.001 to 0.02 m). For top z=0.50, cube center is z=0.552. Y, Z and orientation
are constrained; belt yaw rotates the travel axis. The model's canonical link is
the visible box, so Gazebo pose data and cleanup follow the moving cube.

Start the existing Franka simulation normally, then in another configured shell:

```bash
# Confirm the world from gz service -l (tested world name: empty).
ros2 launch franka_conveyor_sim add_conveyor.launch.py world:=empty motion_mode:=slider
# After the spawner starts, command all boxes:
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
```

Use a fresh world or remove the earlier conveyor before switching modes; this
launch does not replace an existing `conveyor`. Do not run two spawners. Commands
0.2, 0, and -0.1 change speed, stop, and reverse. Newly spawned boxes inherit the
last command received by the spawner; send the first command after it starts.
Keep speeds within the model's ±1 m/s joint limit (tested ±0.1 and +0.2).

Standalone demonstration with the same Bullet backend:

```bash
ros2 launch franka_conveyor_sim conveyor_test.launch.py motion_mode:=slider \
  gz_args:='-r -v 4 --physics-engine gz-physics-bullet-featherstone-plugin'
```

This mode retains collision geometry but the box is held on a world-fixed rail.
It cannot fall, lift, tumble, or be freely grasped; commanded velocity can resist
contacts unrealistically. Use it for appearance, camera/perception development
and interception timing. It is unsuitable for validating belt friction, slip,
contact forces or grasp physics. The force mode above is the free-body alternative; slider mode itself has no free-body release. Reverse
motion works, but automatic cleanup currently handles the +X end only.

Measured Bullet slider velocities: 0.10027, 0.19840, 0, -0.10026 m/s for commands
0.1, 0.2, 0, -0.1. Height stayed at 0.552 m. A 90-degree yaw test passed with motion
along world +Y and no lateral drift. Logs: `/tmp/conveyor_smoke_18560.log` and
`/tmp/conveyor_smoke_18855.log`. Slider spawning/hover/inherited speed, pause,
spacing, time reset and downstream removal passed in the installed launch:
`/tmp/conveyor_flow_18682.log`. A combined unchanged Franka + slider test also passed in discovered world `empty`:
measured vx=0.099687 m/s, y=0.5 and z=0.552, with arm controller and joint-state
broadcaster active and arm joint states still present. Log:
`/tmp/franka_slider_trial.log`. Gripper action and MoveIt execution were not verified in that slider trial. GUI appearance is not yet visually verified.

Repeat tests (headless):

```bash
python3 src/franka_conveyor_sim/test/transport_smoke.py \
  --engine gz-physics-bullet-featherstone-plugin --motion-mode slider
python3 src/franka_conveyor_sim/test/transport_smoke.py \
  --engine gz-physics-bullet-featherstone-plugin --motion-mode slider --belt-yaw 1.5707963267948966
python3 src/franka_conveyor_sim/test/spawner_smoke.py \
  --engine gz-physics-bullet-featherstone-plugin --motion-mode slider
# Starts an isolated unchanged Franka simulation; no separate conveyor world:
python3 src/franka_conveyor_sim/test/franka_slider_smoke.py
```

## Build and shell setup

From `/home/nick/franka_ros2_ws`:

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
colcon build --packages-select franka_conveyor_force_system franka_conveyor_sim
source install/setup.bash
source franka_sim_env.sh
```

Use that environment in every participating terminal. This laptop's environment
script selects Cyclone DDS and `GZ_IP=127.0.0.1` because Wi-Fi multicast discovery
has failed. For remote hosts, use appropriate shared discovery/network settings.
`GZ_PARTITION` must match between server, CLI and ROS spawner. Smoke scripts use
an isolated partition and terminate their own launch processes.

## Standalone physical conveyor

Do not run this alongside Franka as an integration method; it starts Gazebo.

```bash
ros2 launch franka_conveyor_sim conveyor_test.launch.py
# Headless equivalent:
ros2 launch franka_conveyor_sim conveyor_test.launch.py gz_args:='-s -r -v 4'
```

World name is `conveyor_test`. Default DART engine supports this TrackController
setup. Belt center is (0.6,0,0.45), top z=0.50 m. Spawner starts automatically;
the belt starts **stopped**. In another configured terminal:

```bash
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.2'
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.0'
# Reverse supported physically in DART; automatic cleanup is +X only:
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: -0.1'
```

These are Gazebo Transport commands, not ROS topics; no speed bridge is needed.
Stop/start automatic arrivals while leaving the launch running:

```bash
ros2 param set /box_spawner enabled false
ros2 param set /box_spawner enabled true
```

Ctrl-C stops the launch and its nodes. Existing models persist if only a spawner
attached to an external world is stopped. Launch with `spawn_boxes:=false` for
manual creation:

```bash
share=$(ros2 pkg prefix --share franka_conveyor_sim)
ros2 run ros_gz_sim create -world conveyor_test \
  -file "$share/models/box/model.sdf" -name box_test -x -0.25 -y 0 -z 0.57
```

## Add to the existing Franka world

Known existing start command (also in workspace `Franka Gazebo Launch.txt`):

```bash
source franka_sim_env.sh
ros2 launch franka_gazebo_bringup franka_sim.launch.py
```

Discover the active world; do not assume `default`:

```bash
gz service -l
# Find /world/<actual_name>/create, then use that name:
ros2 launch franka_conveyor_sim add_conveyor.launch.py world:=ACTUAL_NAME spawn_boxes:=false
```

`add_conveyor` never starts a Gazebo process. It spawns a separately collidable
belt via `ros_gz_sim create`. Do not inject a duplicate belt named `conveyor`.
With supported physics, omit `spawn_boxes:=false` to enable automatic boxes.
**The unchanged Franka Bullet backend cannot currently transport the boxes.**
Clock bridging defaults off here because Franka already bridges `/clock`.
For another external world without that bridge, set `bridge_clock:=true`.

Default injection center is (0.6,0.5,0.45), yaw=0 in **world coordinates**.
The inspected robot xacro anchors `world -> fr3_link0` at zero. The provisional
lateral offset gives the belt y range [0.3,0.7], avoiding the origin; the original
candidate y=0 would cross the base. Arm/gripper clearance and IK reach remain
**UNVERIFIED**. Inspect the posed robot and validate an approach pose before
planning motions near the belt. Gazebo models do not automatically enter the
MoveIt planning scene.

Launch arguments for injection: `world` (required), `belt_x`, `belt_y`, `belt_z`,
`belt_yaw`, `interval`, `spawn_local_x`, `spawn_boxes`, `bridge_clock`,
`motion_mode` (physical, slider or force; restart to change), `hover_gap`.
Spawner defaults are in `config/conveyor.yaml`; run it separately if desired:

```bash
share=$(ros2 pkg prefix --share franka_conveyor_sim)
ros2 run franka_conveyor_sim box_spawner --ros-args \
  --params-file "$share/config/conveyor.yaml" \
  -p world:=ACTUAL_NAME -p belt_y:=0.5
```

Do not run two spawners unintentionally. All placement values must agree with
the actual belt pose. Resource paths are prepended while preserving existing
values. Injection uses installed absolute SDF paths and does not depend on
changing the already running server's resource environment.

## Models and spawner behavior

Belt geometry is currently fixed at 2.0×0.4×0.1 m; cube is 0.10 m, 0.20 kg,
with diagonal inertia 0.000333333 kg m². Geometry configurability is pending;
edit model dimensions and associated placement bounds together if changing it.
Box spawn point is transformed from belt-local x=-0.85 and configurable lateral
offset; z=belt_z+0.12 (0.57 m by default), allowing settling. Optional lateral
randomness uses a fixed seed. Speeds and poses are configurable; nominal speed
is commanded explicitly after startup.

TrackController attaches to `base_link`, topic `/conveyor/cmd_vel`, message
`gz.msgs.Double`. Friction follows the installed matching gz-sim8 conveyor example
(mu=0.7, mu2=150, fdir1=0 1 0). Static friction alone does not drive boxes.

The spawner uses ROS simulation time, fresh Gazebo poses, unique per-run names,
minimum spacing, bounded box count and retries with simulation-time backoff.
A persistent service-only worker process avoids observed blocking-request
failures when Python transport subscriptions share the requesting process.
No repeated `ros2 run` subprocess is created per box.

Cleanup only deletes owned boxes beyond belt-local +X=1.15, within a narrow
lateral corridor and below belt_z+0.18. Lifted/laterally moved boxes are retained.
Negative-direction cleanup and general lifetime expiry are not implemented;
max_boxes bounds accumulation. Disable cleanup for manipulation trials where
this conservative corridor is insufficient. A world time reset preserves
ownership and starts a new spawn interval. A full reset may remove models;
full-reset ownership reconciliation remains unverified.

## Repeatable validation

From workspace root, after sourcing the environment:

```bash
gz sdf -k src/franka_conveyor_sim/models/conveyor/model.sdf
gz sdf -k src/franka_conveyor_sim/models/box/model.sdf
gz sdf -k src/franka_conveyor_sim/worlds/conveyor_test.sdf
python3 -m compileall -q src/franka_conveyor_sim
python3 src/franka_conveyor_sim/test/transport_smoke.py
python3 src/franka_conveyor_sim/test/spawner_smoke.py
# Expected failure until backend gains surface-motion support:
python3 src/franka_conveyor_sim/test/transport_smoke.py \
  --engine gz-physics-bullet-featherstone-plugin
```

Transport test uses installed assets and checks measured velocities and settling,
not merely topic publication. Flow test exercises the installed ROS launch and
removal through world services. Avoid setting an existing `GZ_PARTITION` for
these isolated tests. Verbose server logs are printed by the tests.

For Franka runtime checks before and after injection:

```bash
ros2 control list_controllers
ros2 topic echo /joint_states --once
ros2 action list -t
```

Expected arm trajectory interface from config:
`/fr3_arm_controller/follow_joint_trajectory`. MoveIt gripper mapping in config
is `franka_gripper/gripper_action`; availability and command execution must be
confirmed against the actual running stack. Do not start the generic
`moveit.launch.py` alongside Gazebo without review: it also starts its own
controller manager and hardware stack. The optional stationary-pickup executor
uses its own finger trajectory action instead of that hardware gripper mapping;
execution on the moving conveyor remains **UNVERIFIED**.

## Troubleshooting and next milestone

Clock stays zero / services unavailable: check matching partition and GZ_IP,
world name, server log, `/clock` bridge and `use_sim_time`. Successful server-side
creation does not prove a service response reached the client. The service worker
separation fixed the observed Python request timeout and shutdown failure in the
standalone trials.

Plugin loads but boxes stay still: verify physics backend first. Bullet
Featherstone's measured failure is a known feature gap; increasing friction did
not establish transport. Preserve the working gripper backend. Completing
physical combined Franka + conveyor requires a compatible backend implementation
or a separately validated native conveyor mechanism. The new external-force
approximation bypasses this gap without claiming contact-surface transport. No distributions were
installed/upgraded and no robot files were changed for this package.

Next: resolve that physics compatibility gap, verify gripper/controllers/MoveIt
in the combined scene, validate clearance and reach, and finish geometry/full-reset
configuration. Later milestones must synchronize static conveyor and dynamic
boxes into the MoveIt planning scene before perception, estimation or MPC.
See `RESUME.md` for the latest checkpoint and historical audit.

## OpenCV camera conveyor following with joint velocity control

For the equations mapped to functions, stability assumptions, and design tradeoffs,
see `CONTROL_THEORY_IMPLEMENTATION.md` in the workspace root (historical ground-truth controller; the camera control law below supersedes its prediction terms).

Build the two native plugins and Python package, then launch **one** complete scene:

```bash
cd ~/franka_ros2_ws
source /opt/ros/jazzy/setup.bash
colcon build --packages-select franka_conveyor_force_system franka_tracking_controller franka_conveyor_sim --symlink-install
source ./franka_sim_env.sh
ros2 launch franka_conveyor_sim conveyor_tracking.launch.py
```

This is an alternative to `pickup_planning.launch.py`, not an additional launch on
that stationary planner. It starts the existing `franka_pickup` force scene with
the belt stopped, the unchanged Franka hardware/hand configuration, one MoveIt
server, and one cube. MoveIt plans and executes from the measured starting state
to an automatically selected upstream entry pose on the conveyor centerline.
The search samples from the box toward `tracking_start_x` (now the search upper
bound, default X=0.0 m), at `workspace_step` intervals (default 2.5 cm). It uses
collision-aware MoveIt IK at the candidate, the waiting pose, and 6 cm downstream,
requiring 0.12 rad joint-limit margins and feasible nominal tracking rates. This
is an approximate usable workspace boundary for the fixed tool orientation and
belt height, rather than a full workspace map or a proof of the global optimum. The tool points down with `fr3_hand_tcp` **15 cm above the cube
top**. The 6 cm cube settles near Z=0.48 m, giving TCP Z approximately 0.66 m.
The cube starts at the upstream end: `block_x:=upstream` computes its center
from the belt endpoint, half the cube size and a 5 cm edge margin (default
X=-1.32 m). MoveIt must solve the entry pose before the belt starts at 0.10 m/s.
The position controller holds the TCP `entry_lead` (default 2 cm) downstream
of that boundary while status is `waiting_for_box`. Tracking activates when the
box crosses the selected workspace boundary, before it reaches the waiting TCP.
Status `workspace_entry_selected` reports both X positions. The initial 2 cm
horizontal offset converges during tracking; vertical clearance stays 15 cm.
When measured cube X reaches the workspace entry, a strict ros2_control switch deactivates
`fr3_arm_controller` and activates `conveyor_velocity_controller`; tracking then
publishes joint velocity commands at 100 Hz simulation time. The gripper does not close and this launch does not pick up the cube.

The primary control law, in world coordinates, is:

```text
p_cube = latest OpenCV RGB-D cube center transformed into world at image time
p_target = p_cube  # no extrapolation
p_target.z = measured_cube_top_z + clearance
v_tcp = position_gain*(p_target - p_tcp)
Jv = world-aligned translational TCP Jacobian, shape 3 x 7
qdot_primary = Jv.T * inverse(Jv*Jv.T + damping^2*I) * v_tcp
```

`position_gain=5.0 /s` and damping=0.02 are defaults. This is a reactive position
servo: no velocity/acceleration feedforward, Kalman filter, latency compensation,
prediction or MPC. At 0.10 m/s the proportional law naturally has about 20 mm
following lag, plus camera latency. It should not reproduce the old feedforward
controller's millimetre tracking results.

The existing OpenCV estimator segments the red cube, back-projects synchronized
RGB-D using CameraInfo and calibrated optical TF, and fits its top-face rectangle.
Tracking launches it with `stability_samples=1`: every valid image supplies the
current pose, with no stationary gate or temporal averaging. This assumes one
known-size upright red cube resting on the belt; yaw is ambiguous modulo 90 degrees.
Partial occlusion, other red objects, unknown sizes and arbitrary roll/pitch are
not supported. Gazebo truth and force topics are never subscribed by the tracker.

The tracking camera aims at world X=-0.55, Y=belt_y from Z=1.8 m, tilted 25 degrees
from vertical on the +Y side, with yaw=-90 degrees. The wider view covers the
upstream spawn and tracking corridor. `camera_target_x`, `camera_z`,
`camera_tilt_deg`, `camera_yaw_deg`, `camera_width`, `camera_height`, `camera_rate`
are exposed (defaults 848×480 at 30 Hz). The camera spawn and its TF use the same
computed extrinsics. The stationary pickup launch keeps its previous defaults;
only an optional camera aim argument was added to that shared launch.

Pinocchio computes the TCP position and Jacobian from `/joint_states` and the
same expanded URDF as Gazebo/MoveIt. The translational Jacobian is expressed at
the TCP in `LOCAL_WORLD_ALIGNED`; the first three rows are linear velocity.
A secondary angular correction holds the initial downward orientation in the
**null space of the translational Jacobian**. This matters physically: a first
translation-only experiment tilted a fingertip into the cube despite maintaining
the TCP point clearance. The secondary correction preserves the primary
translational task before limits are applied. Cartesian speed is capped at
0.25 m/s and joint speeds at 1.5 rad/s, below the FR3 URDF limits.

Default tracking ends when the cube reaches world X=0.24 m (workspace-search lower bound -1.4 m).
At the new 15 cm clearance, the old 0.42 m endpoint reached a joint limit
margin during testing; 0.24 m bounds the demonstration before that region.
This is a bounded demonstration; the
arm cannot follow the full 3 m belt. It stops the belt, writes zero joint rates,
and restores the original position trajectory controller holding the current
arm pose. It also stops for stale camera pose/joints, a clock reset, a 5 cm
position error, a joint limit margin of 0.08 rad, or the cube leaving the validated
belt corridor. The initial approach is collision checked by MoveIt. The live
velocity loop does **not** perform continuous collision checking; the default
scene and tracking corridor were tested, but changed geometry needs validation.
The MoveIt cube object represents its initial approach position; it is not
continuously updated during tracking.

Useful options and commands:

```bash
ros2 launch franka_conveyor_sim conveyor_tracking.launch.py \
  belt_speed:=0.1 clearance:=0.15 position_gain:=5.0 \
  maximum_measurement_age:=0.25 tracking_end_x:=0.24
# Headless, with the same control path:
ros2 launch franka_conveyor_sim conveyor_tracking.launch.py \
  rviz:=false 'gz_args:=-s -r -v 3 --headless-rendering'
# Stop during either the MoveIt approach or velocity tracking:
ros2 service call /conveyor_tracking/stop std_srvs/srv/Trigger '{}'
ros2 topic echo /conveyor_tracking/status
ros2 topic echo /pickup/box_pose
ros2 topic echo /conveyor_tracking/camera_measurement
# RViz Image topic: /pickup/detection_image
ros2 control list_controllers
```

`start_sim:=false` adds this tracker and its MoveIt server to an existing compatible
`franka_pickup` force scene with `box_pickup`; do not use it alongside another
MoveIt server or stationary pickup executor. The existing scene must initially
have the belt stopped. `block_x`, `block_y`, `box_size`, belt/table geometry,
`gz_args`, RViz and result path remain launch arguments. The initial cube must be
within 5 mm of the configured conveyor centerline. Other robot/model names and
world transforms are not generalized: this controller targets the audited FR3 at
world origin, with the single `box_pickup` cube. A completed run is not restarted
by the inherited `/pickup/plan` service; relaunch for another run.

Camera feedback interfaces:

| Interface | Meaning |
| --- | --- |
| `/camera/color/image_raw`, `/camera/depth/image_rect_raw`, `/camera/color/camera_info` | Bridged camera inputs |
| `/pickup/box_pose`, `geometry_msgs/PoseStamped` | Current world-frame cube estimate, stamped at image acquisition |
| `/pickup/detection_image` | RGB image with the selected contour overlay |
| `/conveyor_tracking/camera_measurement`, `nav_msgs/Odometry` | Pose used during tracking; twist is unused, not an estimated velocity |
| `/conveyor_velocity_controller/commands`, `std_msgs/Float64MultiArray` | Seven joint rates in `fr3_joint1` through `fr3_joint7` order |
| `/tmp/conveyor_tracking.json` | Stop reason, camera/TCP/rate trace, image timestamps/ages and feedback source |

Camera loss stops the belt, zeros velocity commands and restores the position
controller. The default simulation-time age limit is `maximum_measurement_age=0.25`
seconds; a separate 0.5 s wall-time arrival watchdog and joint-state watchdog
also apply. `start_sim:=false` needs an existing camera/bridge/TF with the full
corridor visible; it launches an estimator, so avoid a second pose publisher.

The native ros2_control plugin has a **200 ms steady-clock command watchdog**,
rejects malformed/nonfinite commands, clamps joint speeds, zeros on activation
and deactivation, and commands zero if the Python tracker disappears. Killing the
tracker leaves the velocity controller active with zero commands; it cannot
perform the normal position-controller handoff or stop the belt after its process
has died. Do not run another arm command source during tracking. The Python loop
is a simulation controller, not a hard real-time physical Franka controller.

Validation commands (run from workspace root after sourcing):

```bash
python3 -m pytest -q src/franka_conveyor_sim/test/test_tracking_kinematics.py
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py --mode stop
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py --mode camera-loss
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py --mode stop-approach
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py --mode stop-waiting
python3 src/franka_conveyor_sim/test/camera_tracking_smoke.py --mode watchdog
```

**Historical ground-truth controller results (not camera validation):**
Automatic workspace-entry validation passed in an isolated headless scene: the
search selected entry X=-0.245 m and waiting TCP X=-0.225 m at Z approximately
0.66 m. First tracked box X=-0.24486 m was still upstream of measured TCP
X=-0.22535 m. Tracking continued to the configured 0.24 m endpoint across 91
samples / 4.819 simulation seconds and restored the arm position controller.
The deliberate initial horizontal offset was 19.52 mm; after 0.8 simulation
seconds, maximum absolute errors were 2.01 mm X, 0.10 mm Y, 0.019 mm Z. Maximum
vertical error including acquisition was 0.35 mm. The selected entry can vary
with IK solutions and scene geometry. Build and all three kinematics tests passed.
The active-tracking stop regression also passed with automatic entry, restoring
the arm position controller and leaving the velocity controller inactive.
Workspace-search edits were backed up in `/tmp/conveyor_workspace_entry_backup/`.
The currently running tracker must be restarted to load these changes.

**Earlier fixed-entry validation (before automatic workspace search):** the headless smoke test passed with the cube starting
at X=-1.32 m, entering tracking at X approximately 0.0 m, and stopping at the
configured 0.24 m boundary. Across 45 samples / 2.35 simulation seconds, maximum
absolute TCP errors were 1.91 mm X, 0.15 mm Y and 0.041 mm Z relative to the cube
center plus 0.18 m (3 cm half-size plus 15 cm top clearance). The original arm
position controller was active afterward and the velocity controller inactive.
The test checks the upstream spawn, entry gate and new clearance explicitly.
The `stop-waiting` test also passed: the stop service completed before tracking
began, with no velocity-tracking samples. The active-tracking `stop` test passed
and restored the arm position controller, leaving the velocity controller inactive.
Pre-edit copies of the tracker, launch,
README and smoke test are in `/tmp/conveyor_tracking_fix_backup/`.
All tracking measurements use the existing force-driven box model, not TrackController
surface transport. Full gripper actuation was not re-tested by this tracking test.

**Historical results for the previous 15 mm clearance and reachable spawn**,
not validation of the new upstream/15 cm behavior: headless Gazebo validation tracked approximately 0.27 m over 2.73 s simulation
with maximum absolute TCP errors of **2.09 mm X, 0.27 mm Y, 0.30 mm Z** relative to
the cube center plus 45 mm. The nominal top clearance remained 15 mm within that
Z error; cube lateral motion stayed below 1 mm. Stop-service validation restored
the original arm controller. Killing the Python tracker left measured joint speeds
below 0.00011 rad/s after the watchdog interval. Numerical tests independently
check the translational Jacobian by finite differences, null-space priority, and
singularity damping. Results and traces live in `test/results/conveyor_tracking_*`.

Source pointers: `conveyor_tracker.py` (`run`, `control`, `kinematics`,
`tracking_rates`, `switch`); `launch/conveyor_tracking.launch.py` (`configure`);
`franka_tracking_controller/src/Velocity.cpp` (`update`, lifecycle callbacks);
`franka_conveyor_force_system/src/ConveyorForce.cc` (`PreUpdate`, telemetry).
The original stationary pickup launch, robot description, gripper and hardware
configuration were preserved. The force plugin was backed up to
`/tmp/tracking_backup/ConveyorForce.cc` before adding telemetry.

Camera migration changed `franka_conveyor_sim/conveyor_tracker.py`,
`franka_conveyor_sim/box_pose_estimator.py`, `launch/conveyor_tracking.launch.py`
and `launch/franka_pickup_sim.launch.py`; pre-edit copies are in
`backups/pre_camera_tracking/`. No robot description, hardware, gripper, MoveIt
parameters or native velocity controller were changed. The existing force-driven
box transport remains an external-force approximation. Camera smoke-test results
and traces use `test/results/camera_tracking_*`; truth in that test is only an
independent accuracy reference, never controller feedback.

**Camera-feedback validation:** the headless run completed 91 samples across
4.812 simulation seconds with max camera position error 3.48 mm against an
independent Gazebo reference. Maximum TCP X error against the last camera pose
was 22.61 mm; maximum measurement age was .119 s. The original arm controller was
active and the velocity controller inactive afterward. Killing the estimator
also passed the stale-camera stop and controller-restoration check. The six
vision-geometry/kinematics tests and package build passed. These results are for
the simulated ideal RGB-D camera and the configured single red cube, not a
physical camera. Latest detailed rerun metrics are in `test/results/camera_tracking_*`.

Final rerun with the installed launch settings: 90 samples / 4.77 simulation
seconds, maximum camera error 3.50 mm, maximum TCP X error relative to the
**current** independent Gazebo cube position 24.47 mm (Y=.654 mm, Z=1.069 mm),
and maximum image age .116 s. The explicit stop-service regression also passed
and restored the position controller. Camera-loss and full-travel tests passed.
