#include <iostream>
#include "DataMiner.h"


int main()
{
    string filename="data.txt";

    string customer;
    cout << "Enter query customer name:" << endl;
    cin >> customer;
    
    DataMiner dm;
    dm.loadDataFile(filename);

    cout << "Enter option: (0: sort a customers records; 1: verbose sort a customers recrods; 2: print Pattern frequency)\n";
    int option;
    cin >> option;
    if ( option == 0 ) {
        vector<Record*> cdata = dm.getSortedCustomerRecords(customer, false);
        for (long unsigned int i = 0; i < cdata.size(); i++) {
            cdata[i]->printRecord();
        }
    }
    else if ( option == 1 ) {        
        vector<Record*> cdata = dm.getSortedCustomerRecords(customer, true);
    }
    else if ( option == 2 ) {        
        dm.printPatternFrequency(customer, false);
    }  
    else {
        cout << "Unknown option " << option << endl;
   }

    return 0;
}
