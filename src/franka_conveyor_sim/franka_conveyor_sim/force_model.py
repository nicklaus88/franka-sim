"""Configure the per-box force system with the actual world-frame belt geometry."""
from pathlib import Path
import math
from ament_index_python.packages import get_package_prefix


def configure_force_plugin(root, *, belt_x, belt_y, belt_top, belt_yaw,
                           belt_length=2., belt_width=.4, box_size=.1,
                           initial_speed=.1, velocity_gain=10., integral_gain=2.,
                           max_acceleration=1.):
    values = (belt_x,belt_y,belt_top,belt_yaw,belt_length,belt_width,box_size,
              initial_speed,velocity_gain,integral_gain,max_acceleration)
    if (not all(math.isfinite(v) for v in values) or
            not 0 < box_size < min(belt_length,belt_width) or
            velocity_gain <= 0 or integral_gain < 0 or max_acceleration <= 0):
        raise ValueError('Invalid force-controller geometry, gains or speed')
    plugin = root.find("model/plugin[@name='franka_conveyor::ConveyorForce']")
    if plugin is None:
        raise ValueError('Force mode requires the box_force model')
    # Supports injection into a Gazebo server that predates this overlay.
    plugin.set('filename',str(Path(get_package_prefix('franka_conveyor_force_system'))/
                              'lib/libfranka_conveyor_force_system.so'))
    for key,value in dict(belt_x=belt_x,belt_y=belt_y,belt_top=belt_top,belt_yaw=belt_yaw,
                          belt_length=belt_length,belt_width=belt_width,box_size=box_size,
                          initial_speed=initial_speed,velocity_gain=velocity_gain,
                          integral_gain=integral_gain,max_acceleration=max_acceleration).items():
        plugin.find(key).text = str(value)
