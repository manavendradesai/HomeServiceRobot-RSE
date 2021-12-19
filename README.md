# HomeServiceRobot-RSE

## Description -->
Project 5 of the Robotics Software Engineering Nanodegree Program at Udacity. Program a home service robot using ROS that automatically maps an environment and navigates to pickup and deliver objects in Gazebo. 

## Outcomes -->

- Learnt classic path planning concepts and approaches such as Minkowski sum, visibility graphs, Voronoi diagrams, graph search and A* search
- Learnt sample-based planning methods and techniques such as the probabilistic roadmap method and rapidly exploring random tree, and path smoothing and Markov Decision processes 
- Successfully programed the turtlebot in ROS that automatically maps an environment and navigates to pickup and deliver objects in Gazebo 
- Coupled the advanced Monte Carlo localization algorithm with Dijkstra’s path planning algorithm to move the turtlebot to commanded waypoints (for eg. when using the 2D Nav Goal tool in Rviz)

## Directory structure -->

    ├── add_markers                    # my_robot package                   
    │   ├── add_markers.cpp            # C++ code that added markers in Rviz at the positions of object pick-up and drop-off
    ├── map                            # map to be used for the localization test 
    │   ├── map.pgm                     
    │   ├── map.yaml
    ├── pick_objects                   
    │   ├── pick_objects.cpp           # C++ code to drive to goal locations for pick-up and drop-off of objects
    ├── rvizConfig                     # Configuration setup file for Rviz
    │   ├── homeservicerobotConfig.rviz 
    ├── scripts                        # Shell scripts to launch nodes to run the home service robot
    │   ├── add_marker.sh              # Shell script to add markers in Rviz at the pick-up and drop-off virtual objects
    │   ├── home_service.sh            # Shell script to run nodes that get the home service robot running
    │   ├── pick_objects.sh            # Shell script to run nodes that drives the mobile robot to the pick-up and drop-off locations
    │   ├── test_navigation.sh         # Shell-script to run the nodes used to test the navigation algorithm 
    │   ├── test_slam.sh               # Shell-script to run the nodes used to test the slam algorithm
    ├── turtlebot_gazebo               # launch files to test localization and mapping tasks
    │   ├── amcl_demo.launch                   
    │   ├── gmapping_demo.launch       
    │   ├── turtlebot_world.launch
    ├── turtlebot_rviz_launchers       # launch file to run Rviz
    │   ├── view_navigation.launch     
    ├── turtlebot_teleop               # launch file to run the teleop node to drive the mobile robot
    │   ├── keyboard_teleop.launch     
    
    
