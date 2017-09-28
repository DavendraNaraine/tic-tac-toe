/*
Date: 28-09-2017
Author(s): 
Tic-Tac-Toe Percept-Based Algorithm 
Computer plays by selecting a random move at all times.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
typedef char Board[ROWS][COLS];

void printBoard(Board board) {
	printf("\n\n");
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int hasWinner(Board board, int line) {
	if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
		(board[0][2]==board[1][1] && board[0][2]==board[2][0])) { return 1; }
	for(line = 0; line <=2; line++) {
		if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
			(board[0][line]==board[1][line] && board[0][line]==board[2][line])) {
				return 1;
			}
	}
	return 0;
}

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

