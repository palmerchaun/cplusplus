#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

//Generate a map
/*********************************************/
void map::generate(){
	srand(time(NULL));	

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			discovered[i][j] = false;
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			int num = rand() % 100;
			switch(num){
				case 0 ... 20:
					squares[i][j] = TRAP;
					break;
				case 21 ... 30:
					squares[i][j] = POTION;
					break;
                case 31 ... 60:
                    squares[i][j] = BLOCKED;
                    break;
				default:
					squares[i][j] = BLANK;
					break;
			}
		}
	}

	squares[0][0] = ENTRANCE;
	squares[9][9] = EXIT;
	discovered[0][0] = true;
}
/*********************************************/

//Draw the map
/*********************************************/
void map::draw(hero &h){
    if (system("clear")){
        system("cls");
    }
    cout << endl << "-----------------------------------------" << endl;

	for (int i = 0; i < 10; i++){
        cout << "|";
		for (int j = 0; j < 10; j++){
			if (h.yPos == i && h.xPos == j){
				cout << " H |";
            }else if (squares[i][j] == BLOCKED){
                cout << "||||";
            }else if (squares[i][j] == EXIT){
                cout << " O |";
			}else if (discovered[i][j]){
                cout << "   |";
            }else{
				cout << " ? |";
			}
		}
        cout << endl << "-----------------------------------------" << endl;
	}
}
/*********************************************/

//Check what square the hero is on to determine what event is triggered
/*********************************************/
TYPE map::checkSquare(hero &h){
    static int numChecked = 0;
    if (!discovered[h.yPos][h.xPos]){
        numChecked++;
        if (numChecked > 1){
            cout << h.name << " has explored " << numChecked << " rooms." << endl;
        }else{
            cout << h.name << " has explored " << numChecked << " room." << endl;
        }
        discovered[h.yPos][h.xPos] = true;
        return squares[h.yPos][h.xPos];
    }
    return BLANK;
}
/*********************************************/

//Recursively check if there is a possible route through the maze
/*********************************************/
bool checked[10][10];
void map::checkNode(int i, int j){
    if (squares[i][j] == BLOCKED){
        checked[i][j] = true;
        return;
    }else{
        checked[i][j] = true;
    }
    if (i < 9 && !checked[i+1][j]){
        checkNode(i+1, j);
    }
    if (i > 0 && !checked[i-1][j]){
        checkNode(i-1, j);
    }
    if (j > 0 && !checked[i][j-1]){
        checkNode(i, j-1);
    }
    if (j < 9 && !checked[i][j+1]){
        checkNode(i, j+1);
    }

}

bool map::checkMap(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            checked[i][j] = false;
        }
    }

    checkNode(0, 0);

    if (checked[9][9]) return true;

    return false;
}
/*********************************************/
