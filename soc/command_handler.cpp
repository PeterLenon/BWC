#include <iostream>
#include "analog_input_handler.h"
#include "local_storage.h"
#include "mode_descriptor.h"

int main(void){
     AnalogInputHandler sensor_input_api;
     StorageClient storage_client;
     ModeDescriptor sox_processor;

     AnalogInputObject sensor_data = sensor_input_api.fetch_inputs();
     std::string cell_id = sensor_data.cell_id;
     StorageObject storage_data = storage_client.fetch_data_from_storage(cell_id);
     StorageObject processed_data = sox_processor.process(storage_data, sensor_data);

     storage_client.post_data_to_storage(processed_data);
     return 0;
}