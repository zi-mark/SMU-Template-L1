#include "drivercontrol.h"
#include "definer.h"
#include "robot-config.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "initialize.h"

#ifdef KL
    int lv, rv;
    bool save;
    void DC(){
        Stop(coast);
        Brain.Screen.clearScreen(black);
        while(1){

            #if DriversHabit == 1
            lv = Con.Axis3.position() + Con.Axis4.position();
            rv = Con.Axis3.position() - Con.Axis4.position();

            if(Con.ButtonUp.pressing()) Lift_SpinTo(150, 100, 0);
            else if(Con.ButtonDown.pressing()) Lift_SpinTo(30, 100, 0);
            else if(abs(Con.Axis2.position()) > 4) Lift_Spin(Con.Axis2.position());
            else if(Lift_IsDone()) Lift_Stop();

            if(Con.ButtonL1.pressing()) Hook.set(1);
            if(Con.ButtonL2.pressing()) Hook.set(0);

            #elif DriversHabit == 2
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            if(Con.ButtonA.pressing()) Hook.set(1);
            else if(Con.ButtonB.pressing()) Hook.set(0);

            if(Con.ButtonUp.pressing()) Lift_SpinTo(470, 100, 0);
            else if(Con.ButtonL1.pressing()) Lift_Spin(100);
            else if(Con.ButtonL2.pressing()) Lift_Spin(-100);
            else if(Lift_IsDone()) Lift_Stop(hold);

            #elif DriversHabit == 3
            lv = Con.Axis3.position() + Con.Axis1.position();
            rv = Con.Axis3.position() - Con.Axis1.position();

            if(Con.ButtonL1.pressing()) Hook.set(1);
            if(Con.ButtonL2.pressing()) Hook.set(0);

            if(Con.ButtonA.pressing()) Lift_Spin(100);
            else if(Con.ButtonB.pressing()) Lift_Spin(-100);
            else Lift_Stop(hold);


            #endif

            if(abs(lv) < 5) lv = 0;
            if(abs(rv) < 5) rv = 0;
            SpinLR(lv, rv);

            if(Con.ButtonR1.pressing()) Suck_Spin(100);
            else if(Con.ButtonR2.pressing()) Suck_Spin(-100);
            else Suck_Stop();

            if(Con.ButtonY.pressing()) HandR.set(1);
            else HandR.set(0);
            
            if(Con.ButtonX.pressing()) Raise.set(1);
            else Raise.set(0);
        }
    }

#endif