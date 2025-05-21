#include "autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"


#ifdef KL
    #if KL == 1 || KL ==2 || KL == 3 || KL == 4
    //1+2 AWP, 联队桩出发
    void P1(int colors){
        Lift_SpinTo(340);//抬坡
        Break();
        // PMGo(8);
        Go(8.5, 20);
        Break();
        Lift_SpinTo(220, 70);//放环
        Suck_Spin(-100);
        task::sleep(500);
        Suck_Stop();
        PMGo(-10);
        Break();
        Lift_SpinTo(0, 100, 0);
        PMTurnTo(-15 * colors);
        Break();
        PMGo(-17);
        Go(-10, 40);
        Hook.set(1);
        PMTurnTo(-125 * colors);
        Suck_Spin();
        Break();
        PMGo(15);
        PMTurnTo(18 * colors);
        Break();
        PMGo(35);
        Go(5, 30);
        Suck_Stop();
        PMTurnTo(80 * colors);
        Suck_Spin(-100);
        task::sleep(600);
        PMTurnTo(18 * colors);
        Suck_Spin();
        PMGo(25);
        PMGo(-50);
        Break();
        PMTurnTo(98 * colors);
        PMGo(24);
    }
    //2，面对Mogo出发，碰杆
    void P2(int colors){
        PMGo(-22);
        Go(-10, 30);
        Hook.set(1);
        Break();
        Suck_Spin();
        PMTurnTo(-90 * colors);
        Break();
        PMGo(24);
        PMTurnTo(110 * colors);
        Break();
        PMGo(40);
    }
    //屁股抢中立1+1，碰杆，近围板出发
    void P3(int colors){
        PMGo(-36);
        Break();
        PMTurnTo(-30 * colors);
        Break();
        Go(-13, 40);
        Hook.set(1);
        Break();
        Suck_Spin();
        PMTurnTo(10 * colors);
        task::sleep(600);
        Break();
        PMGo(17);
        Hook.set(0);
        Suck_Stop();
        Break();
        PMTurnTo(-90 * colors);
        Break();

        PMGo(-16);
        Go(-5, 20);
        Hook.set(1);
        Break();

        Suck_Spin();
        task::sleep(700);
        PMTurnTo(-230 * colors);
        task::sleep(1000);
        Break();
        PMGo(20);
        Suck_Stop();

    }
     // 1+3，碰杆，AWP，联队桩出发
    void N1(int colors){
        Lift_SpinTo(340);//抬坡
        Break();
        // PMGo(8);
        Go(8.5, 30);
        Break();
        Lift_SpinTo(220, 70);//放环
        Suck_Spin(-100);
        task::sleep(300);
        Suck_Stop();
        PMGo(-10);
        Break();
        Lift_SpinTo(0, 100, 0);
        PMTurnTo(15 * colors);
        Break();
        PMGo(-17);
        Go(-7, 40);
        Hook.set(1);
        Break();
        PMTurnTo(175 * colors);
        Suck_Spin();
        Break();
        PMGo(22);//第一个
        Break();
        PMGo(-15);
        PMTurnTo(125 * colors);
        Break();
        PMGo(17);//第二个
        PMTurnTo(190 * colors);
        Break();
        PMGo(11);//第三个
        Break();
        PMGo(-20);
        PMTurnTo(272 * colors);
        Break();
        PMGo(33);
    }
    //2，碰杆，面对Mogo出发
    void N2(int colors){
        PMGo(-22);
        Go(-10, 30);
        Hook.set(1);
        Break();
        Suck_Spin();
        PMTurnTo(90 * colors);
        Break();
        PMGo(24);
        PMTurnTo(-110 * colors);
        Break();
        PMGo(40);

    }
    //1+4，不碰杆，联队桩出发
    void N3(int colors){
        Lift_SpinTo(340);//抬坡
        Break();
        // PMGo(8);
        Go(8.5, 30);
        Break();
        Lift_SpinTo(220, 70);//放环
        Suck_Spin(-100);
        task::sleep(300);
        Suck_Stop();
        PMGo(-10);
        Break();
        Lift_SpinTo(0, 100, 0);
        PMTurnTo(15 * colors);
        Break();
        PMGo(-17);
        Go(-7, 40);
        Hook.set(1);
        Break();
        PMTurnTo(175 * colors);
        Suck_Spin();
        Break();
        PMGo(22);//第一个
        Break();
        PMGo(-15);
        PMTurnTo(125 * colors);
        Break();
        PMGo(17);//第二个
        PMTurnTo(190 * colors);
        Break();
        PMGo(11);//第三个
        Break();
        PMGo(-38);
        PMTurnTo(310 * colors);
        Break();
        PMGo(20);
        Go(5, 50);
        Suck_Stop();
        PMTurnTo(250 * colors);
        Suck_Spin(-100);
        task::sleep(500);
        Suck_Stop();
        Break();
        PMTurnTo(310 * colors);
        Suck_Spin();
        Break();
        PMGo(25);//第四个

    }
    
    
    void Skills(){}
    #elif KL ==6

    void P1(int colors){
        Lift_SpinTo(540, 90);
        PMGo(-12);
        Break();
        Lift_SpinTo(80, 100, 0);
        PMTurnTo(-55 * colors);
        Break();
        PMGo(-25);
        // Go(-7, 40);
        Hook.set(1);
        Break();
        PMTurnTo(-145 * colors);
    }
    void P2(int colors){
        Lift_SpinTo(80, 100, 0);
        PMGo(-28);
        // Go(-10, 30);
        Hook.set(1);
        Break();
        Suck_Spin();
        PMTurnTo(-90 * colors);
        Break();
        PMGo(24);
        PMTurnTo(100 * colors);
        Break();
        PMGo(37);
    }
    void P3(int colors){}
    void N1(int colors){
        Lift_SpinTo(540, 90);
        PMGo(-12);
        Break();
        Lift_SpinTo(80, 100, 0);
        PMTurnTo(55 * colors);
        Break();
        PMGo(-25);
        // Go(-7, 40);
        Hook.set(1);
        Break();
        PMTurnTo(192 * colors);
        Suck_Spin();
        Break();
        PMGo(22);//第一个
        Break();
        PMGo(-15);
        PMTurnTo(142 * colors);
        Break();
        PMGo(17);//第二个
        PMTurnTo(210 * colors);
        Break();
        PMGo(11);//第三个
        Break();
        PMGo(-20);
        PMTurnTo(295 * colors);
        Break();
        PMGo(33);

    }
    void N2(int colors){
        Lift_SpinTo(80, 100, 0);
        PMGo(-28);
        // Go(-10, 30);
        Hook.set(1);
        Break();
        Suck_Spin();
        PMTurnTo(90 * colors);
        Break();
        PMGo(24);
        PMTurnTo(-100 * colors);
        Break();
        PMGo(37);
}
    void N3(int colors){}
    void Skills(){}
    
    #endif

    void RR(){P1(1);}
    void RR2(){P2(1);}
    void RR3(){P3(1);}
    void RL(){N1(1);}
    void RL2(){N2(1);}
    void RL3(){N3(1);}
    void BR(){N1(-1);}
    void BR2(){N2(-1);}
    void BR3(){N3(-1);}
    void BL(){P1(-1);}
    void BL2(){P2(-1);}
    void BL3(){P3(-1);}

#endif


// // version 1.0
    // void RR(){
    //     //thread CL(ColorSelecting);
    //     Suck_Stop(hold);
    //     PMGo(-14);//推开两个环
    //     Break();
    //     PMTurnTo(90);//对准联队桩
    //     Break();
    //     Lift_SpinTo(370);//抬坡
    //     task::sleep(300);
    //     Break();
    //     PMGo(5);//环对准尖头
    //     Break();
    //     Lift_SpinTo(220, 40);//放环
    //     Break();
    //     PMGo(-10);//离开
    //     Break();

    //     PMTurnTo(136);//对准右塔
    //     Break();
    //     Lift_SpinTo(0, 90, 0);
    //     PMGo(-27.5);//边降坡边后退
    //     Go(-5, 20);
    //     Hook.set(1);//钩右塔
    //     Break();

    //     Suck_Spin(100);
    //     PMTurnTo(0);//面对右红环
    //     Break();
    //     PMGo(25);//前进吸
    //     Break();
    //     PMTurnTo(200);//对高挂杆
    //     // Hook.set(0);
    //     Break();
    //     PMGo(39);//碰杆
    //     // Suck.stop(hold);
    //     //CL.join();
    // }

    // void RR2(){
    //     PMGo(-22);
    //     Go(-10, 30);
    //     Hook.set(1);
    //     Break();
    //     Suck_Spin();
    //     PMTurnTo(-90);
    //     task::sleep(600);
    //     Break();
    //     PMGo(24);
    //     task::sleep(600);
    //     PMTurnTo(93);
    //     Hook.set(0);
    //     task::sleep(600);
    //     Break();
    //     PMGo(45);
        
    // }

    // // void RR3(){
    //     // Suck.stop(hold);
    //     // PMGo(-14);//推开两个环
    //     // Break();
    //     // PMTurnTo(90);//对准联队桩
    //     // Break();
    //     // Lift.spinTo(370, deg, 90, velocityUnits::pct);//抬坡
    //     // task::sleep(300);
    //     // Break();
    //     // PMGo(5);//环对准尖头
    //     // Break();
    //     // Lift.spinTo(220, deg, 40, velocityUnits::pct);//放环
    //     // Break();
    //     // PMGo(-10);//离开
    //     // Break();

    //     // PMTurnTo(136);//对准右塔
    //     // Break();
    //     // Lift.spinTo(0, deg, 90, velocityUnits::pct, 0);
    //     // PMGo(-27.5);//边降坡边后退
    //     // Go(-6.5, 20);
    //     // Hook.set(1);//钩右塔
    //     // Suck.spin(fwd, 100, velocityUnits::pct);
    //     // Break();

    //     // PMTurnTo(45);
    //     // Lift.spinTo(100, deg, 100, velocityUnits::pct);
    //     // // Suck.spin(fwd, -100, pct);
    //     // Break();
    //     // PMGo(50);
    //     // // Suck.spin(fwd, 100, pct);
    //     // Break();
    //     // task::sleep(600);
    //     // Lift.spinTo(0, deg, 100, velocityUnits::pct, 0);
    //     // PMGo(-14);


    //     // Break();
    //     // PMTurnTo(-90);
    //     // Break();

    //     // PMGo(30);
    //     // Break();
    //     // PMTurnTo(-171);
    //     // Break();
    //     // PMGo(38);
    // // }

    // void RR3(){
    //     PMGo(-36);
    //     Break();
    //     PMTurnTo(-30);
    //     Break();
    //     PMGo(-8);
    //     Go(-5, 20);
    //     Hook.set(1);
    //     Break();
    //     Suck_Spin();
    //     task::sleep(400);
    //     PMTurnTo(10);
    //     task::sleep(600);
    //     Hook.set(0);
    //     Break();
    //     PMGo(17);
    //     Suck.stop();
    //     Break();
    //     PMTurnTo(-90);
    //     Break();

    //     PMGo(-16);
    //     Go(-5, 20);
    //     Hook.set(1);
    //     Break();

    //     Suck_Spin();
    //     task::sleep(700);
    //     PMTurnTo(-230);
    //     task::sleep(500);
    //     Break();
    //     PMGo(20);

    // }

    // void RL(){
    //     Suck_Stop(hold);
    //     PMGo(-14);//推开两个环
    //     Break();
    //     PMTurnTo(-90);//对准联队桩
    //     Break();
    //     Lift_SpinTo(370);//抬坡
    //     task::sleep(300);
    //     Break();
    //     PMGo(5);//环对准尖头
    //     Break();
    //     Lift_SpinTo(220, 40);//放环
    //     Break();
    //     PMGo(-10);//离开
    //     Break();

    //     PMTurnTo(-136);//对准右塔
    //     Break();
    //     Lift_SpinTo(0, 90, 0);
    //     PMGo(-27.5);//边降坡边后退
    //     Go(-5, 20);
    //     Hook.set(1);//钩右塔
    //     Break();

    //     Suck_Spin();
    //     PMTurnTo(45);//对准右边二层
    //     Break();
    //     PMGo(19);//吸右边二层
    //     Break();
    //     PMTurnTo(20);//对准左边二层
    //     Break();
    //     PMGo(5);//吸左边二层// 7
    //     Break();
    //     PMGo(-16);//返回准备旋转
    //     Break();

    //     PMTurnTo(-23);//对准左后两层
    //     Break(); 
    //     PMGo(19);//吸左后两层
    //     Break();
    //     PMTurnTo(-195);//对准高挂杆
    //     //Suck.stop();
    //     Break();
    //     PMGo(40);
    // }

    // void RL2(){
    //     Suck_Stop(hold);
    //     PMGo(-14);//推开两个环
    //     Break();
    //     PMTurnTo(-90);//对准联队桩
    //     Break();
    //     Lift_SpinTo(370);//抬坡
    //     task::sleep(300);
    //     Break();
    //     PMGo(5);//环对准尖头
    //     Break();
    //     Lift_SpinTo(220, 40);//放环
    //     Break();
    //     PMGo(-10);//离开
    //     Break();

    //     PMTurnTo(-136);//对准右塔
    //     Break();
    //     Lift_SpinTo(0, 90, 0);
    //     PMGo(-27.5);//边降坡边后退
    //     Go(-5, 20);
    //     Hook.set(1);//钩右塔
    //     Break();

    //     Suck_Spin();
    //     PMTurnTo(45);//对准右边二层
    //     Break();
    //     PMGo(19);//吸右边二层
    //     Break();
    //     PMTurnTo(20);//对准左边二层
    //     Break();
    //     PMGo(7);//吸左边二层
    //     Break();
    //     PMGo(-16);//返回准备旋转
    //     Break();

    //     PMTurnTo(-23);//对准左后两层
    //     Break(); 
    //     PMGo(19);//吸左后两层
    //     Break();

    //     PMTurnTo(-45);
    //     Lift_SpinTo(100, 100);
    //     Break();
    //     PMGo(50);
    //     Spin_T(30, 500);
    //     Break();

    //     Lift_SpinTo(0, 100, 0);
    //     PMGo(-70);
    // }

    // void RL3(){
    //     thread CL(Auto_CLSorting);
    //     Lift_SpinTo(340);//抬坡
    //     Break();
    //     // PMGo(8);
    //     Go(8.5, 30);
    //     Break();
    //     Lift_SpinTo(220, 70);//放环
    //     Suck_Spin(-100);
    //     task::sleep(300);
    //     Suck_Stop();
    //     PMGo(-10);
    //     Break();
    //     Lift_SpinTo(0, 100, 0);
    //     PMTurnTo(15);
    //     Break();
    //     PMGo(-17);
    //     Go(-7, 40);
    //     Hook.set(1);
    //     Break();
    //     PMTurnTo(175);
    //     Suck_Spin();
    //     Break();
    //     PMGo(22);//第一个
    //     Break();
    //     PMGo(-15);
    //     PMTurnTo(125);
    //     Break();
    //     PMGo(17);//第二个
    //     PMTurnTo(190);
    //     Break();
    //     PMGo(11);//第三个
    //     Break();
    //     PMGo(-38);
    //     PMTurnTo(310);
    //     Break();
    //     PMGo(20);
    //     Go(5, 50);
    //     Suck_Stop();
    //     PMTurnTo(250);
    //     Suck_Spin(-100);
    //     task::sleep(500);
    //     Suck_Stop();
    //     Break();
    //     PMTurnTo(310);
    //     Suck_Spin();
    //     Break();
    //     PMGo(25);//第四个
    // }

    // void BR(){
    //     Suck.stop(hold);
    //     PMGo(-14);//推开两个环
    //     Break();
    //     PMTurnTo(90);//对准联队桩
    //     Break();
    //     Lift_SpinTo(370);//抬坡
    //     task::sleep(300);
    //     Break();
    //     PMGo(5);//环对准尖头
    //     Break();
    //     Lift_SpinTo(220, 40);//放环
    //     Break();
    //     PMGo(-10);//离开
    //     Break();

    //     PMTurnTo(136);//对准右塔
    //     Break();
    //     Lift_SpinTo(0, 100, 0);
    //     PMGo(-27.5);//边降坡边后退
    //     Go(-5, 20);
    //     Hook.set(1);//钩右塔
    //     Break();

    //     Suck_Spin();
    //     PMTurnTo(-45);//对准右边二层
    //     Break();
    //     PMGo(19);//吸右边二层
    //     Break();
    //     PMTurnTo(-20);//对准左边二层
    //     Break();
    //     PMGo(4);//吸左边二层// 7
    //     Break();
    //     PMGo(-16);//返回准备旋转
    //     Break();

    //     PMTurnTo(23);//对准左后两层
    //     Break(); 
    //     PMGo(19);//吸左后两层
    //     Break();
    //     PMTurnTo(195);//对准高挂杆
    //     //Suck.stop();
    //     Break();
    //     PMGo(40);
    // }

    // void BR2(){}

    // void BR3(){
    //     thread CL(Auto_CLSorting);
    //     Lift_SpinTo(340);//抬坡
    //     Break();
    //     // PMGo(8);
    //     Go(8.5, 30);
    //     Break();
    //     Lift_SpinTo(220, 70);//放环
    //     Suck_Spin(-100);
    //     task::sleep(300);
    //     Suck_Stop();
    //     PMGo(-10);
    //     Break();
    //     Lift_SpinTo(0, 100, 0);
    //     PMTurnTo(15);
    //     Break();
    //     PMGo(-17);
    //     Go(-7, 40);
    //     Hook.set(1);
    //     Break();
    //     PMTurnTo(175);
    //     Suck_Spin();
    //     Break();
    //     PMGo(22);//第一个
    //     Break();
    //     PMGo(-15);
    //     PMTurnTo(125);
    //     Break();
    //     PMGo(17);//第二个
    //     PMTurnTo(190);
    //     Break();
    //     PMGo(11);//第三个
    //     Break();
    //     PMGo(-38);
    //     PMTurnTo(310);
    //     Break();
    //     PMGo(20);
    //     Go(5, 50);
    //     Suck_Stop();
    //     PMTurnTo(250);
    //     Suck_Spin(-100);
    //     task::sleep(500);
    //     Suck_Stop();
    //     Break();
    //     PMTurnTo(310);
    //     Suck_Spin();
    //     Break();
    //     PMGo(25);//第四个
    // }

    // void BL(){
    //     Suck_Stop(hold);
    //     PMGo(-14);//推开两个环
    //     Break();
    //     PMTurnTo(-90);//对准联队桩
    //     Break();
    //     Lift_SpinTo(370);//抬坡
    //     task::sleep(300);
    //     Break();
    //     PMGo(5);//环对准尖头
    //     Break();
    //     Lift_SpinTo(220, 40);//放环
    //     Break();
    //     PMGo(-10);//离开
    //     Break();

    //     PMTurnTo(-136);//对准右塔
    //     Break();
    //     Lift_SpinTo(0, 90, 0);
    //     PMGo(-27.5);//边降坡边后退
    //     Go(-5, 20);
    //     Hook.set(1);//钩右塔
    //     Break();

    //     Suck_Spin();
    //     PMTurnTo(0);//面对右红环
    //     Break();
    //     PMGo(25);//前进吸
    //     Break();
    //     PMTurnTo(-200);//对高挂杆
    //     // Hook.set(0);
    //     Break();
    //     PMGo(39);//碰杆
    //     // Suck.stop(hold);
    // }

    // void BL2(){
    //     PMGo(-22);
    //     Go(-10, 30);
    //     Hook.set(1);
    //     Break();
    //     Suck_Spin();
    //     PMTurnTo(90);
    //     task::sleep(600);
    //     Break();
    //     PMGo(24);
    //     task::sleep(600);
    //     PMTurnTo(-93);
    //     Hook.set(0);
    //     task::sleep(600);
    //     Break();
    //     PMGo(45);
    // }

    // void BL3(){
    //     PMGo(-36);
    //     Break();
    //     PMTurnTo(30);
    //     Break();
    //     PMGo(-8);
    //     Go(-5, 20);
    //     Hook.set(1);
    //     Break();
    //     Suck_Spin();
    //     task::sleep(400);
    //     PMTurnTo(-10);
    //     task::sleep(600);
    //     Hook.set(0);
    //     Break();
    //     PMGo(17);
    //     Suck_Stop();
    //     Break();
    //     PMTurnTo(90);
    //     Break();

    //     PMGo(-16);
    //     Go(-5, 20);
    //     Hook.set(1);
    //     Break();

    //     Suck_Spin();
    //     task::sleep(700);
    //     PMTurnTo(230);
    //     task::sleep(500);
    //     Break();
    //     PMGo(20);
    // }

    // void Skills(){

    // }

