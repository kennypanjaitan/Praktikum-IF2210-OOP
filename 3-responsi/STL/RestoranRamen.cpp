#include <iostream>
#include "RestoranRamen.hpp"
using namespace std;

void RestoranRamen::tambahOrder(int n, int p) {
    this->daftarMeja[n] += p;
}

int RestoranRamen::tutupOrder(int n) {
    int total = this->daftarMeja[n];
    this->daftarMeja.erase(n);
    return total;
}

int RestoranRamen::cekTotal(int n) {
    return this->daftarMeja[n];
}

int RestoranRamen::totalMeja() {
    return this->daftarMeja.size();
}

void RestoranRamen::cetakMeja() {
    if (this->daftarMeja.size() == 0) {
        cout << "Restoran kosong" << endl;
    } else{
        for (auto i = this->daftarMeja.begin(); i != this->daftarMeja.end(); i++){
            cout << "Meja " << i->first << " = " << i->second << endl;
        }
    }
}