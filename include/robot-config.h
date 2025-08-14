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
extern int Suck2_Count;
extern int Suck3_Count;
extern int Suck4_Count;
extern motor Sucks[];
extern motor Sucks2[];
extern motor Sucks3[];
extern motor Sucks4[];

extern motor Suck;
extern motor Suck2;
extern motor Suck3;
extern motor Suck4;

extern int Lift_Count;
extern motor Lifts[];

extern digital_out Hook;
extern digital_out Pis;
extern digital_out Lift;
extern digital_out Killer;
extern digital_out Hand;
extern digital_out CL_Pis;
extern digital_out Pis2;

extern inertial GR;
extern optical CLSensor;

extern thread CL;

extern double WheelRadius, ChasisRatio, ChasisWidth;
