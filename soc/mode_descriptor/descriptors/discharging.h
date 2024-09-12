#ifndef DISCHARGING_DESCRIPTOR
#define DISCHARGING_DESCRIPTOR
#include "storage_object.h"
#include "analog_input_object.h"

class DischargingDescriptor{
     private:
     bool is_fully_discharged(double sensor_voltage, double min_rated_voltage);

     public:
     DischargingDescriptor();

     StorageObject describe(StorageObject storage_data, AnalogInputObject sensor_data);
};

#endif 