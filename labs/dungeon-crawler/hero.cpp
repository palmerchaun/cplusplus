#include <iostream>
#include "header.h"

using namespace std;

void move(char d, hero &h, map &m){
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

    if (!m.discovered[h.yPos][h.xPos]){
        switch(m.squares[h.yPos][h.xPos]){
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

	m.discovered[h.yPos][h.xPos] = true;

    if(h.yPos == 9 && h.xPos == 9){
        m = generate();
        h.yPos = 0;
        h.xPos = 0;
    }
}
