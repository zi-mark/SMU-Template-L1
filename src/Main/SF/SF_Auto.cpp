#include "autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef SF

#if SF == 1

void RR(){
// PMGo(-34);
    Go(-30, 100);
    Break();
    PMTurnTo(-35);
    Break();
    // PMGo(-8);
    Go(-7, 40);
    Hook.set(1);
    Break();
    // Suck_Spin();
    // Suck.spin(fwd, 100, pct);
    PMTurnTo(18);
    Suck_Spin();
    // task::sleep(500);
    Go(5, 90);
    task::sleep(600);
    Hook.set(0);
    Suck_Stop();
    // Suck2.spin(fwd, 100, pct);
    Suck_Spin();
    Break();
    PMGo(6);
    // Suck.spin(fwd, 100, pct);
    Break();
    PMTurnTo(-90);
    // Suck_Stop();
    Break();

    PMGo(-13);
    Go(-5, 20);
    Hook.set(1);
    Break();

    Suck_Spin();
    PMGo(30);
    PMTurnTo(-30);

    HandR.set(1);
    PMGo(31);
    // Spin_T(100, 500);

    PMTurnTo(90);
    HandR.set(0);
    // Spin_T(50, 500);
    PMTurnTo(90);
    // PMGo(10);
    // task::sleep(800);
    Hook.set(0);

    Break();
    PMTurnTo(0);
    PMGo(-25);//30
    

}
void RR2(){}
void RR3(){}
void RL(){}
void RL2(){}
void RL3(){}
void BR(){}
void BR2(){}
void BR3(){}
void BL(){
    // PMGo(-34);
    Go(-30, 100);
    Break();
    PMTurnTo(35);
    Break();
    // PMGo(-8);
    Go(-7, 40);
    Hook.set(1);
    Break();
    // Suck_Spin();
    // Suck.spin(fwd, 100, pct);
    PMTurnTo(-18);
    Suck_Spin();
    // task::sleep(500);
    Go(5, 90);
    task::sleep(600);
    Hook.set(0);
    Suck_Stop();
    // Suck2.spin(fwd, 100, pct);
    Suck_Spin();
    Break();
    PMGo(6);
    // Suck.spin(fwd, 100, pct);
    Break();
    PMTurnTo(90);
    // Suck_Stop();
    Break();

    PMGo(-13);
    Go(-5, 20);
    Hook.set(1);
    Break();

    Suck_Spin();
    PMGo(30);
    PMTurnTo(30);

    HandR.set(1);
    PMGo(31);
    // Spin_T(100, 500);

    PMTurnTo(-90);
    HandR.set(0);
    // Spin_T(50, 500);
    PMTurnTo(-90);
    // PMGo(10);
    // task::sleep(800);
    Hook.set(0);

    Break();
    PMTurnTo(0);
    PMGo(-25);//30
    

    
}
void BL2(){}
void BL3(){}
void Skills(){}

#elif SF == 5

void RR(){
    PMGo(-26);
    wait(100,msec);
    Hook.set(1);
    wait(100,msec);
    Suck_Spin(100);
    wait(300,msec);
    PMTurnTo(-90);
    PMGo(20);
    wait(300,msec);
    PMTurnTo(90);
    Lift_SpinTo(470, 80);
    PMGo(30);

}
void RR2(){
    Go(-31, 100);
    PMTurnTo(-35);
    Go(-9.4, 40);
    Hook.set(1);
    PMTurnTo(18);
    Sucks[2].spin(fwd, 100, pct);
    task::sleep(150);
    Suck_Spin();
    Go(7.8, 90);
    PMGo(3.4);
    Hook.set(0);
    Suck_Stop();
    PMTurnTo(-87);
    Go(-11,100);
    Go(-8, 20);
    Hook.set(1);
    PMTurnTo(0);
    Suck_Spin();
    Go(20,100);
    PMTurnTo(-47);
    Go(24,100);
    PMTurnTo(-57);
    HandR.set(1);
    Sucks[1].spin(fwd,-100,pct);
    Go(8.8,10);
    task::sleep(750);
    Go(-8,80);
    HandR.set(0);
    task::sleep(100);
    Suck_Spin();
    Go(8,80);
    task::sleep(300);
    Go(-25,100);
    task::sleep(400);
}
void RR3(){
    
}
void RL(){
    PMGo(-10);
    Go(-12,20);
    Hook.set(1);//扣桩
    PMTurnTo(136);
    Suck_Spin(100);
    PMGo(17);
    Go(6.5,30);
    task::sleep(200);//到第一个环
    Go(-3,50);
    task::sleep(50);
    PMTurnTo(112);
    task::sleep(200);
    Go(11,30);
    task::sleep(500);
    PMGo(-15.2);
    Sucks[1].stop();
    PMTurnTo(70);
    Sucks[1].spin(fwd,100,pct);
    Go(4,20);
    task::sleep(600);
    Go(13,40);
    task::sleep(1400);
    PMTurnTo(-90);
    PMGo(40);
    PMTurnTo(-30);
    Lift_SpinTo(490, 80);
    Stop(coast);

}
void RL2(){
    Lift_SpinTo(490, 80);
    //task::sleep(700);
    //Lift.spinTo(500, deg, 40, velocityUnits::pct, 0);
    Go(-3,60);
    Lift_SpinTo(-90, 100, 0);
    PMTurnTo(35);
    PMGo(-20);
    //task::sleep(90);
    Go(-15,25);
    Hook.set(1);
    PMTurnTo(184);
    Suck_Spin();
    PMGo(18);
    //Go(5,30);
    task::sleep(450);
    PMTurnTo(161);
    task::sleep(100);
    Go(7,30);
    task::sleep(200);
    PMGo(-9);
    task::sleep(450);
    PMTurnTo(90);
    Go(12,40);
    PMTurnTo(-10);
    PMGo(34);
    task::sleep(300);
    PMTurnTo(-110);
    PMGo(6.5);
    Lift_SpinTo(432,100);
    // Lift_SpinTo(-2, 100, 0);
    // PMTurnTo(180);
    // PMGo(18);
    // Suck_Stop(coast);
    // Lift_SpinTo(310, 70);
    // Go(2.5,10);
    /*PM
    
    
    Suck.spin(fwd,100,pct);
    task::sleep(300);
    Suck.stop();
    PMGo(15);
    PMTurnTo(215);
    PMGo(-20);
    

    PMTurnTo(40);
    Suck.spin(fwd,100,pct);
    Suck2.spin(fwd,100,pct);
    PMGo(11.7);
    Go(6.5,30);
    task::sleep(300);//到第一个环
    Go(-3,50);
    task::sleep(900);
    PMGo(-9);
    task::sleep(300);
    PMTurnTo(-20);
    Go(15,30);
    task::sleep(200);
    PMTurnTo(175);
    task::sleep(800);
    PMGo(31.5);
    Stop(coast);*/

}
void RL3(){

}
void BR(){
    PMGo(-10);
    Go(-12,20);
    Hook.set(1);//扣桩
    PMTurnTo(-136);
    Suck_Spin();
    PMGo(17);
    Go(6.5,30);
    task::sleep(200);//到第一个环
    Go(-3,50);
    task::sleep(50);
    PMTurnTo(-112);
    task::sleep(200);
    Go(9.7,30);
    task::sleep(500);
    PMGo(-15.2);
    Sucks[1].stop();
    PMTurnTo(-55);
    Sucks[1].spin(fwd,100,pct);
    Go(4,20);
    task::sleep(600);
    Go(12,40);
    task::sleep(1400);
    PMTurnTo(90);
    PMGo(25);
    Lift_SpinTo(480,90);
}
void BR2(){
    Lift_SpinTo(490, 80);
    //task::sleep(700);
    //Lift.spinTo(500, deg, 40, velocityUnits::pct, 0);
    Go(-3,60);
    Lift_SpinTo(-90, 100, 0);
    PMTurnTo(-35);
    PMGo(-20);
    //task::sleep(90);
    Go(-15,25);
    Hook.set(1);
    PMTurnTo(-184);
    Suck_Spin();
    PMGo(18);
    //Go(5,30);
    task::sleep(450);
    PMTurnTo(-161);
    task::sleep(100);
    Go(7,30);
    task::sleep(200);
    PMGo(-9);
    task::sleep(450);
    PMTurnTo(-90);
    Go(12,40);
    PMTurnTo(10);
    PMGo(34);
    task::sleep(300);
    PMTurnTo(110);
    PMGo(6.5);
    Lift_SpinTo(432,100);
    /*PMGo(-20);
    Go(-10,20);
    Hook.set(1);
    PMTurnTo(-40);
    Suck.spin(fwd,100,pct);
    Suck2.spin(fwd,100,pct);
    PMGo(11.7);
    Go(6.5,30);
    task::sleep(300);//到第一个环
    Go(-3,50);
    task::sleep(900);
    PMGo(-9);
    task::sleep(300);
    PMTurnTo(20);
    Go(15,30);
    task::sleep(200);
    PMTurnTo(-175);
    task::sleep(800);
    PMGo(31.5);
    Stop(coast);*/
}
void BR3(){

}
void BL(){
    Go(-31, 100);
    PMTurnTo(35);
    Go(-9.4, 40);
    Hook.set(1);
    PMTurnTo(-18);
    Sucks[2].spin(fwd, 100, pct);
    task::sleep(150);
    Suck_Spin();
    Go(7.8, 90);
    PMGo(3.4);
    Hook.set(0);
    Suck_Stop();
    PMTurnTo(87);
    Go(-11,100);
    Go(-8, 20);
    Hook.set(1);
    PMTurnTo(0);
    Suck_Spin();
    Go(20,100);
    PMTurnTo(47);
    Go(24,100);
    PMTurnTo(57);
    HandR.set(1);
    Sucks[1].spin(fwd,-100,pct);
    Go(8.8,10);
    task::sleep(750);
    Go(-8,80);
    HandR.set(0);
    task::sleep(100);
    Suck_Spin();
    Go(8,80);
    task::sleep(300);
    Go(-25,100);
    task::sleep(400);
}
void BL2(){

}
void BL3(){}
void Skills(){}

#else

void RR(){}
void RR2(){}
void RR3(){}
void RL(){}
void RL2(){}
void RL3(){}
void BR(){}
void BR2(){}
void BR3(){}
void BL(){}
void BL2(){}
void BL3(){}
void Skills(){}

#endif
#endif