#include <stdbool.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

typedef char Tile;
typedef Tile Board[ROWS][COLS];

typedef struct {
	int* indices;
	int size;
} EmptyTiles;

void printBoard(Board board) {
	printf("\n\n");
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

bool hasWinner(Board board) {
	int line;
	if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
		(board[0][2]==board[1][1] && board[0][2]==board[2][0])) { return true; }
	for(line = 0; line <=2; line++) {
		if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
			(board[0][line]==board[1][line] && board[0][line]==board[2][line])) {
				return true;
			}
	}
	return false;
}

EmptyTiles getEmptyTiles(Board board) {
	int emptyTilesSize = 0;
	int* emptyTiles = (int*) malloc(sizeof(int) * emptyTilesSize);
	int i, row, column;

	for (i = 1; i <= 9; i++) {
		row = (i-1)/3;
		column = (i-1)%3;

		if (!(board[row][column] > '9')) {
			emptyTilesSize++;
			emptyTiles = (int*) realloc(emptyTiles, sizeof(int) * emptyTilesSize);
			emptyTiles[emptyTilesSize - 1] = i;
		}
	}

	return (EmptyTiles) { emptyTiles, emptyTilesSize };
}
