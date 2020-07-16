#include <stdio.h>
#include <flmoon.h>

int main()
{
  int exit_code = 1;

  printf("The Driver for NumericalRecepiesInC\n");

  int n = 1;
  int nph = 0;
  long *jd = 0;
  float *frac = 0;

  flmoon(n, nph, jd, frac);

  fprintf("n=%i , nph=%i, jd=%d, frac=%d",n,nph,jd,frac);

  return 0;
}
