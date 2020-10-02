#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

map generate(){
	srand(time(NULL));	
	map m;

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			m.discovered[i][j] = false;
		}
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			int num = rand() % 10;
			switch(num){
				case 8:
					m.squares[i][j] = trap;
					break;
				case 9:
					m.squares[i][j] = potion;
					break;
				default:
					m.squares[i][j] = blank;
					break;
			}
		}
	}

	m.squares[0][0] = blank;
	m.squares[9][9] = blank;
	m.discovered[0][0] = true;

	return m;
}

void draw(map &m, hero &h){
	cout << endl;
	for (int i = 0; i < 12; i++){
		if (i){
			cout << "-\t";
		}else{
			cout << " \t";
		}
	}
	cout << endl << endl;

	for (int i = 0; i < 10; i++){
		if (i){
			cout << "|\t";
		}else{
			cout << " \t";
		}
		for (int j = 0; j < 10; j++){
			if (h.yPos == i && h.xPos == j){
				cout << "H\t";
			}else if (m.discovered[i][j]){
				switch(m.squares[i][j]){
					case blank:
						cout << " \t";
						break;
					case trap:
						cout << "X\t";
						break;
					case potion:
						cout << "O\t";
						break;
					default:
						break;
				}
			}else{
				cout << "?\t";
			}
		}
		cout << "|" << endl << endl;
	}
	for (int i = 0; i < 12; i++){
		if (i != 11){
			cout << "-\t";
		}else{
			cout << " \t";
		}
	}
	cout << endl << endl;
}
