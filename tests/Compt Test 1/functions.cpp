#include "functions.h"
#include "constants.h"
#include "planets.h"

using namespace Gravity;

double currentCal = 0;

double getGravity(Planet planet)
{
	
	switch(planet){
		case sun : return Sun;
		case jupiter : return Jupiter;
		case neptune : return Neptune;
		case saturn : return Saturn;
		case earth : return Earth;
		case uranus : return Uranus;
		case venus : return Venus;
		case mars : return Mars;
		case mercury : return Mercury;
		case moon : return Moon;
		case pluto : return Pluto;
		default : return 0;
	}
}

void setCalories(double mass, Planet planet, double distance)
{
	currentCal = mass * getGravity(planet) * distance * CALCONST;
}
