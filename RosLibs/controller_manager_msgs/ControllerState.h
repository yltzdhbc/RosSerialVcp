#ifndef _ROS_controller_manager_msgs_ControllerState_h
#define _ROS_controller_manager_msgs_ControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace controller_manager_msgs
{

  class ControllerState : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _type_type;
      _type_type type;
      typedef const char* _hardware_interface_type;
      _hardware_interface_type hardware_interface;
      uint32_t resources_length;
      typedef char* _resources_type;
      _resources_type st_resources;
      _resources_type * resources;

    ControllerState():
      name(""),
      state(""),
      type(""),
      hardware_interface(""),
      resources_length(0), resources(NULL)
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
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      uint32_t length_hardware_interface = strlen(this->hardware_interface);
      varToArr(outbuffer + offset, length_hardware_interface);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_interface, length_hardware_interface);
      offset += length_hardware_interface;
      *(outbuffer + offset + 0) = (this->resources_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resources_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->resources_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->resources_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resources_length);
      for( uint32_t i = 0; i < resources_length; i++){
      uint32_t length_resourcesi = strlen(this->resources[i]);
      varToArr(outbuffer + offset, length_resourcesi);
      offset += 4;
      memcpy(outbuffer + offset, this->resources[i], length_resourcesi);
      offset += length_resourcesi;
      }
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
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t length_hardware_interface;
      arrToVar(length_hardware_interface, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_interface; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_interface-1]=0;
      this->hardware_interface = (char *)(inbuffer + offset-1);
      offset += length_hardware_interface;
      uint32_t resources_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      resources_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->resources_length);
      if(resources_lengthT > resources_length)
        this->resources = (char**)realloc(this->resources, resources_lengthT * sizeof(char*));
      resources_length = resources_lengthT;
      for( uint32_t i = 0; i < resources_length; i++){
      uint32_t length_st_resources;
      arrToVar(length_st_resources, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_resources; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_resources-1]=0;
      this->st_resources = (char *)(inbuffer + offset-1);
      offset += length_st_resources;
        memcpy( &(this->resources[i]), &(this->st_resources), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "controller_manager_msgs/ControllerState"; };
    const char * getMD5(){ return "cac963cc68f4f5836765c108de0fc446"; };

  };

}
#endif