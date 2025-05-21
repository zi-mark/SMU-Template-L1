#include "autonomous.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef CSTU

    #if CSTU == 1
    void GoToMoGo(){
        #if GoType == 1
        PMGo(39);
        Hook.set(1);
        HandR.set(0);
        #elif GoType == 2
        Go(35, 100);
        task::sleep(100);
        Hook.set(1);
        HandR.set(0);
        task::sleep(200);
        #endif
    }

    void RR(){//针对抢负分的6+1淘汰
        // HandR.set(1);
        // GoToMoGo();
        // PMGo(-25);//20
        // Lift_SpinTo(50, 30, 0);
        // Break();
        // Hook.set(0);
        // PMGo(-5);
        // HandR.set(0);
        // PMTurnTo(60);
        // Break();
        // PMGo(-29);
        // Hook.set(1);
        // PMTurnTo(75);
        // Suck_Spin();
        // Break();
        // PMGo(38);
        // Suck_Stop();
        // task::sleep(500);
        // PMTurnTo(30);
        // Hook.set(0);
        // PMTurnTo(-180);
        // Break();
        // PMGo(-20);
        // Hook.set(1);
        // Suck_Spin();

        Lift_SpinTo(540/3, 60);
        PMGo(-12);
        Break();
        Lift_SpinTo(80/3, 100, 0);
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
    void RR2(){}
    void RR3(){}
    void RL(){//针对抢中6环 | 套联队桩后走，再去扣第二
        Lift_SpinTo(150, 80);
        PMGo(-20);
        Break();
        Lift_SpinTo(40);
        PMTurnTo(-40);
        task::sleep(5000);
        PMGo(50);
        PMTurnTo(35);
        Break();
        Go(-10, 20);
        Hook.set(1);
        Suck_Spin();
        Break();
        PMGo(10);
        PMTurnTo(88);
        Break();
        PMGo(23);
        task::sleep(1000);
        PMTurnTo(210);
        Spin_T(30, 1200);


    }
    void RL2(){//针对抢中6环 | 抢负分+负叠1+放正分+拿中间+联队桩
        
    }
    void RL3(){}
    void BR(){//针对正分区自己桩6 | 抢负分1+套联队
        HandR.set(1);
        GoToMoGo();
        PMGo(-20);
        Lift_SpinTo(50, 30, 0);
        Break();
        Hook.set(0);
        PMGo(-5);
        HandR.set(0);
        PMTurnTo(173);
        Break();
        PMGo(-18);
        Hook.set(1);
        Break();
        PMGo(35);
        PMTurnTo(235);
        Suck_Spin();
        Break();
        PMGo(30);
        // task::sleep(1);
        PMTurnTo(170);
        PMGo(-3);
        Break();
        Lift_SpinTo(150, 80);
        PMGo(-10);
        Lift_SpinTo(0, 30, 0);
        PMTurnTo(-10);
        Spin_T(20, 800);

    }
    void BR2(){//针对正分区抢来桩6 | 抢负分+负分叠1+负分塔放+自己1+联队

    }
    void BR3(){}
    void BL(){//针对抢中立的负分区6+1 | 联队桩+拿中立+拿正分叠
        Lift_SpinTo(150, 80);
        PMGo(-20);
        Break();
        Lift_SpinTo(40);
        PMTurnTo(-40);
        task::sleep(4500);
        PMGo(50);
        PMTurnTo(35);
        Break();
        Go(-10, 20);
        Hook.set(1);
        Break();
        PMGo(20);
        PMTurnTo(140);
        Suck_Spin();
        PMGo(65);
        Suck_Stop();
        // task::sleep(300);
        Break();

        PMTurnTo(190);
        Suck_Stop();
        PMGo(22);
        Suck_Spin();
        task::sleep(700);

        Hook.set(0);
        Go(10, 30);
        PMTurnTo(85);


        // PMTurnTo(135+90);
        // PMGo(-10);
        // Suck_Stop();
        // Hook.set(0);
        // Break();
        // PMGo(35);
        // PMTurnTo(45);

    }
    void BL2(){}
    void BL3(){}
    void Skills(){}
    #elif CSTU == 5
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

    #elif CSTU == 6

        void HookSet(bool state){
            if(state){
                HookP.set(0);
                HookR.set(1);
            }
            else{
                HookP.set(1);
                HookR.set(0);
            }
        }
        
        void HandRSet(bool state){
            if(state){
                HandRP.set(1);
                HandRR.set(0);
            }
            else{
                HandRP.set(0);
                HandRR.set(1);
            }
        }

        void HandLSet(bool state){
            if(state){
                HandLP.set(1);
                HandLR.set(0);
            }
            else{
                HandLP.set(0);
                HandLR.set(1);
            }
        }

        void GoToMoGo(){
            #if GoType == 1
            PMGo(39);
            Hook.set(1);
            HandR.set(0);
            #elif GoType == 2
            Go(35, 100);
            task::sleep(100);
            HookLio.set(1);
            // HandRSet(0);
            task::sleep(200);
            #endif
        }
        void GoToMoGo2(){
            #if GoType == 1
            PMGo(39);
            Hook.set(1);
            HandR.set(0);
            #elif GoType == 2
            Go(29.5, 100);
            task::sleep(100);
            HookLio.set(1);
            // HandRSet(0);
            task::sleep(200);
            #endif
        }

        void RR(){//针对抢负分的6+1淘汰
            HandRSet(1);
            GoToMoGo();
            PMGo(-25);//20
            Lift_SpinTo(50, 30, 0);
            Break();
            HookLio.set(0);
            PMGo(-5);
            HandRSet(0);
            PMTurnTo(60);
            Break();
            PMGo(-29);
            HookSet(1);
            PMTurnTo(75);
            Suck_Spin();
            Break();
            PMGo(38);
            Suck_Stop();
            task::sleep(500);
            PMTurnTo(30);
            HookSet(0);
            PMTurnTo(-180);
            Break();
            PMGo(-20);
            HookSet(1);
            Suck_Spin();
    }
        void RR2(){}
        void RR3(){}
        void RL(){

            //针对抢中6环 | 套联队桩后走，再去扣第二
            Suck_Spin(-100);
            Lift_SpinTo(170, 30);
            Suck_Stop();
            PMGo(-20);
            Break();
            Lift_SpinTo(40);
            PMTurnTo(-39);
            task::sleep(2500);
            PMGo(47);
            PMTurnTo(38);
            Break();
            Go(-15, 20);
            Suck_Spin();
            HookSet(1);
            Break();
            PMGo(13);
            PMTurnTo(95);
            Break();
            PMGo(16);
            // task::sleep(500);
            PMTurnTo(150);
            PMGo(50);
            PMTurnTo(104);
            Break();
            PMGo(10);
            Spin_T(40, 800);
            PMGo(-20);
            Break();
            PMTurnTo(220);
            // PMGo(5);
            HandRSet(1);
            Break();
            PMTurnTo(240);
            PMGo(5);
            HandRSet(0);
            PMTurnTo(260);
            PMGo(15);
            Break();


            // HandRSet(1);
            // GoToMoGo2();
            // PMGo(-15);
            // Break();
            // HookLio.set(0);
            // PMGo(-5);
            // HandRSet(0);
            // PMTurnTo(-40);
            // PMGo(12);
            // PMTurnTo(-130);
            // Break();
            // PMGo(-20);
            // // Go(-5, 20);
            // HookSet(1);
            // PMTurnTo(-160);
            // PMGo(45);
            // Lift_SpinTo(50, 100, 0);
            // PMTurnTo(-100);
            // Suck_Spin();
            // Break();
            // // PMGo(19.5);
            // Go(20, 60);
            // PMTurnTo(-140);
            // Break();
            // PMGo(12);
            // Spin_T(30, 500);//
            // PMGo(-15);
            // PMTurnTo(3);
            // Break();
            // PMGo(7);
            // HandLSet(1);
            // // task::sleep(200);
            // Break();
            // PMGo(-5);
            // PMTurnTo(-25);
            // HandLSet(0);
            // PMTurnTo(-40);
            // Break();
            // PMGo(19);
            // PMTurnTo(-7);
            // Break();
            // PMGo(16);
            // HandLSet(1);
            // task::sleep(200);
            // Break();
            // PMGo(-10);
            // HandLSet(0);
            // PMTurnTo(-15);
            // PMGo(12);
            // Break();
            


            

            // PMGo(-43);
            // Break();
            // HookLio.set(0);
            // PMGo(-5);
            // HandRSet(0);
            // PMTurnTo(-165);
            // Lift_SpinTo(50, 30, 0);
            // Break();
            // PMGo(-22);
            // // Go(-5, 20);
            // HookSet(1);
            // PMGo(15);
            // PMTurnTo(-100);
            // Break();
            // Suck_Spin();
            // PMGo(32);
            // PMTurnTo(-165);
            // Break();

            
    }
        void RL2(){}
        void RL3(){}
        void BR(){
            HandLSet(1);
            GoToMoGo2();
            PMGo(-15);
            Break();
            HookLio.set(0);
            PMGo(-5);
            HandLSet(0);
            PMTurnTo(-40);
            PMGo(12);
            PMTurnTo(-130);
            Break();
            PMGo(-20);
            // Go(-5, 20);
            HookSet(1);
            PMTurnTo(-160);
            PMGo(45);
            Lift_SpinTo(50, 100, 0);
            PMTurnTo(-100);
            Suck_Spin();
            Break();
            // PMGo(19.5);
            Go(20, 60);
            PMTurnTo(-140);
            Break();
            PMGo(12);
            Spin_T(30, 500);//
            PMGo(-15);
            PMTurnTo(3);
            Break();
            PMGo(7);
            HandRSet(1);
            // task::sleep(200);
            Break();
            PMGo(-5);
            PMTurnTo(-25);
            HandRSet(0);
            PMTurnTo(-40);
            Break();
            PMGo(19);
            PMTurnTo(-7);
            Break();
            PMGo(16);
            HandRSet(1);
            task::sleep(200);
            Break();
            PMGo(-10);
            HandRSet(0);
            PMTurnTo(-15);
            PMGo(12);
            Break();
        }
        void BR2(){}
        void BR3(){}
        void BL(){}
        void BL2(){}
        void BL3(){}
        void Skills(){
            Lift_SpinTo(170, 30);
            PMGo(-20);
            Break();
            Lift_SpinTo(40);
        }
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

// //针对抢中6环 | 套联队桩后走，再去扣第二
// Suck_Spin();
// Lift_SpinTo(170, 30);
// PMGo(-20);
// Break();
// Lift_SpinTo(40);
// PMTurnTo(-39);
// task::sleep(2500);
// PMGo(47);
// PMTurnTo(38);
// Break();
// Go(-15, 20);
// Suck_Spin();
// HookSet(1);
// Break();
// PMGo(13);
// PMTurnTo(95);
// Break();
// PMGo(16);
// // task::sleep(500);
// PMTurnTo(150);
// PMGo(50);
// PMTurnTo(104);
// Break();
// PMGo(10);
// Spin_T(40, 800);
// PMGo(-20);
// Break();
// PMTurnTo(220);
// // PMGo(5);
// HandRSet(1);
// Break();
// PMTurnTo(240);
// PMGo(5);
// HandRSet(0);
// PMTurnTo(260);
// PMGo(15);
// Break();

// // Lift_SpinTo(130, 100, 0);
// // PMTurnTo(-70);
// // Suck_Stop();
// // PMGo(36);






//gen 1
// void RR(){
//     PMGo(-37);
//     Hook.set(1);
//     // Break();
//     PMGo(10);
//     HandL.set(0);
//     Lift_SpinTo(80);
//     Suck_Spin();
//     task::sleep(1000);
//     PMTurnTo(100);
//     Break();
//     PMGo(13);
//     Spin_T(30, 600);
// }
// void RR2(){
//     Lift_SpinTo(150, 30);
//     PMGo(-30);
//     // Lift_SpinTo(130, 100);
//     Break();
// }
// void RR3(){
//     HandR.set(1);
//     PMGo(39);
//     // Go(30, 100);
//     // Spin_T(10, 500);
//     Hook.set(1);
//     HandR.set(0);
//     PMGo(-20);
//     Break();
//     Hook.set(0);
//     PMGo(-15);
//     HandR.set(0);
//     PMTurnTo(180);
//     Break();
    
// }
// void RL(){
//     Lift_SpinTo(150, 30);
//     PMGo(-30);
//     // Lift_SpinTo(130, 100);
//     Break();

// }
// void RL2(){
//     Lift_SpinTo(150, 30);
//     PMGo(-10);
//     // Lift_SpinTo(130, 100);
//     Break();
//     PMTurnTo(27);
//     Break();
//     PMGo(-52);
//     Hook.set(1);
//     Break();
//     PMGo(25);
//     PMTurnTo(94);
//     Break();

//     Suck_Spin(100);
//     PMGo(30);
//     PMTurnTo(-25);
//     Suck_Stop();
//     Break();
//     task::sleep(8000);
//     PMGo(80);
// }
// void RL3(){
    
// }
// void BR(){
//     Lift_SpinTo(150, 30);
//     PMGo(-30);
//     // Lift_SpinTo(130, 100);
//     Break();
// }
// void BR2(){
//     Lift_SpinTo(150, 30);
//     PMGo(-10);
//     // Lift_SpinTo(130, 100);
//     Break();
//     PMTurnTo(-25.5);//
//     Break();
//     PMGo(-52);
//     Hook.set(1);
//     Break();
//     PMGo(25);
//     PMTurnTo(-94);
//     Break();

//     Suck_Spin(100);
//     PMGo(30);
//     task::sleep(1000);
//     PMTurnTo(28);
//     Suck_Stop();
//     Break();
//     task::sleep(8000);
//     PMGo(80);
// }
// void BR3(){}
// void BL(){
//     PMGo(-37);
//     Hook.set(1);
//     // Break();
//     PMGo(10);
//     Lift_SpinTo(80);
//     HandR.set(0);
//     Suck_Spin();
//     task::sleep(1000);
//     PMTurnTo(-100);
//     Break();
//     PMGo(13);
//     Spin_T(30, 600);

// }
// void BL2(){
//     Lift_SpinTo(150, 30);
//     PMGo(-30);
//     // Lift_SpinTo(130, 100);
//     Break();
// }
// void BL3(){
//     Lift_SpinTo(150, 30);
//     PMGo(-30);
//     Break();
//     Lift_SpinTo(40);
//     PMTurnTo(-20);
//     task::sleep(1);
//     PMGo(30);
//     PMTurnTo(45);
    
// }
// void Skills(){
//     Lift_SpinTo(80, 90, 0);
//     PMGo(-28);
//     Hook.set(1);
//     Break();
//     PMTurnTo(-20);
//     Suck_Spin();
//     PMGo(30);
//     task::sleep(1000);
//     PMTurnTo(-75);
//     // Lift_SpinTo(0);
//     Break();
//     // PMGo(20);
//     Spin_T(50, 1000);
//     Suck_Stop();
//     PMGo(-10);
//     PMTurnTo(105);
//     Hook.set(0);
//     Spin_T(-50, 1000);
//     PMGo(10);
//     Break();
//     PMTurnTo(-35);
//     Break();
//     PMGo(-70);
//     Break();
//     PMTurnTo(-85);
//     Break();
//     PMGo(-30);
//     Hook.set(1);
//     Suck_Spin();
//     Break();
//     PMTurnTo(15);
//     Hook.set(0);
//     Spin_T(-80, 2000);
//     // PMGo(10);



// }