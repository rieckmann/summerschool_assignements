#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "output.h"

// define a function to compute the 2-Norm
double L2Norm(double* vector, int size){
  double norm;
  for (int i=0; i<size; i++){
    norm+=vector[i]*vector[i];
  }
  return sqrt(norm);
}

int main(int argc, char *argv[]) {

  // first create the matrix A
  double *A = (double *)malloc(1000*1000*sizeof(double));
  randomT2(A);

  // now create the b vector
  double *b = (double *)malloc(1000*sizeof(double));
  // initialize the first entry of b
  b[0] = 0.5;
  // polpulate the vector
  for(int i=1; i<1000; i++){
    b[i]=b[i-1]*(-1);
  }

  // allocate memory for the result vector
  double *c = (double *)malloc(1000*sizeof(double));

  // setup timer
  clock_t start, end;
  double timer;
  // start the timer
  start=clock();

  // calculate c
  for (int i=0; i<1000; i++){
    for(int j=0; j<1000; j++){
      c[i]+=A[i*1000+j]*b[j];
    }
  }

  // calculate the 2-Norm of c
  double c2norm = L2Norm(c, 1000);

  // stop the timer
  end=clock();
  timer = ((double) (end - start)) / CLOCKS_PER_SEC;

  // clear c
  for (int i=0;i<1000;i++){
    c[i]=0;
  }
  // output results
  outputT2(c2norm, timer);

  // now lets switch up the calculation of c
  printf("If we change the way c is calculated, we get this: \n");
  // start the timer
  start=clock();
  // calculate c
  for (int i=0; i<1000; i++){
    for(int j=0; j<1000; j++){
      c[j]+=A[j*1000+i]*b[i];
    }
  }
  // calculate the 2-Norm of c
  c2norm = L2Norm(c, 1000);
  // stop the timer
  end=clock();
  timer = ((double) (end - start)) / CLOCKS_PER_SEC;

  // output results
  outputT2(c2norm, timer);

  // free the allocated memory
  free(A);
  free(b);
  free(c);
}
