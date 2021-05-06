#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <string>
#include "Song.h"
using namespace std;

class MusicLibrary {

private:
    int maxSongs;
    int numSongs;    // number of Songs in library
    Song* mySongs;   // dynamic array storing all Songs

public:
    MusicLibrary(int maxsongs);
    ~MusicLibrary();

    bool addSong(string title, string artist, string album, int year, int time);
    bool addSong(Song& song);
    void readSongsFromFile(string filename);

    int getNumSongs () const;
    Song* getSong (const int pos ) const;
        
    static int getNumSongsInFile(string filename);
};
#endif // MUSICLIBRARY_H
