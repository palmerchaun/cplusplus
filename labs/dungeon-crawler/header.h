#ifndef HEADER_H
#define HEADER_H

#include <string>

enum TYPE {blank, trap, potion};

struct hero {
    std::string name;
    int health;
    int xPos;
    int yPos;
};

struct map {
    static int mapNum;
    bool discovered [10][10];
    TYPE squares [10][10];
};

map generate();
void draw(map &, hero &);
void move(char, hero &, map &);


#endif
