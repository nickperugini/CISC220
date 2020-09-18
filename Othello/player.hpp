/*
 * player.hpp
 *
 *
 *
 *  Created on: Sep 13, 2020
 *      Author: Nick Perugini
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

		// Setter
		//void setPiece(char s);
		//char getPiece();

};




#endif /* OTHELLO_HPP_ */
