#ifndef _ROS_ait_ros_messages_VioSensorMsg_h
#define _ROS_ait_ros_messages_VioSensorMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"
#include "std_msgs/UInt64.h"

namespace ait_ros_messages
{

  class VioSensorMsg : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::Image _left_image_type;
      _left_image_type left_image;
      typedef sensor_msgs::Image _right_image_type;
      _right_image_type right_image;
      uint32_t imu_length;
      typedef sensor_msgs::Imu _imu_type;
      _imu_type st_imu;
      _imu_type * imu;
      typedef std_msgs::UInt64 _seq_type;
      _seq_type seq;

    VioSensorMsg():
      header(),
      left_image(),
      right_image(),
      imu_length(0), imu(NULL),
      seq()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->left_image.serialize(outbuffer + offset);
      offset += this->right_image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->imu_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imu_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->imu_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->imu_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu_length);
      for( uint32_t i = 0; i < imu_length; i++){
      offset += this->imu[i].serialize(outbuffer + offset);
      }
      offset += this->seq.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->left_image.deserialize(inbuffer + offset);
      offset += this->right_image.deserialize(inbuffer + offset);
      uint32_t imu_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      imu_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      imu_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      imu_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->imu_length);
      if(imu_lengthT > imu_length)
        this->imu = (sensor_msgs::Imu*)realloc(this->imu, imu_lengthT * sizeof(sensor_msgs::Imu));
      imu_length = imu_lengthT;
      for( uint32_t i = 0; i < imu_length; i++){
      offset += this->st_imu.deserialize(inbuffer + offset);
        memcpy( &(this->imu[i]), &(this->st_imu), sizeof(sensor_msgs::Imu));
      }
      offset += this->seq.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ait_ros_messages/VioSensorMsg"; };
    const char * getMD5(){ return "a253981cc62e29685765ff67ecbfc577"; };

  };

}
#endif