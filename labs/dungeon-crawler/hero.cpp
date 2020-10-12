#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

void move(char d, hero &h){
    switch(d){
        case 'n':
            if (h.yPos > 0) h.yPos--;
            break;
        case 's':
            if (h.yPos < 9) h.yPos++;
            break;
        case 'e':
            if (h.xPos < 9) h.xPos++;
            break;
        case 'w':
            if (h.xPos > 0) h.xPos--;
            break;
        default:
            break;
    }
}

void battle(hero &h){
    if (system("clear")){
        system("cls");
    }
    monster m;
    m.name = "Dragon";
    m.health = 20;
    m.strength = 5;

    int attack = 0;
    int given = 0;
    int taken = 0;

    cout << "You encountered a " << m.name << endl;
    string line;
    ifstream myfile ("monster");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            cout << line << endl;
        }
        myfile.close();
    }
    cout << h.name << " health: " << h.health << "\t\t";
    cout << m.name << " health: " << m.health;

    cout << endl << endl << endl;

    cout << "1. Accurate Attack" << endl;
    cout << "2. Heavy Attack" << endl;

    cin >> attack;
    if (!cin.good()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        given = 0;
    }else{
        if (attack == 1){
            given = h.strength;
        }else if (attack == 2){
            given = rand() % (h.strength * 2) + 1;
        }else{
            given = 0;
        }
    }
    m.health -= given;

    taken = rand() % m.strength + 1;
    h.health -= taken;

    if (system("clear")){
        system("cls");
    }

    while(h.health > 0 && m.health > 0){
        ifstream myfile ("monster");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
            cout << line << '\n';
            }
            myfile.close();
        }
        if (attack == 1){
            cout << h.name << " swung for " << given << endl;
        }else if(attack == 2){
            if (given >= h.strength){
                cout << h.name << " made a nice heavy attack for " << given << endl;
            }else{
                cout << h.name << " made a poor heavy attack for " << given << endl;
            }
        }else{
            cout << h.name << " attempted an invalid attack and dealt 0" << endl;
        }
        cout << m.name << " swung for " << taken << endl;
        cout << h.name << " health: " << h.health << "\t\t";
        cout << m.name << " health: " << m.health;

        cout << endl << endl << endl;

        cout << "1. Punch" << endl;
        cout << "2. Kick" << endl;

        cin >> attack;

        if (!cin.good()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            given = 0;
        }else{
            if (attack == 1){
                given = h.strength;
            }else if (attack == 2){
                given = rand() % (h.strength * 2) + 1;
            }else{
                given = 0;
            }
        }
        m.health -= given;

        taken = rand() % m.strength + 1;
        h.health -= taken;

        if (system("clear")){
            system("cls");
        }
    }
    string str;
    if (h.health > 0){
        cout << "You defeated " << m.name << "!" << endl;
        cout << "Press ENTER to continue:" << endl;

        cin >> str;
    }
}
