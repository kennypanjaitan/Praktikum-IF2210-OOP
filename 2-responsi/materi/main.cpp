#include "plant.cpp"
#include "weed.cpp"
#include "flytrap.cpp"

void waterPlant(Plant* v) {
    v->absorbWater(1.5);
    v->photosynthesis();
}

int main() {
    Plant p;
    Weed weed;
    Plant *pointer = &weed;

    waterPlant(&p);
    waterPlant(&weed);
    p.photosynthesis();
    weed.photosynthesis();
    pointer->photosynthesis();
    // (&weed);
}
