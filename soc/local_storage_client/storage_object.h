#ifndef STORAGE_OBJECT
#define STORAGE_OBJECT
#include <ctime>
#include <chrono>
#include <string>

struct StorageObject{
     double state_of_health;
     double state_of_charge;
     std::time_t last_time_charge;
     std::string cell_id;
     double charge_discharged;
     
     double max_voltage;
     double max_allowable_charge;

     double min_voltage;
     double max_rated_charge;

     StorageObject(){
          state_of_health = NULL;
          state_of_charge = NULL;
          last_time_charge = NULL;
          cell_id = "";
          charge_discharged = NULL;
          
          max_voltage = NULL;
          max_allowable_charge = NULL;

          min_voltage = NULL;
          max_rated_charge = NULL;
     }
};

#endif
