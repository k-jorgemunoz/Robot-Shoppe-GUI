#include "sales_associate.h"
#include <iostream>
#include <fstream>
using namespace std;

void SalesAssociate::list_all_detail(){
    
    cout << name << " " <<number;
    
}

void SalesAssociate::save_all(){
    
    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);
    
    ofs << number << endl;
    ofs << name << endl;
    
    ofs.close();
}

void SalesAssociate::raisecheck(){
    
    raise_check = true;
}

void SalesAssociate::raise_final(){
    
    raise = true;
}
