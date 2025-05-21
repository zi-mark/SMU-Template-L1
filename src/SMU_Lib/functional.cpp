#include "SMU_Lib/functional.h"
#include "initialize.h"

void Break(){
    if(!Com.isFieldControl() && !Com.isCompetitionSwitch()){
    while(!Con.ButtonA.pressing()) continue;
    }
}

void LiftSpinToEnd(double v = 90){
    // Lift.spin(fwd, v, pct);
    // while(fabs(Lift.velocity(pct)) >= fabs(v/10)) continue;
    // Lift.stop(hold);
    // Lift.resetPosition();
}

void WaitToHook(int t){
    task::sleep(t);
    Hook.set(1);
}

void Suck_Spin(double v, velocityUnits vu){
    for(int i = 0; i < Suck_Count; i++) Sucks[i].spin(fwd, v, vu);
}

void Suck_Stop(brakeType bt){
    for(int i = 0; i < Suck_Count; i++) Sucks[i].stop(bt);
}


void Lift_Spin(double v, velocityUnits vu){
    for(int i = 0; i < Lift_Count; i++) Lifts[i].spin(fwd, v, vu);
}

void Lift_Stop(brakeType bt){
    for(int i = 0; i < Lift_Count; i++) Lifts[i].stop(bt);
}

void Lift_ResetPosition(){
    for(int i = 0; i < Lift_Count; i++) Lifts[i].resetPosition();
}

double Lift_AverPosition(rotationUnits ru){
    double Position_Sum = 0.0;
    for(int i = 0; i < Lift_Count; i++){
        Position_Sum += Lifts[i].position(ru);
    }
    return (Position_Sum / Lift_Count);
}

bool Lift_IsDone(){
    bool Sum = 1;
    for(int i = 0; i < Lift_Count; i++) Sum *= Lifts[i].isDone();
    return Sum;
}

void Lift_SpinTo(double rotation, double v, bool waiter){
    for(int i = 0; i < Lift_Count; i++) Lifts[i].spinTo(rotation, deg, v, velocityUnits::pct, 0);
    if(waiter){
        while(waiter){
            waiter = !Lift_IsDone();
        }
        Lift_Stop(hold);
    }
}

timer CLTimer;
int Blue_Value = 150, Red_Value = 25;

void ColorSelecting(int Color){
    if(Color >= 0 && Color <=5){
        if(CLSensor.hue() >= Blue_Value && CLSensor.isNearObject()){
                CLSelector.set(1);
                CLTimer.reset();
        }
        else if((CLSensor.hue() <= Red_Value && CLSensor.isNearObject())|| CLTimer.time(msec) >= 300) CLSelector.set(0);
    }
    else if(Color >=6 && Color <= 9){
        if(CLSensor.hue() <= Red_Value && CLSensor.isNearObject()){
                CLSelector.set(1);
                CLTimer.reset();
            }
            else if((CLSensor.hue() >= Blue_Value && CLSensor.isNearObject())|| CLTimer.time(msec) >= 300) CLSelector.set(0);
    }
}

void Auto_CLSorting(){
    while(1) ColorSelecting(ProgramChoice);
}






