#ifndef HEADER_H
#define HEADER_H

#include <string>

enum TYPE {BLANK, POTION, TRAP, BLOCKED, ENTRANCE, EXIT};

struct hero {
    std::string name;
    int health;
    int xPos;
    int yPos;
    int strength;
    int potions;
};

struct monster {
    std::string name;
    int health;
    int strength;
};

class map {
    public:
        bool discovered [20][60];
        TYPE squares [20][60];
        void draw(hero &);
        void generate();
        TYPE checkSquare(hero &);
        bool checkForPossibility();
        void checkNode(int, int);
        bool checkMap();
};

void move(char, hero &, map &);
void battle(hero &);


extern std::string names[3];
extern int healths[3];
extern int strengths[3];

#endif
