/*
Prime Example functions
9/18/20
Seth Palmer
*/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    if (num < 2){
        return false;
    } else{
        for (int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                return false;
            }
        }
    }
    return true;
}

void listPrimes(int num){
        bool nums [num + 1];
        fill_n(nums, num + 1, true);
        for (int i = 2; i <= num; i++){
            if (nums[i]){
                for (int j = 2 * i; j <= num; j += i){
                    nums[j] = false;
                }
            }
        }
        for (int i = 2; i <= num; i++){
            if (nums[i]){
                cout << i << endl;
            }
        }
}
