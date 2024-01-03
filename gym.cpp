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
    cout << "3. Lihat Fasilitas Beserta Member" << endl;
    cout << "0. Keluar" << endl;
    cin >> inputUser;
    return inputUser;
}

void invalidMenu(int invalid) {
    cout << "Menu dengan pilihan " << invalid << " tidak tersedia" << endl;
}

void initList(listFacility &LF, listMember &LM) {
    first(LF) = NULL;
    first(LM) = NULL;
    last(LM) = NULL;
}

adrFacility createElmFacility(infotypeFacility x) {
    adrFacility P = new elmFacility;
    info(P) = x;
    nextFac(P) = nil;
    firstRelation(P) = nil;
    return P;
}

adrMember createElmMember(infotypeMember x) {
    adrMember P = new elmMember;
    info(P) = x;
    nextMem(P) = nil;
    prevMem(P) = nil;
    return P;
}

adrRelation createElmRelation() {
    adrRelation P = new elmRelation;
    pointerMember(P) = nil;
    nextRel(P) = nil;
    return P;
}

void facilityMenu(listFacility &LF, listMember &LM) {
    int inputUser;
    cout << "----- Menu Fasilitas -----" << endl;
    cout << "1. Tambah Fasilitas" << endl;
    cout << "2. Lihat Fasilitas" << endl;
    cout << "3. Hapus Fasilitas" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    while (inputUser != 0) {
        if (inputUser == 1) {
            addFacility(LF, LM);
        } else if (inputUser == 2) {
            showAllFacilityData(LF, LM);
        } else if (inputUser == 3) {
            deleteFacilityByname(LF);
        } else {
            invalidMenu(inputUser);
        }
        cout << "----- Menu Fasilitas -----" << endl;
        cout << "1. Tambah Fasilitas" << endl;
        cout << "2. Lihat Fasilitas" << endl;
        cout << "3. Hapus Fasilitas" << endl;
        cout << "0. Kembali" << endl;
        cin >> inputUser;
    }
}

void addFacility(listFacility &LF, listMember &LM){
    int inputUser;
    cout << "----- Tambah Fasilitas -----" << endl;
    infotypeFacility fasilitas;
    cout << "Nama Fasilitas/Layanan : ";
    cin >> fasilitas.name;
    cout << "Nama Instruktur : ";
    cin >> fasilitas.instructor;
    fasilitas.membersCount = 0;
    cout << "1. Tambah Fasilitas Diawal" << endl;
    cout << "2. Tambah Fasilitas Diakhir" << endl;
    cin >> inputUser;
    if (inputUser == 1) {
        insertFacilityFirst(LF, createElmFacility(fasilitas));
    } else if (inputUser == 2) {
        insertFacilityLast(LF, createElmFacility(fasilitas));
    } else {
        invalidMenu(inputUser);
    }
}

void insertFacilityFirst(listFacility &LF, adrFacility adr) {
    if (first(LF) == nil) {
        first(LF) = adr;
    } else {
        nextFac(adr) = first(LF);
        first(LF) = adr;  
    }
}

void insertFacilityLast(listFacility &LF, adrFacility adr) {
    adrFacility q;
    q = first(LF);
    if (first(LF) == nil) {
        first(LF) = adr;
    } else {
        while (nextFac(q) != nil) {
            q = nextFac(q);
        }
        nextFac(q) = adr;
    }
}

void showAllFacilityData(listFacility LF, listMember LM) {
    adrFacility adr = first(LF);
    if (first(LF) == nil) {
        cout << "List Masih Kosong" << endl;
    } else {
        while (adr != nil) {
            cout << "Nama : " << info(adr).name << endl;
            cout << "Instruktur : " << info(adr).instructor << endl;
            cout << endl;
            adr = nextFac(adr);
        }
    }
}

adrFacility searchFacility(listFacility LF, string name) {
    adrFacility adr = first(LF);
    while (adr != nil) {
        if (info(adr).name == name) {
            return adr;
        }
        adr = nextFac(adr);
    }
    return adr;
}

adrFacility deleteFacility(listFacility &LF, string name){
    adrFacility adrDel = searchFacility(LF, name);
    if (adrDel == nil){
        cout << "Fasilitas tidak ditemukan" << endl;
    } else {
        // First condition is used for delete first
        if (adrDel == first(LF)) {
            first(LF) = nextFac(adrDel);
            nextFac(adrDel) = nil;
        // Second condition is used for delete last
        } else if (nextFac(adrDel) == nil) { 
            adrFacility Q = first(LF);
            while (nextFac(Q) != adrDel) {
                Q = nextFac(Q);
            }
            nextFac(Q) = nil;
        // Third condition is used for delete after
        } else {
            adrFacility Q = first(LF);
            while (nextFac(Q) != adrDel) {
                Q = nextFac(Q);
            }
            nextFac(Q) = nextFac(adrDel);
            nextFac(adrDel) = nil;
        }
        // New condition here, for delete all relation to member
        if (firstRelation(adrDel) != nil){
            adrRelation adrRel = firstRelation(adrDel);
            while (adrRel != nil){
                pointerMember(adrRel) = nil;
                adrRel = nextRel(adrRel);
            }
        }
    }
    return adrDel;
}

void deleteFacilityByname(listFacility &LF) {
    string name;
    cout << "Nama fasilitas yang akan dihapus : ";
    cin >> name;
    adrFacility adrDel = deleteFacility(LF, name);
    if (adrDel != nil){
        cout << "Fasilitas dengan nama " << info(adrDel).name << " dihapus" << endl;
    }
}

void memberMenu(listFacility &LF, listMember &LM) {
    int inputUser;
    cout << "----- Menu Member -----" << endl;
    cout << "1. Tambah Member" << endl;
    cout << "2. Lihat Member" << endl;
    cout << "3. Hapus Member" << endl;
    cout << "4. Pilih Fasilitas" << endl;
    cout << "0. Kembali" << endl;
    cin >> inputUser;
    while (inputUser != 0) {
        if (inputUser == 1) {
            addMember(LM);
        } else if (inputUser == 2) {
            showAllMemberData(LM);
        } else if (inputUser == 3) {
            deleteMemberByname(LF, LM);
        } else if (inputUser == 4) {
            chooseFacility(LF, LM);
        }
        cout << "----- Menu Member -----" << endl;
        cout << "1. Tambah Member" << endl;
        cout << "2. Lihat Member" << endl;
        cout << "3. Hapus Member" << endl;
        cout << "4. Pilih Fasilitas" << endl;
        cout << "0. Kembali" << endl;
        cin >> inputUser;
    }
}

void addMember(listMember &LM) {
    infotypeMember member;
    int inputUser;
    cout << "----- Tambah Member -----" << endl;
    cout << "Nama Member : ";
    cin >> member.name;
    cout << "Nomor Telepon : ";
    cin >> member.phoneNumber;
    cout << "Umur : ";
    cin >> member.age;
    cout << "1. Tambah Member Diawal" << endl;
    cout << "2. Tambah Member Diakhir" << endl;
    cin >> inputUser;
    if (inputUser == 1) {
        insertMemberFirst(LM, createElmMember(member));
    } else if (inputUser == 2) {
        insertMemberLast(LM, createElmMember(member));
    } else {
        invalidMenu(inputUser);
    }
}

void insertMemberFirst(listMember &LM, adrMember adr) {
    if (first(LM) == nil) {
        first(LM) = adr;
        last(LM) = adr;
    } else {
        nextMem(adr) = first(LM);
        prevMem(first(LM)) = adr;
        first(LM) = adr;
    }
}

void insertMemberLast(listMember &LM, adrMember adr) {
    if (first(LM) == nil) {
        first(LM) = adr;
        last(LM) = adr;
    } else {
        nextMem(last(LM)) = adr;
        prevMem(adr) = last(LM);
        last(LM) = adr;
    }
}

void showAllMemberData(listMember LM) {
    adrMember adr = first(LM);
    if (first(LM) == nil) {
        cout << "List Masih Kosong" << endl;
    } else {
        while (adr != nil) {
            cout << endl;
            cout << "Nama : " << info(adr).name << endl;
            cout << "Nomor Telepon : " << info(adr).phoneNumber << endl;
            cout << "Umur : " << info(adr).age << endl;
            adr = nextMem(adr);
        }
    }
    cout << endl;
}

adrMember searchMember(listMember LM, string name) {
    adrMember adr = first(LM);
    while (adr != nil) {
        if (info(adr).name == name) {
            return adr;
        }
        adr = nextMem(adr);
    }
    return adr;
}

adrMember deleteMember(listFacility &LF, listMember &LM, string name) {
    adrMember adrDel = searchMember(LM, name);
    if (adrDel == nil) {
        cout << "Member tidak ditemukan" << endl;
    } else {
        // First condition is used for delete first
        if (adrDel == first(LM)) {
            first(LM) = nextMem(adrDel);
            nextMem(adrDel) = nil;
        // Second condition is used for delete last
        } else if (nextMem(adrDel) == nil) { 
            adrMember Q = first(LM);
            while (nextMem(Q) != adrDel) {
                Q = nextMem(Q);
            }
            nextMem(Q) = nil;
        // Third condition is used for delete after
        } else {
            adrMember Q = first(LM);
            while (nextMem(Q) != adrDel) {
                Q = nextMem(Q);
            }
            nextMem(Q) = nextMem(adrDel);
            nextMem(adrDel) = nil;
        }
        // Search if the member have a relation/connection associated
        adrFacility srcFac = first(LF);
        adrRelation srcRel;
        while (srcFac != nil) {
            searchRelation(LF, LM, srcFac, adrDel, srcRel);
            if (srcRel != nil){
                pointerMember(srcRel) = nil;
                if (srcRel == firstRelation(srcFac)){
                    firstRelation(srcFac) = nextRel(srcRel);
                    nextRel(srcRel) = nil;
                }else if (nextRel(srcRel) == nil){
                    adrRelation Q = firstRelation(srcFac);
                    while (nextRel(Q) != srcRel){
                        Q = nextRel(Q);
                    }
                    nextRel(Q) = nil;
                }else{
                    adrRelation Q = firstRelation(srcFac);
                    while (nextRel(Q) != srcRel){
                        Q = nextRel(Q);
                    }
                    nextRel(Q) = nextRel(srcRel);
                    nextRel(srcRel) = nil;
                }
                info(srcFac).membersCount--;
            }
            srcFac = nextFac(srcFac);

        }
    }
    return adrDel;
}

void deleteMemberByname(listFacility &LF, listMember &LM){
    string name;
    cout << "Nama member yang akan dihapus : ";
    cin >> name;
    adrMember adrDel = deleteMember(LF, LM, name);
    if (adrDel != nil){
        cout << "Member dengan nama " << info(adrDel).name << " dihapus" << endl;
    }
}

void searchRelation(listFacility LF, listMember LM, adrFacility &srcFac, adrMember adrDel, adrRelation &srcRel){
    bool found = false;
    while (srcFac != nil && !found) {
        srcRel = firstRelation(srcFac);
        while (srcRel !=nil && !found) {
            if (adrDel == pointerMember(srcRel)){
                found = true;
            } else {
                srcRel = next(srcRel);
            }
        }
        if (!found){
            srcFac = nextFac(srcFac);
        }
    }
}

void connectFacility(listFacility &LF, listMember &LM, adrFacility adrFac, adrMember adrMem){
    adrRelation newRel = createElmRelation();
    pointerMember(newRel) = adrMem;
    nextRel(newRel) = nil;
    if (firstRelation(adrFac) == nil){
        firstRelation(adrFac) = newRel;
    }else{
        adrRelation Q = firstRelation(adrFac);
        while (nextRel(Q) != nil){
            Q = nextRel(Q);
        }
        nextRel(Q) = newRel;
    }
}

void chooseFacility(listFacility &LF, listMember &LM){
    if (first(LF) == nil && first(LM) == nil){
        if (first(LF) == nil){
            cout << "fasilitas kosong, kamu belum bisa memilih menu ini" << endl;
        }else if (first(LM) == nil){
            cout << "fasilitas kosong, kamu belum bisa memilih menu ini" << endl;
        }
    }
    string name;
    cout << "Nama member: ";
    cin >> name;
    adrMember memberMemilih = searchMember(LM, name);
    while (memberMemilih == nil){
        cout << "Member tidak ditemukan, silahkan tulis nama member yang valid: ";
        cin >> name;
        memberMemilih = searchMember(LM, name);
    }
    cout << "Fasilitas yang dipilih: ";
    cin >> name;
    adrFacility fasilitasTerpilih = searchFacility(LF, name);
    while (fasilitasTerpilih == nil){
        cout << "Fasilitas tidak ditemukan, silahkan tulis nama fasilitas yang tersedia: ";
        cin >> name;
        fasilitasTerpilih = searchFacility(LF, name);
    }
    connectFacility(LF, LM, fasilitasTerpilih, memberMemilih);
    info(fasilitasTerpilih).membersCount++;
}

void showAllData(listFacility LF, listMember LM) {
    adrFacility facilityAdr = first(LF);

    if (facilityAdr == nil) {
        cout << "List Masih Kosong" << endl;
    } else {
        while (facilityAdr != nil) {
            cout << "Nama : " << info(facilityAdr).name << endl;
            cout << "Instruktur : " << info(facilityAdr).instructor << endl;
            if (firstRelation(facilityAdr) == nil) {
                cout << "Fasilitas ini belum digunakan siapa pun" << endl;
            } else {
                cout << "Pengguna Fasilitas : " << endl;
                cout << "Fasilitas digunakan sebanyak : " << info(facilityAdr).membersCount << endl;
                subListRelation(firstRelation(facilityAdr));
            }
            facilityAdr = nextFac(facilityAdr);
        }
    }
}

void subListRelation(adrRelation relation) {
    while (relation != nil) {
        cout << "Nama : " << info(pointerMember(relation)).name << endl;
        cout << "No. Telepon : " << info(pointerMember(relation)).phoneNumber << endl;
        cout << "Umur : " << info(pointerMember(relation)).age << endl;
        relation = nextRel(relation);
    }
}