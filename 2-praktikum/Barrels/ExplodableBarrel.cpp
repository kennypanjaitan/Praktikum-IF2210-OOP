#include <iostream>
using namespace std;

#include "ExplodableBarrel.hpp"

ExplodableBarrel::ExplodableBarrel() : 
    Damageable(1), Explodable() {
    radius = 5;
}

ExplodableBarrel::ExplodableBarrel(int x, int y) :
    Explodable(y), Damageable(1) {
    radius = x;
}

void ExplodableBarrel::takeDamage(int i, string s) {
    if (!this->isDestroyed()) {
        Damageable::takeDamage(i);
        if (this->isDestroyed()) {
            Explodable::explode(radius);
        }
    }
}