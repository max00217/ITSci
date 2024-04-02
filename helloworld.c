#include <stdio.h>

int main() {
  // Variable declaration and initialization
  int num1 = 10;
  float num2 = 3.14;
  char letter = 'A';
  
  // Arithmetic operations
  int sum = num1 + 5;
  float product = num1 * num2;
  
  // Conditional statement
  if (sum > 15) {
    printf("The sum is greater than 15.\n");
  } else {
    printf("The sum is not greater than 15.\n");
  }
  
  // Looping statement
  for (int i = 0; i < 5; i++) {
    printf("Iteration %d\n", i);
  }
  
  // Function definition and call
  int square(int x) {
    return x * x;
  }
  
  int result = square(4);
  printf("The square of 4 is %d\n", result);
  
  return 0;
}