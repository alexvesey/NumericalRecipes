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

float **matrix(long nrl, long nrh, long ncl, long nch)
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  float **m;
 
  m = (float **) malloc((size_t)((nrow+NR_END)*sizeof(float*)));
  if(!m)
  {
    nerror("allocation failure 1 in matrix()");
  }
  m += NR_END;
  m -= nrl;
  
  m[nrl]=(float *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(float)));
  if(!m[nrl])
  {
    nerror("allocation failure 2 in matrix()");
  }
  m[nrl] += NR_END;
  m[nrl] -= ncl;

  for(i=nrl+1; i<=nrh;i++)
  {
    m[i] = m[i-1]+ncol;
  }
 
  return m;
}
double **dmatrix(long nrl, long nrh, long ncl, long nch)
{

}
