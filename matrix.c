#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define N 1024

double A[N][N], B[N][N], C[N][N], T[N][N];

#ifdef USE_TRANSPOSE
double T[N][N];
#endif

/*
 * Transpose matrix B
 */
void transposeB()
{
  int i, j;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      T[i][j] = B[j][i];
}

/* conventional approach */
void mult1()
{
  int i, j, k;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      for (k=0; k<N; k++)
        C[i][j] += A[i][k]*B[k][j];
}

/* using the transpose */
#ifdef USE_TRANSPOSE
void mult2()
{
  int i, j, k;
  transposeB();
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      for (k=0; k<N; k++)
        C[i][j] += A[i][k]*T[j][k];
}
#endif

void printRes()
{
  int i, j;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      fprintf(stdout, "%f ", C[i][j]); 
}

int main()
{

  struct timeval start, end;

/*
 * Initialize all 3 matrices (possibily warming up the cache)
 */
  int i, j;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++) {
      A[i][j] = i+j; B[i][j] = i+2*j;
      C[i][j] = 0;
    }

  int duration;
   
  gettimeofday(&start, NULL);

#ifdef USE_TRANSPOSE
  mult2();
#else
  mult1();
#endif

  gettimeofday(&end, NULL);
  duration = (end.tv_sec*1000 + end.tv_usec/1000) - (start.tv_sec*1000 + start.tv_usec/1000);
  printf("GFLOPS = %f - time = %fs\n", (float)N*N*N*2/(float)duration/(float)1000000, duration/(float)1000);
//  printRes();


  return 0;
}
