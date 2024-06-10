#include <stdio.h>

int fibo(int n) {
  if (n <= 1) {
    return n;
  }
  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Result: \n");

  for (int i = 0; i <= n; i++) {
    printf("%d \n", fibo(i));
  }

  return 0;
}



