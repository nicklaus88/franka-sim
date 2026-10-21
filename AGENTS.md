# AGENTS.md — Franka Conveyor Simulation Environment

## Mission
Implement a reproducible conveyor-belt and moving-box environment for an **existing, working** Franka robot simulation using **Ubuntu 24.04, ROS 2 Jazzy, Gazebo Harmonic (gz-sim8), MoveIt 2, and ros2_control**. The environment is the foundation for a later vision-based MPC interception and grasping project. **This task is environment setup only:** do not implement perception, Kalman filtering, MPC, or autonomous grasping yet.

## Nonnegotiable constraints
1. **Inspect the existing workspace first.** Discover its root, launch files, active Gazebo world name, Franka base transform, spawn mechanism, controller configuration, and MoveIt configuration. Do not assume `~/ros2_ws` or a world named `default`.
2. **Do not break the functioning Franka stack.** Do not replace Franka URDF/Xacro, gripper configuration, ros2_control hardware interfaces, MoveIt parameters, or existing launch files. Favor a standalone environment package and wrapper launch file. Back up any necessary edits and explain each one.
3. **Use Gazebo Harmonic APIs, not Gazebo Classic** (`gazebo_ros`, old `gazebo_plugins`, Classic spawn scripts, etc.). Do not install or upgrade ROS/Gazebo distributions unnecessarily.
4. **Do not claim a feature works without testing it.** If Gazebo cannot be launched in the execution environment, run static checks, clearly say integration tests are pending, and provide exact commands for the user.
5. Make the conveyor and boxes **separate SDF models**, dynamically spawnable into the already running Franka world. Do not edit the arm description for these objects.
6. Prefer **physics-based box movement** via Gazebo's `TrackController` system. Do not silently substitute pose-teleportation as physically accurate transport. A clearly labeled kinematic fallback is acceptable only for debugging and interception-only experiments.
7. Keep launch, geometry, speeds, spawning, and resource paths configurable; use sim time in ROS nodes and avoid duplicate Gazebo processes.

## Success criteria (definition of done)
- Running Franka + MoveIt 2 + ros2_control remains operational, including its gripper and existing controllers.
- A belt model is visible and collidable near, but not intersecting, the robot; its top is nominally 0.50 m above the floor.
- One 0.10 m cube (0.20 kg) can spawn just above the belt, settle, and move in belt +X at a commanded nominal 0.10 m/s.
- Changing the belt command to 0.20 m/s visibly and measurably changes box motion. Pausing / stopping the belt behaves sensibly.
- An automated ROS 2 spawner creates uniquely named boxes at configurable **simulation-time** intervals, avoids overlapping boxes, and cleans up expired boxes.
- At least one launch / documented command path adds the conveyor to the **existing** Franka simulation without running a second independent Gazebo instance.
- A standalone world permits testing the conveyor without Franka.
- README documents build, execution, tests, configuration, troubleshooting, and what is not yet implemented.

## Proposed package layout
Create or adapt a ROS 2 package named `franka_conveyor_sim` (use `ament_python` unless an actual C++ plugin becomes necessary):

```text
franka_conveyor_sim/
├── AGENTS.md                     # optionally copy this file here
├── package.xml
├── setup.py
├── setup.cfg
├── resource/franka_conveyor_sim
├── franka_conveyor_sim/
│   ├── __init__.py
│   └── box_spawner.py
├── models/
│   ├── conveyor/model.config
│   ├── conveyor/model.sdf
│   ├── box/model.config
│   └── box/model.sdf
├── worlds/conveyor_test.sdf
├── config/conveyor.yaml
├── launch/conveyor_test.launch.py
├── launch/add_conveyor.launch.py
├── test/
└── README.md
```

Install `worlds/`, `models/`, `launch/`, and `config/` into the package share directory using `setup.py` data files. Resolve installed assets using `ament_index_python` rather than source-tree absolute paths. Add needed package dependencies (`rclpy`, `ament_index_python`, `ros_gz_sim`, etc.). Do not add ROS dependencies that are not actually used. Configure `GZ_SIM_RESOURCE_PATH` to allow `model://conveyor` and `model://box` resolution; avoid overwriting an existing value.

## Design parameters (defaults, adjustable after inspecting Franka reach)
- Conveyor collision/visual box: **2.0 × 0.4 × 0.1 m**; top height **0.50 m**, so nominal center **z=0.45 m**.
- Conveyor center in robot base frame: candidate **x=0.6, y=0.0 m**, but **validate reachability and collision clearance** against the actual Franka base/gripper. Never blindly place it through the robot.
- Belt movement direction: conveyor local **+X**.
- Belt command topic: `/conveyor/cmd_vel` using `gz.msgs.Double`, nominal `0.10 m/s`; include `0.0`, `0.20`, and negative-direction tests if supported.
- Boxes: dynamic, visually distinct 0.10 m cubes, **mass 0.20 kg**, physically correct inertia (uniform solid cuboid: `Ixx=m*(y²+z²)/12`, etc.). Spawn initial cube center about **z=0.57 m** for a belt top at 0.50 m; let it settle to ~0.55 m.
- Suggested initial spawn point for a conveyor at x=0.6: **x=-0.25, y=0.0, z=0.57 m** in world coordinates, *provided* the conveyor's world-frame X range and robot placement match these assumptions. Compute actual positions from the model pose in code where possible.
- Spawner interval: 3.0 seconds **of simulation time**, initially one cube / single-file flow. Optional random lateral position with reproducible seed, kept within belt width. Gate spawns if the previous cube is too close to prevent initial interpenetration.
- Stop boxes from accumulating off-belt; use simulation-world entity removal supported by the installed Gazebo/ROS bridge version.
- World physics step size about 1 ms initially; use default supported physics engine and verify friction/contact transport actually functions.

## Implementation plan

### 0 — Audit and baseline
- Inspect `ros2 --version`-equivalent distro environment (`echo $ROS_DISTRO`), `gz sim --versions` / `gz sim --version` as supported, package availability, and current Franka launch invocation.
- Identify world name using `gz service -l` or `gz topic -l`, and list controllers using `ros2 control list_controllers` with the current stack running.
- Record robot base frame (`world` -> base link), working gripper commands, and MoveIt launch. Preserve a known-good start command in the README.
- Look for existing environment/world hooks in Franka's launch before introducing a wrapper.

### 1 — Standalone physical models
- Create valid SDFormat model files and `model.config` files for conveyor and box. Include collisions, visuals, material, inertial properties for the box, and friction settings appropriate to the installed physics engine. Conveyor is stationary in world; its contact surface must simulate nonzero tangential motion.
- Research **Gazebo Sim 8/Harmonic** `TrackController` actual system filename, XML element names, velocity-message type, friction requirements, and physics-backend limitations. Base the SDF on the **matching gz-sim8 conveyor example**, not docs for newer gz-sim10 unless equivalent options are verified.
- Include required world systems: `Physics`, `UserCommands`, `SceneBroadcaster`; add `Sensors` only if actually needed later. Add ground plane and light in standalone world.
- Ensure the conveyor plugin attaches to the link named in SDF. A visible stationary belt graphic is acceptable if the **contact surface** moves boxes physically.
- **Critical verification:** Before claiming success, inspect Gazebo verbose output for a plugin-loading error and demonstrate that the test box moves when commanded. Static friction values in a model alone do *not* make a conveyor move.

### 2 — Standalone smoke test
- Create `conveyor_test.launch.py` to launch a standalone world, and a documented command to spawn a cube through the **installed** `ros_gz_sim` interface.
- For example (adjust `-world`, paths, and option aliases based on `--helpshort`):

```bash
ros2 run ros_gz_sim create \
  -world conveyor_test \
  -file /ABSOLUTE/PATH/to/models/box/model.sdf \
  -name box_test -x -0.25 -y 0.0 -z 0.57

gz topic -t /conveyor/cmd_vel -m gz.msgs.Double -p 'data: 0.1'
```

- Measure cube world X from Gazebo state/pose data at two or more simulation timestamps. For a physically driven box, allow transient acceleration/slip; **do not demand exact x(t)=x0+v*t**.
- If TrackController fails, investigate plugin installation, canonical example syntax, friction directions/contact configuration, Gazebo physics engine, and whether this exact plugin version supports the setup. Report blocked causes; only then implement a configurable **debug-only kinematic movement** mode, explicitly flagged as unsuitable for grasp-contact evaluation.

### 3 — ROS 2 box spawner
- Implement `box_spawner.py` as a maintainable `rclpy` node, reading parameters from `config/conveyor.yaml`.
- Use Gazebo model creation service / `ros_gz_sim` interface verified to exist on Jazzy/Harmonic. `ros2 run ros_gz_sim create` is a valid manual smoke test. For repeated spawns, prefer a persistent API or Gazebo Transport service (via an appropriate bridge), not an uncontrolled new subprocess every few seconds.
- Ensure distinct entity names (`box_0001`, etc.), successful service responses, retries with backoff, and clean shutdown.
- Generate randomized optional box placements; start with fixed 0.10 m boxes to avoid needlessly regenerating inertial tensors.
- Implement cleanup once a box passes downstream limits, using confirmed Gazebo state and deletion APIs. Avoid deleting a box merely because it is grasped/moved away from the belt; if uncertain, make cleanup conservative/configurable.
- Use `/clock` with `use_sim_time` and handle reset or pause without continuous spawning based on wall time.

### 4 — Integrate with the existing Franka launch
- **Preferred:** spawn the belt (and boxes) into the currently running Franka Gazebo world through `ros_gz_sim create` / Gazebo creation service; do not launch another Gazebo server.
- **Alternative:** use a wrapper launch or existing world-file argument to start Gazebo with the conveyor world, then start the *unchanged* Franka spawn/ros2_control/MoveIt stack. Do not silently replace existing world plugins required by Franka.
- Make world name, belt pose, spawn pose, and optional box spawner exposed as launch arguments or parameters.
- Verify the belt is reachable: use TF/MoveIt scene and the Franka end-effector approach pose; avoid collisions with robot base at default pose.
- Note that Gazebo entities are **not automatically MoveIt collision objects**. Document that a later milestone must add conveyor/static collision geometry and dynamic boxes into the MoveIt planning scene. It is acceptable to postpone that integration for this environment-only task, but it must be called out explicitly.

### 5 — Validation and handoff
- `colcon build --packages-select franka_conveyor_sim` completes and `source install/setup.bash` exposes launch files / executables.
- SDF files parse (use `gz sdf -k` or available SDFormat validation commands; verify actual installed CLI options).
- Standalone conveyor displays, box settles, and belt command changes box measured velocity.
- With Franka integration, `/joint_states`, MoveIt, controllers, and gripper remain operational.
- Automatic spawning produces multiple independent box entities, at roughly configured sim-time interval, without spawn collisions; cleanup works.
- Record exact tested commands and results. Where integration testing is impossible, provide explicit **UNVERIFIED** labels and runnable user checks.
- Do not declare project done if belt commands publish but no box moves.

## Common failure modes to actively check
- Wrong Gazebo generation (Classic vs Harmonic), plugin filename, or TrackController parameters.
- Physics engine / friction direction unsupported or misconfigured: plugin loads but boxes remain stationary.
- `model://...` URI resolution broken because `GZ_SIM_RESOURCE_PATH` not installed/exported.
- Running a second Gazebo instance instead of injecting models into Franka's existing world.
- Wrong world name in `ros_gz_sim create` / Gazebo services.
- Boxes spawn partially through belt or outside belt; nonphysical inertia / collision geometry.
- Spawner uses wall time and floods box creation while sim is paused.
- Gazebo and MoveIt have inconsistent frames, unknown obstacle geometry, or unreachable grasp region.
- Exposing an ROS topic does not mean a Gazebo topic is bridged; use `ros_gz_bridge` only where necessary and specify direction/message type.

## Deliverables to report
1. Files created or changed (with paths).
2. How to build, launch standalone, inject into Franka world, command belt speed, start/stop box spawner.
3. Tested functions and measurements, including velocity response.
4. Remaining issues, assumptions about world frame/robot pose, and specific next steps for later perception/MPC integration.

## References (verify against installed versions)
- Gazebo Harmonic ROS spawning: https://gazebosim.org/docs/harmonic/ros2_spawn_model/
- Gazebo Sim 8 TrackController: https://gazebosim.org/api/sim/8/classgz_1_1sim_1_1systems_1_1TrackController.html
- Gazebo Sim 8 source examples: https://github.com/gazebosim/gz-sim/tree/gz-sim8/examples/worlds
- ros_gz_sim entity creation: https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_sim

## Agent operating style
Make incremental edits; after every stage, run the smallest useful validation. Prefer reliable, simple defaults over elaborate abstraction. When facing an uncertain plugin API, inspect the actual installed docs or upstream gz-sim8 source rather than guessing. Do not modify the user's working robot configuration without a compelling, documented reason.
