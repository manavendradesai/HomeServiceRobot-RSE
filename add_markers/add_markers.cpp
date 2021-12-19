#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

double check = 0;

// This callback function continuously executes and reads the position from odom
void check_position(const nav_msgs::Odometry xyz)
{
  
    //Create the publisher
     ros::NodeHandle m;
     ros::Publisher marker_pub = m.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  
     //Get joints current position
     double x = xyz.pose.pose.position.x;
     double y = xyz.pose.pose.position.y;

     //Print position
  	 ROS_INFO("%f",x);
     ROS_INFO("%f",y);
  
     //Display markers
  	 //Tolerance
     double tol = 0.5; 
  
  
	//Create the marker
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    //Set the namespace and id for this marker.  This serves to create a unique ID
    //Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    //Set the marker type
    marker.type = visualization_msgs::Marker::CUBE;
  
  	marker.lifetime = ros::Duration();

    //Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;
    
    //Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;
    
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header   
    //Prepare marker for pickup location
    marker.pose.position.x = 0;
    marker.pose.position.y = -2;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
  
    double xpickup = marker.pose.position.x;
    double ypickup = marker.pose.position.y;
  
    //Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    //Publish the marker at the pickup location
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
      ROS_WARN_ONCE("ROS is not ok");
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
  
  	if(check == 0)
    {
    marker_pub.publish(marker);
    }
 
  
   //Wait for home service robot to collect virtual object 
    ROS_INFO("Waiting for home service robot to collect virtual object");

    
     //Hide marker on pickup
     if(fabs(x-xpickup)<tol && fabs(y-ypickup)<tol && check == 0)
     {
     marker.action = visualization_msgs::Marker::DELETE;
     marker_pub.publish(marker);
     ROS_INFO("Home service robot has reached the pick-up location");
       
     //Wait 5 seconds to simulate pickup
     ROS_INFO("Waiting for home service robot to pick-up the virtual object");
     check = 1;
     ros::Duration(5.0).sleep();
     ROS_INFO("Home service robot is moving towards the drop-off location");
     }
  
     //Prepare marker for drop-off location
     marker.pose.position.x = 0;
     marker.pose.position.y = 0;
     marker.pose.position.z = 0;
  
     double xdropoff = marker.pose.position.x;
     double ydropoff = marker.pose.position.y;

   
    //Bring up marker on drop-off
    if(fabs(x-xdropoff)<tol && fabs(y-ydropoff)<tol && check == 1)
    {
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
    ROS_INFO("Home service robot has dropped-off the virtual object");
    }
}
           

int main( int argc, char** argv )
{
  //Create the node
  ros::init(argc, argv, "add_markers");

  //Subscriber
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("odom", 1000, check_position);
    
  //Handle ROS communication events to continue listen to the subscriber
  ros::spin();
  return 0;

  }

