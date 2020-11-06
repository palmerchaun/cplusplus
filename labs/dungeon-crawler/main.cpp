/*
 * Seth Palmer Dungeon Crawler
 * Completed 10/25/2020
 * CS 3150
 */
#include <fstream>
#include <iostream>
#include <string>
#include "header.h"

using namespace std;

//declare extern vars from header.h
string names[3];
int healths[3];
int strengths[3];

int main(){

    //initialize extern vars
    /*********************************************/
    names[0] = "Draco the Dragon";
    names[1] = "Bill the Bear";
    names[2] = "Craig the Crab";

    healths[0] = 60;
    healths[1] = 40;
    healths[2] = 25;

    strengths[0] = 8;
    strengths[1] = 4;
    strengths[2] = 10;
    /*********************************************/
    
    string name;

    if (system("clear")){
        system("cls");
    }

    //Menu
    /*********************************************/
    cout << "Welcome to Seth's Dungeon Crawler" << endl << endl;
    cout << "To win, you must navigate through an array of rooms while monsters try to slay you." << endl << endl;
    cout << "To begin, enter your hero's name: ";
    getline(cin, name);
    /*********************************************/

    char d;

    //Setup map and ensure a possible route exists
    /*********************************************/
    map m;
    m.generate();
    while(!m.checkMap()){
        m.generate();
    }
    /*********************************************/

    if (system("cls")){
        system("clear");
    }

    //Setup hero
    /*********************************************/
    hero h;
    h.name = name;
    h.health = 100;
    h.strength = 5;
    h.potions = 0;
    h.xPos = 0;
    h.yPos = 0;
    /*********************************************/

    TYPE current = BLANK;

    bool potUsed = false;

    //Main game loop
    /*********************************************/
    while(h.health > 0){
        m.draw(h);
        current = m.checkSquare(h);
        if (current == TRAP){
            battle(h);
        }else if(current == EXIT){
            break;
        }else{
            if (current == POTION){
                string line;
				ifstream myfile ("potion");
				if (myfile.is_open())
				{
					while ( getline (myfile,line) )
					{
					cout << line << '\n';
					}
					myfile.close();
				}
                cout << h.name << " found a potion!" << endl;
                h.potions += 1;
            }
            if (potUsed == true){
                cout << "You used a potion and restored some health." << endl;
                potUsed = false;
            }
            cout << "Current health: " << h.health << endl;
            cout << "Enter a direction (n s e w)";
            if (h.potions > 0){
                cout << "or enter \'p\' to use one of your " << h.potions << " potions:";
            }
            cout << endl;
            cin >> d;
            if (d == 'p' && h.potions != 0){
                if (h.health < 91){
                    cout << "You used a potion and regained 5 health!" << endl;
                    h.health += 10;
                    h.potions -= 1;
                    potUsed = true;
                }else if (h.health < 100){
                    cout << "You used a potion and regained " << 100 - h.health << " health!" << endl;
                    h.health += 100 - h.health;
                    h.potions -= 1;
                    potUsed = true;
                }else {
                    cout << "You are already at full health!" << endl;
                }

            }
            move(d, h, m);
        }
    }
    /*********************************************/

    system("clear");
    
    if (h.health > 0){
        cout << "You made it to the exit! Congrats!" << endl;
    }else{
        cout << "You died. RIP " << h.name << ". 2020-2020" << endl;
    }
}

//Battle when hero steps on trap
/*********************************************/
void battle(hero &h){
    if (system("clear")){
        system("cls");
    }
	int mon = 0;
    int ran = rand() % 10;
    switch (ran){
        case 0 ... 4:
            mon = 2;
            break;
        case 5 ... 7:
            mon = 1;
        default:
            break;
    }
    monster m;
    m.name = names[mon];;
    m.health = healths[mon];
    m.strength = strengths[mon];

    int attack = 0;
    int given = 0;
    int taken = 0;

    string line;
    ifstream myfile ("monster" + to_string(mon));
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            cout << line << endl;
        }
        myfile.close();
    }
    cout << h.name << " health: " << h.health << "\t\t";
    cout << m.name << " health: " << m.health;

    cout << endl << endl << "You encountered " << m.name << endl << endl;

    cout << "1. Accurate Attack" << endl;
    cout << "2. Heavy Attack" << endl;

    cin >> attack;
    if (!cin.good()){
        cin.clear();
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

    if (m.health > 0){
        taken = rand() % m.strength + 1;
        h.health -= taken;
    }

    if (system("clear")){
        system("cls");
    }

    while(h.health > 0 && m.health > 0){
        ifstream myfile ("monster" + to_string(mon));
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
            cout << line << '\n';
            }
            myfile.close();
        }
        cout << h.name << " health: " << h.health << "\t\t";
        cout << m.name << " health: " << m.health << endl << endl;
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
        cout << m.name << " swung for " << taken << endl << endl;


        cout << "1. Accurate Attack" << endl;
        cout << "2. Heavy Attack" << endl;

        cin >> attack;

        if (!cin.good()){
            cin.clear();
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
        cout << "You defeated " << m.name << " and your strength has increased to " << ++h.strength << "!" <<  endl;
        cout << "Enter f to pay respects:" << endl;

        cin >> str;
    }
}
/*********************************************/
