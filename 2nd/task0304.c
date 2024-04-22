#include <stdio.h>

int main() {
  int n, i, j, blank;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    for (blank = 1; blank <= n - i; blank++) {
      printf(" ");
    }
    for (j = 1; j <= 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  for (i = n - 1; i >= 1; i--) {
    for (blank = 1; blank <= n - i; blank++) {
      printf(" ");
    }
    for (j = 1; j <= 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}