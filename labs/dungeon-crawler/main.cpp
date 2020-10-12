#include <iostream>
#include "header.h"

using namespace std;

int main(){
    char d;
    map m;
    m.generate();
    hero h;
    h.name = "Seth";
    h.health = 100;
    h.strength = 5;
    h.xPos = 0;
    h.yPos = 0;

    TYPE current = BLANK;

    while(h.health > 0){
        m.draw(h);
        current = m.checkSquare(h);
        if (current == TRAP){
            battle(h);
        }else{
            if (current == POTION){
                cout << h.name << " found a potion!" << endl;
                if (h.health < 91){
                    cout << "You found a potion and regained 5 health!" << endl;
                    h.health += 10;
                }else if (h.health < 100){
                    cout << "You found a potion and regained " << 100 - h.health << " health!" << endl;
                    h.health += 100 - h.health;
                }else {
                    cout << "You found a potion, but you are already at full health!" << endl;
                }

            }
            cout << "Current health: " << h.health << endl;
            cout << "Enter a direction (n s e w): ";
            cin >> d;
            move(d, h);
        }
    }
}
