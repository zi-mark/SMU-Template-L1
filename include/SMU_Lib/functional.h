#include "robot-config.h"
void Suck_Spin(double v = 100, velocityUnits bt = velocityUnits::pct);
void Suck_Stop(brakeType bt = brakeType::hold);
void Lift_Spin(double v, velocityUnits vu = velocityUnits::pct);
void Lift_Stop(brakeType bt = brakeType::hold);
void Lift_ResetPosition();
double Lift_AverPosition(rotationUnits ru = rotationUnits::deg);
bool Lift_IsDone();
void Lift_SpinTo(double rotation, double v = 90, bool waiter = 1);
void ColorSelecting(int Color);
void Auto_CLSorting();
extern timer CLTimer;