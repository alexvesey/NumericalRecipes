#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include "flmoon.h"
#include "julday.h"
#include "gauss_jordan.h"

int testLinearAlgebra(void);

int main()
{
  int exit_code = 0;

  printf("//////////////////////////////////////////\n");
  printf("The Driver for NumericalRecepiesInC Tests\n");
  printf("//////////////////////////////////////////\n\n");

  int n = 1;
  int nph = 0;
  long jd;
  float frac;

  flmoon(n, nph, &jd, &frac);

  printf("flmoon test: ");
  printf("n=%i , nph=%i, jd=%ld, frac=%lf\n",n,nph,jd,(double)frac);

  int mm = 5;
  int id = 23;
  int iyyy = 1968;
  long expected_julday = 2440000;

  long calculated_julday = julday(mm,id,iyyy);

  if(calculated_julday != expected_julday)
  {
    printf("Expected Jul Day = %ld but calculated day = %ld\n", expected_julday, calculated_julday);
    exit_code++;
  }
  else
  {
    printf("JulDay test passed\n");
  }

  int mm_in;
  int id_in;
  int iyyy_in;

  caldat(calculated_julday, &mm_in, &id_in, &iyyy_in);

  if(mm == mm_in && id == id_in && iyyy == iyyy_in)
  {
    printf("Caldat Test Passed\n");
  }
  else
  {
    printf("Caldat Test Failed. Expected %d/%d/%d but got %d/%d/%d\n",mm,id,iyyy,mm_in,id_in,iyyy_in);
    exit_code++;
  }

  exit_code = testLinearAlgebra();

  if(exit_code == 0)
  {
    printf("Linear Algebra Tests Passed\n");
  }

  return exit_code;
}

int testLinearAlgebra(void)
{
  int exit_code = 0;
  int n = 3;
  int m = 1;
  float **a = matrix(1,n,1,n);
  a[1][1] = 1; a[1][2]=  1;a[1][3] = -1;
  a[2][1] = 1; a[2][2]= -1;a[2][3] =  2;
  a[3][1] = 2; a[3][2]=1;a[3][3] = 1;

  float **x = matrix(1,n,1,m);
  x[1][1] = 7; x[2][1] = 3; x[3][1] = 9; 

  gaussj(a,n,x,m);

  assert(6.0 == x[1][1]);
  assert(-1.0 == x[2][1]);
  assert(-2.0 == x[3][1]); 

  printf("Solution to gauss jordan example: %f,%f,%f\n", x[1][1], x[2][1], x[3][1]);

  return exit_code;
}
