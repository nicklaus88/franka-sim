"""Independent finite-difference check of TCP Jacobian and primary-task projection."""
from pathlib import Path
import numpy as np
import pinocchio as pin
import xacro
from ament_index_python.packages import get_package_share_directory
from franka_conveyor_sim.conveyor_tracker import resolved_velocity, tracking_rates


def test_translational_jacobian_matches_finite_difference():
    path=Path(get_package_share_directory('franka_gazebo_bringup'))/'urdf/franka_arm.gazebo.xacro'
    xml=xacro.process_file(str(path),mappings={'robot_type':'fr3','hand':'true','ee_id':'franka_hand','gazebo_effort':'true'}).toxml()
    model=pin.buildModelFromXML(xml)
    data=model.createData()
    q=pin.neutral(model)
    names=[f'fr3_joint{i}' for i in range(1,8)]
    indices=[model.joints[model.getJointId(n)].idx_v for n in names]
    q[indices]=[0.,-.785,0.,-2.356,0.,1.571,.785]
    frame=model.getFrameId('fr3_hand_tcp')
    jac=pin.computeFrameJacobian(model,data,q,frame,pin.LOCAL_WORLD_ALIGNED)[:3,indices]
    numerical=[]
    for i in indices:
        delta=np.zeros(model.nv);delta[i]=1e-6
        positions=[]
        for sign in (-1,1):
            pin.framesForwardKinematics(model,data,pin.integrate(model,q,sign*delta))
            positions.append(data.oMf[frame].translation.copy())
        numerical.append((positions[1]-positions[0])/2e-6)
    np.testing.assert_allclose(jac,np.array(numerical).T,atol=1e-8)


def test_null_space_orientation_preserves_translation():
    rng=np.random.default_rng(42)
    jac=rng.normal(size=(6,7))
    velocity=np.array([.1,0.,.01])
    primary=resolved_velocity(jac[:3],velocity)
    rates,_=tracking_rates(jac,np.eye(3),velocity)
    np.testing.assert_allclose(jac[:3]@rates,jac[:3]@primary,atol=1e-12)


def test_damped_solution_remains_finite_at_singularity():
    jac=np.zeros((3,7));jac[0,0]=1
    rates=resolved_velocity(jac,np.ones(3))
    assert np.isfinite(rates).all()
    np.testing.assert_allclose(rates[1:],0)
