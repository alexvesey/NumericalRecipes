#ifndef _NR_UTILS_H_
#define _NR_UTILS_H_

#if defined(__STDC__) || defined(ANSI) || defined(NRANSI)
void nerror(char error_text[]);
#else
void nerror();
#endif

static float sqrarg;
#define SQR(a) ((sqrarg=(a)) == 0.0 ? 0.0 : sqrarg * sqrarg)

static double dsqrarg;
#define DSQR(a) ((dsqrarg=(a)) == 0.0 ? 0.0 : dsqrarg * dsqrarg)

int *ivector(long nl, long nh);
float *vector(long nl, long nh);

void free_vector(float *v, long nl, long nh);
void free_ivector(int *v, long nl, long nh);

float **matrix(long nrl, long nrh, long ncl, long nch);
double **dmatrix(long nrl, long nrh, long ncl, long nch);

#endif
