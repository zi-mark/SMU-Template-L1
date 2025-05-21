#include "SMU_Lib/chasis.h" 

void SpinLR(double lv, double rv, vex::velocityUnits vu){

    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].spin(fwd, lv, vu);
        RMs[i].spin(fwd, rv, vu);
    }

}
 
void Stop(brakeType bt){
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].stop(bt);
        RMs[i].stop(bt);
    }
}

void ResetPosition(){
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].resetPosition();
        RMs[i].resetPosition();
    }
}

double AverPosition(rotationUnits ru){
    double Position_Sum = 0.0;
    for(int i = 0; i < Chassis_Count; i++){
        Position_Sum += LMs[i].position(ru);
        Position_Sum += RMs[i].position(ru);
    }
    return (Position_Sum / (2.0 * Chassis_Count));
}

void Spin_T(double v, double t){
    SpinLR(v, v);
    task::sleep(t);
    Stop();
}

void PMTurnTo(double target, double kp, double vmin, double offset){
    double temp, v;
    while(1){
        temp = target - GR.rotation();
        if (fabs(temp) <= offset) break;
        v = kp * temp;
        if(v < -vmin || v > vmin){
            SpinLR(v, -v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v < 0){
            SpinLR(-vmin, vmin, dps);
            Brain.Screen.clearScreen(green);
        }
        else{
            SpinLR(vmin, -vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
    }
    Stop(hold);
}

void PMGo(double target, double kp, double vmin, double offset){
    ResetPosition();
    double temp, v;
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){
        temp = target - AverPosition(deg);
        if(fabs(temp) < offset) break;
        v = kp * temp;
        if(v < -vmin || v > vmin){
            SpinLR(v,v, dps);
            Brain.Screen.clearScreen(red);
        }
        else if(v > 0){
            SpinLR(vmin, vmin, dps);
            Brain.Screen.clearScreen(blue);
        }
        else{
            SpinLR(-vmin, -vmin, dps);
            Brain.Screen.clearScreen(green);
        }
    }
    Stop(hold);
}

void PMDTurnTo(double rtn, double r, double kp, double vmin, double offset){
    double temp, cv, rv, lv;
    while(1){
        temp = rtn - GR.rotation();
        if (fabs(temp) <= offset) break;
        cv = kp * temp;
        rv = cv * (r-ChasisWidth/2)/r;
        lv = cv * (r+ChasisWidth/2)/r;

        if(r > 0){
            if(fabs(lv) >= 3600) SpinLR(Sign(lv)*3600, Sign(rv)*3600*(r-ChasisWidth/2)/(r+ChasisWidth/2), dps);
            else if(fabs(rv) <= vmin) SpinLR(Sign(lv)*vmin*(r+ChasisWidth/2)/(r-ChasisWidth/2), Sign(rv)*vmin, dps);
            else SpinLR(lv, rv, dps);
        }

        // if(v < -vmin || v > vmin){
        //     SpinLR(v * ratio, v, dps);
        //     Brain.Screen.clearScreen(red);
        // }
        // else if(v < 0){
        //     SpinLR(-vmin * ratio, -vmin, dps);
        //     Brain.Screen.clearScreen(green);
        // }
        // else{
        //     SpinLR(vmin * ratio, vmin, dps);
        //     Brain.Screen.clearScreen(blue);
        // }
    }
    Stop(hold);
}

void PIDGo(double target, double kp, double ki, double startI, double kd, double offset, double endT){
    ResetPosition();
    double v, staticI = 0.0, error, lasterror, P, I, D;
    bool end;
    timer PIDT;
    lasterror = target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    while(1){

        error = target - AverPosition(deg);

        if(fabs(error) <= offset){
            if(end){
                if(PIDT.time() >= endT) break;
            }
            else{
                end = 1;
                PIDT.reset();
            }
        }
        else end = 0;

        P = kp * error;
        if(fabs(error) <= startI) staticI += v;
        I = ki * staticI;
        D = kd * (error - lasterror);

        v = P + I + D;
        SpinLR(v, v);

        lasterror = error;
    }
    Brain.Screen.clearScreen(red);
    Stop();
}

void Go(double target, double v, velocityUnits vu){
    target = target * 360 / (2 * Pi * WheelRadius * ChasisRatio);
    for(int i = 0; i < Chassis_Count; i++){
        LMs[i].spinFor(target, deg, v, vu, 0);
        RMs[i].spinFor(target, deg, v, vu, 0);
    }
    bool finish = 1;
    while(finish){
        for(int i = 0; i < Chassis_Count; i++){
            finish *= !LMs[i].isDone() * !RMs[i].isDone();
        }
    }
    Stop(hold);
}


