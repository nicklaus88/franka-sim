# Current checkpoint

[Full session handoff](SESSION_HANDOFF_2026-10-14.md) — objectives, changes, issues, solutions, validation and next steps.

Read [details](src/franka_conveyor_sim/RESUME.md) and
[commands/results](src/franka_conveyor_sim/README.md).

Latest: OpenCV RGB-D cube pose + MoveIt home/pre-grasp/grasp planning implemented
and tested. User approved 6 cm pickup cube. Run:
```
source franka_sim_env.sh
ros2 launch franka_conveyor_sim pickup_planning.launch.py
```
Planning-only: no arm/gripper commands. Vision error1.9mm, full collision-checked
Cartesian approach, FK endpoints and Trigger replan passed. Plan JSON/overlay in
package test/results. Next: gripper interface/open-hand execution validation,
actual grasp/lift/goal placement; desktop RViz layout unverified.
