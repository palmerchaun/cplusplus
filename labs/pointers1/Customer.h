#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

struct customer{
    std::string name;
    int id;
    double balance;
};

bool charge(customer*, double);
void print(customer*);

#endif
