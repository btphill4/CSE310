// Copyright Guoliang Xue
// Last updated on 2021-0112
// This program shows
// dynamic memory allocation for pointer to pointers
// profiling matrix multiplication: O(n^3) time
#include <iostream>
#include <time.h>
#include "sub2.h"

using namespace std;

int main(){
  clock_t start, end, total;
  int n, i, j, k;
  int **A, **B, **C, **D;


  n = 1;
  while (n != 0) {
    printf("Enter a positive integer, 0 to stop\n");
    scanf("%d", &n);
    if (n == 0){
      return (0);
    }

    start = clock();
    A = (int **) malloc(n*sizeof(int *));
    B = (int **) malloc(n*sizeof(int *));
    C = (int **) malloc(n*sizeof(int *));
    for (i=0; i<n; i++) A[i] = (int *) malloc(n*sizeof(int));
    for (i=0; i<n; i++) B[i] = (int *) malloc(n*sizeof(int));
    for (i=0; i<n; i++) C[i] = (int *) malloc(n*sizeof(int));

    for (i=0; i<n; i++) for (j=0; j<n; j++) {
      A[i][j] = i+j;
      B[i][j] = i*j;
    }
    mm(n, A, B, C);
    end = clock();
    cout << "Time used: " << (double) (end - start) / CLOCKS_PER_SEC << " sec " << endl;

    if (n <= 4) {
      cout << "A= " << endl;
      for (i=0; i<n; i++){
        for (j=0; j<n; j++){
          cout << A[i][j] << "  ";
        }
        cout << endl;
      }
  
      cout << "B= " << endl;
      for (i=0; i<n; i++){
        for (j=0; j<n; j++){
          cout << B[i][j] << "  ";
        }
        cout << endl;
      }
  
      cout << "C= " << endl;
      for (i=0; i<n; i++){
        for (j=0; j<n; j++){
          cout << C[i][j] << "  ";
        }
        cout << endl;
      }
    }
    for (i=0; i<n; i++) free(A[i]); free(A);
    for (i=0; i<n; i++) free(B[i]); free(B);
    for (i=0; i<n; i++) free(C[i]); free(C);
  }

 return 0;
}
