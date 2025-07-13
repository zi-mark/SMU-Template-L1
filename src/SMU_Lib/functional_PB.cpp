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

void Lift_Spin(double v, velocityUnits vu){
    for(int i = 0; i < Lift_Count; i++) {
        Lifts[i].spin(fwd, v, vu);
    }
}

void Lift_Stop(brakeType bt){
    for(int i = 0; i < Lift_Count; i++) {
        Lifts[i].stop(bt);
    }
}

void Lift_SpinTo(double target, double v, velocityUnits vu, bool wait){
    for(int i = 0; i < Lift_Count; i++) {
        Lifts[i].spinTo(target, deg, v, vu, 0);
    }
    if(wait){
        wait = 0;
        while(!wait){
            for(int i = 0; i < Lift_Count; i++) {
                wait *= Lifts[i].isDone();
            }
        }
        Lift_Stop();
    }
}

