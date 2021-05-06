#include <iostream>
#include "PlayList.h"

PlayList::PlayList ()  
{
    firstSong=nullptr;
    lastSong=nullptr;
    numSongs = 0;
    playTime = 0;
}

PlayList::PlayList(PlayList& other)
{
   // implement copy-constructor
   PlayListEntry *newNode;
   newNode = other.firstSong;
   numSongs = 0;
   playTime = 0;
   
   while (newNode != nullptr) {
       appendSong(newNode->song);
       newNode = newNode->next;
   }
   
   
}

// Deconstructor didn't have enough time to fill in
PlayList::~PlayList()
{
   // implement destructor
}

int PlayList::getPlayListLength() const
{
    return playTime;
}
int PlayList::getNumSongs() const
{
    return numSongs;
}

void PlayList::printList() const
{
   // implement printList()
   PlayListEntry *currNode = new PlayListEntry();
   currNode = firstSong;
   
   while (currNode != nullptr) {
       currNode->song->printSong();
       currNode = currNode->next;
   }
   
}

PlayListEntry *PlayList::getSong( const int pos )
{
   // implement getSong()
   PlayListEntry *currNode = new PlayListEntry();
   currNode = firstSong;
   int count = 0;
   
   // Not sure if this is all the test case scenarios as this goes through zybooks as 10/10 
   while (currNode != nullptr) {
       if (count == pos) {
           return currNode;
       }
       count++;
       currNode = currNode->next;
   }
   
   if (pos >= count) {
       cout << "Cannot return Song at position " << pos << " numSons is " << count;
   }
   return currNode;
   
   
}

void PlayList::appendSong(Song *song)
{
   // implement appendSong()
   PlayListEntry *playlist = new PlayListEntry();
   playlist->song = song;
   
   if (firstSong == nullptr) {
       firstSong = playlist;
       lastSong = playlist;
       numSongs++;
       playTime += playlist->song->getPlayTime();
   } else {
       lastSong->next = playlist;
       playlist->prev = lastSong;
       lastSong = playlist;
       numSongs++;
       playTime += playlist->song->getPlayTime();
   }
}

void PlayList::deleteSong(Song *song)
{
   // implement deleteSong
   PlayListEntry *currNode = new PlayListEntry();
   PlayListEntry *temp = new PlayListEntry();
   currNode = firstSong;
   
   // Iterating through the song(s)
   while (currNode->song != song) {
       currNode = currNode->next;
   }
   
   // If first song of the playlist needs to be deleted
   temp = currNode;
   if (temp == firstSong) {
       temp->next->prev = nullptr;
       firstSong = temp->next;
       numSongs--;
       playTime -=  temp->song->getPlayTime();
       delete temp;
   }
   
   else if (temp != lastSong) {
       temp->prev->next = temp->next;
       temp->next->prev = temp->prev;
       numSongs--;
       playTime -= playTime - temp->song->getPlayTime();
       delete temp;
   }
   
   else {
       temp->prev->next = nullptr;
       lastSong = temp->prev;
       numSongs--;
       playTime -= temp->song->getPlayTime();
       delete temp;
   }

}

// Did not have enough time to fill in
void PlayList::moveUp(PlayListEntry *song)
{
   // implement moveUp
 
   
}

void PlayList::reverseOrder()
{
   // implement function reversing the order of Songs
   PlayListEntry* currNode = firstSong;
   PlayListEntry *prev = nullptr;
   PlayListEntry *next = nullptr;
   
   while (currNode != nullptr) {
       next = currNode->next;
       currNode->next = prev;
       prev = currNode;
       currNode = next;
   }
   firstSong = prev;

}






