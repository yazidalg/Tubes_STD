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
#define next(P) P->next
#define prev(P) P->prev
#define first(L) (L).first
#define last(L) (L).last
#define pointerMember(P) P->pointerMember
#define nextChild(P) P->nextChild
#define firstChild(P) P->firstChild

// Child Section

typedef struct elmChild *adrChild;
struct elmChild{
    adrMember pointerMember;
    adrChild nextChild;
};

// Facility Section
struct infotypeFacility {
    string name;
    string instructor;
    int membersCount;
};

typedef struct elmFacility *adrFacility;

struct elmFacility {
    infotypeFacility info;
    adrFacility next;
    adrChild firstChild;
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

typedef struct elmMember *adrMember;

struct elmMember {
    infotypeMember info;
    adrMember next;
    adrMember prev;
};

struct listMember {
    adrMember first;
    adrMember last;
};

// Functionality

#endif /* gym_hpp */
