/*
Date: 28-09-2017
Author(s):
Tic-Tac-Toe Percept-Based Algorithm
Computer plays by selecting a random move at all times.
*/
#include <stdio.h>
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

	Board board = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	Result result = DRAW;
	EmptyTiles emptyTiles;
	Player activePlayer = COMPUTER;

	// Perform maximum (or less) number of moves.
	for (i = 0; i < MAX_MOVES; i++) {
		printBoard(board);

		// Generate for comuter or collect from user a valid choice.
		switch (activePlayer) {
			case COMPUTER:
				emptyTiles = getEmptyTiles(board);
				choice = randomChoiceFromEmptyTiles(emptyTiles);
				free(emptyTiles.indices);
				break;

			case USER:
				choice = collectValidChoiceFromUser(board);
				break;

			default:
				break;
		}

		// Update board
		row = (choice-1)/3;
		column = (choice-1)%3;
		board[row][column] = (activePlayer == COMPUTER) ? 'X' : 'O';

		// check for winner and break from moves loop
		if (hasWinner(board)) {
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
