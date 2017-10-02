/*
Date: 28-09-2017
Author(s):
Tic-Tac-Toe Percept-Based Algorithm
Computer plays by selecting a random move at all times.
*/
#include <stdio.h>
#include <stdlib.h>
#include "libs/Board.h"
#include "libs/Player.h"
#include "libs/Result.h"
#include "libs/utils.h"

#define MAX_MOVES 9

int main() {
	init();

	int i;
	int choice;
	int row;
	int column;
	int line = 0;

	Board board = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	Result result = DRAW;
	Player activePlayer = COMPUTER;

	printBoard(board);

	// Perform maximum (or less) number of moves.
	for (i = 0; i < MAX_MOVES; i++) {
		printBoard(board);

		// Collect from user or generate for comuter a valid move choice.
		do {
			switch (activePlayer) {
				case COMPUTER:
					choice = (rand() % 9) + 1;
					break;

				case USER:
					printf("\nPlease enter the number of the square where you want to place your O: ");
					scanf("%d", &choice);
					break;

				default:
					break;
			}

			row = (choice-1)/3;
			column = (choice-1)%3;
		} while(choice<1 || choice>9 || board[row][column]>'9');

		// Update board
		board[row][column] = (activePlayer == COMPUTER) ? 'X' : 'O';

		// check for winner and break from moves loop
		if (hasWinner(board, line)) {
			result = activePlayer == COMPUTER ? COMPUTER_WINS : USER_WINS;
			break;
		}

		// toggle active player
		activePlayer = activePlayer == COMPUTER ? USER : COMPUTER;
	}

	printBoard(board);
	printResult(result);

	return 0;
}
