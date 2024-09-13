## Directories

### analog_input_handler
- this module handles gathering data from the hardware and package it in format that the entire SOC module can process

### local_storage_client
- this module fetches and posts cell data from/to storage

### mode_descriptor
- this module processes data to calculate various things to calculate SOC mode wise i.e charging mode, atRest mode and discharging mode;

### sox_processor
- this file orchestrates all the various components to perform SOC estimations using the Coulomb Counting method