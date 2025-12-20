#include "Keluarga.h"

int main() {
    ListOrangTua LO;
    ListAnak LA;
    initList(LO, LA);

    int pilih;
    do {
        cout << "\n1. Tambah Orang Tua";
        cout << "\n2. Tambah Anak";
        cout << "\n3. Hubungkan Ortu-Anak";
        cout << "\n4. Tampilkan Semua";
        cout << "\n5. Anak dari Ortu";
        cout << "\n6. Ortu dari Anak";
        cout << "\n7. Hapus Orang Tua";
        cout << "\n8. Hapus Anak";
        cout << "\n9. Statistik";
        cout << "\n0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            string nama;
            char jk;

            cout << "Nama orang tua: ";
            getline(cin, nama);

            cout << "Jenis kelamin (L/P): ";
            cin >> jk;
            cin.ignore();

            if (jk != 'L' && jk != 'P') {
                cout << "Input tidak valid.";
                return 0;
            }

            insertOrangTuaLast(LO, createOrangTua(nama, jk));
        }

        else if (pilih == 2) {
            string nama;
            char jk;

            cout << "Nama anak: ";
            getline(cin, nama);

            cout << "Jenis kelamin (L/P): ";
            cin >> jk;
            cin.ignore();

            if (jk != 'L' && jk != 'P') {
                cout << "Input tidak valid.\n";
                return 0;
            }

            insertAnakLast(LA, createAnak(nama, jk));
        }

        else if (pilih == 3) {
            string ortu, anak;
            cout << "Nama orang tua: ";
            getline(cin, ortu);
            cout << "Nama anak: ";
            getline(cin, anak);

            hubungkan(findOrangTua(LO, ortu), findAnak(LA, anak));
        }

        else if (pilih == 4) {
            showAll(LO);
        }

        else if (pilih == 5) {
            string nama;
            cout << "Nama orang tua: ";
            getline(cin, nama);
            showAnakDariOrtu(LO, nama);
        }

        else if (pilih == 6) {
            string nama;
            cout << "Nama anak: ";
            getline(cin, nama);
            showOrtuDariAnak(LO, nama);
        }

        else if (pilih == 7) {
            string nama;
            cout << "Nama orang tua: ";
            getline(cin, nama);
            deleteOrangTua(LO, nama);
        }

        else if (pilih == 8) {
            string nama;
            cout << "Nama anak: ";
            getline(cin, nama);
            deleteAnak(LA, LO, nama);
        }

        else if (pilih == 9) {
            showOrtuEkstrem(LO);
        }

    } while (pilih != 0);

    return 0;
}

