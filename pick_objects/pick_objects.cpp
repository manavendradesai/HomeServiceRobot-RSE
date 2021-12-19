#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define the first position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y = -2.0;
  goal.target_pose.pose.position.z = 0.0;
  goal.target_pose.pose.orientation.w = 1;

  
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pick-up zone");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ROS_INFO("Going to pick-up zone");
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Hooray, the base reached the pickup zone");
    ROS_INFO("Picking up object");
  	ac.waitForServer(ros::Duration(5.0));
  }
  else
  {
    ROS_INFO("The base failed to reach the pick-up zone for some reason");
  }
  
  // Define a second position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y = 0.0;
  goal.target_pose.pose.position.z = 0.0;
  goal.target_pose.pose.orientation.w = 1;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending drop-off zone");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ROS_INFO("Going to drop-off zone");
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base reached the drop-off zone");
  else
    ROS_INFO("The base failed to reach the drop-off zone for some reason");

  return 0;
}