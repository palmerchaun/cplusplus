#include <iostream>
#include "header.h"

using namespace std;

int main(){
    char d;
    map m = generate();
    hero h;
    h.health = 10;
    h.xPos = 0;
    h.yPos = 0;
    draw(m, h);

    while(h.health > 0){
        cout << "Level " << endl;
        cout << "Current health: " << h.health << endl;
        cout << "Enter a direction (n s e w): ";
        cin >> d;
        move(d, h, m);
        draw(m, h);
    }
}
