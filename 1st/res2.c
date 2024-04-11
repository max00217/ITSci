#include <stdio.h>

int main() {
  int DEC;

  printf("Enter a DEC integer: ");
  scanf("%d", &DEC);

  printf("DEC: %d\n", DEC);
  printf("OCR: 0%o\n", DEC);
  printf("HEX: 0x%x\n", DEC);

  return 0;
}
