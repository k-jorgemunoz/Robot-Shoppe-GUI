#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "sales_associate.h"
using namespace std;

class Customer {

    friend SalesAssociate;
public:
    Customer(string c_name, int c_num, int sales_a) : name(c_name), number(c_num), sales_a(sales_a) {}

    void list_all_detail();
    void save_all();
    
protected:
    string name;
    int number;
    int sales_a;
    //Order order;

};


#endif // CUSTOMER_H
