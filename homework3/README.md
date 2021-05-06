Hash Tables

The main function will read songs from an input file (songs-long.txt) and create a MusicLibrary object, which uses the HashTable class functions to 
manage the library. An additional feature in this assignment will be to implement a cleanup function which deletes songs less than a certain length.

Your objective will be to complete the HashTable class (HashTable.cpp) and implement methods to add, access and remove Song objects from it. The hash 
table will handle collisions using chaining which means when two elements map to the same bucket both will be added to the index using a linked list 
(read section 5.2). The hash table will be implemented using an array of HashBucket objects which point to the head of the linked list constructed 
using BucketNode objects. The BucketNode object stores a pointer to the inserted Song object.

The hashing function adds the integer equivalent of every character in a song’s title to determine the index into the HashBucket array, where it’s 
reference is then stored into an inserted BucketNode object. This function is provided to you as hashFunc() and must not be changed.

The methods you will have to implement in the HashTable.cpp will be:

- int numElements(): Get number of songs in the hash table.
- void addElement(Song *songElement): Add a song to the hash table. Use the hashFunc function to calculate the index in the HashBucket array then chain 
the song using BucketNode if there is already a song stored in that bucket. 
- Song *getElement(string songName, int &x, int &y): Get a pointer to a song with the given name by finding it in the hash table and modify x to be the
index in the HashBucket array and y to be the index in the bucket linked list. Use hashFunc to calculate the x and then search through the bucket to
find the song and y.
-void removeElement(string songName): Find song with the specified name and delete it from the hash table. Remember that when removing the BucketNode
containing the song, you need to modify the neighboring nodes and modify HashBucket if it is the first node. Free all the memory allocated for the song and node.
- void cleanupElements(int t): Iterate through the entire hash table and remove all songs which have a playtime less than t.
