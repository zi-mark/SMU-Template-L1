#include "vex.h"
#include "definer.h"
#include "robot-config.h"
#include "autonomous.h"
#include "drivercontrol.h"
#include "initialize.h"

using namespace vex;

timer Auto_T;

// void (*Auto[MaxChoice])() = {&DC, &RR, &RR2, &RR3, &RL, &RL2, &RL3, &BR, &BR2,&BR3,  &BL, &BL2, &BL3, &Skills, &Test, &Motor_Test};

int main(){
    Brain.Screen.clearScreen();
    #ifndef Testing
    ProgramChoosing();
    #endif
    Init();
    #ifndef Testing
    if(Com.isCompetitionSwitch() || Com.isFieldControl()){
        Com.drivercontrol(DC);
        Com.autonomous(Auto[ProgramChoice].Funcs);
        Con.Screen.print("Competition ");
    }
    else{
        Con.Screen.print("Not Competition ");
        while(!Con.ButtonA.pressing()) continue;
        Auto_T.reset();
        Auto[ProgramChoice].Funcs();
        Con.Screen.newLine();
        Con.Screen.print(Auto_T.value());
        DC();
    }
    #else
    Con.Screen.print("Init Compelete");
    while(!Con.ButtonA.pressing()) continue;
    Auto_T.reset();
    // Test();
    // Skills();
    RL();
    // DC();
    Con.Screen.print(Auto_T.value());
    #endif
    
 while(1) wait(10,msec);
}
