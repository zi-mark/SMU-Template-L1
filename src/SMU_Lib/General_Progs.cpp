#include "SMU_Lib/autonomous.h"
#include "SMU_Lib/drivercontrol.h"
#include "definer.h"
#include "SMU_Lib/chasis.h"
#include "SMU_Lib/functional.h"

//测自动断点
void Break(){
    if(!Com.isFieldControl() && !Com.isCompetitionSwitch()){
    while(!Con.ButtonA.pressing()) continue;
    }
}

void PrintChoice(int ProgramChoice){
    switch (ProgramChoice)
    {
    case 0:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("DC ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("DC ");
        break;
    case 1:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RR ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RR ");
        break;
    case 2:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RR2 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RR2 ");
        break;
    case 3:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RR3 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RR3 ");
        break;
    case 4:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RL ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RL ");
        break;
    case 5:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RL2 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RL2 ");
        break;
    case 6:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("RL3 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("RL3 ");
        break;
    case 7:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BL ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BL ");
        break;
    case 8:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BL2 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BL2 ");
        break;
    case 9:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BL3 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BL3 ");
        break;
    case 10:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BR ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BR ");
        break;
    case 11:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BR2 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BR2 ");
        break;
    case 12:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("BR3 ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("BR3 ");
        break;
    case 13:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("SK ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("SK ");
        break;
    case 14:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("Test ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Test ");
        break;
    case 15:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("MT ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("MT ");
        break;
    default:
        Con.Screen.clearLine(1);
        Con.Screen.setCursor(1,1);
        Con.Screen.print("Error ");
        Brain.Screen.clearLine(1);
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Error ");
        break;
    }
    
}

void GetChoice(){
    switch (ProgramChoice)
    {
    case 0: DC(); break;
    case 1: RR(); break;
    case 2: RR2(); break;
    case 3: RR3(); break;
    case 4: RL(); break;
    case 5: RL2(); break;
    case 6: RL3(); break;
    case 7: BL(); break;
    case 8: BL2(); break;
    case 9: BL3(); break;
    case 10: BR(); break;
    case 11: BR2(); break;
    case 12: BR3(); break;
    case 13: Skills(); break;
    case 14: Test(); break;
    case 15: Motor_Test(); break;
    default: break;
    }
    
}

int ProgramChoice = 0;
//屏幕选程序
void ProgramChoosing(){
    timer T;
    bool save = 1;
    T.reset();
    PrintChoice(ProgramChoice);
    while(T.time() <= 3000){
        if(Brain.Screen.pressing()){
            if(save){
                save = 0;
                ProgramChoice++;
                if(ProgramChoice == MaxChoice) ProgramChoice = 0;

                PrintChoice(ProgramChoice);

                T.reset();
            }
        }
        else save = 1;
        task::sleep(100);
    }
}

//测试函数
void Test(){

    while(1){
        if(Con.ButtonUp.pressing()){
            ResetPosition();
            PMGo(24);
            Brain.Screen.newLine();
            Brain.Screen.print(AverPosition(deg));
        }
        else if(Con.ButtonDown.pressing()){
            ResetPosition();
            PMGo(-24);
            Brain.Screen.newLine();
            Brain.Screen.print(AverPosition(deg));
        }
        else if(Con.ButtonA.pressing()){
            PMTurnTo(90);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonY.pressing()){
            PMTurnTo(-90);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonX.pressing()){
            PMTurnTo(0);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
        else if(Con.ButtonB.pressing()){
            PMTurnTo(180);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
            task::sleep(3000);
            Brain.Screen.newLine();
            Brain.Screen.print(GR.rotation());
        }
    }
    
}



//YBA-123-RDL
void Motor_Test(){
    while(1){
        if(Con.ButtonY.pressing()) LMs[0].spin(forward, 100, percent);
        else LMs[0].stop(coast);
        if(Con.ButtonB.pressing()) LMs[1].spin(forward, 100, percent);
        else LMs[1].stop(coast);
        if(Con.ButtonA.pressing()) LMs[2].spin(forward, 100, percent);
        else LMs[2].stop(coast);
        if(Con.ButtonRight.pressing()) RMs[0].spin(forward, 100, percent);
        else RMs[0].stop(coast);
        if(Con.ButtonDown.pressing()) RMs[1].spin(forward, 100, percent);
        else RMs[1].stop(coast);
        if(Con.ButtonLeft.pressing()) RMs[2].spin(forward, 100, percent);
        else RMs[2].stop(coast);
    }
}