#include "analog_input_handler.h"

AnalogInputHandler::AnalogInputHandler(){
     AnalogInputHandler::mount_external_inputs();
};

AnalogInputObject AnalogInputHandler::fetch_inputs(){
     AnalogInputObject data;
     data.current = AnalogInputHandler::fetch_current();
     data.voltage = AnalogInputHandler::fetch_voltage();
     data.temperature = AnalogInputHandler::fetch_current();
     return data;
};

double AnalogInputHandler::fetch_current(){};

double AnalogInputHandler::fetch_voltage(){};

double AnalogInputHandler::fetch_temperature(){};