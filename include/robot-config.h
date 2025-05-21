#include "vex.h"

#define Pi 3.14159265358979323846

using namespace vex;

extern brain Brain;
extern controller Con;
extern competition Com;

extern int Chassis_Count;
extern motor RMs[];
extern motor LMs[];

extern int Suck_Count;
extern motor Sucks[];

extern int Lift_Count;
extern motor Lifts[];

extern digital_out Hook;
extern digital_out HookR;
extern digital_out HookP;
extern digital_out CLSelector;
extern digital_out Hand;
extern digital_out HandL;
extern digital_out HandR;
extern digital_out HandRR;
extern digital_out HandRP;
extern digital_out HandLR;
extern digital_out HandLP;
extern digital_out HookLio;
extern digital_out Raise;
extern bumper Selecter;

extern inertial GR;
extern optical CLSensor;

extern thread CL;

extern double WheelRadius, ChasisRatio, ChasisWidth;
