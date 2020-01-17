#ifndef _ROS_SERVICE_TrackFeatures_h
#define _ROS_SERVICE_TrackFeatures_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace klt_feature_tracker
{

static const char TRACKFEATURES[] = "klt_feature_tracker/TrackFeatures";

  class TrackFeaturesRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _left_image_type;
      _left_image_type left_image;
      typedef sensor_msgs::Image _right_image_type;
      _right_image_type right_image;
      uint32_t update_vect_length;
      typedef int32_t _update_vect_type;
      _update_vect_type st_update_vect;
      _update_vect_type * update_vect;
      typedef int32_t _stereo_type;
      _stereo_type stereo;

    TrackFeaturesRequest():
      left_image(),
      right_image(),
      update_vect_length(0), update_vect(NULL),
      stereo(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->left_image.serialize(outbuffer + offset);
      offset += this->right_image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->update_vect_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_vect_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_vect_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_vect_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_vect_length);
      for( uint32_t i = 0; i < update_vect_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_update_vecti;
      u_update_vecti.real = this->update_vect[i];
      *(outbuffer + offset + 0) = (u_update_vecti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_update_vecti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_update_vecti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_update_vecti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_vect[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_stereo;
      u_stereo.real = this->stereo;
      *(outbuffer + offset + 0) = (u_stereo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stereo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stereo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stereo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stereo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->left_image.deserialize(inbuffer + offset);
      offset += this->right_image.deserialize(inbuffer + offset);
      uint32_t update_vect_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->update_vect_length);
      if(update_vect_lengthT > update_vect_length)
        this->update_vect = (int32_t*)realloc(this->update_vect, update_vect_lengthT * sizeof(int32_t));
      update_vect_length = update_vect_lengthT;
      for( uint32_t i = 0; i < update_vect_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_update_vect;
      u_st_update_vect.base = 0;
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_update_vect = u_st_update_vect.real;
      offset += sizeof(this->st_update_vect);
        memcpy( &(this->update_vect[i]), &(this->st_update_vect), sizeof(int32_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_stereo;
      u_stereo.base = 0;
      u_stereo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stereo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stereo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stereo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stereo = u_stereo.real;
      offset += sizeof(this->stereo);
     return offset;
    }

    const char * getType(){ return TRACKFEATURES; };
    const char * getMD5(){ return "e6ba594a5fc048bf5a4498bc48e6665e"; };

  };

  class TrackFeaturesResponse : public ros::Msg
  {
    public:
      uint32_t update_vect_length;
      typedef int32_t _update_vect_type;
      _update_vect_type st_update_vect;
      _update_vect_type * update_vect;
      uint32_t features_l_length;
      typedef float _features_l_type;
      _features_l_type st_features_l;
      _features_l_type * features_l;
      uint32_t features_r_length;
      typedef float _features_r_type;
      _features_r_type st_features_r;
      _features_r_type * features_r;

    TrackFeaturesResponse():
      update_vect_length(0), update_vect(NULL),
      features_l_length(0), features_l(NULL),
      features_r_length(0), features_r(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->update_vect_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->update_vect_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->update_vect_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->update_vect_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_vect_length);
      for( uint32_t i = 0; i < update_vect_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_update_vecti;
      u_update_vecti.real = this->update_vect[i];
      *(outbuffer + offset + 0) = (u_update_vecti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_update_vecti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_update_vecti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_update_vecti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_vect[i]);
      }
      *(outbuffer + offset + 0) = (this->features_l_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->features_l_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->features_l_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->features_l_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->features_l_length);
      for( uint32_t i = 0; i < features_l_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->features_l[i]);
      }
      *(outbuffer + offset + 0) = (this->features_r_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->features_r_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->features_r_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->features_r_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->features_r_length);
      for( uint32_t i = 0; i < features_r_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->features_r[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t update_vect_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      update_vect_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->update_vect_length);
      if(update_vect_lengthT > update_vect_length)
        this->update_vect = (int32_t*)realloc(this->update_vect, update_vect_lengthT * sizeof(int32_t));
      update_vect_length = update_vect_lengthT;
      for( uint32_t i = 0; i < update_vect_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_update_vect;
      u_st_update_vect.base = 0;
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_update_vect.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_update_vect = u_st_update_vect.real;
      offset += sizeof(this->st_update_vect);
        memcpy( &(this->update_vect[i]), &(this->st_update_vect), sizeof(int32_t));
      }
      uint32_t features_l_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      features_l_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      features_l_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      features_l_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->features_l_length);
      if(features_l_lengthT > features_l_length)
        this->features_l = (float*)realloc(this->features_l, features_l_lengthT * sizeof(float));
      features_l_length = features_l_lengthT;
      for( uint32_t i = 0; i < features_l_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_features_l));
        memcpy( &(this->features_l[i]), &(this->st_features_l), sizeof(float));
      }
      uint32_t features_r_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      features_r_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      features_r_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      features_r_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->features_r_length);
      if(features_r_lengthT > features_r_length)
        this->features_r = (float*)realloc(this->features_r, features_r_lengthT * sizeof(float));
      features_r_length = features_r_lengthT;
      for( uint32_t i = 0; i < features_r_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_features_r));
        memcpy( &(this->features_r[i]), &(this->st_features_r), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return TRACKFEATURES; };
    const char * getMD5(){ return "b2c0cf55e2ad9e563c111a72cc01130a"; };

  };

  class TrackFeatures {
    public:
    typedef TrackFeaturesRequest Request;
    typedef TrackFeaturesResponse Response;
  };

}
#endif
