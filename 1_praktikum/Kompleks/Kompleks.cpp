#include <iostream>
#include "Kompleks.h"
using namespace std;
static int n_Kompleks = 0;

Kompleks::Kompleks() {
	this->real = 0;
	this->imaginer = 0;
	n_Kompleks++;
}

Kompleks::Kompleks(int real, int imaginer) {
	this->real = real;
	this->imaginer = imaginer;
	n_Kompleks++;
}

int Kompleks::GetReal() const {
	return this->real;
}

int Kompleks::GetImaginer() const {
	return this->imaginer;
}

void Kompleks::SetReal(int real) {
	this->real = real;
}

void Kompleks::SetImaginer(int imaginer) {
	this->imaginer = imaginer;
}

Kompleks operator+ (const Kompleks& x, const Kompleks& y) {
	Kompleks baru;
	baru.SetReal(x.GetReal() + y.GetReal());
	baru.SetImaginer(x.GetImaginer() + y.GetImaginer());
	return baru;
}

Kompleks operator- (const Kompleks& x, const Kompleks& y) {
	Kompleks baru;
	baru.SetReal(x.GetReal() - y.GetReal());
	baru.SetImaginer(x.GetImaginer() - y.GetImaginer());
	return baru;
}

Kompleks operator* (const Kompleks& x, const Kompleks& y) {
	Kompleks baru;
	baru.SetReal((x.GetReal() * y.GetReal()) - (x.GetImaginer() * y.GetImaginer()));
	baru.SetImaginer((x.GetImaginer() * y.GetReal()) + (x.GetReal() * y.GetImaginer()));
	return baru;
}

Kompleks operator* (const Kompleks& x, const int a) {
	Kompleks baru;
	baru.SetReal(x.GetReal() * a);
	baru.SetImaginer(x.GetImaginer() * a);
	return baru;
}

Kompleks operator* (const int a, const Kompleks& x) {
	Kompleks baru;
	baru.SetReal(a * x.GetReal());
	baru.SetImaginer(a * x.GetImaginer());
	return baru;
}
int Kompleks::CountKompleksInstance() {
	return n_Kompleks;
}

void Kompleks::Print() {
	cout << this->real;
	if (this->imaginer >= 0) {
		cout << "+" << this->imaginer << "i" << endl;
	} else {
		cout << this->imaginer << "i" << endl;
	}
}