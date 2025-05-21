#include "drivercontrol.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef SF

    int lv, rv;
    bool save;

    #if SF == 1 || SF == 3

    void DC(){
        Stop(coast);
        Brain.Screen.clearScreen(black);
        while(1){

            #if DriversHabit == 1
            lv = Con.Axis3.position() + Con.Axis4.position();
            rv = Con.Axis3.position() - Con.Axis4.position();

            if(Con.ButtonUp.pressing()) Lift_SpinTo(60, 100, 0);
            else if(Con.ButtonDown.pressing()) Lift_SpinTo(30, 100, 0);
            else if(Con.ButtonY.pressing()) Lift_SpinTo(90, 100, 0);
            else if(abs(Con.Axis2.position()) > 4) Lift_Spin(Con.Axis2.position());
            else if(Lift_IsDone()) Lift_Stop();

            if(Con.ButtonL1.pressing()) Hook.set(1);
            if(Con.ButtonL2.pressing()) Hook.set(0);

            #elif DriversHabit == 2
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            if(Con.ButtonA.pressing()) Hook.set(1);
            else if(Con.ButtonB.pressing()) Hook.set(0);

            if(Con.ButtonUp.pressing()) Lift.spinTo(470, deg, 100, velocityUnits::pct, 0);
            else if(Con.ButtonL1.pressing()) Lift.spin(fwd, 100, pct);
            else if(Con.ButtonL2.pressing()) Lift.spin(fwd, -100, pct);
            else if(Lift.isDone()) Lift.stop(hold);

            #endif

            if(abs(lv) < 5) lv = 0;
            if(abs(rv) < 5) rv = 0;
            SpinLR(lv, rv);

            if(Con.ButtonR1.pressing()) Suck_Spin(100);
            else if(Con.ButtonR2.pressing()) Suck_Spin(-100);
            else Suck_Stop(coast);

            if(Con.ButtonX.pressing()) CLSelector.set(1);
            else if(Con.ButtonA.pressing()) ColorSelecting(ProgramChoice);
            else CLSelector.set(0);

            if(Con.ButtonB.pressing()) HandR.set(1);
            else HandR.set(0);

        }
    }

    #elif SF == 2
    void DC(){
        bool save = 1;
        bool save1 = 1;
        Stop(coast);
        while(1){

            #if DriversHabit == 1
            lv = Con.Axis3.position() + Con.Axis4.position();
            rv = Con.Axis3.position() - Con.Axis4.position();

            //if(abs(Con.Axis2.position()) > 4) Lift.spin(fwd, Con.Axis2.position(), pct);
            //else Lift.stop(hold);

            if(Con.ButtonL1.pressing()) Lift_Spin(100);
            else if(Con.ButtonL2.pressing()) Lift_Spin(-100);
            else if(Con.ButtonY.pressing()) Lift_SpinTo(70, 100, 0);
            else if(Lift_IsDone())Lift_Stop(hold);

            if(Con.ButtonX.pressing()) {
                if(save){
                    save = 0; 
                    Hook.set(!Hook.value());
                }
            }
            else save = 1;
    
            if(Con.ButtonB.pressing()) {
                if(save1){
                    save1 = 0;
                    HandR.set(!HandR.value());
                }
            }
            else save1 = 1;

            //if(Con.ButtonL1.pressing()) Hook.set(1);
            //if(Con.ButtonL2.pressing()) Hook.set(0);

            #elif DriversHabit == 2
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            if(Con.ButtonX.pressing()) {
                if(save){
                    save = 0; 
                    Hook.set(!Hook.value());
                    wait(150,msec);
                }else{
                    save = 1; 
                    Hook.set(!Hook.value());
                    wait(150,msec);}

            };
            if(Con.ButtonL1.pressing()) Lift.spin(fwd, 100, pct);
            else if(Con.ButtonL2.pressing()) Lift.spin(fwd, -100, pct);
            else if(Con.ButtonY.pressing()) Lift.spinToPosition(90, deg, 90, velocityUnits::pct, 0);
            else if(Lift.isDone())Lift.stop(hold);

            #endif

            if(abs(lv) < 5) lv = 0;
            if(abs(rv) < 5) rv = 0;
            SpinLR(lv, rv);

            if(Con.ButtonR2.pressing()) Suck_Spin(-100);
            else if(Con.ButtonR1.pressing()) Suck_Spin(100);
            else Suck_Stop();

        }
    }

    #elif SF == 4
    void DC(){
        Stop(coast);
        Brain.Screen.clearScreen(black);
            while(1){
    
                #if DriversHabit == 1
                lv = Con.Axis3.position() + Con.Axis4.position();
                rv = Con.Axis3.position() - Con.Axis4.position();
    
                if(Con.ButtonY.pressing()) Lift_SpinTo(300, 100, 0);
                else if(Con.ButtonX.pressing()) Lift_SpinTo(50, 100, 0);
                else if(abs(Con.Axis2.position()) > 4){
                    if(Lift_AverPosition() <= 480 || abs(Con.Axis1.position()) >= 40) Lift_Spin(Con.Axis2.position());
                    else if(Con.Axis2.position() <= 4) Lift_Spin(Con.Axis2.position());
                    else Lift_Stop() ;
                }
                else if(Lift_IsDone()) Lift_Stop();
    
                if(Con.ButtonL1.pressing()) Hook.set(1);
                if(Con.ButtonL2.pressing()) Hook.set(0);
    
                #elif DriversHabit == 2
                lv = Con.Axis3.position() + Con.Axis1.position();
                rv = Con.Axis3.position() - Con.Axis1.position();
    
                if(Con.ButtonA.pressing()) Hook.set(1);
                else if(Con.ButtonB.pressing()) Hook.set(0);
    
                if(Con.ButtonUp.pressing()) Lift_SpinTo(150, 100, 0);
                else if(Con.ButtonDown.pressing()) Lift_SpinTo(30, 100, 0);
                else if(Con.ButtonL1.pressing()) Lift_Spin(100);
                else if(Con.ButtonL2.pressing()) Lift_Spin(-100);
                else if(Lift_IsDone()) Lift_Stop(hold);
    
                #endif
    
                if(abs(lv) < 5) lv = 0;
                if(abs(rv) < 5) rv = 0;
                SpinLR(lv, rv);
    
                if(Con.ButtonR1.pressing()) Suck_Spin(100);
                else if(Con.ButtonR2.pressing()) Suck_Spin(-100);
                else Suck_Stop(coast);
                
                if(Lift_AverPosition() > 130) HandR.set(1);
                else if(Con.ButtonB.pressing()) HandR.set(1);
                else HandR.set(0);
    
                // if(Con.ButtonY.pressing()) HandL.set(1);
                // else HandL.set(0);
    
            }
        }
    #elif SF == 5

    void DC(){
        bool save = 1;
            bool save1 = 1;
            Stop(coast);
            while(1){
        
                #if DriversHabit == 1
                lv = Con.Axis3.position() + Con.Axis4.position();
                rv = Con.Axis3.position() - Con.Axis4.position();
        
                //if(abs(Con.Axis2.position()) > 4) Lift.spin(fwd, Con.Axis2.position(), pct);
                //else Lift.stop(hold);
        
                if(Con.ButtonL1.pressing()) Lift_Spin(100);
                else if(Con.ButtonL2.pressing()) Lift_Spin(-100);
                else if(Con.ButtonY.pressing()) Lift_SpinTo(60, 100, 0);
                else if(Lift_IsDone())Lift_Stop(hold);
        
                if(Con.ButtonX.pressing()) {
                    if(save){
                         save = 0; 
                         Hook.set(!Hook.value());
                     }
                }
                else save = 1;
         
                if(Con.ButtonB.pressing()) {
                    if(save1){
                         save1 = 0;
                         HandR.set(!HandR.value());
                     }
                }
                else save1 = 1;
        
                //if(Con.ButtonL1.pressing()) Hook.set(1);
                //if(Con.ButtonL2.pressing()) Hook.set(0);
        
                #elif DriversHabit == 2
                lv = Con.Axis3.position() + Con.Axis1.position();
                rv = Con.Axis3.position() - Con.Axis1.position();
        
                if(Con.ButtonX.pressing()) {
                    if(save){
                         save = 0; 
                         Hook.set(!Hook.value());
                         wait(150,msec);
                     }else{
                        save = 1; 
                         Hook.set(!Hook.value());
                         wait(150,msec);}
        
                };
                if(Con.ButtonL1.pressing()) Lift.spin(fwd, 100, pct);
                else if(Con.ButtonL2.pressing()) Lift.spin(fwd, -100, pct);
                else if(Con.ButtonY.pressing()) Lift.spinToPosition(90, deg, 90, velocityUnits::pct, 0);
                else if(Lift.isDone())Lift.stop(hold);
        
                #endif
        
                if(abs(lv) < 5) lv = 0;
                if(abs(rv) < 5) rv = 0;
                SpinLR(lv, rv);
        
                if(Con.ButtonR2.pressing()){
                    Suck_Spin(-100);
                    }
                else if(Con.ButtonR1.pressing()){
                    Suck_Spin(100);
                }
                else {
                 Suck_Stop(coast);
                }
        
            }
        }

    #endif
#endif

