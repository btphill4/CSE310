#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int ma(int n, int *A[10000], int *B[10000], int *C[10000]){
  int i, j, k;

  if (n < 1) return -1; 

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return 0;
}
