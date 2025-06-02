#include "initialize.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

void Init(){
    
    GR.calibrate();
    ResetPosition();
    Lift_ResetPosition();
    CLSensor.setLight(ledState::on);
    CLSensor.setLightPower(100);
    #if CSTU == 6
    HookP.set(1);
    HandRR.set(1);
    HandLR.set(1);
    #endif
    // #ifdef CSTU
    // if(ProgramChoice == 1) HandL.set(1);
    // else if(ProgramChoice == 8) HandR.set(1);
    // #endif
    
    while(GR.isCalibrating()) continue;
}