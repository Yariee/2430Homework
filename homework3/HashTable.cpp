#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size)
{
	bucketArray = new HashBucket[size];
	maxBuckets = size;
	totalElements = 0;
}

HashTable::~HashTable()
{
	//free memory related to the table
}


/*
call this hash function with the title of the song as the argument
do not modify this method
use the returned integer as the index into bucketArray
*/
int HashTable::hashFunc(string title)
{
    int bias = 0;
    int scale = 1;
    int hashval = 0;
    for (unsigned int i = 0; i < title.size(); i++)
    {
        hashval = hashval + ((char)title[i]);
    }

    hashval = ( (hashval * scale ) + bias) % maxBuckets;

    return hashval;
}

int HashTable::numElements()
{
    //return number of songs in hash table
    return totalElements;
}



void HashTable::addElement(Song* songElement)
{
    //add pointer to song object in the hash table
    
    int y = 0;  // This is the increment for the node index
    string title = songElement->getTitle();
    int x = hashFunc(title);
    
    BucketNode* newNode = new BucketNode;
    newNode->thisSong = songElement;
    BucketNode* tail = nullptr;
    // Current Node
    BucketNode* current = bucketArray[x].head;
    

    if(bucketArray[x].head == nullptr) {
        bucketArray[x].head = newNode;
        bucketArray[x].head->next = nullptr;
        bucketArray[x].head->prev = nullptr;
    } 
    else {
        while (bucketArray[x].head != nullptr && bucketArray[x].head->next != nullptr) {
            bucketArray[x].head = bucketArray[x].head->next;  // Moving onto the next node if occupied
            y++;  // incrementing the node index
        }
        tail = newNode;
        tail->next = nullptr;
        tail->prev = current;
        current->next = tail;
        y++;
    }
    totalElements++;  // Increasing the total number of songs in the hash table
    cout << "Added in bucket " << x << " at node " << y << ": "; 
    songElement->printSong();
    
}


void HashTable::removeElement(string songName)
{

    int x = -1;
    int y = -1;
    
    // Searching for the element
    Song* searchedSong = getElement(songName, x, y);
    
    // Node head and no other elements are in the following nodes
    if (searchedSong != nullptr) {
        if (bucketArray[x].head->thisSong == searchedSong && bucketArray[x].head->next == nullptr) {
            bucketArray[x].head = nullptr;
            totalElements--;
        }
        // Node head
        BucketNode* current = bucketArray[x].head;
        // Iterating through nodes
        if (y != 0) {
            for (int i = 0; i < y; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        
        bucketArray[x].head = current->next;
        current->next->prev = nullptr;
        totalElements--;
        delete searchedSong;
        
    }
}


Song* HashTable::getElement(string songName, int &x, int &y)
{
    //return a pointer to the song with the given title
    //x is the index in bucketArray
    //y is the index in the bucket linked list
    //print error message if song not found
    
    x = hashFunc(songName);  // Finds the hash for the song title
    y = 0;  // Incrementor 
    BucketNode* current = bucketArray[x].head;
    
    while (current->next != nullptr && current->thisSong->getTitle() != songName) {
        current = current->next;
        y++;
    }
    if (current->thisSong->getTitle() == songName) {
        return current->thisSong;
    } 
    else {
        cout << "Error! Song " << songName << " not found.";
    }
}

void HashTable::cleanupElements(int t)
{
    //iterate through the table and remove all songs with playtime less than t
    //this can be implemented in many ways
    
    //  Have to start by looping through the buckets then we start looping through the linked lists
    for (int i = 0; i < maxBuckets; i++) {
        BucketNode* current = bucketArray[i].head;
        // Iterating through the nodes within the buckets
        if (current != nullptr) {
            while (current->next != nullptr) {  // long as the bucket is not empty
                if (current->thisSong->getPlayTime() < t) {
                    removeElement(current->thisSong->getTitle());
                }
                current = current->next;  // ITerate though to next node
            }
            totalElements--;
        }
    }
}
