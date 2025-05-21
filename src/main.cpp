#include "vex.h"
#include "definer.h"
#include "robot-config.h"
#include "autonomous.h"
#include "drivercontrol.h"
#include "initialize.h"

using namespace vex;

timer Auto_T;

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
