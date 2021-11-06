# ROS2 Publisher and Subscriber
[![License: MIT](https://img.shields.io/badge/License-MIT-Default.svg)](https://opensource.org/licenses/MIT)

# Overview
Implemented a publisher and subscriber in ROS2(foxy)

# Dependencies
- Ubuntu 20.04
- ROS Foxy

## Building package via command-line
```
mkdir -p ~/temp_ws/src/
cd ~/temp_ws/src/
git clone https://github.com/viveksood97/ros2_pub-sub.git
cd ../
source /opt/ros/foxy/setup.bash
rosdep install -i --from-path src --rosdistro foxy -y
colcon build
```
## Run
1. Run Publisher in new terminal
```
cd ~/temp_ws/
source /opt/ros/foxy/setup.bash
. install/setup.bash
ros2 run ros2_pub-sub publisher
```
1. Run Subscriber in new terminal
```
cd ~/temp_ws/
source /opt/ros/foxy/setup.bash
. install/setup.bash
ros2 run ros2_pub-sub subscriber