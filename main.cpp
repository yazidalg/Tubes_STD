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
    int inputUser = menu();
    while (inputUser != 0){
        if (inputUser == 1){
            menu1(LF,LM);
        }else if (inputUser == 2){
            
        }
        menu();
    }
    std::cout << inputUser;
    return 0;
}
