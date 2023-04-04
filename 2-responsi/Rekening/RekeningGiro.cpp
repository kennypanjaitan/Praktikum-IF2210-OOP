#include <iostream>
#include "RekeningGiro.h"
using namespace std;

RekeningGiro::RekeningGiro(double s, double b) : Rekening(s) {
    if (b <= 0) {
        sukuBunga = 0.0;
    } else {
        sukuBunga = b;
    }
}

void RekeningGiro::setSukuBunga(double b) {
    sukuBunga = b;
}

double RekeningGiro::getSukuBunga() const {
    return sukuBunga;
}

double RekeningGiro::hitungBunga() {
    return getSaldo() * sukuBunga;
}