#include <iostream>
#include <cstring>
#include "ArtistUser.h"

using namespace std;

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* name) : User(name) {
    num_of_music_uploaded = 0;
    uploaded_music_list = new char *[255];
    num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& au) : User(au) {
    this->num_of_favourite_music = au.num_of_favourite_music;
    this->num_of_music_uploaded = au.num_of_music_uploaded;
    this->music_list = new char *[5000];
    this->uploaded_music_list = new char *[5000];

    for (int i = 0; i < au.num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(au.music_list[i])];
        strcpy(this->music_list[i], au.music_list[i]);
    }

    for (int i = 0; i < au.num_of_music_uploaded; i++)
    {
        this->uploaded_music_list[i] = new char[strlen(au.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], au.uploaded_music_list[i]);
    }

    num_of_artist++;
}

ArtistUser::~ArtistUser() {
    cout << "Artist user " << name << " deleted" << endl;
}

void ArtistUser::uploadMusic(char* music) {
    num_of_music_uploaded++;
    uploaded_music_list[num_of_music_uploaded - 1] = new char[strlen(music)];
    strcpy(uploaded_music_list[num_of_music_uploaded - 1], music);
}

void ArtistUser::deleteUploadedMusic(char* music) {
    if (num_of_music_uploaded > 0)
    {
        int deletedmusic = -1;
        for (int i = 0; i < num_of_music_uploaded; i++)
        {
            if (strcmp(uploaded_music_list[i], music) == 0)
            {
                deletedmusic = i;
                break;
            }
        }
        if (deletedmusic != -1 && deletedmusic < num_of_music_uploaded)
        {
            num_of_music_uploaded--;
            for (int j = deletedmusic; j < num_of_music_uploaded; j++)
            {
                strcpy(uploaded_music_list[j], uploaded_music_list[j + 1]);
            }
        }
    }
}

void ArtistUser::viewUploadedMusicList() const {
    if (num_of_music_uploaded == 0) {
        cout << "No music uploaded" << endl;
    } else {
        for (int i = 0; i < num_of_music_uploaded; i++) {
            cout << i + 1 << ". " << uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const{
    return num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist(){
    return ArtistUser::num_of_artist;
}