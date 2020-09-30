/*
Part of the Battle sequence ICE
8 - 18 - 2019
Dr. G
*/

#include "Character.h"
#include <iostream>
#include <cstdlib>


using namespace std;

int battleNum = 0; //Driver needs access to this value

//battle sequence fix the hit value
void battle (character c1, character c2)
{
	battleNum++;

    srand(time(0));

	while (c1.state == alive && c2.state==alive)
	{
		int hitValue = 0;
		
        //c1 hits c2
        if (c1.state==alive){
            hitValue = rand() % c1.strength + 1; 
            c2.hitPoints -=hitValue;
            c2.state = statusCheck(c2);
            cout << c1.name << " hits for " << hitValue << ". " << c2.name << " has " << c2.hitPoints << endl;
        }

		//c2 hits c1
		if (c2.state==alive)
		{
			hitValue = rand() % c2.strength + 1;
			c1.hitPoints -=hitValue;
			c1.state = statusCheck(c1);
            cout << c2.name << " hits for " << hitValue << ". " << c1.name << " has " << c1.hitPoints << endl;
		}
	}
	
	cout << "And the winner is: " ;
	if (c1.state == alive) cout << c1.name << endl; else cout << c2.name << endl;
	
}

//determine if the character should be alive or dead
STATUS statusCheck(character c)
{
	if (c.hitPoints >= 0) return alive;
    return dead;
}
