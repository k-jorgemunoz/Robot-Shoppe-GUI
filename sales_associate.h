#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H

#include <string>
using namespace std;

class SalesAssociate {

public:
    SalesAssociate(string sa_name, int sa_num) : name(sa_name), number(sa_num) {}
    void save_all();
    void list_all_detail();
    void raisecheck();
    void raise_final();
    
private:
    string name;
    int number;
    bool raise_check = false;
    bool raise = false;

};

#endif // SALES_ASSOCIATE_H
