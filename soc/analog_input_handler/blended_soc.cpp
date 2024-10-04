#include "blended_soc.h"
#include <algorithm>
#include "local_storage.h"
#include <cmath>

UserDisplayedSOC::UserDisplayedSOC(){};

double UserDisplayedSOC::get_blended_soc(){
     double MaxCellSOC = this->storageClient.fetch_highestSOC();
     double MinCellSOC = this->storageClient.fetch_lowestSOC();
     const double SOCMaxLimit = 100;
     const double SOCMinLimit = 0;

     double MidPoint = (MaxCellSOC + MinCellSOC) / 2.0;
    double UpperMid = SOCMaxLimit - ((MaxCellSOC - MinCellSOC) / 2.0);
    double LowerMid = SOCMinLimit + ((MaxCellSOC - MinCellSOC) / 2.0);

    double LowWeightNum = UpperMid - MidPoint;
    double LowWeightDen = std::max((UpperMid - LowerMid), 1e-6);

    double LowWeight = LowWeightNum / LowWeightDen;

    if (LowWeight < 0.0) {
        LowWeight = 0.0;
    } else if (LowWeight > 1.0) {
        LowWeight = 1.0;
    }

    double HighWeight = 1.0 - LowWeight;

    double BlendedValue = HighWeight * MaxCellSOC + LowWeight * MinCellSOC;

    return BlendedValue;

}