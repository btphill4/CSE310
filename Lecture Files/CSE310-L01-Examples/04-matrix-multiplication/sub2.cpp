#include <stdio.h>
#include <stdlib.h>

using namespace std;

int mm(int n, int **A, int **B, int **C){
  int i, j, k;

  if (n < 1) return -1; 

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      C[i][j] = 0;
      for (k=0; k<n; k++){
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
    }
  }
  return 0;
}
