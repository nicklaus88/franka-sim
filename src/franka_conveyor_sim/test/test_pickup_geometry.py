import math
import cv2
import numpy as np
import pytest
from franka_conveyor_sim.pickup_geometry import estimate_cube, grasp_targets, rotation_matrix


def fixture():
    rgb = np.zeros((240,320,3),np.uint8)
    depth = np.ones((240,320),np.float32)
    # Square top at z=.51, side .06, optical depth 1 m, 400 px focal length.
    rgb[108:133,148:173] = (180,0,0)
    k = [400,0,160,0,400,120,0,0,1]
    transform = ([.15,.5,1.51],[1,0,0,0])
    return rgb,depth,k,transform


def test_rgbd_center_and_topdown_grasp():
    result = estimate_cube(*fixture())
    assert np.allclose(result['center'],[.15,.5,.48],atol=.002)
    pre,grasp,q = grasp_targets(result['center'],result['yaw'])
    assert np.allclose(grasp,[.15,.5,.49],atol=.002)
    assert abs(pre[2]-grasp[2]-.12) < 1e-8
    assert np.allclose(rotation_matrix(q)@[0,0,1],[0,0,-1])


def test_reject_missing_depth_and_oversized_cube():
    rgb,depth,k,transform = fixture()
    depth[:] = np.nan
    with pytest.raises(ValueError):
        estimate_cube(rgb,depth,k,transform)
    with pytest.raises(ValueError,match='opening'):
        grasp_targets([0,0,.5],0,size=.10)


def test_rotated_square_yaw_is_observable_modulo_quarter_turn():
    rgb,depth,k,transform = fixture()
    rgb[:] = 0
    corners = cv2.boxPoints(((160,120),(24,24),20)).astype(np.int32)
    cv2.fillConvexPoly(rgb,corners,(180,0,0))
    result = estimate_cube(rgb,depth,k,transform)
    # Optical Y points down in world for this transform; image +20° is world -20°.
    assert abs(result['yaw']+math.radians(20)) < .08
