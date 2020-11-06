#include <iostream>
#include <array>

using namespace std;

int main(){
    srand(time(NULL));
    std::array<int, 100> arr;
    arr.fill(rand() % 201 - 100);
    cout << arr.at(0);
}
