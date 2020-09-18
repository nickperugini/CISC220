/*
 * player.cpp
 *
 *  Created on: Sep 11, 2020
 *  Author: Nicholas Perugini
 *  Partner: Suryanuj Gupta
 */

#include "player.hpp"

Player::Player(){
	name="computer";
	piece='O';
}

Player::Player(string name1, char piece1){
	name=name1;
	piece=piece1;
}
