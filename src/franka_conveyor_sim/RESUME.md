# Current checkpoint: reactive OpenCV camera tracking

The current tracking launch uses `/pickup/box_pose` from the existing OpenCV RGB-D
red-cube estimator. It runs with one sample per measurement, no stationary gate.
Gazebo pose/velocity and force subscriptions have been removed from the tracker.
The law is `v_tcp = position_gain * (measured_target - tcp)`, followed by the
existing DLS and orientation null-space correction. No prediction, feedforward,
filter or MPC. Gain 5/s yields about 2 cm following lag at 0.1 m/s, plus latency.
Clearance is 15 cm above the cube, tracking ends at X=.24 m, automatic entry is
near X=-.243 m. Camera aim X=-.55, Z=1.8, tilt 25 degrees, yaw -90, 848x480/30Hz.
Camera pose and optical TF are computed together by the shared scene launch;
stationary pickup camera defaults are preserved with an optional aim argument.

Build passed; six vision geometry / DLS tests passed. Full headless camera run
passed (91 samples over 4.812 simulation seconds): max camera error vs independent
Gazebo reference 3.48 mm, max TCP X error vs measured camera pose 22.61 mm, max
measurement age .119 s. Camera estimator process death stopped the belt and
restored the arm controller, with no ground-truth fallback. See
`test/results/camera_tracking_*` for the latest rerun results and README for usage.
`test/camera_tracking_smoke.py` is the current integration test;
`test/tracking_smoke.py` forwards to it. Truth is used only by the test reference.
Backups of the four implementation/launch edits: `backups/pre_camera_tracking/`.
The force-driven transport approximation is unchanged. Full gripper actuation
was not retested. Existing continuous collision-checking limitations remain.

Final rerun: 90 samples / 4.77 sim seconds; max camera error 3.50 mm; max TCP
X error vs current truth 24.47 mm; max image age .116 s. Explicit stop-service
regression passed and restored the position controller.

The following checkpoints are historical and include superseded control laws:

# Historical checkpoint: ground-truth moving-cube velocity tracking

Implemented `conveyor_tracking.launch.py`: starts one force-driven `franka_pickup`
scene with belt stopped, uses MoveIt for a collision-checked approach to the belt
centerline, then strictly switches from the existing arm position JTC to the new
`franka_tracking_controller/Velocity` plugin and starts the belt at 0.1 m/s.
`ConveyorTracker` consumes simulation-stamped Gazebo world pose/velocity and actual
force/mass telemetry from `ConveyorForce`. Pinocchio uses the matching sim URDF;
3x7 world-aligned translational Jacobian, damped inverse, velocity feedforward +
K position feedback, and a projected null-space downward-orientation correction.
The correction was necessary: translation alone tilted fingers into the cube.
Target TCP clearance is 15 mm above the cube top. Default tracking ends at cube
world X=0.42 m, before the downward-tool workspace limit, and restores the original
arm controller. New native velocity plugin zeros after 200 ms without commands.
Original robot URDF/hardware/gripper, stationary planner, and launches preserved.
Force plugin backup: `/tmp/tracking_backup/ConveyorForce.cc`.

Tested headless complete run: 49 trace samples over 2.73 s, cube travel about
0.27 m; maximum absolute TCP errors X=2.085 mm, Y=0.263 mm, Z=0.295 mm. Original
arm controller and joint-state broadcaster active afterward, velocity controller
inactive. Explicit stop, cancellation during approach, and killing the Python
tracker passed; watchdog left joint speeds below 0.00011 rad/s. 13 kinematics /
existing pickup unit tests passed. Force-conveyor regression passed 0.1, 0.2,
zero, reverse, pause, free-fall and off-belt force cutoff. All test processes exited.

Build: `colcon build --packages-select franka_conveyor_force_system franka_tracking_controller franka_conveyor_sim --symlink-install`.
Launch after sourcing env: `ros2 launch franka_conveyor_sim conveyor_tracking.launch.py`.
Tests: `test/tracking_smoke.py [--mode stop|stop-approach|watchdog]` and
`test/test_tracking_kinematics.py`; durable results/traces in `test/results/`.
README and root `PIPELINE_EXPLAINED.md` section 18 explain equations, function
pointers, commands, frame conventions, and limitations. Runtime loop does not
continuously collision-check, estimate camera states, perform MPC, or grasp.
Default instance targets FR3 at world origin and `box_pickup`; changed geometry
needs validation. Live ROS ground-truth topics publish while tracking. A process
kill relies on zero-velocity watchdog; it cannot restore the JTC or stop the belt.

---

# Current checkpoint — force-driven conveyor, 2026-10-19

User returned from the completed stationary pick/place task to conveyor motion,
explicitly requesting force acceleration toward a belt-speed target.

- Added `franka_conveyor_force_system` (ament_cmake): model-scoped Harmonic
  Configure/PreUpdate system using actual velocity/mass and AddWorldForce at COM.
  Kp=10, Ki=2, acceleration contribution capped at 1 m/s² (0.2 N for 0.2 kg).
- New `conveyor_force` belt with ODE and Bullet friction 0.01. Bullet ignored ODE
  tags in the first trial; adding Bullet friction fields resolved stationary boxes.
  `box_force` keeps original body/gripper friction and is fully dynamic, no rail.
- Force gates on footprint, bottom height within 3 mm, vertical speed <0.03 m/s;
  this is a geometric proxy, not a true contact/grasp sensor. No vertical/lateral
  control, pose teleportation or direct velocity commands.
- Existing pickup/camera/table scene now accepts motion_mode:=force belt_speed:=0.1
  for its 6 cm box. Default and planning wrapper remain explicitly stationary.
- Existing combined conveyor wrapper now defaults to force at 0.1 m/s, with
  automatic 10 cm boxes. Injection/standalone also accept force mode; old defaults
  and slider/TrackController variants remain available.
- Shared force_model.configure_force_plugin validates/writes actual geometry and
  an absolute plugin path, permitting injection into already-running worlds.
- Spawner remembers force speed commands, retains sim-time spacing/reset logic,
  and cleans up downstream fallen boxes as well as the original corridor limit.

Build BOTH packages:
`colcon build --packages-select franka_conveyor_force_system franka_conveyor_sim --symlink-install`

Run (no other simulation running):
`ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py motion_mode:=force belt_speed:=0.1`
For auto flow instead: `ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py`.
Use native gz.msgs.Double `/conveyor/cmd_vel` for 0.1, 0.2, zero or negative speed.

Tests passed: force step response, bounded force/gradual acceleration, pause,
rotated belt, free fall and airborne/off-belt cutoff; same checks with Franka and
camera; original controllers active; flow intervals, speed inheritance, spacing,
reset and cleanup; combined wrapper; stationary preview regression; ten unit tests.
See test/results/conveyor_force_validation.json and README for exact measurements.
Moving pickup/MPC is not implemented. Force mode is a low-friction external-force
approximation, not native moving-surface traction. Backups: /tmp/conveyor_force_backups.
PIPELINE_EXPLAINED.md at workspace root now includes section 17 and refreshed links.

---

# Current phase — OpenCV + MoveIt pickup planning, 2026-10-14

User explicitly requested perception and home/pre-grasp/grasp trajectory
planning, superseding the original environment-only scope. User approved changing
the pickup cube from 10 cm to 6 cm to fit the existing 8 cm Franka hand. The
original box model/conveyor spawner remain unchanged. Robot files unchanged.

## Implemented
- models/box_pickup: 6 cm free .2 kg cube, correct inertia .00012 kg m².
  Pickup launch now exposes block_size, default .06; camera automatically aims
  at its new top. Default center (.15,.5,.48), camera (.15,.25835,1.6).
- pickup_geometry.py: OpenCV red mask, finite aligned depth back-projection,
  optical TF transform, world top-face minAreaRect, known-size upright center/yaw.
  Square yaw modulo90 degrees, roll/pitch assumed upright. No Gazebo truth input.
- box_pose_estimator.py: synchronized images/info/TF, stale/size/height/depth
  rejection, five-frame stationary validation; publishes pose/metrics/debug image.
- pickup_planner.py: persistent ROS clients to installed MoveIt2 services,
  scene objects (belt, goal tabletop+legs, floor, detected cube), home joints from
  inspected SRDF, collision-free pre-grasp IK + RRTConnect, full Cartesian descent.
  Tool fr3_hand_tcp points down. Pre-grasp clearance .12, insertion below top .02.
  Pose/marker/DisplayTrajectory/status topics; atomic JSON; Trigger-service replan.
- pickup_planning.launch.py: optionally starts one pickup sim, one move_group,
  estimator/planner, planning RViz. Uses EXACT simulation xacro. New runtime
  semantic copy removes invalid virtual joint to missing base; new runtime OMPL
  copy maps old panda_arm config to fr3_arm. No original URDF/config edits.
  No second controller manager/hardware node/RSP. MoveIt execution disabled.
- config/pickup_planning.rviz; tests/test_pickup_geometry.py and
  pickup_planning_smoke.py. Relevant dependencies/entry points documented.

## Important behavior
PLANNING ONLY. Arm and gripper are not commanded. Planned state assumes finger
joints .04 each (8 cm open); actual sim hand stays in its existing state. Before
execution, add/verify gripper interface, open it, replan/revalidate against actual
state. No close/lift/attachment/goal transfer/release implemented. Home normally
already reached: one-point zero-motion home stage, explicit metadata.

## Tests PASS
- 3 geometry tests: transform/tool pose; invalid depth + oversized hand refusal;
  rotated cube yaw modulo90.
- Clean isolated headless camera->MoveIt trial and Trigger replan PASS:
  center error .001892 m vs test-only Gazebo truth, full Cartesian fraction1.0,
  continuous stages, no arm execution. Actual TCP FK pre-grasp error .000408 m,
  final grasp error6.75e-9 m, tool Z down.
  Log `/tmp/pickup_planning_50613.log`.
- Camera/free-body regression for approved 6 cm cube PASS: allRGB/depth/info/cloud
  and TF correct, 672 red pixels, center cloud world(.15125,.49872,.51), cube settles
  z=.48 and falls back after elevation; controllers active.
  Log `/tmp/pickup_smoke_49772.log`.
- Saved artifacts test/results/{pickup_plan.json,pickup_detection.png,
  pickup_planning_validation.json,pickup_rgb.png,pickup_validation.json}; installed.
- Builds/Python checks pass. Final SDF/dependency/launch checks in session output.
- An interrupted early test exposed cleanup issues; fixed test try_shutdown,
  unique ROS domains, bounded subscriber buffers and isolated process-group cleanup.
  Current tests left no live simulation/planning processes.

## Run
```
source franka_sim_env.sh
ros2 launch franka_conveyor_sim pickup_planning.launch.py
```
No other sim/MoveIt running. Attach to existing matching6cm scene with
start_sim:=false. auto_plan:=false waits for
`ros2 service call /pickup/plan std_srvs/srv/Trigger '{}'`.
Default output /tmp/franka_pickup_plan.json. See README for topics/configuration.

## Remaining / next
Review RViz desktop configuration (not visually tested) and saved trajectories.
Implement/verify simulation gripper command interface before arm execution.
Then validate actual open-hand approach/closure/contact, lift and goal placement.
General objects/occlusion/real-camera calibration/noise, arbitrary6DOF estimation,
MPC and moving-box release remain outside this completed planning stage.
Historical checkpoints follow and may contain superseded geometry/scope.

---

# Latest adjustment — goal table left in camera view

Moved goal table 10 cm toward image-left for current camera yaw=90 degrees:
world X -.45 -> -.55. Default center now (-.55,+.15), top .35 m.
Yellow marker and goal_destination TF follow table. Camera, robot, belt and block
unchanged. Build/Python checks only; restart pickup launch to apply.

---

# Latest adjustment — lower goal table

Destination tabletop default lowered from .45 to .35 m. Launch-generated legs,
yellow marker and goal_destination TF follow the configured height. Conveyor,
block and camera unchanged. Build/Python/configuration checks; restart pickup
launch to apply. No live scene or grasp test performed for this height.

---

# Latest change — goal destination table

Added separate static/collidable models/goal_table and spawn in pickup launch.
Default center (-.45,+.15), tabletop .50x.24 with top z=.45, four floor-reaching
legs, visual-only yellow disk radius .08. Rear-left placement leaves .03 m gap
to conveyor and avoids base footprint. New launch args goal_table_x/y/top, with
finite/height and conveyor-overlap validation. Static TF goal_destination marks
circle center on tabletop (resting cube center is +.05 m). No placement logic.
Robot configuration and block/camera defaults untouched. SDF/Python/build and
geometry checks; live scene/gripper reach verification pending. User simulation
was already running and left unchanged; restart pickup launch to apply.

---

# Latest adjustment — 10 cm closer along conveyor

Pickup block defaults XY=(.15,.50), camera=(.15,.26722,1.6). Centerline,
robot and conveyor unchanged. Build/Python checks; restart launch to apply.
Latest placement runtime verification remains pending.

---

# Latest placement correction — conveyor centerline

User requested block on centerline, shifted horizontally back toward robot.
Pickup defaults now block XY=(.25,.50), replacing the lateral-edge (.35,.38)
placement. Camera automatically becomes (.25,.26722,1.6), same tilt/height.
Robot and conveyor unchanged. Updated README and smoke-test expectations.
Static geometry/build/Python checks only; restart current launch to apply.
Runtime visibility/reach/grasp at this placement remains pending.

---

# Latest change — closer pickup placement, 2026-10-14

User requested moving box/camera closer to arm. Changed pickup launch defaults
from block (.55,.5) to (.35,.38) in world XY. The unchanged arm base is at origin.
Horizontal distance decreases .743 -> .517 m (~30%). Cube footprint remains
3 cm inside conveyor's robot-side edge. Belt and arm stay in their existing poses.
Camera tracks block automatically: new optical origin (.35,.14722,1.6), same
12.5-degree tilt and same target at cube top. Updated smoke-test expected world
coordinates and lift/reset position, plus README defaults.

An existing user GUI simulation was running, so it was left untouched and no
second Gazebo was started. New defaults apply after restarting the launch.
Build/Python/placement geometry checks performed; live camera/clearance/grasp
behavior at the closer placement is NOT yet verified. Persistent preview/result
assets describe the earlier placement. Next runtime check:
`python3 src/franka_conveyor_sim/test/pickup_smoke.py`
(after stopping the user simulation). Historical camera setup follows.

---

# Current focus — stationary pickup + overhead RGB-D, 2026-10-14

User deferred moving-box grasp/release work. New requested launch implemented:
`franka_pickup_sim.launch.py` in package franka_conveyor_sim. Old moving-conveyor
launch remains unchanged and available. No existing Franka robot files edited.

## New scene
- One Bullet Featherstone Gazebo world named `franka_pickup`; same underlying
  Franka launch, hand and fr3_arm_controller. Custom world preserves Physics,
  UserCommands, SceneBroadcaster and Contact; adds Ogre2 Sensors and robot Imu.
- New stationary conveyor_pickup model: length 3 m, width .4, thickness .1;
  center (.1,.5,.4), top .45 (lowered 5 cm). Upstream X now -1.4, downstream
  remains 1.6. Configurable extension/top/lateral placement via launch.
- One original free dynamic cube `box_pickup`: .1 m, .2 kg, no slider/world joint.
  Spawn (.55,.5,.52), settles at center z=.5. No automatic box spawner.
- D435-sized 90 mm visual housing with native idealized RGB-D sensor: 87-degree
  HFOV, 848x480, configured 15 sim Hz, clips .1–5 m. Not stereo/firmware/noise or
  separate calibrated RGB optics simulation; one ideal aligned sensor.
- Camera optical origin (.55,.26722,1.6), tilted 12.5 degrees from vertical toward
  +Y away from robot. XY computed from block/camera height/tilt to aim at cube top.
- ROS RGB/depth/info/cloud bridges, world->camera_link->camera_optical_frame TF.
  Tested installed Harmonic cloud has +X-forward coordinates despite optical
  metadata; per-cloud bridge `frame_id: camera_link` fixes its label. Images and
  intrinsics remain optical. Verified numerically in test.
- Custom pickup RViz config for robot/cloud/RGB/depth. Desktop layout UNVERIFIED;
  actual rendered RGB image inspected successfully from headless test.

## Files added / changed
Added launch/franka_pickup_sim.launch.py, worlds/franka_pickup.sdf,
models/{conveyor_pickup,d435}/{model.config,model.sdf},
config/{pickup_camera_bridge.yaml,pickup.rviz}, test/pickup_smoke.py and
 test/results/{pickup_rgb.png,pickup_validation.json}.
Updated package.xml dependencies (sensor_msgs, tf2_ros, rviz2; test numpy/Pillow),
setup.py installs preview/result assets, README and resume notes.

## Latest validation PASS
`python3 src/franka_conveyor_sim/test/pickup_smoke.py`
- Same unchanged Franka stack + custom world, headless Ogre2 rendering works.
- Live rgb8,32FC1,CameraInfo x2, PointCloud2 streams; resolution848x480, frames correct.
- 1962 red cube pixels; median cube depth 1.07683 m.
- Center cloud transformed to world (.551203,.498768,.549999): cube top .55.
- Cube free-fall after set_pose elevation settles to (.55,.5,.499999).
  This verifies freedom from a rail, NOT a gripper grasp.
- Arm controller and joint_state_broadcaster active.
- Log `/tmp/pickup_smoke_33943.log`, persistent image/result test/results files.
- All new SDFs valid, Python compileall passed, bridge/RViz YAML parsed.
- Final build and installed launch argument validation recorded in session output.

## Start
```
source franka_sim_env.sh
ros2 launch franka_conveyor_sim franka_pickup_sim.launch.py
```
No other Gazebo/robot launch should already be running. No velocity command needed.
See README for params/topics/TF/headless/test commands.

## Next work / limits
Focus is camera integration and a future stationary pickup. User explicitly
postponed slider grasp-release / physical moving-belt compatibility. Do not resume
those as the active objective without a request. Gripper action execution, actual
pickup, MoveIt planning-scene insertion, collision-free reach and GUI RViz layout
remain UNVERIFIED. No segmentation/pose estimation/MPC/autonomous grasp added.
The headless Ogre2 server survived the Ruby launcher during one shutdown; the
smoke test now terminates its isolated process group after launcher exit. The
leftover test server was identified by partition and stopped. If a desktop
shutdown leaves a server behind, verify its partition/process before restarting.
Historical checkpoints below are superseded by this focus.

---

# Latest checkpoint — combined launch, 2026-10-14

Added `launch/franka_conveyor_sim.launch.py` at user request. One command starts
unchanged underlying Franka bringup (FR3 + hand + arm controller + Bullet physics)
and includes add_conveyor for the same world. No robot launch files were edited.
Wrapper defaults to slider, world empty, RViz on; conveyor initially stopped.
Pass-through args cover gz_args/rviz, world, belt pose, mode/gap, spawn toggle,
interval and local spawn X. No duplicate clock bridge. Existing standalone and
injection launches retained. Added actual bringup runtime dependency.

Installed wrapper headless test PASS:
`python3 src/franka_conveyor_sim/test/franka_slider_smoke.py --combined-launch`
- discovered world empty, successful belt/box creation
- moving box vx=.100725 m/s, y=.5, z=.552
- arm controller and state broadcaster active; joint_states present
- clean process shutdown; log `/tmp/franka_conveyor_wrapper_trial.log`
Build and Python compilation passed. README has the one-command instructions.

Run (no other robot/Gazebo running):
```
source franka_sim_env.sh
ros2 launch franka_conveyor_sim franka_conveyor_sim.launch.py
```
Then publish `/conveyor/cmd_vel` Double after spawner startup. Visual GUI rendering,
gripper action/MoveIt execution and reach validation remain unverified; slider
boxes remain constrained and not freely graspable. Earlier notes follow.

---

# Latest checkpoint — one-DOF visual conveyor mode, 2026-10-14

User requested boxes constrained to one translational DOF slightly above a
stationary conveyor. Implemented and tested as opt-in `motion_mode:=slider`.
The original default `physical` mode and robot configuration are preserved.

## Implementation
- Added `models/box_slider`: original cube collision/visual/inertia, hidden anchor
  link fixed to world, prismatic slide joint to visible canonical box link, native
  Harmonic JointController on `/conveyor/cmd_vel` (Double). Direct prismatic parent
  world was rejected by Bullet; fixed anchor + prismatic link works.
- Added `models/conveyor_stationary`: original static belt without TrackController.
- Launch arguments `motion_mode` and `hover_gap` (default .002 m). Spawner selects
  the slider model at startup, holds center at belt_z+.10+gap, and seeds new box
  JointController initial velocity from last received command.
- Extended transport/flow smoke tests for mode, rotated axis, exact hover height
  and newly spawned box speed inheritance. Added combined Franka slider test.
- README describes exact commands and limitations. No free-body release added.

## Results
- Bullet slider smoke PASS: 0.100267,0.198402,0,-0.100263 m/s for .1,.2,0,-.1.
  z=.55199999, y fixed. Log `/tmp/conveyor_smoke_18560.log`.
- 90-degree yaw smoke PASS: travel axis rotates to world Y, no lateral drift,
  correct hover and command response. Log `/tmp/conveyor_smoke_18855.log`.
- Installed Bullet slider flow PASS: births 3.304,6.403,9.503 sim seconds;
  second box inherits one-shot speed, measured .100087 m/s; pause, stopped-belt
  spacing, time reset, downstream deletion all pass.
  Log `/tmp/conveyor_flow_18682.log`.
- Combined unchanged Franka + injected slider PASS: discovered world empty,
  vx=.099687 m/s, y=.5, z=.552; active arm controller and state broadcaster before
  and after, joint_states present. Log `/tmp/franka_slider_trial.log`.
- New SDFs validate; Python compileall passes. Final package rebuild and installed launch arguments passed. Default physical
  flow regression also PASS: intervals, pause, spacing, reset and cleanup; log
  `/tmp/conveyor_flow_19494.log`.

## Usage
Existing robot running, in configured shell:
```
ros2 launch franka_conveyor_sim add_conveyor.launch.py world:=empty motion_mode:=slider
gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
```
Confirm actual world name first. Use a fresh world if a conveyor already exists;
launch never replaces the existing conveyor or starts another Gazebo server.
Publish speed after spawner starts. New boxes inherit that speed. `hover_gap`
range .001–.02 m. Tested velocities ±.1 and +.2 m/s; joint limit ±1 m/s.

## Important remaining scope
Slider boxes are driven on a world-fixed rail, not friction-driven free bodies.
They cannot be lifted/tumbled/grasped freely; collision response is constrained.
Useful for appearance/perception/interception timing; not grasp-contact physics.
GUI appearance, gripper actions, MoveIt and reach/clearance remain unverified.
Negative-flow cleanup and full-reset reconciliation remain pending. Physical
TrackController transport still fails under Bullet. No robot files modified.
See README for repeatable tests; historical checkpoints below are superseded.

---

# Current checkpoint — 2026-10-14 (continued implementation)

The earlier response timeout is resolved. Standalone physical conveyor and ROS
flow tests now PASS. Combined physical Franka transport remains BLOCKED by the
installed Bullet Featherstone backend's missing contact surface velocity support.
No changes were made to existing robot/gripper/controller/MoveIt files.

## Changes retained
- Added `franka_conveyor_sim/transport_service.py`: persistent service-only worker
  process, isolating blocking requests from Python transport subscribers. A
  service-only probe succeeded whereas subscriber+request clients timed out.
- Spawner uses one ProcessPoolExecutor worker with serialized protobuf requests;
  shutdown unsubscribes pose callbacks. Trial also unsubscribes callbacks.
- Fixed Jazzy runtime launch errors: unavailable LogError import replaced with
  LogInfo; parsed numeric arguments use float rather than ParameterValue on raw
  strings.
- Added installed-launch `test/spawner_smoke.py` and service diagnostics in
  `test/transport_smoke.py`.
- Replaced placeholder README with build/launch/manual spawning/configuration,
  measured results, explicit backend and MoveIt/gripper limitations.
- setup.py installs RESUME.md and excludes bytecode assets.

## Tests and results
- Package build passed after transport/launch changes; final documentation rebuild
  and static validation recorded in session output.
- DART physical smoke: vx=0.100066,0.200397,0,-0.099271 for commands
  0.1,0.2,0,-0.1 m/s. Cube z≈0.55 m. Create/remove responses succeed.
  Log `/tmp/conveyor_smoke_16750.log`.
- Bullet Featherstone smoke: box settles but vx=0 for every command, expected
  assertion failure. TrackController loads. Log `/tmp/conveyor_smoke_16835.log`.
  Upstream https://github.com/gazebosim/gz-physics/issues/569 identifies missing
  contactSurfaceMotionVelocity support. Do NOT switch Franka to DART: mimic hand.
- Installed standalone launch flow PASS: births at sim t=3.291,6.306,9.403;
  pause stops time/arrivals; stopped-belt spacing gates overlaps; time-only reset
  has no burst; downstream boxes removed after resuming .2 m/s.
  Log `/tmp/conveyor_flow_17166.log`.
- Headless unchanged Franka inner launch PASS. Gazebo services identify `empty`.
  Injected belt via add_conveyor world:=empty spawn_boxes:=false successfully,
  without another server. Active arm controller and joint_state_broadcaster
  unchanged; joint_states includes arm and finger. Only arm trajectory action
  was listed; gripper action execution and MoveIt are UNVERIFIED.
  Log `/tmp/franka_injection_trial.log`.

## Resume next
1. Resolve physical transport compatibility with the working Franka backend.
   Options require deliberate implementation: backend surface-motion support or
   a validated physical moving conveyor mechanism. No kinematic fallback is
   implemented. Do not silently change robot engine/hand/controller configuration.
2. Verify gripper action setup and MoveIt execution on the existing stack. Generic
   MoveIt moveit.launch.py starts its own hardware/controller stack; do not launch
   it blindly alongside Gazebo.
3. Validate arm/gripper clearance and IK for provisional belt pose (.6,.5,.45).
   Still UNVERIFIED; models are not synchronized into MoveIt planning scene.
4. Geometry configurability, full-reset ownership reconciliation and negative-flow
   cleanup remain pending. GUI rendering has not been verified.
5. Project is not complete: combined physical transport and gripper/MoveIt criteria
   are not satisfied. All trials stop their processes; keep workspace root RESUME.md
   pointed here.

Exact standalone/retest commands and configuration are now in README.md.
Historical checkpoints follow; their timeout descriptions are superseded.

---

# Response recheck — 2026-10-14

Added request diagnostics to `test/transport_smoke.py` and repeated the trial
with `GZ_IP=127.0.0.1`. Actual output:
```
create: ok=False, response=, elapsed=3.001s
```
The response prints empty because the Boolean protobuf has no true data field;
this does not establish a server rejection. The request result is false after
its configured 3-second deadline. Server-side creation should be distinguished
from successful delivery of a response. The run also reports
`terminate called without an active exception` (exit 134) after the assertion,
so Python transport shutdown needs investigation as well.
Latest server log: `/tmp/conveyor_smoke_13129.log`.
No box motion measurement was reached. Next debugging remains service response
handling / Python transport callback scheduling. Diagnostic print retained.

# Latest trial checkpoint — 2026-10-14

Resumed at the saved headless trial and stopped after recording the result.
Existing Franka files were not modified. Full implementation remains incomplete.

- No running Gazebo / ROS launch was found before the trial.
- Workspace `franka_sim_env.sh` documents Wi-Fi discovery trouble and sets
  `GZ_IP=127.0.0.1`. Applying this resolves the earlier clock timeout: simulation
  time advances and the trial reaches the create request.
- Trial FAILS at the first `request('create', belt)` assertion. The server log
  confirms conveyor entity creation, TrackController loading/subscription, and
  contact surface customization enabled with DART. The Python client does not
  obtain a successful response within its 3000 ms request timeout.
- A second trial using a separate service Node fails identically; this speculative
  code change was reverted. No functional source changes retained.
- No cube velocity measurement exists. Transport, spawning, cleanup, and Franka
  integration must NOT be reported as verified.
- Logs: `/tmp/conveyor_smoke_11844.log` and the subsequent
  `/tmp/conveyor_smoke_*.log` from this session. Both trials exited through server
  cleanup.

Reproduce from workspace root:
```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
export GZ_IP=127.0.0.1
python3 src/franka_conveyor_sim/test/transport_smoke.py
```

Next: diagnose the Python service response timeout despite server-side creation.
Print `ok` and `response`, compare against a Gazebo CLI create request in the same
partition, and investigate blocking Python transport / callback scheduling before
retrying creation (the entity may already exist). Then measure box motion with
DART and the existing Franka Bullet Featherstone backend. Do not change the
working Franka physics engine. Earlier audit and remaining work follow below.

---

# Resume checkpoint — 2026-10-13

User explicitly requested stopping for later resumption. Implementation is incomplete.
Read workspace AGENTS.md before continuing. Do not change existing robot configuration.

## Completed
- Audited /home/nick/franka_ros2_ws. ROS_DISTRO=jazzy, Gazebo Sim 8.15.0.
- No live Gazebo services/processes or controller manager at initial audit.
- Existing src/franka_gazebo/franka_gazebo_bringup/launch/franka_sim.launch.py starts FR3 + hand using fr3_arm_controller and `-r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf`.
- gazebo_franka_arm_example_controller.launch.py spawns from /robot_description with ros_gz_sim create, bridges /clock, and overwrites its own GZ_SIM_RESOURCE_PATH with franka_description parent. Do not modify this launch casually.
- franka_arm.gazebo.xacro anchors world -> fr3_link0 at xyz/rpy zero by default. Existing robot/controller/MoveIt files untouched.
- Existing MoveIt files: src/franka_fr3_moveit_config/launch/{moveit,move_group}.launch.py and config/fr3_controllers.yaml; trajectory action fr3_arm_controller/follow_joint_trajectory, gripper mapping franka_gripper/gripper_action. Runtime functionality UNVERIFIED.
- Installed authoritative example: /opt/ros/jazzy/opt/gz_sim_vendor/share/gz/gz-sim8/worlds/conveyor.sdf.
- Read https://gazebosim.org/api/sim/8/classgz_1_1sim_1_1systems_1_1TrackController.html (8.15.0). Plugin gz-sim-track-controller-system, model scoped, <link>base_link</link>, <velocity_topic>/conveyor/cmd_vel</velocity_topic>, gz.msgs.Double, local +X. Friction copied from matching installed example (mu .7, mu2 150, fdir1 0 1 0).
- Created separate ament_python package src/franka_conveyor_sim: models, world, config, spawner, injection and standalone launch, setup metadata, transport smoke script.
- SDF validation `gz sdf -k` passed all three SDFs. Python compileall passed.
- `source /opt/ros/jazzy/setup.bash; source install/setup.bash; colcon build --packages-select franka_conveyor_sim` passed (before final test script was added; test script is source only).
- Integration candidate shifted to belt center (0.6,0.5,0.45), yaw 0: 2m belt at y=0 would cross robot origin. Lateral offset is a provisional base-clearance choice, NOT validated arm/gripper clearance or IK reach. Standalone uses y=0.

## Current blocker / next debugging step
Headless transport_smoke.py timed out waiting for /world/conveyor_test/clock with data time=0 and pose=None twice. Gazebo server launched and advertised services/pose topics successfully. No physical transport measurement exists yet; no feature should be claimed working.
Logs: /tmp/conveyor_smoke_18421.log and /tmp/conveyor_smoke_18500.log.
First attempt set GZ_PARTITION after importing transport; second moved it before transport import but still timed out. Investigate Python gz transport subscriber discovery/network/interface/partition, whether clock is actually publishing, and server runtime. Script terminates server in finally; verified no test/server processes remain at checkpoint.
Repro: `source install/setup.bash; python3 src/franka_conveyor_sim/test/transport_smoke.py`.
Then repeat with `--engine gz-physics-bullet-featherstone-plugin` to check compatibility with working Franka gripper engine. Do not switch Franka engine to DART (mimic joint issue).

## Implementation notes requiring review
- box_spawner.py uses persistent gz.transport13 Node with gz.msgs10 create/remove requests, worker thread with one pending operation, sim-time timer, retry backoff, UUID-prefixed box names, confirmed pose spacing, downstream conservative cleanup. Gazebo Python bindings were inspected and are installed via vendor packages.
- Spawner currently subscribes /world/<world>/pose/info, depends on fresh messages and bridged /clock. Needs actual pause/reset/spacing/cleanup tests; max_boxes guards accumulation. Cleanup for negative belt flow not implemented (default downstream +X only).
- add_conveyor.launch.py requires explicit world name, creates belt with installed absolute file path, starts spawner only on successful create exit; bridge_clock defaults false to avoid duplicating Franka clock bridge. Does not start Gazebo.
- conveyor_test.launch.py starts standalone server and includes injection with bridge_clock=true, y=0. Need runtime launch testing.
- No initial nominal speed publication yet: belt remains stopped until gz topic command. Document or add configurable initial-speed handling.
- Geometry is currently fixed in model files, pose/spawn/interval configurable; full geometry configurability requested by AGENTS remains to address.
- Resource path appended in launch process; injection cannot retroactively alter server environment, but absolute SDF files have no external resources.
- README.md is a placeholder. Must replace with full audit/build/launch/manual create/speed commands/tests/config/troubleshooting/limitations and measured results.
- setup.py installs models/worlds/config/launch; README installed. RESUME.md currently not installed.

## Remaining work
1. Resolve transport smoke discovery timeout; measure 0.1, 0.2, 0, -0.1 commands with sim timestamps and box settle z~.55. Inspect verbose plugin loading and backend limitations.
2. Test installed standalone launch, repeated spawns, pause/reset gating, stopped-belt spacing and deletion.
3. Validate injection in unchanged Franka stack, controllers/joint_states/gripper/MoveIt and reachable collision-free belt region. Start baseline headless if feasible; otherwise explicit UNVERIFIED and exact user commands.
4. Add meaningful tests for spawn/reset/cleanup behavior and configuration validation as needed.
5. Finish README, rebuild, validate installed assets/launch arguments, final handoff with honest pending results.
6. No perception, estimation, MPC or grasping. MoveIt planning-scene obstacle synchronization deliberately pending and must be documented.

## Execution environment
All sandbox exec calls fail before running with `bwrap: loopback: Failed RTM_NEWADDR: Operation not permitted`. Tools were rerun with require_escalated approvals. Continue using appropriate approval mechanism; do not bypass it.
Workspace root is not a git repo; do not infer clean/dirty state from root git status. Existing robot files were only read.
