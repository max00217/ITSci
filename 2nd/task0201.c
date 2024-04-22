#include <stdio.h>
#include <stdbool.h>

int main() {
  int score;

  while (true) {
    printf("Enter your score: ");
    
    if (scanf("%d", &score) != 1 || score > 100) {
      printf("Invalid score\n");
      break;
    }

    if (score >= 90) {
      printf("Your Grade: A\n");
    } else if (score >= 80) {
      printf("Your Grade: B\n");
    } else if (score >= 70) {
      printf("Your Grade: C\n");
    } else {
      printf("Your Grade: D\n");
    }
  }

  return 0;
}