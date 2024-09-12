#include "local_storage.h"
#include <string>
#include <ctime>
#include <chrono>


StorageClient::StorageClient(){
}

StorageObject StorageClient::fetch_data_from_storage(std::string cell_id){
     //fetch data for the provided cell Id from local storage
}

void StorageClient::post_data_to_storage(StorageObject data){
     //post data to localstorage
}

bool StorageClient::has_historical_data(std::string cell_id){
     StorageObject data = fetch_data_from_storage(cell_id);
     if(data.charge_discharged && data.last_time_charge && data.state_of_charge && data.state_of_health){
          return true;
     }
     return false;
}

double StorageClient::fetch_soc(std::string cell_id){
     try
     {
          return fetch_data_from_storage(cell_id).state_of_charge;
     }
     catch(const std::exception& e)
     {
          return NULL;
     }
}

double StorageClient::fetch_soh(std::string cell_id){
     try
     {
          return fetch_data_from_storage(cell_id).state_of_health;
     }
     catch(const std::exception& e){
          return NULL;
     }
}

double StorageClient::fetch_amount_discharged(std::string cell_id){
     try
     {
          return fetch_data_from_storage(cell_id).charge_discharged;
     }
     catch(const std::exception& e){
          return NULL;
     }
}

std::time_t StorageClient::fetch_last_timestamp_charged(std::string cell_id){
     try
     {
          return fetch_data_from_storage(cell_id).last_time_charge;
     }
     catch(const std::exception& e){
          return NULL;
     }
}

