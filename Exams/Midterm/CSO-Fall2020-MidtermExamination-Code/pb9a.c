#include <stdio.h>
#include <stdlib.h>

long sparse_switch_eg
(long x, long y, long z) {
  long w = 1;
  switch(x) {
  case 100:
    w = y*z;
    break;
  case 200:
    w = y/z;
    /* Fall through */
  case 300:
    w += z;
  case 600:
    w -= z;
    break;
  case 700:
    w += z;
  default:
    w = 2;
  }
  return w;
}

int main() {
  long x = 200;
  long y = 10;
  long z = 20;
  long w = sparse_switch_eg(x, y, z);
  printf("x = %ld, y = %ld, z = %ld --> %ld\n",
	 x, y, z, w);
  exit(0);
}
