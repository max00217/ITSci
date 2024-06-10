#include <stdio.h>

int main() {
  char a = 0x12, b = 0x34;
  short c = 0x5678;
  int t;

  t = a;
  t = (t << 8) | b;
  t = (t << 16) | c;

  printf("0x%x\n", t);

  return 0;
}


