# HomeServiceRobot-RSE
Project 5 of the Robotics Software Engineering Nanodegree Program at Udacity

## Objectives -->
Program a home service robot using ROS that automatically maps an environment and navigates to pickup and deliver objects in Gazebo. 

## Outcomes -->

- Learnt classic path planning concepts and approaches such as Minkowski sum, visibility graphs, Voronoi diagrams, graph search and A* search
- Learnt sample-based planning methods and techniques such as the probabilistic roadmap method and rapidly exploring random tree, and path smoothing and Markov Decision processes 
- Successfully programed the turtlebot in ROS that automatically maps an environment and navigates to pickup and deliver objects in Gazebo 
- Coupled the advanced Monte Carlo localization algorithm with Dijkstra’s path planning algorithm to move the turtlebot to commanded waypoints (for eg. when using the 2D Nav Goal tool in Rviz)

## Directory structure -->

    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files
    │   │   ├── RvizLaunch.launch
    │   │   ├── amcl.launch
    │   │   ├── robot_descriptionGoChaseIt.launch
    │   │   ├── worldGoChaseIt.launch
    │   │   ├── mapping.launch         # runs the nodes of the RTAB-Map package
    │   │   ├── teleop.launch          # runs the node for the teleoperation package used to move the mobile robot
    │   ├── model                      # folder containing the Gazebo world model
    │   │   ├── homeGoChaseIt
    │   │   │   ├── model.config
    │   │   │   ├── model.sdf
    │   ├── meshes                     # meshes folder for the lidar sensor
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robotGoChaseIt.gazebo
    │   │   ├── my_robotGoChaseIt.xacro
    │   ├── worlds                     # world folder for world files
    │   │   ├── homeGoChaseIt
    │   │   ├── homeGoChaseIt.world
    │   │   ├── myApartment
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── teleop_twist_keyboard          # Tele-operation package for navigating the mobile robot in Gazebo
    │   ├── CHANGELOG.rst              
    │   ├── CMakeLists.txt             
    │   ├── README.md                  
    │   ├── package.xml                # package info
    │   ├── teleop_twist_keyboard.py   # package info
    └── Media                          # screenshots of the world and the mobile robot in Gazebo, 3D map of the world and the 2D occupancy grid map generated using SLAM 
    
