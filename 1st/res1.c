#include <stdio.h>
#define USD_TO_KRW 1130

int main() {
  int usd = 5;
  int krw = usd * USD_TO_KRW;

  printf("%dUSD == %dKRW\n", usd, krw);
  
  return 0;
}
