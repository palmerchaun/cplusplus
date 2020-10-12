//Demo Code for String vs CString
//10-6-2020
//-Dr. G
//Tested on https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //1. Declare a c string
    char cs[] = "Bob";
    //2. Declare a standard library string
    string s = "not bob";
    //What's the difference?
	
    //3. view the 2nd char of each string
    //
    //4. create a for loop that will display each char 
    //   alter that for loop to display those chars as ints
    //	 what do you notice

    //for (int x = 0; x < sizeof(cs)/sizeof(char); x++)
    //    cout << int(cs[x]) << " ";

    //cout << cs;

    
    //overwrite the last char in cs and use cout
	
    //5. Test out cin when you initialize and when you don't
    //what is cin.getline for cstrings?
    //what is <cstring> for?
    
    cin >> cs;
    cout << cs << endl;
    
    //6. Get the size of each 
    //Change the size of s and re-run
    
    //7. test out assignment and equivalence
    //Is it using memory locations or contents?
    
    //When would you use C-Strings?
    //How can you tell the difference?
    
}

