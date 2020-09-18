/*
 * othello.hpp
 *
 *  Created on: Sep 11, 2020
 *  Author: Nicholas Perugini
 *  Partner: Suryanuj Gupta
 */

#ifndef OTHELLO_HPP_
#define OTHELLO_HPP_
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "player.hpp"
using namespace std;

//static int boardSize = 8;

class Othello {
	public:
		char matrix[9][9];
		Player player1;
		Player player2;
		int numPlayers;

		Othello();
		Othello(string, char);
		Othello(string, char, string, char);

		void playGame();
		void makemat();
		void printmat();
		void placepiece(string, char);
		int countandflippieces(int, int, string, char, bool);
		void ckwin();
		void compplacepiece(Player p);
};

#endif /* OTHELLO_HPP_ */
