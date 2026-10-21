"""RGB-D geometry for a known upright red cube; no Gazebo truth input."""
import math
import cv2
import numpy as np


def rotation_matrix(q):
    q = np.asarray(q, dtype=float)
    norm = np.linalg.norm(q)
    if norm < 1e-9 or not np.isfinite(norm):
        raise ValueError('Invalid transform quaternion')
    x, y, z, w = q/norm
    return np.array([[1-2*(y*y+z*z), 2*(x*y-z*w), 2*(x*z+y*w)],
                     [2*(x*y+z*w), 1-2*(x*x+z*z), 2*(y*z-x*w)],
                     [2*(x*z-y*w), 2*(y*z+x*w), 1-2*(x*x+y*y)]])


def estimate_cube(rgb, depth, k, transform, size=.06, belt_top=.45):
    """Segment red, back-project finite depth, fit world-XY top-face rectangle.

    Assumes a known upright cube resting on the configured belt. Square yaw is
    returned modulo 90 degrees; roll/pitch are not independently observable.
    """
    if rgb.shape[:2] != depth.shape or rgb.ndim != 3:
        raise ValueError('Aligned RGB and depth dimensions must match')
    k = np.asarray(k, dtype=float).reshape(3, 3)
    if k[0, 0] <= 0 or k[1, 1] <= 0:
        raise ValueError('Invalid intrinsics')
    hsv = cv2.cvtColor(rgb, cv2.COLOR_RGB2HSV)
    mask = cv2.inRange(hsv, (0, 100, 60), (12, 255, 255)) | cv2.inRange(hsv, (170, 100, 60), (179, 255, 255))
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, np.ones((3, 3), np.uint8))
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    candidates = sorted(contours, key=cv2.contourArea, reverse=True)
    rotation = rotation_matrix(transform[1])
    for contour in candidates:
        if not 40 <= cv2.contourArea(contour) <= rgb.shape[0]*rgb.shape[1]*.2:
            continue
        selected = np.zeros(depth.shape, np.uint8)
        cv2.drawContours(selected, [contour], -1, 255, -1)
        rows, cols = np.nonzero((selected > 0) & np.isfinite(depth) & (depth > .1) & (depth < 5))
        if len(rows) < 30:
            continue
        z = depth[rows, cols]
        optical = np.column_stack(((cols-k[0,2])*z/k[0,0], (rows-k[1,2])*z/k[1,1], z))
        world = optical @ rotation.T + np.asarray(transform[0])
        top_z = float(np.percentile(world[:, 2], 75))
        top = world[np.abs(world[:, 2]-top_z) < .004]
        if len(top) < 30 or abs(top_z-(belt_top+size)) > .015:
            continue
        rect = cv2.minAreaRect(top[:, :2].astype(np.float32))
        dims = sorted(rect[1])
        if any(abs(d-size) > .018 for d in dims):
            continue
        corners = cv2.boxPoints(rect)
        edge = corners[1]-corners[0]
        yaw = (math.atan2(float(edge[1]),float(edge[0]))+math.pi/4) % (math.pi/2)-math.pi/4
        return dict(center=[float(rect[0][0]),float(rect[0][1]),top_z-size/2],
                    yaw=yaw, size=dims, top_z=top_z, pixels=len(top), contour=contour)
    raise ValueError('No valid red cube top face with matching height/size/depth')


def grasp_targets(center, yaw, size=.06, pregrasp_clearance=.12, insertion=.02):
    if size+.01 > .08:
        raise ValueError('Cube plus clearance exceeds installed 8 cm gripper opening')
    if not 0 < insertion < size or pregrasp_clearance <= 0:
        raise ValueError('Invalid insertion or clearance')
    # TCP's +Z points down; local Y is the finger closing direction.
    quaternion = [math.cos(yaw/2), math.sin(yaw/2), 0., 0.]
    grasp = list(center)
    grasp[2] += size/2-insertion
    pre = list(grasp)
    pre[2] += pregrasp_clearance
    return pre, grasp, quaternion
