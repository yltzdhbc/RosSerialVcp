#ifndef _ROS_viso2_ros_VisoInfo_h
#define _ROS_viso2_ros_VisoInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace viso2_ros
{

  class VisoInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _got_lost_type;
      _got_lost_type got_lost;
      typedef bool _change_reference_frame_type;
      _change_reference_frame_type change_reference_frame;
      typedef bool _motion_estimate_valid_type;
      _motion_estimate_valid_type motion_estimate_valid;
      typedef int32_t _num_matches_type;
      _num_matches_type num_matches;
      typedef int32_t _num_inliers_type;
      _num_inliers_type num_inliers;
      typedef float _runtime_type;
      _runtime_type runtime;

    VisoInfo():
      header(),
      got_lost(0),
      change_reference_frame(0),
      motion_estimate_valid(0),
      num_matches(0),
      num_inliers(0),
      runtime(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_got_lost;
      u_got_lost.real = this->got_lost;
      *(outbuffer + offset + 0) = (u_got_lost.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->got_lost);
      union {
        bool real;
        uint8_t base;
      } u_change_reference_frame;
      u_change_reference_frame.real = this->change_reference_frame;
      *(outbuffer + offset + 0) = (u_change_reference_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->change_reference_frame);
      union {
        bool real;
        uint8_t base;
      } u_motion_estimate_valid;
      u_motion_estimate_valid.real = this->motion_estimate_valid;
      *(outbuffer + offset + 0) = (u_motion_estimate_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motion_estimate_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_num_matches;
      u_num_matches.real = this->num_matches;
      *(outbuffer + offset + 0) = (u_num_matches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_matches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_matches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_matches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_matches);
      union {
        int32_t real;
        uint32_t base;
      } u_num_inliers;
      u_num_inliers.real = this->num_inliers;
      *(outbuffer + offset + 0) = (u_num_inliers.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_inliers.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_inliers.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_inliers.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_inliers);
      offset += serializeAvrFloat64(outbuffer + offset, this->runtime);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_got_lost;
      u_got_lost.base = 0;
      u_got_lost.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->got_lost = u_got_lost.real;
      offset += sizeof(this->got_lost);
      union {
        bool real;
        uint8_t base;
      } u_change_reference_frame;
      u_change_reference_frame.base = 0;
      u_change_reference_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->change_reference_frame = u_change_reference_frame.real;
      offset += sizeof(this->change_reference_frame);
      union {
        bool real;
        uint8_t base;
      } u_motion_estimate_valid;
      u_motion_estimate_valid.base = 0;
      u_motion_estimate_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motion_estimate_valid = u_motion_estimate_valid.real;
      offset += sizeof(this->motion_estimate_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_num_matches;
      u_num_matches.base = 0;
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_matches = u_num_matches.real;
      offset += sizeof(this->num_matches);
      union {
        int32_t real;
        uint32_t base;
      } u_num_inliers;
      u_num_inliers.base = 0;
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_inliers = u_num_inliers.real;
      offset += sizeof(this->num_inliers);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->runtime));
     return offset;
    }

    const char * getType(){ return "viso2_ros/VisoInfo"; };
    const char * getMD5(){ return "765500d8b83bf74f7715c6e2e8e89092"; };

  };

}
#endif