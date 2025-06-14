#include "SMU_Lib/functional.h"
#include "definer.h"
#include "robot-config.h"

void Suck_Spin(double v, vex::velocityUnits vu){
    for(int i = 0; i < Suck_Count; i++){
        Sucks[i].spin(fwd, v, vu);
    }
}

void Suck_Stop(brakeType bt){
    for(int i = 0; i < Suck_Count; i++){
        Sucks[i].stop(bt);
    }
}

