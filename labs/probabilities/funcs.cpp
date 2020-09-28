#include <iostream>
#include "funcs.h"

using namespace std;

void questions(){
    cout << "What is the probability of event A? (0.0-1.0)" << endl;
    cin >> probA;
    cout << "What is the probability of event B? (0.0-1.0)" << endl;
    cout << "Are these events mutually exclusive? (y/n)" << endl;
    cin >> exclusive;
    cout << "Are these events independent from each other? (y/n)" << endl;
    cin >> independent;
}
