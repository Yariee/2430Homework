#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "DataMiner.h"

DataMiner::DataMiner() {
}

DataMiner::~DataMiner() {
    for (unsigned long int i = 0; i < allData.size(); i++) {
        delete allData[i];
    }
}

void DataMiner::loadDataFile(const string path) {
    ifstream input;
    input.open(path);

    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            string cstm, date_str, prod;
            int date_int;

            istringstream inSS(line);
            getline(inSS, cstm, ' ');
            getline(inSS, date_str, ' ');
            getline(inSS, prod, ' ');

            date_int = stoi(date_str);

            Record* r = new Record(cstm, date_int, prod);
            allData.push_back(r);
        }
        input.close();
    } else {
        cout << "Could not open file " << path << std::endl;
        exit(-1);
    }
}

void DataMiner::addRecord (Record *record) {
    allData.push_back(record);
}

void DataMiner::printPatternFrequency(const string customer, bool verbose) {
    vector<Record*> customerRecords = getSortedCustomerRecords(customer, verbose);
    vector<string> patternlist;
    for (long unsigned int i = 0; i < customerRecords.size()-1; i++) {
        for (long unsigned int j = i + 1; j < customerRecords.size(); j++) {
            string firstProd, secondProd;
            firstProd = customerRecords[i]->getProduct();
            secondProd = customerRecords[j]->getProduct();
            string pattern = firstProd + "_" + secondProd;
            if (count(patternlist.begin(), patternlist.end(), pattern) == 0) {
                patternlist.push_back(pattern);
            }
        }
    }

    for ( long unsigned int i = 0; i < patternlist.size(); i++) {
        cout << patternlist[i] << endl;
    }
}


vector<Record*> DataMiner::getSortedCustomerRecords(const string customer, bool verbose) {
    vector<Record*> customerRecords;
    for (long unsigned int i = 0; i < allData.size(); i++) {
        if (allData[i]->getCustomer() == customer) {
            customerRecords.push_back(allData[i]);
        }
    }
    sortRecords(customerRecords, 0, customerRecords.size() - 1, verbose);
    return customerRecords;
}


void DataMiner::sortRecords(vector<Record*>& records, const int left, const int right, bool verbose) {
    // DO NOT CHANGE THE NEXT THREE LINES
    if ( verbose ) {
        cout << "left index " << left << " right index " << right << endl;        
    }
    
    // Implement quicksort
    if (right > left) {
        int part = partition(records, left, right);
        sortRecords(records, left, part, verbose);
        sortRecords(records,part+1,right, verbose);
    } 
    else {
        return;
    }

}


int DataMiner::partition(vector<Record*> &records, const int left, const int right) {

    int pivotIndex = left + (right - left) / 2;
    bool boolOption = false;
    // implement the partition function for quicksort using the pivotIndex.
    int  x = left; 
    int y = right;
    Record* p = records[pivotIndex];
   
   
   
    while(!boolOption) {
        for (int z = left; z < pivotIndex; z++) {
            if (records[x]->getDate() < p->getDate()) {
                x++;
            }
            else if (records[x]->getDate() == p->getDate()) {
                if (records[x]->getProduct().compare(p->getProduct()) < 0) {
                    x++;
                }
            } 
        }
        
        for (int m = right; m > pivotIndex; m--) {
            if (records[y]->getDate() > p->getDate()) {
                y--;
            }
            else if (records[y]->getDate() == p->getDate()) {
                if (records[y]->getProduct().compare(p->getProduct()) > 0) {
                    y--;
                }
            }
        }
    
    if (x >= y) {
        boolOption = true;
    }
    else {
        swap(records[x], records[y]);
        x++;
        y--;
        }
    }
    
    return y;
}



