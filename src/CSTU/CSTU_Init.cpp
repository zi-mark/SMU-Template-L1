#include "initialize.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

void Init(){
    
    GR.calibrate();
    ResetPosition();
    
    while(GR.isCalibrating()) continue;
}