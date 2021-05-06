#include <iostream>
#include "Record.h"


Record::Record()
{
    Customer = "";
    Date = 0;
    Product = "";
}

Record::Record(string customer, int date, string product)
{
    Customer = customer;
    Date = date;
    Product = product;
}

string Record::getCustomer() const
{
    return Customer;
}
void Record::setCustomer(const string customer)
{
    Customer = customer;
}

int Record::getDate() const
{
    return Date;
}
void Record::setDate(const int date)
{
    Date = date;
}

string Record::getProduct() const
{
    return Product;
}
void Record::setProduct(const string product)
{
    Product = product;
}

void Record::printRecord()
{
    cout << Customer << " " << Date << " " << Product << endl;
}
