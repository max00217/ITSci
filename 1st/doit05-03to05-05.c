#include <stdio.h>
#include <stdbool.h>

int main() {
  // int q = 5;
  // int w = q++;
  // int e = ++q;
  // int r = q--;
  // int t = --q;

  // printf("%d(n++), %d(++n), %d(n--), %d(--n)\n\n", q, w, e, r, t);

  // int a = q += 1;
  // int s = q -= 1;
  // int d = q *= 1;
  // int f = q /= 1;
  // int g = q %= 1;
  // int h = q &= 1;
  // int j = q ^= 1;
  // int k = q |= 1;

  // printf("%d(+=) %d(-=) %d(*=) %d(/=) %d(%=) %d(&=) %d(^=) %d(|=)\n", q, a, s, d, f, g, h, j, k);

  int q = 0;
  int w = 10;
  int e = 10;
  int r = 11;
  printf(
    "%d(n>m), %d(n<m), %d(n==m), %d(n!=m), %d(n>=m), %d(n<=m)\n", 
    q > w, q < w, q == w, q != w, w >= e, w <= r
    );

  bool a = true;
  bool b = false;
  printf("%d(n||m), %d(n&&m), %d(!n), %d(!n)\n", a || b, a && b, !a, !b);

  return 0;
}
