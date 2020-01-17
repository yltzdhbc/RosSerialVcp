#include "ros_main.h"
#include "main.h"

#include <ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Imu.h>

ros::NodeHandle nh;

uint32_t tTime[10] = {0};
uint32_t t;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[] = "Hello world!";

//geometry_msgs::TransformStamped tfs_msg;
//tf::TransformBroadcaster tfbroadcaster;

//IMU 
sensor_msgs::Imu imu_msg;
ros::Publisher imu_pub("imu", &imu_msg);

short acc[3] = {2,5,8};
short gyro[3] = {1,4,9};

//Publish msgs (IMU data:angular velocity, linear acceleration, orientation)
void publishImuMsg(void)
{
  //imu_msg.header.stamp  = nh.now();//rosNow();
//  imu_msg.header.frame_id = "imu_link";
  
  imu_msg.angular_velocity.x = gyro[0];//imu_data.gyro[0];
  imu_msg.angular_velocity.y = gyro[1];//imu_data.gyro[1];
  imu_msg.angular_velocity.z = gyro[2];//imu_data.gyro[2];
//  imu_msg.angular_velocity_covariance[0] = 0.02;
//  imu_msg.angular_velocity_covariance[1] = 0;
//  imu_msg.angular_velocity_covariance[2] = 0;
//  imu_msg.angular_velocity_covariance[3] = 0;
//  imu_msg.angular_velocity_covariance[4] = 0.02;
//  imu_msg.angular_velocity_covariance[5] = 0;
//  imu_msg.angular_velocity_covariance[6] = 0;
//  imu_msg.angular_velocity_covariance[7] = 0;
//  imu_msg.angular_velocity_covariance[8] = 0.02;
  
  imu_msg.linear_acceleration.x = acc[0];//imu_data.accel[0];
  imu_msg.linear_acceleration.y = acc[1];//imu_data.accel[1];
  imu_msg.linear_acceleration.z = acc[2];//imu_data.accel[2];
//  imu_msg.linear_acceleration_covariance[0] = 0.04;
//  imu_msg.linear_acceleration_covariance[1] = 0;
//  imu_msg.linear_acceleration_covariance[2] = 0;
//  imu_msg.linear_acceleration_covariance[3] = 0;
//  imu_msg.linear_acceleration_covariance[4] = 0.04;
//  imu_msg.linear_acceleration_covariance[5] = 0;
//  imu_msg.linear_acceleration_covariance[6] = 0;
//  imu_msg.linear_acceleration_covariance[7] = 0;
//  imu_msg.linear_acceleration_covariance[8] = 0.04;
  
//  imu_msg.orientation.w = 0;//imu_data.quat[0];
//  imu_msg.orientation.x = 0;//imu_data.quat[1];
//  imu_msg.orientation.y = 0;//imu_data.quat[2];
//  imu_msg.orientation.z = 0;//imu_data.quat[3];
//  
//  imu_msg.orientation_covariance[0] = 0.0025;
//  imu_msg.orientation_covariance[1] = 0;
//  imu_msg.orientation_covariance[2] = 0;
//  imu_msg.orientation_covariance[3] = 0;
//  imu_msg.orientation_covariance[4] = 0.0025;
//  imu_msg.orientation_covariance[5] = 0;
//  imu_msg.orientation_covariance[6] = 0;
//  imu_msg.orientation_covariance[7] = 0;
//  imu_msg.orientation_covariance[8] = 0.0025;
  
  imu_pub.publish(&imu_msg);
  
//  tfs_msg.header.stamp    = nh.now();
//    tfs_msg.header.frame_id = "base_link";
//    tfs_msg.child_frame_id  = "imu_link";
//    tfs_msg.transform.rotation.w = 0;//imu.quat[0];
//    tfs_msg.transform.rotation.x = 0;//imu.quat[1];
//    tfs_msg.transform.rotation.y = 0;//imu.quat[2];
//    tfs_msg.transform.rotation.z = 0;//imu.quat[3];

//    tfs_msg.transform.translation.x = 0.0;
//    tfs_msg.transform.translation.y = 0.0;
//    tfs_msg.transform.translation.z = 0.0;

//    tfbroadcaster.sendTransform(tfs_msg);
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  //nh.advertise(imu_pub);
  
}


void loop(void)
{
	
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
	
	str_msg.data = hello;
  chatter.publish(&str_msg);
	
	

//  t = HAL_GetTick();
//  
//  if(t - tTime[0] >= 1000/200)
//  {
//    str_msg.data = hello;
//    chatter.publish(&str_msg);
//    //publishImuMsg();
//    
//    tTime[0] = t;
//  }
	
  nh.spinOnce();
	HAL_Delay(500);
}
