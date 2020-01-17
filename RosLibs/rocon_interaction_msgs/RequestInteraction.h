#ifndef _ROS_SERVICE_RequestInteraction_h
#define _ROS_SERVICE_RequestInteraction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

static const char REQUESTINTERACTION[] = "rocon_interaction_msgs/RequestInteraction";

  class RequestInteractionRequest : public ros::Msg
  {
    public:
      typedef const char* _remocon_type;
      _remocon_type remocon;
      typedef int32_t _hash_type;
      _hash_type hash;

    RequestInteractionRequest():
      remocon(""),
      hash(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_remocon = strlen(this->remocon);
      varToArr(outbuffer + offset, length_remocon);
      offset += 4;
      memcpy(outbuffer + offset, this->remocon, length_remocon);
      offset += length_remocon;
      union {
        int32_t real;
        uint32_t base;
      } u_hash;
      u_hash.real = this->hash;
      *(outbuffer + offset + 0) = (u_hash.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hash.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hash.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hash.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hash);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_remocon;
      arrToVar(length_remocon, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_remocon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_remocon-1]=0;
      this->remocon = (char *)(inbuffer + offset-1);
      offset += length_remocon;
      union {
        int32_t real;
        uint32_t base;
      } u_hash;
      u_hash.base = 0;
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hash.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hash = u_hash.real;
      offset += sizeof(this->hash);
     return offset;
    }

    const char * getType(){ return REQUESTINTERACTION; };
    const char * getMD5(){ return "0504d90333f890dfa98784397225e84f"; };

  };

  class RequestInteractionResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef int8_t _error_code_type;
      _error_code_type error_code;
      typedef const char* _message_type;
      _message_type message;

    RequestInteractionResponse():
      result(0),
      error_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      union {
        int8_t real;
        uint8_t base;
      } u_error_code;
      u_error_code.real = this->error_code;
      *(outbuffer + offset + 0) = (u_error_code.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      union {
        int8_t real;
        uint8_t base;
      } u_error_code;
      u_error_code.base = 0;
      u_error_code.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->error_code = u_error_code.real;
      offset += sizeof(this->error_code);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return REQUESTINTERACTION; };
    const char * getMD5(){ return "59c96bfec0e66f629d852df5b53676e1"; };

  };

  class RequestInteraction {
    public:
    typedef RequestInteractionRequest Request;
    typedef RequestInteractionResponse Response;
  };

}
#endif
