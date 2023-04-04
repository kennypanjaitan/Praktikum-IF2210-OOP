// flytrap.h
#ifndef FLYTRAP_H
#define FLYTRAP_H

#include "plant.h"

class FlyTrap : public Plant {
private:
    int eatenInsect;
public:
    FlyTrap();
    void eatInsect(int insect);
};

#endif
