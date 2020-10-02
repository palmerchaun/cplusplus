/*
Header file for a generic character
*/

#include<string>

using namespace std;

enum STATUS {alive, dead};

struct character
{
	STATUS state;
	int hitPoints;
	int strength;	
	string name;
};


void battle(character, character);

typedef character hero, badguy;

STATUS statusCheck(character);

extern int battleNum;
