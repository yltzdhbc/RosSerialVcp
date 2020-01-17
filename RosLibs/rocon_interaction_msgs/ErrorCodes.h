#ifndef _ROS_rocon_interaction_msgs_ErrorCodes_h
#define _ROS_rocon_interaction_msgs_ErrorCodes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

  class ErrorCodes : public ros::Msg
  {
    public:
      enum { SUCCESS =  0 };
      enum { INTERACTION_UNAVAILABLE =  20     };
      enum { INTERACTION_QUOTA_REACHED =  21   };
      enum { START_PAIRED_RAPP_FAILED =  31    };
      enum { ALREADY_PAIRING =  32    };
      enum { MSG_INTERACTION_UNAVAILABLE =  "This role-app pair is not available for use." };
      enum { MSG_INTERACTION_QUOTA_REACHED =  "More connections of this type not permitted." };
      enum { MSG_START_PAIRED_RAPP_FAILED =  "Failed to start the paired rapp." };
      enum { MSG_ALREADY_PAIRING =  "Already pairing, cannot start another pairing." };

    ErrorCodes()
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

    const char * getType(){ return "rocon_interaction_msgs/ErrorCodes"; };
    const char * getMD5(){ return "5137814d1764e0f595e2a0aeb307c101"; };

  };

}
#endif