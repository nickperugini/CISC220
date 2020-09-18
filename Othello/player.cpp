/*
 * player.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Nick Perugini
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

/*void Player::setPiece (char s){
      piece = s;
}

char Player::getPiece(){
  return piece;
}
*/
