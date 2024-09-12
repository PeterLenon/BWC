#ifndef ANALOG_OBJECT
#define ANALOG_OBJECT
#include <string>

struct AnalogInputObject{
     std::string cell_id;
     double voltage;
     double current;
     double temperature;
};

#endif