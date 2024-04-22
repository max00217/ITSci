#include <stdio.h>

int main() {
  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  int q = 2; //기본 최대 소인수

  for (int i = 2; i <= num; i++) {
    while (num % i == 0) {
      q = i;
      num /= i;
    }
  }

  printf("Largest prime factor: %d\n", q);

  return 0;
}