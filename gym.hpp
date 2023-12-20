//
//  gym.hpp
//  Data_Gym_STD
//
//  Created by yazidal on 16/12/23.
//

#ifndef gym_hpp
#define gym_hpp

#include <iostream>

#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) (L).first
#define last(L) (L).last

using namespace std;

// Layanan Section
struct infotype_layanan {
    string name;
    string instruktur;
};

typedef struct gym_layanan *adr_layanan;

struct gym_layanan {
    infotype_layanan info;
    adr_layanan next;
    adr_layanan prev;
};

struct list_layanan {
    adr_layanan first;
    adr_layanan last;
};

// Anggota Section
struct infotype_anggota {
    string name;
    string phone;
};

typedef struct gym_anggota *adr_anggota;

struct gym_anggota {
    infotype_anggota info;
    adr_anggota next;
};

struct list_anggota {
    adr_anggota first;
};


// Layanan Section
void createListL ayanan(list_layanan L);

adr_layanan createElmLayanan(infotype_layanan lay);

#endif /* gym_hpp */
