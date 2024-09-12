#ifndef LOCAL_STORAGE
#define LOCAL_STORAGE
#include <string>
#include <ctime>
#include <chrono>
#include "storage_object.h"

class StorageClient{
     private:
     StorageObject fetch_data_from_storage(std::string cell_id);

     public:
     StorageClient();

     bool has_historical_data(std::string cell_id);

     double fetch_soh(std::string cell_id);

     double fetch_soc(std::string cell_id);

     double fetch_amount_discharged(std::string cell_id);

     std::time_t fetch_last_timestamp_charged(std::string cell_id);

     void post_data_to_storage(StorageObject data);

     ~StorageClient(){}

};

#endif




