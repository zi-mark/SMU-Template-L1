#include "robot-config.h"

extern void Suck_Spin(double v, vex::velocityUnits vu = vex::velocityUnits::pct);
extern void Suck_Stop(brakeType bt = vex::brakeType::hold);

extern void Lift_Spin(double v, vex::velocityUnits vu = vex::velocityUnits::pct);
extern void Lift_Stop(brakeType bt = brakeType::hold);
extern void Lift_SpinTo(double target, double v = 90, velocityUnits vu = velocityUnits::pct, bool wait = 1);
