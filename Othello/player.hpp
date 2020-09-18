/*
 * player.hpp
 *
 *  Created on: Sep 11, 2020
 *  Author: Nicholas Perugini
 *  Partner: Suryanuj Gupta
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Player {
	friend class Othello;
	public:

		string name;
		char piece;

		Player();
		Player(string, char);

};

#endif /* OTHELLO_HPP_ */
