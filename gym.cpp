//
//  gym.cpp
//  Data_Gym_STD
//
//  Created by yazidal on 16/12/23.
//

#include "gym.hpp"
int menu(){
    int inputUser;
    cout << "Menu: " << endl;
    cout << "1. Insert data" << endl;
    cout << "2. Show data" << endl;
    cin >> inputUser;
    return inputUser;
}
void initList(listFacility &LF, listMember &LM){
    first(LF) = NULL;
    first(LM) = NULL;
    last(LM) = NULL;
}
adrFacility createElmFacility(infotypeFacility x){
    adrFacility P = new elmFacility;
    info(P) = x;
    nextFac(P) = NULL;
    firstRelation(P) = NULL;
    return P;
}
adrMember createElmMember(infotypeMember x){
    adrMember P = new elmMember;
    info(P) = x;
    nextMem(P) = NULL;
    prevMem(P) = NULL;
    return P;
}
adrRelation createElmRelation(){
    adrRelation P = new elmRelation;
    pointerMember(P) = NULL;
    nextRel(P) = NULL;
    return P;
}