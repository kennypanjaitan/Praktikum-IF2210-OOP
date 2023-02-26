#include <iostream>
#include <cmath>
#include "Polinom.hpp"
using namespace std;

Polinom::Polinom() {
    koef = new int[1];
    koef[0] = 0;
    derajat = 0;
}

Polinom::Polinom(int n) {
    derajat = n;
    koef = new int[n+1];
    for (int i = 0; i <= derajat; i++) {
        koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& P) {
    this->derajat = P.derajat;
    this->koef = new int [this->derajat+1];
    for (int i = 0; i <= this->derajat; i++) {
        this->koef[i] = P.koef[i];
    }
}

Polinom::~Polinom() {
    delete[] koef;
}

Polinom& Polinom::operator= (const Polinom& P) {
    Polinom* baru = new Polinom(P.derajat+1);
    baru->koef = new int [P.derajat+1];
    baru->derajat = P.derajat;
    for (int i = 0; i <= baru->derajat; i++){
        baru->koef[i] = P.koef[i];
    }
    return *baru;
}

int Polinom::getKoefAt(int idx) const {
    return koef[idx];
}

int Polinom::getDerajat() const {
    return derajat;
}

void Polinom::setKoefAt(int idx, int val) {
    koef[idx] = val;
}

void Polinom::setDerajat(int val) {
    derajat = val;
}

void Polinom::input() {
    for (int i = 0; i <= derajat; i++) {
        cin >> koef[i];
    }
}

void Polinom::printKoef() {
    for (int i = 0; i <= derajat; i++) {
        cout << koef[i] << endl;
    }
}

int Polinom::substitute(int n) {
    int sum = 0;
    for (int i = 0; i <= derajat; i++) {
        sum += koef[i] * pow(n, i);
    }
    return sum;
}

void Polinom::print() {
    int count = 0, i = 0;
    while (count == 0 && i <= derajat) {
        if (koef[i] != 0) {
            if (i == 0) {
                cout << koef[i];
            } else {
                cout << koef[i] << "x^" << i;
            }
            count++;
        }
        i++;
    }

    if (i <= derajat) {
        for (int j = i; j <= derajat; j++) {
            if (koef[j] != 0) {
                if (koef[j] > 0) {
                    cout << "+" << koef[j];
                } else if (koef[j] < 0) {
                    cout << koef[j];
                } 
                cout << "x^" << j;
            }
        }
    }

    if (count == 0) {
        cout << "0";
    }

    cout << endl;
}