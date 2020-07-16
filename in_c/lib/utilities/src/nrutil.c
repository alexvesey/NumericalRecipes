#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define NR_END 1
#define FREE_ARG char*

void nerror(char error_text[])
//Numerical Recipes standard error handler
{
  fprintf(stderr, "Numerical Recepies runtime error...\n");
  fprintf(stderr,"%s\n", error_text);
  fprintf(stderr,"...now exiting to system...");
  exit(1);
}
