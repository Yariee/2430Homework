#include <iostream>
#include <string>
#include <cstdlib>

#include "Song.h"
#include "MusicLibrary.h"
#include "PlayList.h"

using namespace std;

int main(int argc, char** argv) {
    string filename;
    int numsongs;
    int option=0;
        
    cout << "Enter filename with list of Songs :" << endl;
    cin >> filename;

    cout << "Enter option (0 : playlist with all songs; 1: filtered playlist; 2: reverse playlist)\n";
    cin >> option;
    
    if ( option > 2 ) {
        cout << "Invalid option: has to be between 0 and 2\n";
        exit (-1);
    }
    
    numsongs = MusicLibrary::getNumSongsInFile(filename);
    MusicLibrary mylibrary(numsongs);
    mylibrary.readSongsFromFile(filename);

    // Playlist 1: create a playlist with all songs
    if ( option == 0 ) {
        PlayList  list1;
        for ( int i=0; i < numsongs; i++ ) {
            Song *song = mylibrary.getSong(i);
            list1.appendSong (song);
        }
        list1.printList();
    }

    if ( option == 1 ) {
        // Playlist2: only U2 songs
        PlayList list2;
        for ( int i=0; i < numsongs; i++ ) {
            Song *song = mylibrary.getSong(i);
            if ( song->getArtist() == "U2" ) {
                list2.appendSong (song);
            }
        }
        list2.printList();
    }

    if ( option == 2 ) {
        PlayList  list1;
        for ( int i=0; i < numsongs; i++ ) {
            Song *song = mylibrary.getSong(i);
            list1.appendSong (song);
        }
        list1.reverseOrder();
        list1.printList();
    }
    
    return 0;
}
