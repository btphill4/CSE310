
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int mysort(int n, int *A){
  int i, j;
  int key;

  for (j=1; j<n; j++){
    key = A[j];
    i = j-1;
    while (i>=0 && A[i] > key){
      A[i+1] = A[i];
      i = i-1;
    }
    A[i+1] = key;
  }
  return 0;
}


