#include "robot-config.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"

using namespace vex;

#ifdef Exam
    #if Exam == 1

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT1, ratio6_1, 0);
    motor R2(PORT2, ratio6_1, 0);
    motor R3(PORT5, ratio6_1, 0);

    motor L1(PORT10, ratio6_1, 1);
    motor L2(PORT9, ratio6_1, 1);
    motor L3(PORT6, ratio6_1, 1);

    int Chassis_Count = 3;

    motor LMs[] = {L1, L2, L3};
    motor RMs[] = {R1, R2, R3};

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2;
    double ChasisRatio = 35.0/60.0;
    double ChasisWidth = 7.5;

    //自动参数调整
    PM PMT{12, 110, 1};
    PM PMG{1.9, 100, 25};
    PM PMDT{25, 200, 1};
    

    motor LiftL(PORT19, ratio36_1, 1);
    motor LiftR(PORT21, ratio36_1, 0);
    // motor Lift(PORT10, ratio36_1, 0);

    int Lift_Count = 2;
    motor Lifts[] = {LiftL, LiftR};

    motor Suck(PORT20, ratio6_1, 1);
    motor Suck2(PORT20, ratio6_1, 0);

    int Suck_Count = 2;
    motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT20);
    optical CLSensor(PORT20);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.A);
    
    #endif

#endif