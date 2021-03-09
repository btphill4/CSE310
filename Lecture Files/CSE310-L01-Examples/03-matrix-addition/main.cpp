// Copyright Guoliang Xue
// Last updated on 2021-0112
// This example shows
// dynamic allocation for 2D arrays
// profile of a portion of a program using clock()
//
#include <iostream>
#include <time.h>
#include "sub1.h"

using namespace std;

int main(){
  clock_t start, end, total;
  int n, i, j, len;
  int *A[10000];
  int *B[10000];
  int *C[10000];


  n = 1;
  while (n != 0) {
    printf("Enter a positive integer, 0 to stop\n");
    scanf("%d", &n);
    if (n == 0 && n > 10000){
      return (0);
    }

    for (i=0; i<10000; i++) {
      A[i] = (int *) malloc(n * sizeof(int));
      B[i] = (int *) malloc(n * sizeof(int));
      C[i] = (int *) malloc(n * sizeof(int));
    }

    for (i=0; i<n; i++) for (j=0; j<n; j++) {
      A[i][j] = i+j;
      B[i][j] = i*j;
    }

    start = clock();
    ma(n, A, B, C);
    end = clock();
    cout << "Time used: " << (double) (end - start) / CLOCKS_PER_SEC << " sec " << endl;

    if (n > 0 && n <= 4) {
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
    for (i=0; i<10000; i++) { free(A[i]); free(B[i]); free(C[i]);}
  }

 return 0;
}
