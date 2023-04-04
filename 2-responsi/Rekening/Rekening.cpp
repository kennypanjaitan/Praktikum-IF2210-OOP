#include <iostream>
#include "Rekening.h"

using namespace std;

Rekening::Rekening(double s) {
    if (s <= 0) {
        saldo = 0.0;
    } else {
        saldo = s;
    }
}

void Rekening::setSaldo(double s) {
    saldo = s;
}

double Rekening::getSaldo() const {
    return saldo;
}

void Rekening::simpanUang(double nominal) {
    saldo += nominal;
}

bool Rekening::tarikUang(double nominal) {
    if (saldo >= nominal) {
        saldo -= nominal;
        return true;
    } else {
        return false;
    }
}
