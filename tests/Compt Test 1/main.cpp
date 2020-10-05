//3150 Competency Test 1
//10-04-20
//Seth Palmer

#include <iostream>
#include "planets.h"
#include "functions.h"

using namespace std;

extern double currentCal;

int main(){
    int selection;
    double distance = 0;
    double mass;
    int lifts;
    
    cout << "Choose 0 for Sun \nChoose 1 for Jupiter\nChoose 2 for Neptune\nChoose 3 for Saturn\nChoose 4 for Earth\nChoose 5 for Uranus\nChoose 6 for Venus\nChoose 7 for Mars\nChoose 8 for Mercury\nChoose 9 for Earth's moon\nChoose 10 for Pluto\n";
    cin >> selection;
    cout << "Enter distance of benchpress in meters\n";
    cin >> distance;
    cout << "Enter benchpress weight in kilograms\n";
    cin >> mass;
    setCalories(mass, Planet(selection), distance);
    cout << "Enter number of lifts\n";
    cin >> lifts;
    cout << "Calories burned = " << lifts * currentCal << endl;
}
