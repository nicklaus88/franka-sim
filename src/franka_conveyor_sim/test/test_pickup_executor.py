"""Reject unsafe saved-plan data before any controller goal can be sent."""
import copy
import json

import pytest
from moveit_msgs.msg import RobotTrajectory, RobotState, AttachedCollisionObject, CollisionObject
from rosidl_runtime_py.convert import message_to_ordereddict

from franka_conveyor_sim.pickup_executor import decode, load_plan, STAGES
from franka_conveyor_sim.pickup_planner import ARM, FINGERS, HOME


def plan_data():
    values = dict(zip(ARM,HOME))
    values.update(dict.fromkeys(FINGERS,.04))
    plan = dict(status='success',trajectory_start={'joint_state':{'name':list(values),'position':list(values.values())}},
                stages={},stage_start_states={})
    for name in STAGES:
        joints = FINGERS if 'fingers' in name else ARM
        start = [values[j] for j in joints]
        plan['stage_start_states'][name] = {'joint_state':{'name':list(values),'position':list(values.values())}}
        if name == 'close_fingers':
            values.update(dict.fromkeys(FINGERS,.03))
        elif name == 'release_fingers':
            values.update(dict.fromkeys(FINGERS,.04))
        plan['stages'][name] = {'joint_trajectory':{'joint_names':joints,'points':[
            {'positions':start,'time_from_start':{'sec':0,'nanosec':0}},
            {'positions':[values[j] for j in joints],'time_from_start':{'sec':1,'nanosec':0}}]}}
    return plan


def test_decode_does_not_mutate_saved_plan(tmp_path):
    data = plan_data()
    original = copy.deepcopy(data)
    decode(RobotTrajectory,data['stages'][STAGES[0]])
    assert data == original
    path = tmp_path/'plan.json'
    path.write_text(json.dumps(data))
    loaded = load_plan(path)
    for stage in STAGES:
        decode(RobotTrajectory,loaded['stages'][stage])
    assert loaded == original


@pytest.mark.parametrize('corruption', ['nan','time','discontinuity','asymmetric','state'])
def test_reject_corrupt_plan(tmp_path,corruption):
    data = plan_data()
    points = data['stages'][STAGES[0]]['joint_trajectory']['points']
    if corruption == 'nan':
        points[1]['velocities'] = [float('nan')]*7
    elif corruption == 'time':
        points[1]['time_from_start']['sec'] = 0
    elif corruption == 'discontinuity':
        points[0]['positions'][0] = .5
    elif corruption == 'asymmetric':
        data['stages']['close_fingers']['joint_trajectory']['points'][1]['positions'][1] = .02
    else:
        data['stage_start_states'][STAGES[0]]['joint_state']['position'][0] = .5
    path = tmp_path/'plan.json'
    path.write_text(json.dumps(data))
    with pytest.raises(ValueError):
        load_plan(path)


def test_attachment_byte_roundtrip():
    state = RobotState(attached_collision_objects=[AttachedCollisionObject(
        link_name='fr3_hand_tcp', object=CollisionObject(id='pickup_cube',operation=CollisionObject.ADD))])
    data = json.loads(json.dumps(message_to_ordereddict(state)))
    decoded = decode(RobotState,data)
    assert decoded == state
