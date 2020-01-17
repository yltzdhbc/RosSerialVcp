#ifndef _ROS_SERVICE_GetRoles_h
#define _ROS_SERVICE_GetRoles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

static const char GETROLES[] = "rocon_interaction_msgs/GetRoles";

  class GetRolesRequest : public ros::Msg
  {
    public:
      typedef const char* _uri_type;
      _uri_type uri;

    GetRolesRequest():
      uri("")
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
     return offset;
    }

    const char * getType(){ return GETROLES; };
    const char * getMD5(){ return "636fe5e07550f026d28388e95c38a9f4"; };

  };

  class GetRolesResponse : public ros::Msg
  {
    public:
      uint32_t roles_length;
      typedef char* _roles_type;
      _roles_type st_roles;
      _roles_type * roles;

    GetRolesResponse():
      roles_length(0), roles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->roles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->roles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->roles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->roles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roles_length);
      for( uint32_t i = 0; i < roles_length; i++){
      uint32_t length_rolesi = strlen(this->roles[i]);
      varToArr(outbuffer + offset, length_rolesi);
      offset += 4;
      memcpy(outbuffer + offset, this->roles[i], length_rolesi);
      offset += length_rolesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t roles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      roles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      roles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      roles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->roles_length);
      if(roles_lengthT > roles_length)
        this->roles = (char**)realloc(this->roles, roles_lengthT * sizeof(char*));
      roles_length = roles_lengthT;
      for( uint32_t i = 0; i < roles_length; i++){
      uint32_t length_st_roles;
      arrToVar(length_st_roles, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_roles; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_roles-1]=0;
      this->st_roles = (char *)(inbuffer + offset-1);
      offset += length_st_roles;
        memcpy( &(this->roles[i]), &(this->st_roles), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETROLES; };
    const char * getMD5(){ return "ce55e2e9282b0c3ff724b153ff848a8a"; };

  };

  class GetRoles {
    public:
    typedef GetRolesRequest Request;
    typedef GetRolesResponse Response;
  };

}
#endif
