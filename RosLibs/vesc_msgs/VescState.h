#ifndef _ROS_vesc_msgs_VescState_h
#define _ROS_vesc_msgs_VescState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vesc_msgs
{

  class VescState : public ros::Msg
  {
    public:
      typedef float _voltage_input_type;
      _voltage_input_type voltage_input;
      typedef float _temperature_pcb_type;
      _temperature_pcb_type temperature_pcb;
      typedef float _current_motor_type;
      _current_motor_type current_motor;
      typedef float _current_input_type;
      _current_input_type current_input;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _duty_cycle_type;
      _duty_cycle_type duty_cycle;
      typedef float _charge_drawn_type;
      _charge_drawn_type charge_drawn;
      typedef float _charge_regen_type;
      _charge_regen_type charge_regen;
      typedef float _energy_drawn_type;
      _energy_drawn_type energy_drawn;
      typedef float _energy_regen_type;
      _energy_regen_type energy_regen;
      typedef float _displacement_type;
      _displacement_type displacement;
      typedef float _distance_traveled_type;
      _distance_traveled_type distance_traveled;
      typedef int32_t _fault_code_type;
      _fault_code_type fault_code;
      enum { FAULT_CODE_NONE = 0 };
      enum { FAULT_CODE_OVER_VOLTAGE = 1 };
      enum { FAULT_CODE_UNDER_VOLTAGE = 2 };
      enum { FAULT_CODE_DRV8302 = 3 };
      enum { FAULT_CODE_ABS_OVER_CURRENT = 4 };
      enum { FAULT_CODE_OVER_TEMP_FET = 5 };
      enum { FAULT_CODE_OVER_TEMP_MOTOR = 6 };

    VescState():
      voltage_input(0),
      temperature_pcb(0),
      current_motor(0),
      current_input(0),
      speed(0),
      duty_cycle(0),
      charge_drawn(0),
      charge_regen(0),
      energy_drawn(0),
      energy_regen(0),
      displacement(0),
      distance_traveled(0),
      fault_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage_input);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature_pcb);
      offset += serializeAvrFloat64(outbuffer + offset, this->current_motor);
      offset += serializeAvrFloat64(outbuffer + offset, this->current_input);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->duty_cycle);
      offset += serializeAvrFloat64(outbuffer + offset, this->charge_drawn);
      offset += serializeAvrFloat64(outbuffer + offset, this->charge_regen);
      offset += serializeAvrFloat64(outbuffer + offset, this->energy_drawn);
      offset += serializeAvrFloat64(outbuffer + offset, this->energy_regen);
      offset += serializeAvrFloat64(outbuffer + offset, this->displacement);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_traveled);
      union {
        int32_t real;
        uint32_t base;
      } u_fault_code;
      u_fault_code.real = this->fault_code;
      *(outbuffer + offset + 0) = (u_fault_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fault_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fault_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fault_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fault_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage_input));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature_pcb));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_motor));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_input));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->duty_cycle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->charge_drawn));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->charge_regen));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->energy_drawn));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->energy_regen));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->displacement));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_traveled));
      union {
        int32_t real;
        uint32_t base;
      } u_fault_code;
      u_fault_code.base = 0;
      u_fault_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fault_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fault_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fault_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fault_code = u_fault_code.real;
      offset += sizeof(this->fault_code);
     return offset;
    }

    const char * getType(){ return "vesc_msgs/VescState"; };
    const char * getMD5(){ return "81214bb4c1945e7c159bd76ec397ac04"; };

  };

}
#endif