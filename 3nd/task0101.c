#include <stdio.h>

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  int fib1 = 0, fib2 = 1, fib;

  printf("Result: \n");

  for (int i = 1; i <= n; i++) {
    printf("%d \n", fib1);
    fib = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib;
  }

  return 0;
}

