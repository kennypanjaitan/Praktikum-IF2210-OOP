#include <iostream>
using namespace std;

// flytrap.cpp
#include "flytrap.h"

FlyTrap::FlyTrap() : Plant() {
    this->eatenInsect = 0;
}

void FlyTrap::eatInsect(int insect) {
    this->eatenInsect += insect;
}
