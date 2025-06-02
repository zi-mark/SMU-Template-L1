#include "initialize.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

#ifdef Temp
    #if Temp == 1
    void Init(){
        
        GR.calibrate();
        ResetPosition();
        
        while(GR.isCalibrating()) continue;
    }
    #else 
    void Init(){

        GR.calibrate();
        ResetPosition();

        while(GR.isCalibrating()) continue;
    }
    #endif
#endif