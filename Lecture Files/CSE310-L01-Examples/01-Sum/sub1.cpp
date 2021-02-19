

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int sum(int n, int *A){
  int result, i;

  result = 0;
  for (i=0; i<n; i++){
    result = result + A[i];
  }

  return result;
}


