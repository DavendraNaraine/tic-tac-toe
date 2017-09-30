/*
Date: 28-09-2017
Author(s):
Tic-Tac-Toe Percept-Based Algorithm
Computer plays by selecting a random move at all times.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libs/Board.h"

int main() {
	int winner = 0;
	int choice = 0;
	int row = 0;
	int column = 0;
	int line = 0;
	int i;
	int randChoice;

	Board board = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	/*To prevent sequence repetition between runs*/
	srand(time(NULL));

	for (i = 0; i<9 && !winner; i++) {
		int player = i%2 + 1;
		printBoard(board);

		do {

			if (player==1) {
				randChoice = rand() % 10;
				row = --randChoice/3;
				column = randChoice%3;
			} else {
				printf("\nPlease enter the number of the square "
					"where you want to place your O: ");
				scanf("%d", &choice);

				row = --choice/3;
				column = choice%3;
			}
		} while(choice<0 || choice>9 || board [row][column]>'9');

		board[row][column] = (player == 1) ? 'X' : 'O';
		//int holder = hasWinner(board, line);
		if (hasWinner(board, line)) { winner = player; }
	}



	printBoard(board);

	if(!winner) {
		printf("The game is a draw\n");
	} 	else  if (winner==1){
			printf("Computer has won\n");
		}
		else {
			printf("You won\n");
		}
	return 0;
}
