#ifndef ATREST_DESCRIPTOR
#define ATREST_DESCRIPTOR
#include "storage_object.h"
#include "analog_input_object.h"

class AtRestDescriptor{

     private:

     public:
     AtRestDescriptor();

     StorageObject describe(StorageObject storage_data, AnalogInputObject sensor_data);

};


#endif