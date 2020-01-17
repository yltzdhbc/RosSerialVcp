#ifndef _ROS_SERVICE_GetInteractions_h
#define _ROS_SERVICE_GetInteractions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_interaction_msgs/Interaction.h"

namespace rocon_interaction_msgs
{

static const char GETINTERACTIONS[] = "rocon_interaction_msgs/GetInteractions";

  class GetInteractionsRequest : public ros::Msg
  {
    public:
      uint32_t roles_length;
      typedef char* _roles_type;
      _roles_type st_roles;
      _roles_type * roles;
      typedef const char* _uri_type;
      _uri_type uri;

    GetInteractionsRequest():
      roles_length(0), roles(NULL),
      uri("")
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

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "7729678b2d98f5eb8e7358aaf9d23bcb"; };

  };

  class GetInteractionsResponse : public ros::Msg
  {
    public:
      uint32_t interactions_length;
      typedef rocon_interaction_msgs::Interaction _interactions_type;
      _interactions_type st_interactions;
      _interactions_type * interactions;

    GetInteractionsResponse():
      interactions_length(0), interactions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->interactions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->interactions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->interactions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->interactions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interactions_length);
      for( uint32_t i = 0; i < interactions_length; i++){
      offset += this->interactions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t interactions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      interactions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      interactions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      interactions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->interactions_length);
      if(interactions_lengthT > interactions_length)
        this->interactions = (rocon_interaction_msgs::Interaction*)realloc(this->interactions, interactions_lengthT * sizeof(rocon_interaction_msgs::Interaction));
      interactions_length = interactions_lengthT;
      for( uint32_t i = 0; i < interactions_length; i++){
      offset += this->st_interactions.deserialize(inbuffer + offset);
        memcpy( &(this->interactions[i]), &(this->st_interactions), sizeof(rocon_interaction_msgs::Interaction));
      }
     return offset;
    }

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "b53200c67a1f2b4ced2b8771b7d14a13"; };

  };

  class GetInteractions {
    public:
    typedef GetInteractionsRequest Request;
    typedef GetInteractionsResponse Response;
  };

}
#endif
