// plant.h
#ifndef PLANT_H
#define PLANT_H

class Plant {
protected:
    float waterStock;
public:
    Plant();
    void photosynthesis();  // virtual
    void absorbWater(float water);
    // virtual void getSpecies();      // pure virtual = implement in child class
    // At least 1 pure virtual function = Abstract Base Class (ABC)
    // So, Plant is an ABC.....DEFGHI haha lucu ga
};

#endif
