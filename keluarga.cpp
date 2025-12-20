#include "Keluarga.h"

void initList(ListOrangTua& LO, ListAnak& LA) {
    LO.first = nullptr;
    LA.first = nullptr;
}

adrOrangTua createOrangTua(string nama, char jk) {
    adrOrangTua o = new OrangTua;
    o->nama = nama;
    o->jk = jk;
    o->firstRelasi = nullptr;
    o->next = nullptr;
    return o;
}

adrAnak createAnak(string nama, char jk) {
    adrAnak a = new Anak;
    a->nama = nama;
    a->jk = jk;
    a->next = nullptr;
    return a;
}

adrRelasi createRelasi(adrAnak a) {
    adrRelasi r = new Relasi;
    r->anak = a;
    r->next = nullptr;
    return r;
}

void insertOrangTuaLast(ListOrangTua& LO, adrOrangTua o) {
    if (!LO.first) LO.first = o;
    else {
        adrOrangTua p = LO.first;
        while (p->next) p = p->next;
        p->next = o;
    }
}

void insertAnakLast(ListAnak& LA, adrAnak a) {
    if (!LA.first) LA.first = a;
    else {
        adrAnak p = LA.first;
        while (p->next) p = p->next;
        p->next = a;
    }
}

adrOrangTua findOrangTua(ListOrangTua LO, string nama) {
    adrOrangTua p = LO.first;
    while (p) {
        if (p->nama == nama) return p;
        p = p->next;
    }
    return nullptr;
}

adrAnak findAnak(ListAnak LA, string nama) {
    adrAnak p = LA.first;
    while (p) {
        if (p->nama == nama) return p;
        p = p->next;
    }
    return nullptr;
}

void hubungkan(adrOrangTua o, adrAnak a) {
    if (!o || !a) return;
    adrRelasi r = createRelasi(a);
    r->next = o->firstRelasi;
    o->firstRelasi = r;
}

void showAll(ListOrangTua LO) {
    adrOrangTua o = LO.first;
    while (o) {
        cout << o->nama << " (" << o->jk << ") : ";
        adrRelasi r = o->firstRelasi;
        while (r) {
            cout << r->anak->nama << "(" << r->anak->jk << ") ";
            r = r->next;
        }
        cout << endl;
        o = o->next;
    }
}

void showAnakDariOrtu(ListOrangTua LO, string namaOrtu) {
    adrOrangTua o = findOrangTua(LO, namaOrtu);
    if (!o) return;
    adrRelasi r = o->firstRelasi;
    while (r) {
        cout << r->anak->nama << " (" << r->anak->jk << ")" << endl;
        r = r->next;
    }
}

void showOrtuDariAnak(ListOrangTua LO, string namaAnak) {
    adrOrangTua o = LO.first;
    while (o) {
        adrRelasi r = o->firstRelasi;
        while (r) {
            if (r->anak->nama == namaAnak)
                cout << o->nama << " (" << o->jk << ")" << endl;
            r = r->next;
        }
        o = o->next;
    }
}

void deleteAnak(ListAnak& LA, ListOrangTua& LO, string nama) {
    adrAnak p = LA.first, prev = nullptr;
    while (p && p->nama != nama) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    adrOrangTua o = LO.first;
    while (o) {
        adrRelasi r = o->firstRelasi, pr = nullptr;
        while (r) {
            if (r->anak == p) {
                if (!pr) o->firstRelasi = r->next;
                else pr->next = r->next;
                delete r;
                break;
            }
            pr = r;
            r = r->next;
        }
        o = o->next;
    }

    if (!prev) LA.first = p->next;
    else prev->next = p->next;

    delete p;
}

void deleteOrangTua(ListOrangTua& LO, string nama) {
    adrOrangTua p = LO.first, prev = nullptr;
    while (p && p->nama != nama) {
        prev = p;
        p = p->next;
    }
    if (!p) return;

    adrRelasi r = p->firstRelasi;
    while (r) {
        adrRelasi tmp = r;
        r = r->next;
        delete tmp;
    }

    if (!prev) LO.first = p->next;
    else prev->next = p->next;

    delete p;
}

int countAnak(adrOrangTua o) {
    int total = 0;
    adrRelasi r = o->firstRelasi;
    while (r) {
        total++;
        r = r->next;
    }
    return total;
}

void showOrtuEkstrem(ListOrangTua LO) {
    if (!LO.first) return;

    adrOrangTua minO = LO.first;
    adrOrangTua maxO = LO.first;

    adrOrangTua p = LO.first;
    while (p) {
        if (countAnak(p) < countAnak(minO)) minO = p;
        if (countAnak(p) > countAnak(maxO)) maxO = p;
        p = p->next;
    }

    cout << "Terbanyak : " << maxO->nama << " (" << countAnak(maxO) << " anak)\n";
    cout << "Tersedikit: " << minO->nama << " (" << countAnak(minO) << " anak)\n";
}

