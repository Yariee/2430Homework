#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <algorithm>
#include <cstdlib>
#include "MusicLibrary.h"


MusicLibrary::MusicLibrary(int maxsongs) {
    maxSongs = maxsongs;
    numSongs = 0;
    mySongs = new Song[maxsongs];
}

MusicLibrary::~MusicLibrary() {
    delete[] mySongs;
}

int MusicLibrary::getNumSongs () const {
    return numSongs;
}

Song* MusicLibrary::getSong (const int pos ) const {
    if ( pos > numSongs ) {
        cout << "getSong: cannot return song at pos " << pos << ", no. of songs is " << numSongs << endl;
        return nullptr;
    }

    return &mySongs[pos];
}


bool MusicLibrary::addSong(string title, string artist, string album, int year, int time) {
    if (numSongs == maxSongs) {
        cout << "Could not add song to library. Library is full" << endl;
        return false;
	}
    mySongs[numSongs].setTitle(title);
    mySongs[numSongs].setArtist(artist);
    mySongs[numSongs].setAlbum(album);
    mySongs[numSongs].setYear(year);
    mySongs[numSongs].setPlayTime(time);
    numSongs++;

    return true;
}

bool MusicLibrary::addSong(Song& song) {
    if (numSongs == maxSongs) {
        cout << "Could not add song to library. Library is full" << endl;
        return false;
    }
    mySongs[numSongs] = song;
    numSongs++;

    return true;
}

void MusicLibrary::readSongsFromFile(string filename) {

    ifstream input;
    input.open(filename);

    if (input.is_open()) {
        string line;
        while ( getline(input, line) ) {
            string title, artist, album;
            string s_year, s_time;
            int year;
            int time;
            istringstream inSS(line);

            getline(inSS, title, ',');
            getline(inSS, artist, ',');
            getline(inSS, album, ',');
            getline(inSS, s_year, ',');
            getline(inSS, s_time);

            // Trim whitespaces
            artist.erase(artist.begin(), std::find_if(artist.begin(), artist.end(),
                [](char ch) {return !isspace(ch); }));
            album.erase(album.begin(), std::find_if(album.begin(), album.end(),
                [](char ch) {return !isspace(ch); }));

                        
            year = stoi(s_year);
            time = stoi(s_time);
            addSong(title, artist, album, year, time);
        }
        
        input.close();
    }
    
    else {
        cout << "Could not open file " << filename << std::endl;
        exit(-1);
    }        
}

int MusicLibrary::getNumSongsInFile(string filename) {
    ifstream input;
    int lines;
    string line;
        
    input.open(filename);        
    if (input.is_open()) {
        for(lines = 0; getline(input, line); lines++);
        input.close();
	}
        
    else {
        cout << "Could not open file " << filename << std::endl;
        exit(-1);
    }
        
        input.close();
        return lines;
}
