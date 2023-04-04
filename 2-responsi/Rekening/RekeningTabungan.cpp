#include <iostream>
#include "RekeningTabungan.h"
using namespace std;

RekeningTabungan::RekeningTabungan(double s, double transaksi) : Rekening(s) {
    if (transaksi <= 0) {
        biayaTransaksi = 0.0;
    } else {
        biayaTransaksi = transaksi;
    }
}

void RekeningTabungan::setBiayaTransaksi(double transaksi) {
    biayaTransaksi = transaksi;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return biayaTransaksi;
}


void RekeningTabungan::simpanUang(double nominal) {
    Rekening::simpanUang(nominal);
    setSaldo(getSaldo() - biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double nominal) {
    if (Rekening::tarikUang(nominal)) {
        setSaldo(getSaldo() - biayaTransaksi);
        return true;
    } else {
        return false;
    }
}

