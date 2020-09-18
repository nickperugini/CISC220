/*
 * main.cpp
 *
 *
 *
 *  Created on: Sep 11, 2020
 *  	Author: Nick Perugini
 *      Partner: Suryanuj Gupta
 */

#include <iostream>
#include <stdlib.h>
#include "othello.cpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	Othello game("b1",'B',"s1",'O');
	Othello game2("b1",'B');
	Othello game3;
	game.playGame();
}
