# Franka simulation session handoff — 2026-10-14

## Read this first next time

The current milestone is **camera-based stationary-cube pose estimation and MoveIt 2 trajectory generation**. It is implemented and tested headlessly. **Actual arm execution, gripper opening/closing, pickup, lift, transfer, and placement are not implemented by the planning script.**

The user approved a **6 cm pickup cube** because the existing Franka hand opens to at most 8 cm. The planner assumes the hand is open; it does not open the actual simulated hand. Do not execute saved trajectories without resolving this mismatch and checking the live scene/state.

Start the current combined planning scene, with no other simulation or MoveIt server running:

```bash
cd ~/franka_ros2_ws
source franka_sim_env.sh
ros2 launch franka_conveyor_sim pickup_planning.launch.py
```

The latest launch automatically estimates the cube pose and generates plans. It opens RViz configured for the camera, collision scene, target markers, and trajectory preview. Desktop RViz layout has not been directly visually verified by the agent; rendered camera images and numeric planning outputs were inspected/tested.

Useful references:

- [Package README: execution, configuration, tests](src/franka_conveyor_sim/README.md)
- [Detailed checkpoint and historical changes](src/franka_conveyor_sim/RESUME.md)
- [Saved successful trajectory plan](src/franka_conveyor_sim/test/results/pickup_plan.json)
- [OpenCV detection preview](src/franka_conveyor_sim/test/results/pickup_detection.png)
- [Planning validation summary](src/franka_conveyor_sim/test/results/pickup_planning_validation.json)
- [Current camera preview](src/franka_conveyor_sim/test/results/pickup_rgb.png)
- [Camera/free-body validation](src/franka_conveyor_sim/test/results/pickup_validation.json)

## Objectives and how the scope changed

1. Recover the previous resume checkpoint and run the pending conveyor trial.
2. Diagnose Gazebo discovery/service response failures and verify actual box motion.
3. Provide an alternative one-DOF moving-box approximation compatible with the working Franka physics backend.
4. Combine Franka and conveyor startup into one launch.
5. At the user's request, postpone moving-box grasp/release and build a separate stationary pickup scene with overhead RGB-D sensing.
6. Adjust the pickup geometry, block/camera location, and yellow-circle destination table interactively.
7. Implement OpenCV cube-pose estimation and MoveIt planning for home → pre-grasp → grasp.
8. Preserve a detailed handoff for the next session.

The workspace `AGENTS.md` initially limited work to environment setup. The user's later explicit request authorized the stationary perception/planning phase. That later instruction governs current scope. MPC, Kalman filtering, moving-target interception, and autonomous grasp execution were not added.

## Starting point and constraints preserved

Workspace: `/home/nick/franka_ros2_ws` on Ubuntu 24.04 / ROS 2 Jazzy / Gazebo Harmonic. Recorded installed versions: Gazebo Sim 8.15.0 and Gazebo Physics 7.8.0.

The earlier checkpoint already existed at `src/franka_conveyor_sim/RESUME.md`, although it was not visible at the workspace root. It described an incomplete environment package and a headless trial timing out on clock discovery. The package's initial models, spawner, standalone/injection launches, and smoke-test script predated this continuation.

A root `RESUME.md` was created and updated throughout this session so the current checkpoint is easy to find.

Important existing robot facts:

- The working entry point is `franka_gazebo_bringup/franka_sim.launch.py`.
- Its underlying launch is `gazebo_franka_arm_example_controller.launch.py`.
- The stack uses Bullet Featherstone because the existing hand's mimic joint is not supported by the DART setup used here.
- The simulated robot is anchored at `world → fr3_link0`, with zero base translation/rotation.
- Arm controller: `fr3_arm_controller`, trajectory action `/fr3_arm_controller/follow_joint_trajectory`.
- `joint_state_broadcaster` is active in the tested stack.
- Earlier runtime action discovery exposed the arm trajectory action but no verified gripper action.
- The MoveIt configuration's `franka_gripper/gripper_action` mapping is not proof that a compatible simulation gripper action server is running.

No existing Franka URDF/Xacro, hardware interface, gripper configuration, robot controller file, original robot launch, or original MoveIt configuration file was edited. The additions are in `franka_conveyor_sim`, plus root documentation. No ROS/Gazebo distribution installation or upgrade was performed.

The workspace root is not a Git repository. Do not treat root `git status` failures as evidence of clean/dirty source repositories.

## Work completed, in order

### 1. Resume recovery and transport debugging

Located the package resume notes and inspected the pending `test/transport_smoke.py` trial. No live Gazebo server was found at the beginning of that work.

The workspace `franka_sim_env.sh` already documented Wi-Fi multicast trouble and selected:

```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export CYCLONEDDS_URI=file://$HOME/cyclonedds.xml
export GZ_IP=127.0.0.1
```

Applying the loopback setting resolved the old clock-discovery timeout. The trial then reached model creation but reported:

```text
create: ok=False, response=, elapsed=3.001s
```

The server log nevertheless showed conveyor creation and TrackController loading. The correct interpretation was **client request/response timeout**, not established server rejection. A separate service Node in the same Python process did not fix it. One failed run also showed `terminate called without an active exception` during transport shutdown.

A service-only Python process succeeded. The retained fix was a persistent service-only worker process, implemented in `franka_conveyor_sim/transport_service.py`, used by the spawner and transport test. Requests are serialized protobuf messages sent through one process-pool worker, avoiding the observed failures when blocking requests and Python subscriptions share a process. Subscription callbacks are explicitly unsubscribed during shutdown.

The exact lower-level binding/GIL cause was not proven; the process separation was verified operationally. It does not launch a new CLI subprocess for every box.

### 2. Physical conveyor validation and backend limitation

Measured real box motion rather than treating topic publication as success.

| Command (m/s) | DART box vx (m/s) | Bullet Featherstone box vx (m/s) |
| --- | ---: | ---: |
| 0.10 | 0.100066 | 0 |
| 0.20 | 0.200397 | 0 |
| 0.00 | 0 | 0 |
| -0.10 | -0.099271 | 0 |

The cube settled at approximately z=0.550 m on the original 0.50 m conveyor top. TrackController loaded under both backends, but only DART produced contact-surface transport.

The measured Bullet limitation agrees with [Gazebo Physics issue 569: contactSurfaceMotionVelocity support](https://github.com/gazebosim/gz-physics/issues/569). The working robot backend was preserved rather than switching it to DART and breaking the hand setup.

Other runtime fixes found in the original environment package:

- Replaced an unavailable Jazzy `launch.actions.LogError` import with `LogInfo`.
- Converted resolved numeric launch strings using `float(...)`; `ParameterValue` on the raw strings failed at runtime.
- Installed resume notes and excluded bytecode assets from package data.

Standalone installed-launch/spawner tests passed for simulation-time intervals, paused spawning, stopped-belt spacing, time-only reset without a burst, and confirmed downstream removal.

### 3. One-DOF visual conveyor approximation

The user proposed a stationary conveyor with boxes moving slightly above it along one axis. Implemented this as opt-in `motion_mode:=slider`:

- `models/conveyor_stationary`: static surface, no TrackController.
- `models/box_slider`: a hidden world-fixed anchor and a prismatic joint to the visible cube.
- Native Harmonic JointController listens to `/conveyor/cmd_vel` using `gz.msgs.Double`.
- Default hover gap: 2 mm; cube center z=0.552 m over the original belt.
- The visible box is the canonical link, so pose tracking/cleanup follow the moving cube.
- New boxes inherit the last speed received by the spawner.

A direct world-to-prismatic joint failed: this Bullet implementation only accepted a fixed joint to the world. Adding a fixed anchor link followed by the prismatic joint solved it.

Measured Bullet slider velocities were approximately 0.10027, 0.19840, 0, and -0.10026 m/s for the corresponding speed commands. A 90° yaw test verified that the motion axis rotates with the conveyor. Spawning, inherited speed, hover, pause/reset, spacing, and +X cleanup passed.

Combined unchanged Franka + slider integration passed in the discovered world `empty`, with approximately 0.09969 m/s box motion and active arm controllers/joint states.

Limitation explained to the user: these boxes are attached to world-fixed rails and **cannot be freely lifted, rotated, or grasped**. Stopping their speed does not release the joint. The user explicitly deferred release-on-grasp/physical moving-belt work.

### 4. Discovery/startup clarification and combined conveyor launch

The user encountered `Waiting for service [/world/empty/create]` despite sourcing the environment script. Inspection found no running Gazebo server/world services, and the latest launch log contained only conveyor injection. Sourcing the environment script configures discovery; it does not start Gazebo.

Added `launch/franka_conveyor_sim.launch.py` to start the existing underlying Franka bringup and inject the conveyor into the same world. It defaults to slider mode, preserves the original robot settings, uses the existing clock bridge, and starts one Gazebo server. Model creation waits for the world service; the spawner starts after belt creation.

The user subsequently confirmed that this setup worked as expected. The combined wrapper also passed headless motion/controller checks.

### 5. Separate stationary pickup scene and overhead D435-style camera

Added `launch/franka_pickup_sim.launch.py`, leaving the moving-conveyor launch available.

Scene changes requested by the user:

- Stationary, collidable conveyor top lowered from 0.50 to **0.45 m**.
- Length increased from 2 to **3 m**, extending the upstream (-X) end by 1 m while holding the downstream end fixed.
- Conveyor X range: **[-1.4, 1.6] m**; center `(0.10, 0.50, 0.40)` m.
- One free dynamic pickup cube, with no slider/world attachment and no repeating box spawner.
- Overhead D435-sized visual housing with native Gazebo `rgbd_camera`.
- Camera tilted **12.5° from vertical toward +Y**, away from the robot side, and translated automatically to aim at the cube top.

The camera is an **idealized simulation**, not a full RealSense device emulator: approximately 87° horizontal depth-like FOV, aligned RGB/depth, default 848×480, configured 15 simulation Hz, clipping .1–5 m. No stereo/projector model, separate RGB calibration, firmware/SDK behavior, distortion or realistic depth noise is implemented.

The new `franka_pickup` world keeps Physics, UserCommands, SceneBroadcaster, and Contact systems and adds Ogre2 Sensors plus Imu for the camera/robot IMUs. It uses installed local assets, not Fuel downloads.

Camera bridge topics:

| Topic | Type / frame |
| --- | --- |
| `/camera/color/image_raw` | RGB Image / `camera_optical_frame` |
| `/camera/depth/image_rect_raw` | 32FC1 depth in metres / optical frame |
| `/camera/color/camera_info` | CameraInfo / optical frame |
| `/camera/depth/camera_info` | CameraInfo / same ideal intrinsics |
| `/camera/depth/points` | Colored PointCloud2 / `camera_link` |

TF is `world → camera_link → camera_optical_frame`.

A significant tested frame issue: the installed Harmonic RGB-D cloud contained **+X-forward camera-link coordinates** while its metadata named the optical frame. Merely labeling it optical was incorrect. A per-topic `frame_id: camera_link` bridge override fixes the label; the numeric points are not rotated. Images and intrinsics keep the optical frame. Tests verify the center cloud sample transformed into world lands on the cube top.

An unnecessary nonstandard `gz_frame_id` SDF tag was removed; the standard optical-frame field plus the cloud bridge override is retained.

Rendered RGB previews were inspected and show the cube top and an edge. A free-body test raises the cube through Gazebo's pose service and verifies it falls back onto the conveyor. This establishes freedom from a rail; it is **not** a gripper pickup test.

### 6. Interactive position and goal-table refinements

The user requested several placement adjustments. These are historical; use the final values below:

1. Initial pickup block XY was `(0.55, 0.50)`.
2. Moved it toward the robot-side belt edge at `(0.35, 0.38)`; camera followed.
3. User clarified that it should remain on the conveyor centerline. Changed to `(0.25, 0.50)`.
4. Shifted another 10 cm along -X to the current **`(0.15, 0.50)`**.
5. Added a collidable destination table slightly rear-left of the robot, initially `(-0.45, +0.15)`, with a yellow circle.
6. Lowered its top from 0.45 to **0.35 m**.
7. Moved it 10 cm left as seen by the overhead camera: for the current camera yaw, image-left is world -X. Final table center is **`(-0.55, +0.15)`**.

The table is 0.50×0.24 m with a 5 cm thick top and four floor-reaching legs. It leaves a 3 cm lateral gap to the conveyor. The yellow disk has radius 0.08 m and is visual-only, avoiding a collision bump. `goal_destination` TF marks its center at the tabletop surface.

Configurable table height adjusts tabletop, legs, marker, and goal TF together. Table/conveyor footprint overlap is rejected. Static SDF validation caught duplicate collision/visual names in the first table version; collision names were made unique and revalidated.

Most intermediate placement tweaks were built/static-checked while the user's scene was left running. They applied on restart. Later camera/planning integration tests used the final positions and table geometry, but actual robot motion/grasp clearance remains unexecuted.

### 7. OpenCV pose estimation and MoveIt trajectory generation

The user then requested desired end-effector poses, MoveIt trajectories, and OpenCV camera-based box pose estimation.

The existing hand's two finger joints each have an upper limit of 0.04 m, giving at most 0.08 m aperture. The old 0.10 m cube cannot fit. After an explicit question, the user chose a **6 cm pickup cube**. Added a separate `models/box_pickup` with mass 0.20 kg and uniform-cube inertia 0.00012 kg m² per diagonal. The original 10 cm model remains available for conveyor experiments.

Implemented files:

- `pickup_geometry.py`: red HSV segmentation, depth back-projection, quaternion transforms, world-XY rectangle fit, and grasp-target geometry.
- `box_pose_estimator.py`: synchronized RGB/depth, CameraInfo and timestamped optical TF, five-frame stability checks, pose/metrics/debug-image publishers.
- `pickup_planner.py`: asynchronous MoveIt service clients, collision-scene insertion, staged trajectory generation, pose/marker/trajectory/status publishers, Trigger replan service, atomic JSON output.
- `pickup_planning.launch.py`: optional pickup simulation plus one planning-only MoveIt server, estimator, planner, and planning RViz configuration.

The estimator detects a **known-size upright red cube**. It does not estimate arbitrary-object pose: roll/pitch are assumed upright, and square yaw is ambiguous modulo 90°. Invalid/stale depth, mismatched frames/resolution, wrong size/height, unstable detections, and missing detections are rejected. It does not read Gazebo entity truth or the configured block XY as a detection. Gazebo truth is used only in validation code.

MoveIt Python bindings were not installed. Instead of adding an unnecessary dependency, the implementation uses the installed ROS services: planning, IK, Cartesian paths, planning-scene apply/query, and state validity.

The new MoveIt server uses the **exact simulation robot xacro**, avoiding differences between a generic hardware description and the working Gazebo robot. It creates no new hardware node, controller manager, or robot-state publisher. Two mismatches are repaired in runtime copies only:

- Existing SRDF virtual joint refers to nonexistent link `base`; the simulation already has a fixed world root, so the invalid runtime semantic element is removed.
- Existing OMPL settings use `panda_arm`; they are mapped to the actual `fr3_arm` group.

The original files are unchanged. A reserved rclpy `Node.clients` property caused an initial planner startup error; the custom field was renamed `service_clients`.

Collision scene contains the conveyor, table top/legs, floor, and camera-estimated cube. Existing semantic collision allowances are preserved; only base/floor mounting contact is additionally allowed. Cube, hand, conveyor, and table collisions remain enabled.

Tool link: **`fr3_hand_tcp`**, not the flange. Tool +Z points down. Four equivalent cube yaw orientations can be tried. Default grasp TCP is 2 cm below the detected cube top; pre-grasp is another 12 cm above it.

Stages:

1. Current arm configuration → inspected SRDF `ready` home joints using OMPL.
2. Home → collision-free pre-grasp IK solution using RRTConnect.
3. Pre-grasp → grasp using a vertical Cartesian path, 5 mm sampling, collision checks, and joint-jump rejection.

Each stage starts at the previous endpoint. Partial final approaches are rejected. At ordinary startup the robot is already home; that stage is a one-point, zero-motion plan and is labeled `home_already_reached`.

**The virtual planning state opens both fingers to .04 m. The actual hand remains unchanged.** This is an explicit planning assumption and the principal issue to resolve before execution.

### 8. Test isolation, cleanup, and visualization explanation

An interrupted early planning test called `rclpy.shutdown()` after shutdown had already occurred. Cleanup stopped before killing its launch group. A subsequent trial briefly received old test ROS data because both used the same ROS domain. That contaminated run was not accepted as end-to-end verification.

Fixes:

- `rclpy.try_shutdown()` in the planning test.
- Unique ROS domain per test plus unique Gazebo partition.
- Bounded subscriber buffers for large camera messages.
- Cleanup of the isolated launch process group even if Gazebo's Ruby launcher exits before its rendering-server child.
- Prior test leftovers identified by their test partition and terminated.

Clean isolated reruns passed. The final test cleanup left no live test simulation/planning processes at the recorded checks. Do not infer the user's later live process state from this handoff; inspect it next time.

The user asked why the environment looked green. The explanation given was conditional: in **RViz**, MoveIt's collision-scene overlay can appear green; the ghost robot is the trajectory preview. MoveIt should not recolor actual Gazebo models. If it is genuinely Gazebo, inspect collision visualization. No direct observation established which window the user meant. In RViz, disable `Pickup collision scene` or its scene geometry display to hide the overlay.

## Current scene and planning defaults

| Item | Current value |
| --- | --- |
| Robot base | `world → fr3_link0`, unchanged at origin |
| Gazebo world | `franka_pickup` |
| Conveyor | 3.0×0.4×0.1 m, center `(0.10,0.50,0.40)`, top .45 |
| Conveyor X limits | -1.4 to +1.6 |
| Pickup cube | .06 m, .20 kg, XY `(.15,.50)`, settled center z≈.48 |
| Cube initial spawn z | .50, allowing settling |
| Camera origin | approximately `(.15,.25835,1.60)` for 6 cm cube |
| Camera tilt/yaw | 12.5° from vertical / 90° toward world +Y |
| Camera streams | 848×480, configured 15 sim Hz, ideal aligned RGB-D |
| Destination table | center `(-.55,+.15)`, top .35 |
| Yellow goal | radius .08, surface frame `goal_destination` |
| Tool | `fr3_hand_tcp` |
| Pre-grasp offset | .12 m above grasp TCP |
| Grasp insertion | .02 m below detected top |
| Planning scale | .10 velocity and acceleration |
| Default output | `/tmp/franka_pickup_plan.json` |
| Execution | Disabled; no arm/gripper commands |

One observed estimate: cube center `(0.14874,0.50139,0.48027)`; pre-grasp TCP z≈0.61027; grasp TCP z≈0.49027, with tool +Z downward.

## Validation evidence

### Current milestone

- `colcon build --packages-select franka_conveyor_sim`: passed.
- Python compile checks: passed.
- New SDF validation, including the pickup cube: passed.
- Three geometry unit tests: passed (center/tool transform, invalid depth/oversized cube refusal, rotated square yaw).
- Clean end-to-end RGB-D → MoveIt test: passed.
- Cube center error versus test-only Gazebo truth: **0.001892 m**.
- Actual pre-grasp TCP FK error: **0.000408 m**.
- Actual final grasp TCP FK error: approximately **6.75e-9 m**.
- Final Cartesian completion fraction: **1.0**.
- Stage endpoints chained successfully; time ordering/joint data checked.
- Trigger-service replan from a newer image estimate: passed.
- Joint-state check confirmed no arm execution.
- Current 6 cm camera/free-fall regression: passed; 672 red pixels, median depth 1.11758 m, box settles at z≈.48000.

Saved example: home already reached (1 point, 0 s); home→pre-grasp 64 points / 6.2635 s; Cartesian approach 27 points / 2.5426 s. OMPL solutions and durations can vary.

### Important log paths

These are temporary local files and may not survive cleanup/reboot. Persistent results are in the package's `test/results` directory.

| Trial | Log |
| --- | --- |
| Original DART physical transport success | `/tmp/conveyor_smoke_16750.log` |
| Bullet physical-transport failure | `/tmp/conveyor_smoke_16835.log` |
| Bullet slider speed test | `/tmp/conveyor_smoke_18560.log` |
| Slider 90° yaw test | `/tmp/conveyor_smoke_18855.log` |
| Bullet slider flow test | `/tmp/conveyor_flow_18682.log` |
| Earlier Franka slider integration | `/tmp/franka_slider_trial.log` |
| Combined conveyor wrapper | `/tmp/franka_conveyor_wrapper_trial.log` |
| Current 6 cm camera/free-body regression | `/tmp/pickup_smoke_49772.log` |
| Final planning + FK + replan trial | `/tmp/pickup_planning_50613.log` |

## Files and entry points

All package paths below are relative to `src/franka_conveyor_sim/`.

| Area | Files |
| --- | --- |
| Combined launches | `launch/franka_conveyor_sim.launch.py`, `launch/franka_pickup_sim.launch.py`, `launch/pickup_planning.launch.py` |
| Existing-world/standalone launches | `launch/add_conveyor.launch.py`, `launch/conveyor_test.launch.py` |
| Transport and flow | `franka_conveyor_sim/transport_service.py`, `franka_conveyor_sim/box_spawner.py` |
| Vision and planning | `franka_conveyor_sim/pickup_geometry.py`, `box_pose_estimator.py`, `pickup_planner.py` in the same module directory |
| Added model variants | `models/conveyor_stationary`, `box_slider`, `conveyor_pickup`, `d435`, `goal_table`, `box_pickup` |
| World | `worlds/franka_pickup.sdf`; original standalone world retained |
| Camera/planning display | `config/pickup_camera_bridge.yaml`, `pickup.rviz`, `pickup_planning.rviz` |
| Tests | `test/transport_smoke.py`, `spawner_smoke.py`, `franka_slider_smoke.py`, `pickup_smoke.py`, `test_pickup_geometry.py`, `pickup_planning_smoke.py` |
| Packaging | `package.xml`, `setup.py`; assets, configurations, resume notes and saved validation artifacts installed |
| Documentation | `README.md`, package `RESUME.md`, root `RESUME.md`, this handoff |

Installed Python executables: `box_spawner`, `box_pose_estimator`, `pickup_planner`.

## Commands for next time

### Build and launch the current planning milestone

```bash
cd ~/franka_ros2_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
colcon build --packages-select franka_conveyor_sim
source franka_sim_env.sh
ros2 launch franka_conveyor_sim pickup_planning.launch.py
```

Do not launch this alongside another independent robot simulation. If attaching to an already running matching 6 cm pickup scene, use `start_sim:=false`, and confirm no other `move_group` exists.

For manual planning instead of automatic planning:

```bash
ros2 launch franka_conveyor_sim pickup_planning.launch.py auto_plan:=false
# In another configured terminal:
ros2 service call /pickup/plan std_srvs/srv/Trigger '{}'
ros2 topic echo /pickup/planning_status --once --qos-durability transient_local
```

The Trigger response means queued, not completed. Inspect status/JSON for success or failure.

### Camera/environment only

```bash
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py
```

### Older moving-box approximation

```bash
ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py
# Publish after the spawner starts:
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
```

This is the constrained slider experiment, not a freely graspable moving-box solution.

### Core checks

```bash
gz service -l
ros2 node list
ros2 control list_controllers
ros2 action list -t
ros2 topic echo /joint_states --once
ros2 run tf2_ros tf2_echo world camera_optical_frame
```

All participating terminals need consistent Gazebo partition/IP and ROS domain/DDS settings. Source `franka_sim_env.sh`; it does not start the simulator.

### Automated tests

Run with the user's simulation stopped. Tests use isolated discovery settings and start/stop their own scene.

```bash
python3 -m pytest -q src/franka_conveyor_sim/test/test_pickup_geometry.py
python3 src/franka_conveyor_sim/test/pickup_planning_smoke.py
python3 src/franka_conveyor_sim/test/pickup_smoke.py
```

Additional conveyor-only tests and their expected Bullet physical-mode failure are documented in the package README.

## Next steps, in recommended order

1. **Inspect the current live environment before changing anything.** Read this file and the current checkpoint; verify process/world names, controller actions, installed package and scene geometry. Do not assume the last test's processes or temporary logs still exist.
2. **Review the generated plans in desktop RViz.** Confirm the tool frame, downward orientation, collision geometry, camera overlay and actual hand aperture. The numerical plans passed; the specific desktop layout was not directly tested.
3. **Implement or expose a simulation gripper command interface without replacing working robot interfaces.** The arm trajectory controller exists; gripper action execution remains unverified. Determine available finger command interfaces/controllers and preserve mimic behavior. Open the real simulated hand before using an open-hand planned state.
4. **Add deliberate staged arm execution.** Revalidate fresh vision, actual current joint/finger state, collision scene and trajectory continuity. Execute home/pre-grasp first and verify controller results and final pose. Do not blindly replay a stale saved JSON plan.
5. **Execute the final approach and close on the cube.** Validate contact, finger aperture, grasp retention and collision clearances. Passing a planning test is not evidence of a successful physical grasp.
6. **Add lift and destination placement.** Only after a retained grasp, add appropriate MoveIt attached-object handling, lift/transfer/placement trajectories using `goal_destination`, and release. The goal frame is a surface point; resting 6 cm cube center is 3 cm above it.
7. **Improve perception as needed.** Test occlusion by the hand, camera coverage of both pickup/goal regions, size/color variation, ambiguity and real-camera calibration/noise. Current estimator assumes a stationary upright red cube.
8. **Return to moving-target work only when requested.** The user deferred slider release and physical Bullet conveyor compatibility. Do not silently make this the next task. MPC/Kalman filtering/interception remain future phases.

## Known limits and things not to claim

- Slider boxes are not freely graspable. Physical TrackController transport remains unsupported in the tested Bullet setup.
- The current cube is free and collidable, but no actual gripper pickup or placement has been demonstrated.
- The planner assumes an open hand; the actual simulated hand is not commanded by it.
- General 6-DOF object perception, arbitrary objects, realistic D435 behavior and real hardware execution are not implemented.
- Basic environment-only launches do not synchronize their objects into MoveIt; the planning launch explicitly inserts its own matching static/detected objects.
- Negative-flow spawner cleanup and full-world-reset ownership reconciliation remain pending for the older conveyor-flow setup.
- Green MoveIt collision geometry is a visualization overlay in RViz, not evidence that Gazebo's materials changed.
- No performance or physical-grasp claim should be inferred from successful pose/trajectory generation alone.

## Execution-environment notes

Sandboxed shell commands repeatedly failed before execution with `bwrap: loopback: Failed RTM_NEWADDR: Operation not permitted`. Shell work used the tool's approved `require_escalated` mechanism. Continue using the appropriate mechanism rather than bypassing it.

This handoff records the full continuation session, including inherited starting-state findings and later user-authorized scope changes. When historical checkpoint values disagree with the current-default table above, prefer the current code and latest checkpoint.
