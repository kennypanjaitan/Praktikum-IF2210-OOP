#include <iostream>
#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser(char* name) : User(name) {
    active = true;
    num_of_music_downloaded = 0;
}

PremiumUser::PremiumUser(const PremiumUser& pu) : User(pu) {
    this->active = pu.active;
    this->num_of_music_downloaded = pu.num_of_music_downloaded;
    this->num_of_favourite_music = pu.num_of_favourite_music;
    this->music_list = new char *[5000];

    for (int i = 0; i < pu.num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(pu.music_list[i])];
        strcpy(this->music_list[i], pu.music_list[i]);
    }
}

PremiumUser::~PremiumUser() {}

void PremiumUser::downloadMusic(char* music) {
    if (active) {
        num_of_music_downloaded++;
        cout << "Music Downloaded: " << music << endl;
    } else {
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser::inactivatePremium() {
    active = false;
}

void PremiumUser::activatePremium() {
    active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return active;
}