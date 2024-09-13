#ifndef SOC_COMMAND_HANDLER
#define SOC_COMMAND_HANDLER

#include <iostream>
#include "analog_input_handler.h"
#include "local_storage.h"
#include "mode_descriptor.h"

class Sox_processor{
     private:
     AnalogInputHandler sensor_input_api;
     StorageClient storage_client;
     ModeDescriptor sox_processor;

     public:
     Sox_processor();
     int process();
};

#endif