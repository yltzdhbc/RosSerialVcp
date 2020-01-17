#ifndef _ROS_rocon_interaction_msgs_Interaction_h
#define _ROS_rocon_interaction_msgs_Interaction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"
#include "rocon_std_msgs/Remapping.h"
#include "rocon_interaction_msgs/Pairing.h"

namespace rocon_interaction_msgs
{

  class Interaction : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _compatibility_type;
      _compatibility_type compatibility;
      typedef const char* _display_name_type;
      _display_name_type display_name;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _namespace_type;
      _namespace_type namespace;
      typedef rocon_std_msgs::Icon _icon_type;
      _icon_type icon;
      uint32_t remappings_length;
      typedef rocon_std_msgs::Remapping _remappings_type;
      _remappings_type st_remappings;
      _remappings_type * remappings;
      typedef const char* _parameters_type;
      _parameters_type parameters;
      typedef int32_t _max_type;
      _max_type max;
      typedef rocon_interaction_msgs::Pairing _pairing_type;
      _pairing_type pairing;
      typedef int32_t _hash_type;
      _hash_type hash;
      typedef const char* _role_type;
      _role_type role;
      enum { UNLIMITED_INTERACTIONS =  -1 };

    Interaction():
      name(""),
      compatibility(""),
      display_name(""),
      description(""),
      namespace(""),
      icon(),
      remappings_length(0), remappings(NULL),
      parameters(""),
      max(0),
      pairing(),
      hash(0),
      role("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_compatibility = strlen(this->compatibility);
      varToArr(outbuffer + offset, length_compatibility);
      offset += 4;
      memcpy(outbuffer + offset, this->compatibility, length_compatibility);
      offset += length_compatibility;
      uint32_t length_display_name = strlen(this->display_name);
      varToArr(outbuffer + offset, length_display_name);
      offset += 4;
      memcpy(outbuffer + offset, this->display_name, length_display_name);
      offset += length_display_name;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_namespace = strlen(this->namespace);
      varToArr(outbuffer + offset, length_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->namespace, length_namespace);
      offset += length_namespace;
      offset += this->icon.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->remappings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remappings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remappings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remappings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remappings_length);
      for( uint32_t i = 0; i < remappings_length; i++){
      offset += this->remappings[i].serialize(outbuffer + offset);
      }
      uint32_t length_parameters = strlen(this->parameters);
      varToArr(outbuffer + offset, length_parameters);
      offset += 4;
      memcpy(outbuffer + offset, this->parameters, length_parameters);
      offset += length_parameters;
      union {
        int32_t real;
        uint32_t base;
      } u_max;
      u_max.real = this->max;
      *(outbuffer + offset + 0) = (u_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max);
      offset += this->pairing.serialize(outbuffer + offset);
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
      uint32_t length_role = strlen(this->role);
      varToArr(outbuffer + offset, length_role);
      offset += 4;
      memcpy(outbuffer + offset, this->role, length_role);
      offset += length_role;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_compatibility;
      arrToVar(length_compatibility, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_compatibility; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_compatibility-1]=0;
      this->compatibility = (char *)(inbuffer + offset-1);
      offset += length_compatibility;
      uint32_t length_display_name;
      arrToVar(length_display_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_display_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_display_name-1]=0;
      this->display_name = (char *)(inbuffer + offset-1);
      offset += length_display_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_namespace;
      arrToVar(length_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namespace-1]=0;
      this->namespace = (char *)(inbuffer + offset-1);
      offset += length_namespace;
      offset += this->icon.deserialize(inbuffer + offset);
      uint32_t remappings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      remappings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      remappings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      remappings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->remappings_length);
      if(remappings_lengthT > remappings_length)
        this->remappings = (rocon_std_msgs::Remapping*)realloc(this->remappings, remappings_lengthT * sizeof(rocon_std_msgs::Remapping));
      remappings_length = remappings_lengthT;
      for( uint32_t i = 0; i < remappings_length; i++){
      offset += this->st_remappings.deserialize(inbuffer + offset);
        memcpy( &(this->remappings[i]), &(this->st_remappings), sizeof(rocon_std_msgs::Remapping));
      }
      uint32_t length_parameters;
      arrToVar(length_parameters, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameters-1]=0;
      this->parameters = (char *)(inbuffer + offset-1);
      offset += length_parameters;
      union {
        int32_t real;
        uint32_t base;
      } u_max;
      u_max.base = 0;
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max = u_max.real;
      offset += sizeof(this->max);
      offset += this->pairing.deserialize(inbuffer + offset);
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
      uint32_t length_role;
      arrToVar(length_role, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_role; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_role-1]=0;
      this->role = (char *)(inbuffer + offset-1);
      offset += length_role;
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/Interaction"; };
    const char * getMD5(){ return "a0eeafaab98f6fb56bd4aa7196744ab3"; };

  };

}
#endif