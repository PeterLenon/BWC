#ifndef MODE_DESCRIPTOR
#define MODE_DESCRITOR
#include "ModeEnum.h"
#include "storage_object.h"
#include "analog_input_object.h"
#include "atRest.h"
#include "charging.h"
#include "discharging.h"
#include "error.h"

class ModeDescriptor{
     private:
     AtRestDescriptor resting_descriptor;
     ChargingDescriptor charging_desriptor;
     DischargingDescriptor discharging_descriptor;
     ErrorDescriptor error_descriptor;

     Mode determine_mode(AnalogInputObject sensor_data);
     
     public:
     ModeDescriptor();

     StorageObject process(StorageObject storage_data, AnalogInputObject sensor_data);

};

#endif