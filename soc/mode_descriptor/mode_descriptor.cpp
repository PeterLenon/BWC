#include "mode_descriptor.h"
#include "ModeEnum.h"
#include "atRest.h"

enum class Mode{
     atRest = 0,
     Charge= 1,
     Discharge = 2,
     Error = 3
};

ModeDescriptor::ModeDescriptor(){
}

Mode ModeDescriptor::determine_mode(AnalogInputObject sensor_data){
     Mode battery_mode;
     try{
          if(sensor_data.current == 0){
               battery_mode = Mode::atRest;
          }else if(sensor_data.current > 0){
               battery_mode =  Mode::Charge;
          }else if(sensor_data.current < 0){
               battery_mode = Mode::Discharge;
          }
     }catch(std::exception &e){
          battery_mode = Mode::Error;
     }
     return battery_mode;
}

StorageObject ModeDescriptor::process(StorageObject storage_data, AnalogInputObject sensor_data){
     Mode battery_mode = determine_mode(sensor_data);
     switch (battery_mode)
     {
     case Mode::atRest:
          return resting_descriptor.describe(storage_data, sensor_data);
          break;
     
     case Mode::Charge:
          return charging_desriptor.describe(storage_data, sensor_data);
          break;
     
     case Mode::Discharge:
          return discharging_descriptor.describe(storage_data, sensor_data);
          break;
     
     case Mode::Error:
          return error_descriptor.describe(storage_data, sensor_data);
          break;

     default:
          return error_descriptor.describe(storage_data, sensor_data);
          break;
     }
}