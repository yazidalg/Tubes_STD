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
            inputUser = facilityMenu();
            cout << "Anda memilih " << inputUser << endl;
        } else if (inputUser == 2) {
            inputUser = memberMenu(LM);
            cout << "Anda memilih " << inputUser << endl;
        } else {
            invalidMenu(inputUser);
        }
        mainMenu();
        cin >> inputUser;
    }
    cout << "Keluar dari program" << endl;
    return 0;
}
