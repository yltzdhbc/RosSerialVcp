#ifndef _ROS_rocon_std_msgs_PlatformInfo_h
#define _ROS_rocon_std_msgs_PlatformInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"

namespace rocon_std_msgs
{

  class PlatformInfo : public ros::Msg
  {
    public:
      typedef const char* _uri_type;
      _uri_type uri;
      typedef const char* _version_type;
      _version_type version;
      typedef rocon_std_msgs::Icon _icon_type;
      _icon_type icon;

    PlatformInfo():
      uri(""),
      version(""),
      icon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uri = strlen(this->uri);
      varToArr(outbuffer + offset, length_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      offset += this->icon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uri;
      arrToVar(length_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      offset += this->icon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/PlatformInfo"; };
    const char * getMD5(){ return "ffe7bd3c68cda016b708f36a9d12b09e"; };

  };

}
#endif