#include "sox_processor.h"

Sox_processor::Sox_processor(){};

int Sox_processor::process(){
     try{
          AnalogInputObject sensor_data = sensor_input_api.fetch_inputs();
          std::string cell_id = sensor_data.cell_id;
          StorageObject storage_data = storage_client.fetch_data_from_storage(cell_id);
          StorageObject processed_data = sox_processor.process(storage_data, sensor_data);
          storage_client.post_data_to_storage(processed_data);
          return 0;
     }catch(std::system_error &e){
          return e.code().value();
     }catch(std::exception &e){
          return -1;
     }
};
