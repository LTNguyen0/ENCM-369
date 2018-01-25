// exG.c
// ENCM 369 Winter 2018 Lab 1 Exercise G

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ABS_F (5.0e-10)
#define POLY_DEGREE 4

double polyval(const double *a, int n, double x);
// Return a[0] + a[1] * x + ... + a[n] * pow(x, n).

int main(void)
{
    double f[ ] = { 1.53, 0.72, -3.07, -1.15, 1.00 };
    double dfdx[POLY_DEGREE];

    double guess;
    int max_updates;
    int update_count;
    int close_enough, quit;
    int scan_count;
    int i;

    double current_x, current_f, current_dfdx;

    printf("This program demonstrates use of Newton's Method to find\n"
           "approximate roots of the polynomial\nf(x) = ");
    printf("%.2f", f[0]);
	i=1;
	for_start:
	if(i > POLY_DEGREE) goto for_end;
		if(f[i] < 0) goto if_end;
		printf(" + %.2f*pow(x,%d)", f[i], i);
		i++;
		goto for_start;
		if_end:
			printf(" - %.2f*pow(x,%d)", -f[i], i);
			i++;
			goto for_start;
		for_end:
			;

    printf("\nPlease enter a guess at a root, and a maximum number of\n"
           "updates to do, separated by a space.\n");
    scan_count = scanf("%lf%d", &guess, &max_updates);
    if (scan_count != 2) {
        printf("Sorry, I couldn't understand the input.\n");
        exit(1);
    }
  
    if (max_updates < 1)  {
        printf("Sorry, I must be allowed do at least one update.\n");
        exit(1);
    }
    printf("Running with initial guess %f.\n", guess);

	i = POLY_DEGREE-1;
	for2_start:
	if(i < 0) goto for2_end;
		dfdx[i] = (i + 1) * f[i + 1];   // Calculus!
		i--;
		goto for2_start;
	for2_end:
		;
		
    current_x = guess;
    update_count = 0;

	start_do:
	if(quit) goto end_do;
		current_f = polyval(f, POLY_DEGREE, current_x);
        printf("%d update(s) done; x is %.15f; f(x) is %.15e\n",
               update_count, current_x, current_f);
	close_enough = fabs(current_f) < MAX_ABS_F;
        quit = close_enough || update_count == max_updates;
		if(quit) goto end_do;
			current_dfdx = polyval(dfdx, POLY_DEGREE - 1, current_x);
            current_x -= current_f / current_dfdx;
            update_count++;
			goto start_do;
	end_do:
		;

	if(!close_enough) goto else_code;
        printf("Stopped with approximate solution of %.10f.\n", 
               current_x);
		goto end_if;
    else_code:
        printf("%d updates performed, |f(x)| still >= %g.\n", 
               update_count, MAX_ABS_F);
		goto end_if;
	end_if:
    return 0;
}

double polyval(const double *a, int n, double x)
{
    double result = a[n];
    int i;
	
	i=n-1;
	start_for3:
	if(i < 0) goto end_for3;
		result = x * result + a[i];
		i--;
		goto start_for3;
    end_for3:
    return result;
}
