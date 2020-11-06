#include <iostream>

using namespace std;

int main(){
    int a = 1;
    int& b = a;
    int * x = 77;

    cout << b << " " << a;
}
