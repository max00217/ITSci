#include <stdio.h>
#include <stdbool.h>

int main() {
  int s;

  while (true) {
    if (scanf("%d", &s) != 1 || s <= 0 || s > 12) {
      printf("invalid input\n");
      break;
    }

    if (s == 12 || s == 1 || s == 2) {
      printf("winter\n\n");
    } else if (s == 3 || s == 4 || s == 5) {
      printf("spring\n\n");
    } else if (s == 6 || s == 7 || s == 8) {
      printf("summer\n\n");
    } else {
      printf("fall\n\n");
    }
  }

  return 0;
}