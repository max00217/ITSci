#include <stdio.h>

int main() {
  for (int i = 1; i <= 9*9; i++) {
    int dan = (i - 1) / 9 + 1;
    int num = (i - 1) % 9 + 1;
    printf("%d x %d = %d\n", dan, num, dan * num);
    if (num == 9) printf("\n");
  }
  return 0;
}