#include <iostream>
#include "Customer.h"

using namespace std;

bool charge(customer *c, double val){
    if((*c).balance < val){
        return false;
    }
    (*c).balance -= val;
    return true;
}

void print(customer* c){
    cout << "Name:\tID:\tBalance:" << endl;
    cout << c->name << "\t" << c->id << "\t" << c->balance << endl;
}
