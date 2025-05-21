#include "initialize.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"
#include "autonomous.h"

void Init(){
    
    GR.calibrate();
    ResetPosition();
    Lift_ResetPosition();
    CLSensor.setLight(ledState::on);
    CLSensor.setLightPower(100);
    #if CSTU == 6
    HookP.set(1);
    HandRR.set(1);
    HandLR.set(1);
    #endif
    // #ifdef CSTU
    // if(ProgramChoice == 1) HandL.set(1);
    // else if(ProgramChoice == 8) HandR.set(1);
    // #endif
    
    while(GR.isCalibrating()) continue;
}

int ProgramChoice = 0;
//记得每个自动名字后面要加空格
// const char *ProgramNames[MaxChoice] = {"DC ", "RR ", "RR2 ", "RR3", "RL ", "RL2 ", "RL3 ", "BR ", "BR2", "BR3", "BL ", "BL2 ", "BL3", "SK ", "Test ", "MT "};

#if Selection_Type == 1
void ProgramChoosing(){
    timer T;
    bool save = 1;
    T.reset();
    Con.Screen.setCursor(1,1);
    Con.Screen.print(Auto[ProgramChoice].name);
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Auto[ProgramChoice].name);
    while(T.time() <= 3000){
        if(Selecter.pressing()){
            if(save){
                save = 0;
                ProgramChoice++;
                if(ProgramChoice == MaxChoice) ProgramChoice = 0;

                Con.Screen.clearLine(1);
                Con.Screen.setCursor(1,1);
                Con.Screen.print(Auto[ProgramChoice].name);

                Brain.Screen.clearLine(1);
                Brain.Screen.setCursor(1,1);
                Brain.Screen.print(Auto[ProgramChoice].name);

                T.reset();
            }
        }
        else save = 1;
        task::sleep(100);
    }
}

#else

void ProgramChoosing(){
    timer T;
    bool save = 1;
    T.reset();
    Con.Screen.setCursor(1,1);
    Con.Screen.print(Auto[ProgramChoice].name);
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(Auto[ProgramChoice].name);
    while(T.time() <= 3000){
        if(Brain.Screen.pressing()){
            if(save){
                save = 0;
                ProgramChoice++;
                if(ProgramChoice == MaxChoice) ProgramChoice = 0;

                Con.Screen.clearLine(1);
                Con.Screen.setCursor(1,1);
                Con.Screen.print(Auto[ProgramChoice].name);

                Brain.Screen.clearLine(1);
                Brain.Screen.setCursor(1,1);
                Brain.Screen.print(Auto[ProgramChoice].name);

                T.reset();
            }
        }
        else save = 1;
        task::sleep(100);
    }
}

#endif