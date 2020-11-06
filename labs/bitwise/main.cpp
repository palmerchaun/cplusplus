#include <iostream>

using namespace std;

int main()
{
    //Explain the following output with comments.
    //What is the advantage to bitwise operators?
    
    //Tip : research bitwise shifting
    //Tip : research bitwise operators 
    //Tip : write the numbers out in binary
    cout << (1<<1) << endl; //Outputs 1 shifted one place to the left (00000001 -> 00000010 so 1 -> 2)
    cout << (5<<2)<< endl; //Outputs 5 shifted two places to the left (00000101 -> 00010100 so 5 -> 20)
    
    cout << (1>>1) << endl; //Outputs 1 shifted one place to the right (00000001 -> 00000000 so 1 -> 0)
    cout << (5>>2)<< endl; //Outputs 5 shifted two places to the right (00000101 -> 00000001 so 5 -> 1)
    
    cout << (-2 << 2) << endl; //Outputs -2 shifted two places to the left (10000010 -> 10001000 so -2 -> -8)
    cout << (-4 >> 1) << endl; //Outputs -4 shifted 1 place to the right (10000100 -> 10000100 so -4 -> -2)
    
    cout << (1|2) << endl; //Outputs 0001 | 0010 which is 0011, or 3
    cout << (2|4) << endl; //Outputs 0010 | 0100 which is 0110, or 6
    
    cout << (1&2) << endl; //Outputs 0001 & 0010 which is 0000, or 0
    cout << (2&4) << endl; //Outputs 0010 & 0100 which is 0000, or 0
    
    cout << (~1) << endl;
    cout << (~7) << endl;
    
    cout << (5^6) << endl;
    cout << (2^4) << endl;
}
