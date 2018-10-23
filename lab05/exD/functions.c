// functions.c
// ENCM 369 Winter 2018 Lab 5 Exercises D and E


#include "functions.h"

int pointer_version(const int *a, int n)
{
  int sum = 0;
  const int *p;
  const int *past_last;
  past_last = a + n;
  p = a;
  while (p != past_last) {
    sum += *p;
    p++;
  }
  return sum;
}


int index_version(const int *a, int n)
{
  int i, sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}
