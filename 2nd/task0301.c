#include <stdio.h>

int main() {
  int num1, num2;
  
  printf("Enter two positive integers: ");
  if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) {
    printf("Invalid input\n");
    return 1;
  }
  
  printf("Common divisors: ");
  
  for (int i = 1; i <= num1 && i <= num2; i++) {
    if (num1 % i == 0 && num2 % i == 0) {
      printf("%d ", i);
    }
  }
  
  printf("\n");
  
  return 0;
}