#include "robot-config.h"
#include "definer.h"

void SpinLR(double lv, double rv, vex::velocityUnits vu = velocityUnits::pct);
void Stop(vex::brakeType bt = vex::brakeType::hold);
void ResetPosition();
double AverPosition(rotationUnits ru);
void Spin_T(double v, double t);
void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
void Turn();

struct PM{
    double kp;
    double vmin;
    double offset;
};

extern PM PMT;
extern PM PMDT;
extern PM PMG;

struct PID{
    double kp;
    double ki;
    double startI;
    double kd;
    double offset;
    int endT;
};

extern PID PIDG;
    
    void PMTurnTo(double target, double kp = PMT.kp, double vmin = PMT.vmin, double offset = PMT.offset);
    void PMDTurnTo(double rtn, double r, double kp = PMDT.kp, double vmin = PMDT.vmin, double offset = PMDT.offset);
    void PMGo(double target, double kp = PMG.kp, double vmin = PMG.vmin, double offset = PMG.offset);
    void PIDGo(double target, double kp = PIDG.kp, double ki = PIDG.ki, double startI = PIDG.startI, double kd = PIDG.kd, double offset = PIDG.offset, double endT = PIDG.endT);
    void PIDTurnTo();

// #ifdef SMU
//     #if SMU == 1
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 12, double vmin = 110, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 2.5, double vmin = 100, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #elif SMU == 2
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #elif SMU == 3
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #endif
// #endif

// #ifdef SF
//     #if SF == 1
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #elif SF == 2
//     // void Spin_T(double v, double t);
//     // void PMTurnTo(double target, double kp = 22, double vmin = 100, double offset = 1);
//     // void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     // void PMGo(double target, double kp = 2.5, double vmin = 200, double offset = 10);
//     // void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     // void PIDTurnTo();
//     // void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     // void Turn();
//     #endif

// #endif

// #ifdef CSTU
//     #if CSTU == 1
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 12, double vmin = 110, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 2.5, double vmin = 100, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #elif CSTU == 2
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #endif
// #endif

// #ifdef KL
//     #if KL == 1 || KL == 2 || KL == 3 || KL == 4
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     #elif KL == 6
//     void Spin_T(double v, double t);
//     void PMTurnTo(double target, double kp = 35, double vmin = 200, double offset = 1);
//     void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     void PMGo(double target, double kp = 4, double vmin = 250, double offset = 10);
//     void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     void PIDTurnTo();
//     void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     void Turn();
//     // #elif KL == 5
//     // void Spin_T(double v, double t);
//     // void PMTurnTo(double target, double kp = 12, double vmin = 110, double offset = 1);
//     // void PMDTurnTo(double rtn, double r, double kp = 25, double vmin = 200, double offset = 1);
//     // void PMGo(double target, double kp = 2.5, double vmin = 100, double offset = 10);
//     // void PIDGo(double target, double kp = 0.1, double ki = 0, double startI = 60, double kd = 5, double offset = 20, double endT = 1000);
//     // void PIDTurnTo();
//     // void Go(double target, double v = 90, velocityUnits vu = velocityUnits::pct);
//     // void Turn();
//     #endif
// #endif
