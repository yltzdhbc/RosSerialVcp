#ifndef _ROS_SERVICE_SetPidGains_h
#define _ROS_SERVICE_SetPidGains_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_toolbox
{

static const char SETPIDGAINS[] = "control_toolbox/SetPidGains";

  class SetPidGainsRequest : public ros::Msg
  {
    public:
      typedef float _p_type;
      _p_type p;
      typedef float _i_type;
      _i_type i;
      typedef float _d_type;
      _d_type d;
      typedef float _i_clamp_type;
      _i_clamp_type i_clamp;

    SetPidGainsRequest():
      p(0),
      i(0),
      d(0),
      i_clamp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->p);
      offset += serializeAvrFloat64(outbuffer + offset, this->i);
      offset += serializeAvrFloat64(outbuffer + offset, this->d);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_clamp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_clamp));
     return offset;
    }

    const char * getType(){ return SETPIDGAINS; };
    const char * getMD5(){ return "b06494a6fc3d5b972ded4e2a9a71535a"; };

  };

  class SetPidGainsResponse : public ros::Msg
  {
    public:

    SetPidGainsResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETPIDGAINS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPidGains {
    public:
    typedef SetPidGainsRequest Request;
    typedef SetPidGainsResponse Response;
  };

}
#endif
