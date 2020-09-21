/*
Formatting Output With Cout
9/14/2020
Seth Palmer
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // table instructions
    cout << "The following output should be in columns 10 chars wide." << endl;
    cout << "Numbers should all be displayed with two decimal places only (no changing the numbers)." << endl;
    cout << "End the output with a row of *'s the exact length of the output." << endl << endl;
    
    // formatted table
    cout << setw(10) << "Column 1" << setw(10) << "Column 2" << setw(10) << "Column 3" << endl;
    cout << setw(10) << setprecision(2) << 3.14558 << setw(10) << 3.0/8.0 << setw(10) << 789 << endl;
    cout << setw(10) << setprecision(2) << 8.4526585 << setw(10) << 7.1212 << setw(10) << 5.6 << endl;
    cout<<setfill('*')<<setw(30)<<'*'<<endl<<endl;
    
    // fab instructions
    cout << "Print out the word fab by converting the base 10 numbers to hexadecimal" << endl <<endl;
	//you have to use the hex value to get credit for this
    
    // output 15, 10, and 11 in base 16 (spelling fab)
    cout << setbase(16);
    cout << 15 << 10 << 11 << endl;

    return 0;
}
