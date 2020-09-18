/*
 * othello.cpp
 *
 *  Created on: Sep 11, 2020
 *  Author: Nicholas Perugini
 *  Partner: Suryanuj Gupta
*/

#include "othello.hpp"

Othello::Othello(){
	player1.piece='O';
	player1.name="computer";
	player2.piece='B';
	player2.name="computer";
	numPlayers=0;
}

Othello::Othello(string str1, char c){
	player1.piece=c;
	player1.name=str1;
	player2.piece='O';
	player2.name="computer";
	numPlayers=1;
}

Othello::Othello(string str1, char c1, string str2, char c2){
	player1.name=str1;
	player1.piece=c1;
	player2.name=str2;
	player2.piece=c2;
	numPlayers=2;
}

void Othello::makemat(){
	//For every box in the matrix, put an underscore in it, starting with 1,1 not 0,0.
	for(int i=1;i<9;i++){
		for(int j=1;j<9;j++){
			matrix[i][j]='_';
		}
	}
	//In these Y,X co-ordinates, put the following pieces in them, as they are the middle of the board
	matrix[4][5]='O';
	matrix[4][4]='B';
	matrix[5][5]='B';
	matrix[5][4]='O';
}

void Othello::printmat(){
	//For the Top and Side bar, add these numbers in them. This will help the player choose a spot better.
	//This is also why we made a 9x9 matrix and not 8x8, so we can use the top and side row and column to
	//print the numbers.
	string charString="-01234567";
	for(int i=0; i<9; i++){
		matrix[0][i]=charString[i];
	}

	for(int i=1; i<9; i++){
		matrix[i][0]=charString[i];
	}

	int counter=0;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cout << matrix[i][j]<<"\t";
			counter++;

			if(counter%9==0){
				cout << endl;
			}
		}
	}
}

void Othello::placepiece(string player, char piece){
	int x;
	int y;
	bool flag=true;

	//Asks for user input to the co-ordinates of where they want to place the piece.
	while(flag){
		cout<<"enter the x coordinate on the board: ";
			cin >> x;
		cout<<"enter the y coordinate on the board: ";
			cin >> y;

			//If the box you choose is empty, place your piece there.
			if((x>=0 && x<=7)&&(y>=0 && y<=7)){
				if(matrix[x+1][y+1]=='_'){
					matrix[x+1][y+1]=piece;
					flag=false;
				}
			}

			int flipped=countandflippieces(x,y,player,piece,true);

			if(flipped<0){
				cout << "Player forfeits turn!" << endl;
			}
	}
}

int Othello::countandflippieces(int i, int j, string player, char piece, bool flip){
	//Default spot is i+1,j+1
	int globalCounter=0; //this is for the computer to determine the best spot to play
	if(flip==true){

		//Check down
		if(matrix[i+2][j+1]!=piece && matrix[i+2][j+1]!='_'){
			int counter=0;

			for(int k=i+2;k<(8-k);k++){
				if(matrix[k][j+1]==piece){
					for(int k=i+2;matrix[k][j+1]==piece;k++){
						counter++;
						matrix[k][j+1]=piece;
					}
				}
			}
			if(counter>0){
				globalCounter+=counter;
			}

		}

		//Checks up
		if(matrix[i][j+1]!=piece && matrix[i][j+1]!='_'){
			int counter=0;

			for(int k=i;k>(8-k);k--){
				if(matrix[k][j+1]==piece){
					for(int k=i;matrix[k][j+1]==piece;k--){
						counter++;
						matrix[k][j+1]=piece;
					}
				}
			}
			if(counter>0){
				globalCounter+=counter;
			}

		}

		//Checks left
		if(matrix[i+1][j]!=piece && matrix[i+1][j]!='_'){
			int counter=0;

			for(int k=j;k>(8-k);k--){
				if(matrix[i+1][k]==piece){
					for(int k=j;matrix[i+1][k]==piece;k--){
						counter++;
						matrix[i+1][k]=piece;
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks right
		if(matrix[i+1][j+2]!=piece && matrix[i+2][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				if(matrix[i+1][k]==piece){
					for(int k=j;matrix[i+1][k]==piece;k++){
						counter++;
						matrix[i+1][k]=piece;
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks up-right
		if(matrix[i][j+2]!=piece && matrix[i][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				for(int z=i;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j+2;matrix[z][k]==piece;k++){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks up-left
		if(matrix[i][j]!=piece && matrix[i][j]!='_'){
			int counter=0;

			for(int k=j;k<(8-k);k--){
				for(int z=i;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j;matrix[z][k]==piece;k--){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks down-right
		if(matrix[i+2][j+2]!=piece && matrix[i+2][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				for(int z=i+2;z<(8-z);z++){
					if(matrix[z][k]==piece){
						for(int k=j+2;matrix[z][k]==piece;k++){
							for(int z=i+2;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks down-left
		if(matrix[i+2][j]!=piece && matrix[i+2][j]!='_'){
			int counter=0;

			for(int k=j;k<(8-k);k++){
				for(int z=i+2;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j;matrix[z][k]==piece;k++){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}
	}

	if(flip==false){

		//Check down
		if(matrix[i+2][j+1]!=piece && matrix[i+2][j+1]!='_'){
			int counter=0;

			for(int k=i+2;k<(8-k);k++){
				if(matrix[k][j+1]==piece){
					for(int k=i+2;matrix[k][j+1]==piece;k++){
						counter++;
						matrix[k][j+1]=piece;
					}
				}
			}
			if(counter>0){
				globalCounter+=counter;
			}

		}

		//Checks up
		if(matrix[i][j+1]!=piece && matrix[i][j+1]!='_'){
			int counter=0;

			for(int k=i;k>(8-k);k--){
				if(matrix[k][j+1]==piece){
					for(int k=i;matrix[k][j+1]==piece;k--){
						counter++;
						matrix[k][j+1]=piece;
					}
				}
			}
			if(counter>0){
				globalCounter+=counter;
			}

		}

		//Checks left
		if(matrix[i+1][j]!=piece && matrix[i+1][j]!='_'){
			int counter=0;

			for(int k=j;k>(8-k);k--){
				if(matrix[i+1][k]==piece){
					for(int k=j;matrix[i+1][k]==piece;k--){
						counter++;
						matrix[i+1][k]=piece;
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks right
		if(matrix[i+1][j+2]!=piece && matrix[i+2][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				if(matrix[i+1][k]==piece){
					for(int k=j;matrix[i+1][k]==piece;k++){
						counter++;
						matrix[i+1][k]=piece;
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks up-right
		if(matrix[i][j+2]!=piece && matrix[i][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				for(int z=i;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j+2;matrix[z][k]==piece;k++){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks up-left
		if(matrix[i][j]!=piece && matrix[i][j]!='_'){
			int counter=0;

			for(int k=j;k<(8-k);k--){
				for(int z=i;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j;matrix[z][k]==piece;k--){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks down-right
		if(matrix[i+2][j+2]!=piece && matrix[i+2][j+2]!='_'){
			int counter=0;

			for(int k=j+2;k<(8-k);k++){
				for(int z=i+2;z<(8-z);z++){
					if(matrix[z][k]==piece){
						for(int k=j+2;matrix[z][k]==piece;k++){
							for(int z=i+2;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}

		//Checks down-left
		if(matrix[i+2][j]!=piece && matrix[i+2][j]!='_'){
			int counter=0;

			for(int k=j;k<(8-k);k++){
				for(int z=i+2;z<(8-z);z--){
					if(matrix[z][k]==piece){
						for(int k=j;matrix[z][k]==piece;k++){
							for(int z=i;matrix[z][k]==piece;z--){
								counter++;
								matrix[z][k]=piece;
							}
						}
					}
				}
			}

			if(counter>0){
				globalCounter+=counter;
			}
		}
	}
	return globalCounter;
}

void Othello::compplacepiece(Player p){
	int count;
	int topCount=0;
	int topX;
	int topY;
	string playerUp=p.name;
	char c=p.piece;

		for(int i=1;i<9;i++){
			for(int j=1;j<9;j++){
				if(matrix[i][j]=='_'){ //Iterates through every place on the board so the best stop can be determined
					matrix[i][j]=c;//Places a temporary piece so that our countandflippiece function can count how many pieces are in-between that and the next one
					count=countandflippieces(i,j,playerUp, c, false); //Sets count equal to the amount of flips
					matrix[i][j]='_'; //Removes the temporary piece
					if(count>topCount){
						topCount=count; //If the number of flipped pieces is greater than 0 or the last topCount it sets topCount to that number and saves the board spaces. This allows the computer to save the best possible location.
						topX=i; //This allows the computer to save the best possible location, essentially, making it choose the best possible choice for every turn.
						topY=j;
					}
				}
				matrix[topX][topY]=c; //Sets the piece to be placed where the most possible opponent pieces will be flipped
				countandflippieces(topX,topY,playerUp,c,true);
			}
		}
	}

void Othello::ckwin(){
		int underScoreCount=0;
		int counter1=0;
		int counter2=0;
		//bool canCheck=false;

		for(int i=1;i<9;i++){
			for(int j=1;j<9;j++){
				if(matrix[i][j]=='_'){
					underScoreCount++;
				}
			}
		}

		if(underScoreCount==0){
		for(int i=1;i<9;i++){
			for(int j=1;j<9;j++){
				if(matrix[i][j]==player1.piece){
					counter1++;
				}
	        else {
	          counter2++;
	          }
			}
	    }
	  }

	  if(counter1>counter2){
	    cout << "Player 1 wins with: " << counter1 << "versus" << counter2 << endl;
	  }

	  else if(counter2>counter1){
	    cout << "Player 2 wins with: " << counter2 << "versus" << counter1 << endl;
	  }

	  else{
	    cout << "Tie Game" << endl;
	  }

}
//playGame Method:
void Othello::playGame(){
	 makemat();
	 printmat();
	 bool play = true;
	 int fullsqrs = 0;
	 Player p;
	 p=player1;
	 bool whichp = true;
	 bool turn = true;

	 if (rand()%2 == 0) { // p1 plays first
		p = player2;
		turn = false;
		whichp = false;
	 }

	 while ((play) && (fullsqrs < 64)){
		cout << endl << p.name <<" ("<<p.piece<<") choose your square: "<<endl;

		if ((numPlayers == 2) || ((numPlayers == 1) && turn)){
			placepiece(p.name,p.piece);
		}

		else if ((numPlayers == 0) || ((numPlayers == 1) && (turn == false))){
			compplacepiece(p);
		}

		turn = !turn;
		printmat();
		if (whichp) {
			p = player2;
			whichp = false;
		}
		else {
			p=player1;
			whichp = true;
		}

		fullsqrs+=1;
	}
}
/* *************************************************************************
and code for the main function, which should be in its own file with a .cpp
extension, located in the same project folder as your Othello Class and your Player
Class files
****************************************************************************/
