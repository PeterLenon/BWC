#include "charging.h"
#include <ctime>
#include <cmath>

ChargingDescriptor::ChargingDescriptor(){}

bool ChargingDescriptor::is_fully_charged(double sensor_voltage, double max_allowable_voltage){
     return sensor_voltage >= max_allowable_voltage;
}

StorageObject ChargingDescriptor::describe(StorageObject storage_data, AnalogInputObject sensor_data){
     StorageObject processed_data = storage_data;

     processed_data.last_time_charge = time(nullptr);
     double delta_time = difftime(processed_data.last_time_charge, storage_data.last_time_charge);
     double delta_charge = sensor_data.current * delta_time;

     processed_data.charge_discharged = storage_data.charge_discharged + delta_charge;
     double soc = storage_data.state_of_charge + 100 * pow(storage_data.max_allowable_charge, -1) * delta_charge;
     processed_data.state_of_charge = soc;

     bool fully_charged = is_fully_charged(sensor_data.voltage, storage_data.max_voltage);
     if(fully_charged){
          processed_data.max_voltage = sensor_data.voltage;
          processed_data.max_allowable_charge = abs(processed_data.charge_discharged);
          processed_data.state_of_health = abs(processed_data.max_allowable_charge/processed_data.max_rated_charge);
          processed_data.charge_discharged = 0;
          processed_data.state_of_charge = 100;
     }
     return processed_data;  
}

