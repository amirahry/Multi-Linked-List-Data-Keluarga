#ifndef KELUARGA_H
#define KELUARGA_H

#include <iostream>
#include <string>
using namespace std;

//Pengenalan Struct Sebelum Digunakan
struct Anak; 
struct OrangTua;
struct Relasi;

//Alias Pointer
typedef Anak* adrAnak;
typedef OrangTua* adrOrangTua;
typedef Relasi* adrRelasi;

//Struktur Data
struct Anak {
    string nama;
    char jk;
    adrAnak next;
};

struct Relasi {
    adrAnak anak;
    adrRelasi next;
};

struct OrangTua {
    string nama;
    char jk;
    adrRelasi firstRelasi;
    adrOrangTua next;
};

// List
struct ListAnak {
    adrAnak first;
};

struct ListOrangTua {
    adrOrangTua first;
};

//Fungsi-Fungsi Utama

//inisialisasi list kosong
void initList(ListOrangTua& LO, ListAnak& LA);

//membuat node baru
adrOrangTua createOrangTua(string nama, char jk);
adrAnak createAnak(string nama, char jk);
adrRelasi createRelasi(adrAnak a);

//menambahkan node ke akhir list
void insertOrangTuaLast(ListOrangTua& LO, adrOrangTua o);
void insertAnakLast(ListAnak& LA, adrAnak a);

//mencari node berdasarkan nama
adrOrangTua findOrangTua(ListOrangTua LO, string nama);
adrAnak findAnak(ListAnak LA, string nama);

//hubungkan orang tua dengan anak
void hubungkan(adrOrangTua o, adrAnak a);

//menampilkan data
void showAll(ListOrangTua LO);
void showAnakDariOrtu(ListOrangTua LO, string namaOrtu);
void showOrtuDariAnak(ListOrangTua LO, string namaAnak);

//hapus node beserta relasinya
void deleteAnak(ListAnak& LA, ListOrangTua& LO, string nama);
void deleteOrangTua(ListOrangTua& LO, string nama);

//menampilkan statistik
int countAnak(adrOrangTua o);
void showOrtuEkstrem(ListOrangTua LO);

#endif
