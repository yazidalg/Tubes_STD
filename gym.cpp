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

int facilityMenu() {
    int inputUser;
    cout << "----- Menu Fasilitas -----" << endl;
    cout << "1. Tambah Fasilitas" << endl;
    cout << "2. Lihat Fasilitas" << endl;
    cout << "3. Hapus Fasilitas" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    return inputUser;
}

int memberMenu() {
    int inputUser;
    cout << "----- Menu Member -----" << endl;
    cout << "1. Tambah Member" << endl;
    cout << "2. Lihat Member" << endl;
    cout << "3. Hapus Member" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    return inputUser;
}

int invalidMenu(int invalid) {
    cout << endl;
    cout << "Menu dengan pilihan " << invalid << " tidak tersedia" << endl;
    return invalid;
}

void addMember(listMember LM) {
    infotypeMember member;
    cout << "Nama Member : ";
    cin >> member.name;
    cout << "Nomor Telefon : ";
    cin >> member.phoneNumber;
    cout << "Umur : ";
    cin >> member.age;
    if (first(LM) == nil) {
        createListMember(LM);
    }
    insertMember(LM, createElmMember(member));
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
    }
}