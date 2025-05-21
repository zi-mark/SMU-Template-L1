#include "autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef Alex
void RR(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(-57);
    Break();
    PMGo(-18);
    Go(-8, 10);
    Hook.set(1);
    PMTurnTo(-145);
    Suck_Spin();
    Break();
    PMGo(20);
    task::sleep(1000);
    PMTurnTo(50);
    Break();
    PMGo(30);

}
void RR2(){
    Lift_SpinTo(30, 100, 0);
    PMGo(-45);
    Hook.set(1);
    Suck_Spin();
    Break();
    PMGo(10);
    PMTurnTo(-30);
    Break();
    PMGo(20);
    Suck_Stop();
    Hook.set(0);
    PMTurnTo(-100);
    Break();
    PMGo(-24);
    Go(-5, 20);
    Hook.set(1);
    Suck_Spin();
    PMTurnTo(-80);
    PMGo(-30);


}
void RR3(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(-57);
    Break();
    PMGo(-25);
    // Go(-8, 10);
    Hook.set(1);
    PMTurnTo(-145);
    Suck_Spin();
    Break();
    PMGo(25);
    // task::sleep(400);
    PMTurnTo(-85);
    Break();
    Suck_Spin(-100);
    Brain.Screen.clearScreen(black);
    Spin_T(100, 1200);
    Suck_Spin(100);
    Brain.Screen.clearScreen(white);
    Spin_T(100, 900);
    PMGo(-10);
    Suck_Stop();
    Break();
    PMTurnTo(71);
    PMGo(50);


}
void RL(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(57);
    Break();
    PMGo(-18);
    Go(-8, 10);
    Hook.set(1);
    PMTurnTo(145);
    Suck_Spin();
    Break();
    PMGo(20);
    task::sleep(1000);
    PMTurnTo(-50);
    Break();
    PMGo(30);

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
void RL3(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(57);
    Break();
    PMGo(-25);
    // Go(-8, 10);
    Hook.set(1);
    PMTurnTo(145);
    Suck_Spin();
    Break();
    PMGo(15);
    task::sleep(400);
    PMTurnTo(95);
    Break();
    Suck_Spin(-100);
    // PMGo();
    Spin_T(100, 1300);
    Suck_Spin(100);
    task::sleep(300);
    PMGo(-40);
    Suck_Stop();
    Break();
    PMTurnTo(-70);
    PMGo(20);
}
void BR(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(-57);
    Break();
    PMGo(-18);
    Go(-8, 10);
    Hook.set(1);
    PMTurnTo(-145);
    Suck_Spin();
    Break();
    PMGo(20);
    task::sleep(1000);
    PMTurnTo(50);
    Break();
    PMGo(30);
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
void BR3(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(-57);
    Break();
    PMGo(-25);
    // Go(-8, 10);
    Hook.set(1);
    PMTurnTo(-145);
    Suck_Spin();
    Break();
    PMGo(15);
    task::sleep(400);
    PMTurnTo(-95);
    Break();
    Suck_Spin(-100);
    // PMGo();
    Spin_T(100, 1300);
    Suck_Spin(100);
    task::sleep(300);
    PMGo(-40);
    Suck_Stop();
    Break();
    PMTurnTo(70);
    PMGo(20);
}
void BL(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(57);
    Break();
    PMGo(-18);
    Go(-8, 10);
    Hook.set(1);
    PMTurnTo(145);
    Suck_Spin();
    Break();
    PMGo(20);
    task::sleep(1000);
    PMTurnTo(-50);
    Break();
    PMGo(30);
}
void BL2(){
    Lift_SpinTo(150, 30);
    PMGo(-30);
    // Lift_SpinTo(130, 100);
    Break();
}
void BL3(){
    Lift_SpinTo(540, 60);
    PMGo(-12);
    Break();
    Lift_SpinTo(80, 100, 0);
    PMTurnTo(57);
    Break();
    PMGo(-25);
    // Go(-8, 10);
    Hook.set(1);
    PMTurnTo(145);
    Suck_Spin();
    Break();
    PMGo(15);
    task::sleep(400);
    PMTurnTo(95);
    Break();
    Suck_Spin(-100);
    // PMGo();
    Spin_T(100, 1300);
    Suck_Spin(100);
    task::sleep(300);
    PMGo(-40);
    Suck_Stop();
    Break();
    PMTurnTo(-70);
    PMGo(20);
}
void Skills(){
    Lift_SpinTo(80, 90, 0);
    PMGo(-28);
    Hook.set(1);
    Break();
    PMTurnTo(-20);
    Suck_Spin();
    PMGo(30);
    task::sleep(1000);
    PMTurnTo(-75);
    // Lift_SpinTo(0);
    Break();
    // PMGo(20);
    Spin_T(50, 1000);
    Suck_Stop();
    PMGo(-10);
    PMTurnTo(105);
    Hook.set(0);
    Spin_T(-50, 1000);
    PMGo(10);
    Break();
    PMTurnTo(-35);
    Break();
    PMGo(-70);
    Break();
    PMTurnTo(-85);
    Break();
    PMGo(-30);
    Hook.set(1);
    Suck_Spin();
    Break();
    PMTurnTo(15);
    Hook.set(0);
    Spin_T(-80, 2000);
    // PMGo(10);
    
}
#endif