#include "autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef SMU
void RR(){
    thread ClSorting(Auto_CLSorting);
    PMGo(-10,1);
    Hook.set(1);
    Suck_Spin(100);
    Break();

    PMGo(50,1);
    Break();

    PMTurnTo(-90);
    Break();

    PMGo(30,1);
    PMGo(-6);
    Break();

    PMTurnTo(-215);
    Break();

    PMGo(56);
    Break();

    PMTurnTo(-170);
    Break();

    Hook.set(0); 
    PMGo(-62,2);   
    Break();

    PMGo(10,1);
    Break();

    PMTurnTo(-127);
    Break();

    PMGo(60);
    Break();

    ClSorting.join();
}
void RR2(){
    Lift_SpinTo(150, 30);
    PMGo(-5);
    // Lift_SpinTo(130, 100);
    Break();
    PMTurnTo(-23);
    Break();
    PMGo(-56);
    Hook.set(1);
    Break();
    PMGo(1);
    Break();
    PMTurnTo(-100);
    Suck_Spin(100);
    PMGo(20);
    PMTurnTo(-230);
    Break();
    PMGo(10);
    // PMGo(7);
}
void RR3(){
    PMGo(-50);
    Hook.set(1);
    Break();
    Suck_Spin();
    PMGo(40);
}
void RL(){
    Lift_SpinTo(150, 30);
    PMGo(-30);
    // Lift_SpinTo(130, 100);
    Break();

}
void RL2(){
    Lift_SpinTo(150, 30);
    PMGo(-10);
    // Lift_SpinTo(130, 100);
    Break();
    PMTurnTo(27);
    Break();
    PMGo(-52);
    Hook.set(1);
    Break();
    PMGo(25);
    PMTurnTo(94);
    Break();

    Suck_Spin(100);
    PMGo(30);
    PMTurnTo(-25);
    Suck_Stop();
    Break();
    task::sleep(8000);
    PMGo(80);
}
void BR(){
    Lift_SpinTo(150, 30);
    PMGo(-30);
    // Lift_SpinTo(130, 100);
    Break();
}
void BR2(){
    Lift_SpinTo(150, 30);
    PMGo(-10);
    // Lift_SpinTo(130, 100);
    Break();
    PMTurnTo(-25.5);//
    Break();
    PMGo(-52);
    Hook.set(1);
    Break();
    PMGo(25);
    PMTurnTo(-94);
    Break();

    Suck_Spin(100);
    PMGo(30);
    task::sleep(1000);
    PMTurnTo(28);
    Suck_Stop();
    Break();
    task::sleep(8000);
    PMGo(80);
}
void BL(){
    thread ClSorting(Auto_CLSorting);
    PMGo(-10,1.5);
    Hook.set(1);
    Suck_Spin(100);
    Break();

    PMGo(50,1);
    Break();

    PMTurnTo(90);
    Break();

    PMGo(30,1);
    PMGo(-6);
    Break();

    PMTurnTo(215);
    Break();

    PMGo(56);
    Break();

    PMTurnTo(170);
    Break();

    Hook.set(0); 
    PMGo(-62,3);   
    Break();

    PMGo(10,1);
    Break();

    PMTurnTo(127);
    Break();

    PMGo(60);
    Break();

    ClSorting.join();
}
void BL2(){}
void BL3(){}
void Skills(){}

#endif