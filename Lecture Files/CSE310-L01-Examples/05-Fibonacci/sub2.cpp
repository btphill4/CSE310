#include <stdio.h>
#include <stdlib.h>
#include <iostream>

long fibv2(int n){
  long *A;
  int i;

  if (n < 1) {
    printf("Bad parameter\n");
    return -1; }

  if (n == 1 || n == 2)
    return 1;

  A = (long *) malloc(n * sizeof(long));
  if (A != NULL) {
    A[0] = 1;
    A[1] = 1;
    for (i=2; i<n; i++) A[i] = A[i-1]+A[i-2];
    return A[n-1];
  }
  else exit (-1);

}
