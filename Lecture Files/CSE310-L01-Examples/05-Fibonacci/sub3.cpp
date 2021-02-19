#include <stdio.h>
#include <stdlib.h>

long fibv3(int n){
  long A[2];
  int i;

  if (n < 1) {
    printf("Bad parameter\n");
    return -1; }

  if (n == 1 || n == 2)
    return 1;

    A[0] = 1;
    A[1] = 1;
    for (i=2; i<n; i++){
      A[2] = A[0]+A[1];

      A[0] = A[1];
      A[1] = A[2];
    }
    return A[2];
}
