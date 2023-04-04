// weed.cpp
#include <iostream>
#include "weed.h"
using namespace std;

Weed::Weed() : Plant() {}

void Weed::photosynthesis() {
    // Plant::photosynthesis();     
    // u can uncomment this if u want to run plant's photosynthesis function

    cout << "Smoke light everyday" << endl;
}

void Weed::step() {
    cout << "kresek..." << endl;
}

// pure virtual function
void Weed::getSpecies() {
    cout << "420" << endl;
}