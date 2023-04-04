// plant.cpp
#include <iostream>
#include "plant.h"
using namespace std;

Plant::Plant() {
    this->waterStock = 0;
}

void Plant::photosynthesis() {
    cout << "Nyam nyam makan cahaya" << endl;
}

void Plant::absorbWater(float water) {
    this->waterStock += water;
}
