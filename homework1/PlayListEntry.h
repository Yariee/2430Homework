#ifndef PLAYLISTENTRY_H
#define PLAYLISTENTRY_H

#include "Song.h"

class PlayListEntry {

public:
    Song *song;
    PlayListEntry *next;
    PlayListEntry *prev;    

    PlayListEntry() {
        song = nullptr;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // PLAYLISTENTRY
