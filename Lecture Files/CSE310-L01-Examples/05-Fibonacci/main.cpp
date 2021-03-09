// Copyright Guoliang Xue
// Last updated on 2021-0112
// This program shows three programs for Fibonacci
// It uses clock() to measure the running time
//
#include <iostream>
#include <time.h>
#include "sub1.h"
#include "sub2.h"
#include "sub3.h"

using namespace std;

int main(){
  clock_t start, end, total;
  int n, alg;
  long result;


n = 1;
while (n != 0) {
  printf("Enter a positive integer, 0 to stop\n");
  scanf("%d", &n);
  start = clock();
  if (n == 0){
    return (0);
  }

  printf("Enter 1 or 2\n");
  scanf("%d", &alg);

  if (alg==1) {
    result = fibv1(n);
    printf("f1(%d) = %d\n", n, result);
  }

  if (alg==2) {
    result = fibv2(n);
    printf("f2(%d) = %d\n", n, result);
  }

  if (alg==3) {
    result = fibv3(n);
    printf("f3(%d) = %d\n", n, result);
  }

  end = clock();
  cout << "Time used: " << (double) (end - start) / CLOCKS_PER_SEC << " sec " << endl;

}
 return 0;

}
