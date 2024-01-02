//
//  gym.cpp
//  Data_Gym_STD
//
//  Created by yazidal on 16/12/23.
//

#include "gym.hpp"

int mainMenu(){
    int inputUser;
    cout << "----- Gym Ciganitry -----" << endl;
    cout << "1. Data Fasilitas" << endl;
    cout << "2. Data Member" << endl;
    cout << "0. Keluar" << endl;
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

void facilityMenu(listFacility LF, listMember LM) {
    int inputUser;
    cout << "----- Menu Fasilitas -----" << endl;
    cout << "1. Tambah Fasilitas" << endl;
    cout << "2. Lihat Fasilitas" << endl;
    cout << "3. Hapus Fasilitas" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    while (inputUser != 0) {
        if (inputUser == 1) {
            addFacility(LF);
        } else if (inputUser == 2) {
            cout << "hapus aja lah" << endl;
        } else if (inputUser == 3) {
            cout << "hapus aja lah" << endl;
        }
        cin >> inputUser;
    }
}

void addFacility(listFacility LF){
    int inputUser;
    cout << "----- Menu Fasilitas -----" << endl;
    cout << "1. Tambah Fasilitas" << endl;
    cout << "2. Lihat Fasilitas" << endl;
    cout << "3. Hapus Fasilitas" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
}

void memberMenu(listMember LM) {
    int inputUser;
    cout << "----- Menu Member -----" << endl;
    cout << "1. Tambah Member" << endl;
    cout << "2. Lihat Member" << endl;
    cout << "3. Hapus Member" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    while (inputUser != 0) {
        if (inputUser == 1) {
            addMember(LM);
        } else if (inputUser == 2) {
            showAllMemberData(LM);
        } else if (inputUser == 3) {
            cout << "hapus aja lah" << endl;
        }
        cin >> inputUser;
    }
}

void invalidMenu(int invalid) {
    cout << endl;
    cout << "Menu dengan pilihan " << invalid << " tidak tersedia" << endl;
}

void addMember(listMember LM) {
    infotypeMember member;
    cout << "Nama Member : ";
    cin >> member.name;
    cout << "Nomor Telefon : ";
    cin >> member.phoneNumber;
    cout << "Umur : ";
    cin >> member.age;
    insertMember(LM, createElmMember(member));
    memberMenu(LM);
}

void insertMember(listMember &LM, adrMember adr) {
    if (first(LM) == nil) {
        first(LM) = adr;
        last(LM) = adr;
    } else {
        nextMem(adr) = first(LM);
        prevMem(first(LM)) = adr;
        first(LM) = adr;
    }
}

void showAllMemberData(listMember LM) {
    adrMember adr = first(LM);
    while (adr != nil) {
        cout << endl;
        cout << "Nama : " << info(adr).name << endl;
        cout << "Nomor Telepon : " << info(adr).phoneNumber << endl;
        cout << "Umur : " << info(adr).age << endl;
        adr = nextMem(adr);
    }
    memberMenu(LM);
    cout << endl;
}

adrMember searchMember(listMember LM, string name) {
    adrMember found = first(LM);
    adrMember adr = first(LM);
    while (adr != nil) {
        if (info(adr).name == name) {
            found = adr;
        }
        adr = next(adr);
    }
    return found;
}

void showAllFacilityData(listFacility LF) {
    adrFacility adr = first(LF);
    while (adr != nil) {
        cout << endl;
    }
    
} 