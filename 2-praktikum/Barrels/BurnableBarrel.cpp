#include <iostream>
using namespace std;

#include "BurnableBarrel.hpp"

BurnableBarrel::BurnableBarrel() : 
    Damageable(), Burnable(){
}

BurnableBarrel::BurnableBarrel(int n) : 
    Damageable(n), Burnable() {
}

void BurnableBarrel::takeDamage(int i, string s) {
    if (!this->isDestroyed()) {
        if (s == "fire") {
            this->burn();
        }
        else if (s == "water") {
            this->watered();
        }
        int multiplier = 1;
        if (this->isBurned()) {
            multiplier *= this->multiplier;
        }      
        Damageable::takeDamage(i * multiplier);
    }
}