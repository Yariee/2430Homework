#include <iostream>
#include <string>
#include <cstdlib>

#include "Song.h"
#include "MusicLibrary.h"

using namespace std;

int main(int argc, char** argv)
{

    string filename;
    int buckets;

    cout << "Enter filename with list of Songs :" << endl;
    cin >> filename;

    buckets = 9; //small number of buckets to cause collisions

    MusicLibrary mylibrary(buckets);
    mylibrary.readSongsFromFile(filename);

    return 0;
}

