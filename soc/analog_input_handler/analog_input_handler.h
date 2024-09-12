#ifndef ANALOG_INPUT_HANDLER
#define ANALOG_INPUT_HANDLER
#include "analog_input_object.h"

class AnalogInputHandler{
     private:
     void mount_external_inputs();

     double fetch_voltage();

     double fetch_current();

     double fetch_temperature();

     public:
     AnalogInputHandler();

     AnalogInputObject fetch_inputs();
};

#endif