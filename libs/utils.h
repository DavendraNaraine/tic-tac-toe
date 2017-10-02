void init() {
  // To prevent sequence repetition between random runs
  srand(time(NULL));
}

int randomChoiceFromEmptyTiles(EmptyTiles emptyTiles){
  int index = (rand() % emptyTiles.size);
  return emptyTiles.indices[index];
}

int collectValidChoiceFromUser(Board board) {
  int choice, row, column;

  do {
    printf("\nPlease enter the number of the square where you want to place your O: ");
    scanf("%d", &choice);

    row = (choice-1)/3;
    column = (choice-1)%3;
  } while(board[row][column]>'9');

  return choice;
}
