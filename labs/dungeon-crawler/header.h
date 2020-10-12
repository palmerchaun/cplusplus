#ifndef HEADER_H
#define HEADER_H

#include <string>

enum TYPE {BLANK, POTION, TRAP, ENTRANCE, EXIT};

struct hero {
    std::string name;
    int health;
    int xPos;
    int yPos;
    int strength;
};

struct monster {
    std::string name;
    int health;
    int strength;
};

class map {
    public:
        bool discovered [10][10];
        TYPE squares [10][10];
        void draw(hero &);
        void generate();
        TYPE checkSquare(hero &);
};

void move(char, hero &);
void battle(hero &);

#endif
