#ifndef CHARGING_DESCRIPTOR
#define CHARGING_DESCRIPTOR
#include "storage_object.h"
#include "analog_input_object.h"

class ChargingDescriptor{

     private:
     bool is_fully_charged(double sensor_voltage, double max_allowable_voltage);

     public:
     ChargingDescriptor();

     StorageObject describe(StorageObject storage_data,  AnalogInputObject sensor_data);
};

#endif 