#include <stdio.h>

int main() {
  int x = 10;  // 0000 1010
  int y = 6;   // 0000 0110
  printf("%d(n&m)\n", x & y);
  printf("%d(n|m)\n", x | y);
  printf("%d(n^m)\n", x ^ y); 
  printf("%d(~n)\n", ~x);
  printf("%d(~m)\n", ~y);
  printf("%d(n<<k)\n", x << 2);
  printf("%d(n>>k)\n", y >> 1);

  return 0;
}
