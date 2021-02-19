// Copyright Guoliang Xue
// Last updated on 2021-0112
// This example shows file I/O, parameter passing, and dynamic memory allocation
//
#include <iostream>
#include "sub1.h"
#include "sub2.h"

using namespace std;

int main(){
  FILE *fp;
  int n, i, result;
  int *A;

  fp = fopen("INPUT.txt", "r");
  if (fp == NULL) {
    cout << "cannot open file" << endl; exit (-1);
  }

  fscanf(fp, "%d", &n);
  // cout << "n= " << n << endl;

  A = (int *) malloc(n*sizeof(int));
  if (A == NULL) {
    cout << "cannot allocate memory" << endl; exit (-1);
  }

  for (i=0; i<n; i++){
    fscanf(fp, "%d", &A[i]);
  }
  cout << "Input is: ";
  for (i=0; i<n-1; i++) cout << A[i] << ",  ";
  cout << A[n-1] << endl;

  result = sum(n, A);
  cout << "sum= " << result << endl;

  
  result = mysort(n, A);
  cout << "After sorting: ";
  for (i=0; i<n-1; i++) cout << A[i] << ",  ";
  cout << A[n-1] << endl;


 return 0;
}
