#include <iostream>
#include <cstring>
#include "User.h"

using namespace std;

int User::n_user = 0;

User::User(char* name) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    this->num_of_favourite_music = 0;
    this->music_list = new char *[5000];
    n_user++;
}

User::User(const User& u) {
    this->name = new char[strlen(u.getName())];
    strcpy(this->name, u.getName());
    this->num_of_favourite_music = u.num_of_favourite_music;
    this->music_list = new char *[5000];

    for (int i = 0; i < u.num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(u.music_list[i])];
        strcpy(this->music_list[i], u.music_list[i]);
    }
    n_user++;
}

User::~User() {
    cout << "User " << name << " deleted" << endl;
}

void User::addFavouriteMusic(char* music) {
    num_of_favourite_music++;
    music_list[num_of_favourite_music - 1] = new char[strlen(music)];
    strcpy(music_list[num_of_favourite_music - 1], music);
}

void User::deleteFavouriteMusic(char* music) {
    if (num_of_favourite_music > 0) {
        int deletedmusic = -1;
        for (int i = 0; i < num_of_favourite_music; i++) {
            if (strcmp(music_list[i], music) == 0) {
                deletedmusic = i;
                break;
            }
        }
        if (deletedmusic != -1 && deletedmusic < num_of_favourite_music) {
            this->num_of_favourite_music--;
            for (int j = deletedmusic; j < num_of_favourite_music; j++) {
                strcpy(music_list[j], music_list[j + 1]);
            }
        }
    }
}

void User::setName(char* name) {
    strcpy(this->name, name);
}

char* User::getName() const {
    return name;
}

int User::getNumOfFavouriteMusic() const {
    return num_of_favourite_music;
}

void User::viewMusicList() const {
    if (num_of_favourite_music == 0) {
        cout << "No music in your favourite list" << endl;
    } else {
        for (int i = 0; i < num_of_favourite_music; i++) {
            cout << i + 1 << ". " << music_list[i] << endl;
        }
    }
}

int User::getNumOfUser() {
    return n_user;
}