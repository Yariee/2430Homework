#ifndef RECORD_H
#define RECORD_H

#include <string>
using namespace std;

class Record {
private:
    string Customer;
    int Date;
    string Product;

public:
    Record();
    Record(string customer, int date, string product);

    string getCustomer() const;
    void setCustomer(const string customer);

    int getDate() const;
    void setDate(const int date);

    string getProduct() const;
    void setProduct(const string product);

    void printRecord();
};
#endif // RECORD_H
