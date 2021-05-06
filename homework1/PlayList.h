#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "PlayListEntry.h"
#include "Song.h"
using namespace std;

class PlayList {

private:
    PlayListEntry* firstSong;
    PlayListEntry* lastSong;
    int numSongs;
    int playTime;
        
public:
    PlayList();
    PlayList( PlayList& other);
    ~PlayList();

    int getPlayListLength() const;
    int getNumSongs () const;
    PlayListEntry *getSong( const int pos );
    void printList() const;
        
    // Append a Song to the end of the playlist
    void appendSong(Song *song);
    // Delete a song from the playlist
    void deleteSong(Song *song);
    // Move a song one spot up in the playlist
    void moveUp (PlayListEntry *entry);
    // Revert the order of songs on the playlist
    void reverseOrder();
};
#endif // PLAYLIST_H
