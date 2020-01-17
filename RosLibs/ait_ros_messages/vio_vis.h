#ifndef _ROS_ait_ros_messages_vio_vis_h
#define _ROS_ait_ros_messages_vio_vis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseArray.h"
#include "std_msgs/Float32MultiArray.h"

namespace ait_ros_messages
{

  class vio_vis : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef geometry_msgs::Pose _robot_pose_type;
      _robot_pose_type robot_pose;
      typedef geometry_msgs::PoseArray _anchor_poses_type;
      _anchor_poses_type anchor_poses;
      typedef std_msgs::Float32MultiArray _map_type;
      _map_type map;
      typedef std_msgs::Float32MultiArray _status_vect_type;
      _status_vect_type status_vect;
      typedef std_msgs::Float32MultiArray _feature_tracks_type;
      _feature_tracks_type feature_tracks;
      typedef std_msgs::Float32MultiArray _pred_feature_tracks_type;
      _pred_feature_tracks_type pred_feature_tracks;
      typedef std_msgs::Float32MultiArray _gyro_bias_type;
      _gyro_bias_type gyro_bias;
      typedef std_msgs::Float32MultiArray _acc_bias_type;
      _acc_bias_type acc_bias;

    vio_vis():
      image(),
      robot_pose(),
      anchor_poses(),
      map(),
      status_vect(),
      feature_tracks(),
      pred_feature_tracks(),
      gyro_bias(),
      acc_bias()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->robot_pose.serialize(outbuffer + offset);
      offset += this->anchor_poses.serialize(outbuffer + offset);
      offset += this->map.serialize(outbuffer + offset);
      offset += this->status_vect.serialize(outbuffer + offset);
      offset += this->feature_tracks.serialize(outbuffer + offset);
      offset += this->pred_feature_tracks.serialize(outbuffer + offset);
      offset += this->gyro_bias.serialize(outbuffer + offset);
      offset += this->acc_bias.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->robot_pose.deserialize(inbuffer + offset);
      offset += this->anchor_poses.deserialize(inbuffer + offset);
      offset += this->map.deserialize(inbuffer + offset);
      offset += this->status_vect.deserialize(inbuffer + offset);
      offset += this->feature_tracks.deserialize(inbuffer + offset);
      offset += this->pred_feature_tracks.deserialize(inbuffer + offset);
      offset += this->gyro_bias.deserialize(inbuffer + offset);
      offset += this->acc_bias.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ait_ros_messages/vio_vis"; };
    const char * getMD5(){ return "36177acc0f2fa1696c82a496d9a3f65c"; };

  };

}
#endif