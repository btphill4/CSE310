#include <stdio.h>
#include <stdlib.h>

long fibv1(int n){
  if (n < 1) {
    printf("Bad parameter\n");
    return -1; }
  if (n == 1 || n == 2)
    return 1;
  else
    return fibv1(n-1) + fibv1(n-2);
}
