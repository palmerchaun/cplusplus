/*
 * Pointers1
 * Seth Palmer
 * CS 3150
 */

#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

int main(int argsc, char** argsv){
    if (argsc == 4){
        customer c;
        c.name = argsv[1];
        try{
            c.id = stoi(argsv[2]);
        }catch(invalid_argument const &e){
            cout << "Enter an int for ID!" << endl;
        }
        try{
            c.balance = stod(argsv[3]);
        }catch(invalid_argument const&e){
            cout << "Enter a double for balance!" << endl;
        }

        int sel = 0;
        string line;

        if(system("clear")){
            system("cls");
        }

        while(sel != 3){
            cout << "1. Make a charge" << endl;
            cout << "2. Print customer information" << endl;
            cout << "3. Quit" << endl;
            getline(cin, line);
            try{
                sel = stoi(line);
                if (sel == 1){
                    cout << "How much to charge?" << endl;
                    getline(cin, line);
                    try{
                        if(charge(&c, stod(line))){
                            cout << "Charged successfully." << endl;
                        }else{
                            cout << "Insufficient funds. no charge was made." << endl;
                        }
                    }catch(invalid_argument){
                        cout << "Invalid value. No charge was made." << endl;
                    }

                }else if(sel == 2){
                    print(&c);
                }else if(sel == 3){
                    break;
                }
            }catch(invalid_argument){
                cout << "Invalid selection" << endl;
            }

        }
    }else{
        cout << "Invalid format! Please make sure to follow the execution command with <name> <id> <balance>" << endl;
    }
}
