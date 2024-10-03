#ifndef BLENDED_SOC
#define BLENDED_SOC
#include "local_storage.h"

class UserDisplayedSOC{
     private:
     StorageClient storageClient;

     public:
     UserDisplayedSOC();
     double get_blended_soc();
};

#endif