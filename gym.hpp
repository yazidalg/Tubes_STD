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

/* Functionality */

/* -----General----- */

// Initialize parent and child list
void initList(listFacility &LF, listMember &LM);

// Menu displayed to user everytime
int mainMenu();

// Invalid Menu
void invalidMenu(int invalid);

// New elmRelation
adrRelation createElmRelation();

// Search Facility By Name
void searchRelation(listFacility LF, listMember LM, adrFacility &srcFac, adrMember adrDel, adrRelation &srcRel);

/* -----Facility----- */

// Menu displayed everytime user choose facility data
void facilityMenu(listFacility &LF, listMember &LM);

//new elmFacility
adrFacility createElmFacility(infotypeFacility x);

// Add Facility With Input First Index
void addFacility(listFacility &LF, listMember &LM);

// Insert First Index Facility Logic Only
void insertFacilityFirst(listFacility &LF, adrFacility adr);

// Insert Last Index Facility Logic Only
void insertFacilityLast(listFacility &LF, adrFacility adr);

// Centralize Of Function Search Facility And DeleteFacility
void deleteFacilityByname(listFacility &LF);

// Show All Data Facility
void showAllFacilityData(listFacility LF, listMember LM);

// Search Facility By Name
adrFacility searchFacility(listFacility LF, string name);

// Delete Facility with the relation included
adrFacility deleteFacility(listFacility &LF, string name);

// Show All Data Parent And Child
void showAllData(listFacility LF, listMember LM);

void subListRelation(adrRelation relation);
/* -----Member----- */

// Menu displayed everytime user choose member data
void memberMenu(listFacility &LF, listMember &LM);

// New elmMember
adrMember createElmMember(infotypeMember x);

// Add Member
void addMember(listMember &LM);

// Insert First Index Member Logic Only
void insertMemberFirst(listMember &LM, adrMember adr);

// Insert Last Index Member Logic Only
void insertMemberLast(listMember &LM, adrMember adr);

// Show All Data Member
void showAllMemberData(listMember LM);

// Search Member
adrMember searchMember(listMember LM, string name);

// Delete Member
adrMember deleteMember(listFacility &LF, listMember &LM, string name);

// Connect Facility to Member
void connectFacility(listFacility &LF, listMember &LM, adrMember adrMem);

// Centralize of Function Search Facility And DeleteFacility
void deleteMemberByname(listFacility &LF, listMember &LM);

// Centralize of connecting relation
void chooseFacility(listFacility &LF, listMember &LM);

#endif /* gym_hpp */