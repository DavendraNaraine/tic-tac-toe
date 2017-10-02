#include <stdlib.h>
#include <time.h>

void init() {
  // To prevent sequence repetition between random runs
  srand(time(NULL));
}
