#include "robot-config.h"
#include "definer.h"

using namespace vex;

#ifdef SMU

    #if SMU == 1

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT9, ratio6_1, 1);
    motor R2(PORT17, ratio6_1, 1);
    motor R3(PORT19, ratio6_1, 1);
    motor R4(PORT16, ratio6_1, 0);
    motor R5(PORT18, ratio6_1, 0);

    motor L1(PORT1, ratio6_1, 0);
    motor L2(PORT11, ratio6_1, 0);
    motor L3(PORT14, ratio6_1, 0);
    motor L4(PORT13, ratio6_1, 1);
    motor L5(PORT15, ratio6_1, 1);

    int Chassis_Count = 5;

    motor LMs[] = {L1, L2, L3, L4, L5};
    motor RMs[] = {R1, R2, R3, R4, R5};

    motor LiftL(PORT3, ratio36_1, 1);
    motor LiftR(PORT5, ratio36_1, 0);
    // motor Lift(PORT10, ratio36_1, 0);

    int Lift_Count = 2;
    motor Lifts[] = {LiftL, LiftR};

    motor Suck(PORT2, ratio6_1, 1);
    motor Suck2(PORT6, ratio6_1, 0);

    int Suck_Count = 2;
    motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT4);
    optical CLSensor(PORT20);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.A);
    digital_out Hand(Brain.ThreeWirePort.B);
    digital_out CLSelector(Brain.ThreeWirePort.E);
    bumper Selecter(Brain.ThreeWirePort.H);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 1.375;
    double ChasisRatio = 1;
    double ChasisWidth = 7.5;

    PM PMT{12, 110, 1};
    PM PMG{2.5, 100, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};

    #elif SMU == 2
    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT1, ratio6_1, 0);
    motor R2(PORT2, ratio6_1, 0);
    motor R3(PORT3, ratio6_1, 1);
    motor R4(PORT11, ratio6_1, 0);
    motor L1(PORT10, ratio6_1, 1);
    motor L2(PORT9, ratio6_1, 1);
    motor L3(PORT8, ratio6_1, 0);
    motor L4(PORT19, ratio6_1, 1);

    int Chassis_Count = 4;

    motor LMs[] = {L1, L2, L3, L4};
    motor RMs[] = {R1, R2, R3, R4};

    // motor Lift(PORT5, ratio36_1, 0);
    motor LiftR(PORT5, ratio36_1, 0);
    motor LiftL(PORT18, ratio36_1, 1);

    int Lift_Count = 2;
    motor Lifts[] = {LiftR, LiftL};

    motor Suck(PORT4, ratio6_1, 0);
    motor Suck2(PORT7, ratio6_1, 1);

    int Suck_Count = 2;
    motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT20);
    optical CLSensor(PORT17);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.A);
    digital_out CLSelector(Brain.ThreeWirePort.H);
    digital_out HandL(Brain.ThreeWirePort.C);
    digital_out HandR(Brain.ThreeWirePort.D);
    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/84.0;
    double ChasisWidth = 15.5;

    PM PMT{35, 200, 1};
    PM PMG{4, 250, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};
    
    #endif


#endif
