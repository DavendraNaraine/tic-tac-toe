typedef enum {
  DRAW,
  COMPUTER_WINS,
  USER_WINS
} Result;

void printResult(Result result) {
  switch (result) {
    case DRAW:
      printf("The game is a draw\n");
      break;

    case COMPUTER_WINS:
      printf("Computer has won\n");
      break;

    case USER_WINS:
      printf("You won\n");
      break;
  }
}
