#include "robot-config.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"

using namespace vex;

#ifdef SF

#if SF == 1
    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT2, ratio6_1, 0);
    motor R2(PORT19, ratio6_1, 0);
    motor R3(PORT7, ratio6_1, 0);
    motor L1(PORT6, ratio6_1, 1);
    motor L2(PORT3, ratio6_1, 1);
    motor L3(PORT8, ratio6_1, 1);


    int Chassis_Count = 3;

    motor LMs[] = {L1, L2, L3};
    motor RMs[] = {R1, R2, R3};

    motor Lift(PORT10, ratio36_1, 0);
    // motor LiftR(PORT5, ratio36_1, 0);
    // motor LiftL(PORT18, ratio36_1, 1);

    int Lift_Count = 1;
    motor Lifts[] = {Lift};

    motor Suck(PORT9, ratio18_1, 0);
    motor Suck2(PORT20, ratio18_1, 0);


    int Suck_Count = 2;
    motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT5);
    optical CLSensor(PORT21);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.H);
    digital_out CLSelector(Brain.ThreeWirePort.C);
    digital_out HandL(Brain.ThreeWirePort.G);
    digital_out HandR(Brain.ThreeWirePort.D);
    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/72.0;
    double ChasisWidth = 15.5;

    PM PMT{35, 200, 1};
    PM PMG{4, 250, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};

    #elif SF == 2
    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT18, ratio6_1, 0);
    motor R2(PORT19, ratio6_1, 0);
    motor R3(PORT20, ratio6_1, 0);
    motor L1(PORT13, ratio6_1, 1);
    motor L2(PORT16, ratio6_1, 1);
    motor L3(PORT17, ratio6_1, 1);

    int Chassis_Count = 3;

        motor LMs[] = {L1, L2, L3};
        motor RMs[] = {R1, R2, R3};

    // motor LiftL(PORT10, ratio36_1, 1);
    // motor LiftR(PORT3, ratio18_1, 0);
    motor Lift(PORT14, ratio18_1, 0);

    int Lift_Count = 1;
        motor Lifts[] = {Lift};


    motor Suck(PORT11, ratio18_1, 0);
    motor Suck2(PORT1, ratio18_1, 0);

    int Suck_Count = 2;
        motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT12);
    optical CLSensor(PORT21);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.H);
    digital_out HandR(Brain.ThreeWirePort.G);
    digital_out CLSelector(Brain.ThreeWirePort.C);
    digital_out HandL(Brain.ThreeWirePort.G);

    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/72.0;
    double ChasisWidth = 16.1;

    PM PMT{22, 100, 1};
    PM PMG{2.5, 200, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};

    #elif SF == 3

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT18, ratio6_1, 0);
    motor R2(PORT19, ratio6_1, 0);
    motor R3(PORT20, ratio6_1, 0);
    motor L1(PORT15, ratio6_1, 1);
    motor L2(PORT16, ratio6_1, 1);
    motor L3(PORT17, ratio6_1, 1);

    int Chassis_Count = 3;

        motor LMs[] = {L1, L2, L3};
        motor RMs[] = {R1, R2, R3};

    // motor LiftL(PORT10, ratio36_1, 1);
    // motor LiftR(PORT3, ratio18_1, 0);
    motor Lift(PORT14, ratio18_1, 0);

    int Lift_Count = 1;
        motor Lifts[] = {Lift};


    motor Suck(PORT11, ratio18_1, 0);
    motor Suck2(PORT2, ratio18_1, 0);

    int Suck_Count = 2;
        motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT12);
    optical CLSensor(PORT21);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.H);
    digital_out HandR(Brain.ThreeWirePort.G);
    digital_out CLSelector(Brain.ThreeWirePort.C);
    digital_out HandL(Brain.ThreeWirePort.G);

    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/72.0;
    double ChasisWidth = 16.1;

    PM PMT{22, 100, 1};
    PM PMG{2.5, 200, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};

    #elif SF == 4

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT1, ratio6_1, 0);
    motor R2(PORT4, ratio6_1, 0);
    motor R3(PORT3, ratio6_1, 1);
    motor L1(PORT13, ratio6_1, 1);
    motor L2(PORT15, ratio6_1, 1);
    motor L3(PORT14, ratio6_1, 0);

    int Chassis_Count = 3;

        motor LMs[] = {L1, L2, L3};
        motor RMs[] = {R1, R2, R3};

    motor LiftL(PORT19, ratio18_1, 1);
    motor LiftR(PORT9, ratio18_1, 0);
    // motor Lift(PORT14, ratio18_1, 0);

    int Lift_Count = 2;
        motor Lifts[] = {LiftL, LiftR};


    motor Suck(PORT5, ratio18_1, 1);
    motor Suck2(PORT7, ratio18_1, 0);

    int Suck_Count = 2;
        motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT12);
    optical CLSensor(PORT21);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.B);
    digital_out HandR(Brain.ThreeWirePort.G);
    digital_out CLSelector(Brain.ThreeWirePort.C);
    digital_out HandL(Brain.ThreeWirePort.G);

    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/72.0;
    double ChasisWidth = 16.1;

    PM PMT{22, 100, 1};
    PM PMG{2.5, 200, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};

    #elif SF == 5

    //motor 马达名字(端口，变速箱比例，是否反转 0不反转1反转);
    motor R1(PORT18, ratio6_1, 0);
    motor R2(PORT19, ratio6_1, 0);
    motor R3(PORT20, ratio6_1, 0);
    motor L1(PORT15, ratio6_1, 1);
    motor L2(PORT16, ratio6_1, 1);
    motor L3(PORT17, ratio6_1, 1);


 int Chassis_Count = 3;

    motor LMs[] = {L1, L2, L3};
    motor RMs[] = {R1, R2, R3};

    // motor LiftL(PORT10, ratio36_1, 1);
    // motor LiftR(PORT3, ratio18_1, 0);
    motor Lift(PORT14, ratio18_1, 0);

    int Lift_Count = 1;
        motor Lifts[] = {Lift};


    motor Suck(PORT1, ratio18_1, 0);
    motor Suck2(PORT11, ratio18_1, 0);

    int Suck_Count = 2;
        motor Sucks[] = {Suck, Suck2};

    //惯性传感器(端口);
    inertial GR(PORT12);
    optical CLSensor(PORT21);

    //电磁阀(三线接口);
    digital_out Hook(Brain.ThreeWirePort.H);
    digital_out HandR(Brain.ThreeWirePort.G);
    digital_out CLSelector(Brain.ThreeWirePort.C);
    digital_out HandL(Brain.ThreeWirePort.G);

    bumper Selecter(Brain.ThreeWirePort.E);

    //轮子半径和齿轮比 马达齿/轮子齿
    double WheelRadius = 2.0;
    double ChasisRatio = 36/72.0;
    double ChasisWidth = 16.1;
    
    PM PMT{25, 50, 1};
    PM PMG{3.1, 100, 10};
    PM PMDT{25, 200, 1};

    PID PIDG{0.1, 0, 60, 5, 20, 1000};
    
    #endif

#endif