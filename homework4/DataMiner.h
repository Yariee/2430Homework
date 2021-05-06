#ifndef DATAMINER_H
#define DATAMINER_H

#include <string>
#include <vector>
#include "Record.h"

using namespace std;

class DataMiner {
private:
    vector<Record*> allData;

    void sortRecords(vector<Record*>& records, const int left, const int right, bool verbose=false);
    int partition(vector<Record*>& values, const int left, const int right);

public:
    DataMiner();
    ~DataMiner();

    void loadDataFile(const string path);
    void addRecord (Record *record);
    vector<Record*> getSortedCustomerRecords(const string customer, bool verbose=false);
    void printPatternFrequency(const string customer, bool verbose=false);
};
#endif
