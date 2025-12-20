#ifndef KELUARGA_H
#define KELUARGA_H

#include <iostream>
#include <string>
using namespace std;

struct Anak;
struct OrangTua;
struct Relasi;

typedef Anak* adrAnak;
typedef OrangTua* adrOrangTua;
typedef Relasi* adrRelasi;

// node anak
struct Anak {
    string nama;
    char jk;
    adrAnak next;
};

// node relasi
struct Relasi {
    adrAnak anak;
    adrRelasi next;
};

// node orang tua
struct OrangTua {
    string nama;
    char jk;
    adrRelasi firstRelasi;
    adrOrangTua next;
};

// list
struct ListAnak {
    adrAnak first;
};

struct ListOrangTua {
    adrOrangTua first;
};

// fungsi
void initList(ListOrangTua& LO, ListAnak& LA);

adrOrangTua createOrangTua(string nama, char jk);
adrAnak createAnak(string nama, char jk);
adrRelasi createRelasi(adrAnak a);

void insertOrangTuaLast(ListOrangTua& LO, adrOrangTua o);
void insertAnakLast(ListAnak& LA, adrAnak a);

adrOrangTua findOrangTua(ListOrangTua LO, string nama);
adrAnak findAnak(ListAnak LA, string nama);

void hubungkan(adrOrangTua o, adrAnak a);

void showAll(ListOrangTua LO);
void showAnakDariOrtu(ListOrangTua LO, string namaOrtu);
void showOrtuDariAnak(ListOrangTua LO, string namaAnak);

void deleteAnak(ListAnak& LA, ListOrangTua& LO, string nama);
void deleteOrangTua(ListOrangTua& LO, string nama);

int countAnak(adrOrangTua o);
void showOrtuEkstrem(ListOrangTua LO);

#endif

