#ifndef ERROR_DESCRIPTOR
#define ERROR_DESCRIPTOR
#include "storage_object.h"
#include "analog_input_object.h"

class ErrorDescriptor{
     private:

     public:
     ErrorDescriptor();

     StorageObject describe(StorageObject storage_data, AnalogInputObject sensor_data);
};

#endif