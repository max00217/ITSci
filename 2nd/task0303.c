#include <stdio.h>

int main() {
  int lines;
  
  printf("Enter the number of lines: ");
  scanf("%d", &lines);

  int count = 1;
  for (int i = 1; i <= lines; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d ", count);
      count++;
    }
    printf("\n");
  }

  return 0;
}