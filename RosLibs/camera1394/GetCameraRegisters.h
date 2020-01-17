#ifndef _ROS_SERVICE_GetCameraRegisters_h
#define _ROS_SERVICE_GetCameraRegisters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace camera1394
{

static const char GETCAMERAREGISTERS[] = "camera1394/GetCameraRegisters";

  class GetCameraRegistersRequest : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint64_t _offset_type;
      _offset_type offset;
      typedef uint32_t _num_regs_type;
      _num_regs_type num_regs;
      typedef uint32_t _mode_type;
      _mode_type mode;
      enum { TYPE_CONTROL = 0 };
      enum { TYPE_ABSOLUTE = 1 };
      enum { TYPE_FORMAT7 = 2 };
      enum { TYPE_ADVANCED_CONTROL = 3 };
      enum { TYPE_PIO = 4 };
      enum { TYPE_SIO = 5 };
      enum { TYPE_STROBE = 6 };

    GetCameraRegistersRequest():
      type(0),
      offset(0),
      num_regs(0),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        uint64_t real;
        uint32_t base;
      } u_offset;
      u_offset.real = this->offset;
      *(outbuffer + offset + 0) = (u_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      *(outbuffer + offset + 0) = (this->num_regs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_regs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_regs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_regs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_regs);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      union {
        uint64_t real;
        uint32_t base;
      } u_offset;
      u_offset.base = 0;
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset = u_offset.real;
      offset += sizeof(this->offset);
      this->num_regs =  ((uint32_t) (*(inbuffer + offset)));
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_regs);
      this->mode =  ((uint32_t) (*(inbuffer + offset)));
      this->mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return GETCAMERAREGISTERS; };
    const char * getMD5(){ return "3899ed32cc2bf9b6257abe5965b09162"; };

  };

  class GetCameraRegistersResponse : public ros::Msg
  {
    public:
      uint32_t value_length;
      typedef uint32_t _value_type;
      _value_type st_value;
      _value_type * value;

    GetCameraRegistersResponse():
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      *(outbuffer + offset + 0) = (this->value[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (uint32_t*)realloc(this->value, value_lengthT * sizeof(uint32_t));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      this->st_value =  ((uint32_t) (*(inbuffer + offset)));
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return GETCAMERAREGISTERS; };
    const char * getMD5(){ return "4680a08e992f8f11add4bc58e31c78a7"; };

  };

  class GetCameraRegisters {
    public:
    typedef GetCameraRegistersRequest Request;
    typedef GetCameraRegistersResponse Response;
  };

}
#endif
