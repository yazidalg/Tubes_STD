//
//  main.cpp
//  Data_Gym_STD
//
//  Created by yazidal on 16/12/23.
//
#include "gym.hpp"

int main(int argc, const char * argv[]) {
    listFacility LF;
    listMember LM;
    initList(LF, LM);
    int inputUser = mainMenu();
    while (inputUser != 0) {
        if (inputUser == 1) {
            facilityMenu(LF,LM);
        } else if (inputUser == 2) {
            memberMenu(LF, LM);
        } else if (inputUser == 3) {
            showAllData(LF, LM);
        } else {
            invalidMenu(inputUser);
        }
        inputUser = mainMenu();
    }
    cout << "Keluar dari program" << endl;
    return 0;
}
