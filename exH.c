// exH.c
// ENCM 369 Winter 2018 Lab 1 Exercise H

#include <stdio.h>

void print_array(const char *str, const int *a, int n);
// Prints the string given by str on stdout, then
// prints a[0], a[1], ..., a[n - 1] on stdout on a single line.

void sort_array(int *a, int n);
// Sorts a[0], a[1], ..., a[n - 1] from smallest to largest.

int main(void)
{
  int test_array[] = {440, 220, 330, 550, 330, 660, 110, 330, 440};

  print_array("before sorting ...", test_array, 9);
  sort_array(test_array, 9);
  print_array("after sorting ...", test_array, 9);
  return 0;
}

void print_array(const char *str, const int *a, int n)
{
  int i = 0;
  puts(str);
  start_for:
	if(i>=n) goto end_for;
		printf("    %d", a[i]);
		i++;
		goto start_for;
  end_for:
	printf("\n");
}

void sort_array(int *a, int n)
{
  // This is an implementation of an algorithm called insertion sort.

  int i, j, element_i;
  i = 1;
  start_for2:
	if(i >= n) goto end_for2;
		element_i = a[i];
		j = i;
		start_while:
			if(j <= 0) goto end_while;
			if(a[j-1] <= element_i) goto end_while;
				a[j] = a[j - 1];
				j--;
				goto start_while;
		end_while:
			a[j] = element_i;
			i++;
			goto start_for2;
  end_for2:
		;
}
