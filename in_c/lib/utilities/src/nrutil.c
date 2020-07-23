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

int *ivector(long nl, long nh)
{
  int *v;

  v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
  if (!v) nerror("Allocation failure in ivector()");
  return v-nl+NR_END;
}

int *vector(long nl, long nh)
{
  float *v;

  v=(float *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(float)));
  if (!v) nerror("Allocation failure in vector()");
  return v-nl+NR_END;
}

void free_vector(float *v, long nl, long nh)
{
  free((FREE_ARG) (v+nl-NR_END));
}
void free_ivector(int *v, long nl, long nh)
{
  free((FREE_ARG) (v+nl-NR_END));
}
