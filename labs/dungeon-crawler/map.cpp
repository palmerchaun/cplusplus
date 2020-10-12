#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

void map::generate(){
	srand(time(NULL));	

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			discovered[i][j] = false;
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			int num = rand() % 10;
			switch(num){
				case 8:
					squares[i][j] = TRAP;
					break;
				case 9:
					squares[i][j] = POTION;
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
			}else if (discovered[i][j]){
                cout << "   |";
            }else{
				cout << " ? |";
			}
		}
        cout << endl << "-----------------------------------------" << endl;
	}
}

TYPE map::checkSquare(hero &h){
    /*if (!discovered[h.yPos][h.xPos]){
        switch(squares[h.yPos][h.xPos]){
            case trap:
                cout << "You stepped on a trap and took 3 damage!" << endl;
                h.health -= 3;
                break;
            case potion:
                if (h.health < 6){
                    cout << "You found a potion and regained 5 health!" << endl;
                    h.health += 5;
                }else if (h.health < 10){
                    cout << "You found a potion and regained " << 10 - h.health << " health!" << endl;
                    h.health += 10 - h.health;
                }else {
                    cout << "You found a potion, but you are already at full health!" << endl;
                }
                break;
            default:
                break;
        }
    }

	discovered[h.yPos][h.xPos] = true;

    if(h.yPos == 9 && h.xPos == 9){
        cout << "You won!" << endl;
    }
    */


    if (!discovered[h.yPos][h.xPos]){
        discovered[h.yPos][h.xPos] = true;
        return squares[h.yPos][h.xPos];
    }
    return BLANK;
}
