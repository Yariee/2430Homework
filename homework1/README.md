The purpose of this assignment is to developed the code to manage a music playlist. The playlist has to be implemented as a doubly linked list. The code for the assignment
is organized as follows:

Class Song: 
This class provides the abstraction for an individual song, including song title, artist, album, year of publication, and play time in seconds. The class further provides a method
printSong() which displays relevant information for a Song. Code is provided in Song.h and Song.cpp. Students should not modify these files, but use 'as is'.

Class MusicLibrary:
This class provides the abstraction and implementation for a Music Library, including reading Songs from a file and storing them in the library.Code is provided in 
MusicLibrary.h and MusicLibrary.cpp. Students should not modify these files, but use 'as is'.

Class PlayList:
This class provides the abstraction for the Playlist. A Playlist is managed as a double linked list, with the content being a *pointer to a Song * in the Music Library. 
The abstraction for the linked list node is in the class PlayListEntry (file PlayListEntry.h).The header file PlayList.h is fully implemented and does not require any changes. 
All the work is expected to happen in the file PlayList.cpp. Specifically, students are expected to implement the following functionality:
implement the method 'appendSong()' which appends a Song to the doubly linked list. This function is expected to allocate a new PlayListEntry object, correctly store the
pointer to the Song in the object, update the prev and next pointers in the new PlayListEntry as well as already existing PlayListEntry s (if required), update the number of Songs and
the total playtime of the Playlist, as well as the pointers to the first and the last Song in the PlayList ( if required). implement the method 'getSong()' which returns a \
pointer to n-th node in the linked, with n being provided as an input argument. If the linked list does not contain n nodes and no pointer to a Song can be returned, 
the function is expected to return an error message.

implement the method 'deleteSong()': the method is expected to identify a PlayListEntry given a pointer to a Song, remove the corresponding PlayListEntry from the linked
list correctly (i.e. making sure that all prev and next pointers of nearby elements are correctly updated, and numSongs and playTime is updated correctly).

implement method 'printList()' which invokes the printSong() method of each Song in the playlist in the same order as stored in the playlist.

implement the method 'moveUp()' which moves a song identified by a PlayListEntry pointer one sport up in the playlist. If the Song identified by the PlayListEntry is already 
the first Song in the list, the function is expected to output

implement the copy constructor of the PlayList class.

implement the method 'reverseOrder() ". This function is expected reverse the order of songs in the playlist, i.e. the last song becomes the first song, the second last song
will be the second song, …, the first song becomes the last song.

Class PlayListEntry:
This class provides the abstraction required to manage songs in double linked list implemented in the PlayList class. Code is provided in PlayListentry.h . 
Students should not modify this files, but use 'as is'.

Main.cpp:
A main file providing some examples on how the PlayList class is expected to be used is provided. You will most likely have to make changes to this file as part of the 
development process (e.g. to test some of the functions that you developed in more details), but please DO NOT upload your modification main.cpp to zybooks. The original 
main.cpp file is expected as part of the zybook tests.
