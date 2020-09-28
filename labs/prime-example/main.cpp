/*
Prime Example main
9/18/20
Seth Palmer
*/

#include <iostream>
#include "pfuncs.h"

using namespace std;

int main(){
    int num = 1;
    while (num > 0){
        cout << "Pick a number to check (<1 to quit)" << endl;
        cin >> num;

        if (num > 0){
            if (isPrime(num)){
                cout << num << " is prime!" << endl;
            }else{
                cout << num << " is not prime" << endl;
            }

            cout << endl << "The following are prime numbers up to " << num << endl;
            listPrimes(num);
        }
    }
}
