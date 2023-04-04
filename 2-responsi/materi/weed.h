// weed.h
#ifndef WEED_H
#define WEED_H

#include "plant.h"

class Weed : public Plant {
public:
    Weed();
    virtual void photosynthesis();
    void step();
    void getSpecies();
};

#endif
