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

/* Functioanlity */

// Initialize parent and child list
void initList(listFacility &LF, listMember &LM);

//new elmFacility
adrFacility createElmFacility(infotypeFacility x);

// New elmMember
adrMember createElmMember(infotypeMember x);

// New elmRelation
adrRelation createElmRelation();

// Menu displayed to user everytime
int mainMenu();

// Menu displayed everytime user choose facility data
int facilityMenu();

// Menu displayed everytime user choose member data
int memberMenu(listMember LM);

// Invalid Menu
int invalidMenu(int invalid);

// Add Member
void addMember(listMember LM);

// Create List Member
void createListMember(listMember &LM);

// Insert Member
void insertMember(listMember &LM, adrMember adr);

// Show All Data Member
void showAllMemberData(listMember LM);

#endif /* gym_hpp */
