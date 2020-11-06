#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "header.h"

using namespace std;

//Move hero if valid direction
void move(char d, hero &h, map &m){
    switch(d){
        case 'n':
            if (h.yPos > 0 && m.squares[h.yPos - 1][h.xPos] != BLOCKED) h.yPos--;
            break;
        case 's':
            if (h.yPos < 9 && m.squares[h.yPos + 1][h.xPos] != BLOCKED) h.yPos++;
            break;
        case 'e':
            if (h.xPos < 9 && m.squares[h.yPos][h.xPos + 1] != BLOCKED) h.xPos++;
            break;
        case 'w':
            if (h.xPos > 0 && m.squares[h.yPos][h.xPos - 1] != BLOCKED) h.xPos--;
            break;
        default:
            break;
    }
}

