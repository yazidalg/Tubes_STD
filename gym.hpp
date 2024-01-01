//
//  gym.hpp
//  Data_Gym_STD
//
//  Created by yazidal on 16/12/23.
//

#ifndef gym_hpp
#define gym_hpp

#include <iostream>
using namespace std;

#define nil NULL
#define info(P) P->info
#define nextFac(P) P->nextFac
#define nextMem(P) P->nextMem
#define prevMem(P) P->prevMem
#define first(L) (L).first
#define last(L) (L).last
#define pointerMember(P) P->pointerMember
#define nextRel(P) P->nextRel
#define firstRelation(P) P->firstRelation

//Address init
typedef struct elmRelation *adrRelation;
typedef struct elmFacility *adrFacility;
typedef struct elmMember *adrMember;

// Relation Section
struct elmRelation{
    adrMember pointerMember;
    adrRelation nextRel;
};

// Facility Section
struct infotypeFacility {
    string name;
    string instructor;
    int membersCount;
};

struct elmFacility {
    infotypeFacility info;
    adrFacility nextFac;
    adrRelation firstRelation;
};

struct listFacility {
    adrFacility first;
};

// Members Section
struct infotypeMember {
    string name;
    string phoneNumber;
    int age;
};

struct elmMember {
    infotypeMember info;
    adrMember nextMem;
    adrMember prevMem;
};

struct listMember {
    adrMember first;
    adrMember last;
};

// Functionality
void initList(listFacility &LF, listMember &LM); //initialize parent and child list
adrFacility createElmFacility(infotypeFacility x); //new elmFacility
adrMember createElmMember(infotypeMember x); //new elmMember
adrRelation createElmRelation(); //new elmRelation

int menu(); //Menu displayed to user everytime
int menu1(listFacility &LF, listMember &LM); //Menu displayed to user everytime user choose the first menu 

#endif /* gym_hpp */
