#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <flmoon.h>
#include <julday.h>

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

  return exit_code;
}
