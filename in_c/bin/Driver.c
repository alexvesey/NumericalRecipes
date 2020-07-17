#include <stdio.h>
#include <stdlib.h>
#include <flmoon.h>

int main()
{
  int exit_code = 1;

  printf("////////////////////////////////////\n");
  printf("The Driver for NumericalRecepiesInC\n");
  printf("////////////////////////////////////\n\n");

  int n = 1;
  int nph = 0;
  long *jd = malloc(sizeof(long));
  float *frac = malloc(sizeof(float));

  flmoon(n, nph, jd, frac);

  printf("flmoon test: ");
  printf("n=%i , nph=%i, jd=%ld, frac=%lf\n",n,nph,*jd,(double)*frac);

  return 0;
}
