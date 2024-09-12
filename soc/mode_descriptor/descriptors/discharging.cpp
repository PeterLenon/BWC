#include "discharging.h"
#include <ctime>
#include <cmath>

DischargingDescriptor::DischargingDescriptor(){}

bool DischargingDescriptor::is_fully_discharged(double sensor_voltage, double min_rated_voltage){
     return sensor_voltage <= 1.01 * min_rated_voltage;
}

StorageObject DischargingDescriptor::describe(StorageObject storage_data, AnalogInputObject sensor_data){
     StorageObject processed_data = storage_data;
     
     processed_data.last_time_charge = time(nullptr);
     double delta_time = difftime(processed_data.last_time_charge, storage_data.last_time_charge);
     double delta_charge = sensor_data.current * delta_time;
     
     processed_data.charge_discharged = storage_data.charge_discharged + delta_charge;
     double soc = storage_data.state_of_charge + 100 * pow(storage_data.max_allowable_charge, -1) * delta_charge;
     processed_data.state_of_charge = soc;

     bool fully_discharged = is_fully_discharged(sensor_data.voltage, storage_data.min_voltage);
     if(fully_discharged){
          processed_data.max_allowable_charge = abs(processed_data.charge_discharged);
          processed_data.state_of_health = abs(processed_data.max_allowable_charge/processed_data.max_rated_charge);
          processed_data.charge_discharged = 0;
          processed_data.state_of_charge = 0;
     }
     return processed_data;
}