/*
   3 formule matematiche:
   P(a) = a^2 -a^3 +sin(a)
   R(b) = sqrt(b^2 +12)
   S(x, y) = 13x + (x+y)/3

   2 valori n, m e calcola S(P(n), R(n-m)) e lo stampa
 */

#include <math.h>
#include <stdio.h>

double p(double a);
double r(double b);
double s(double x, double y);

int main() {

	double n, m;

	printf("n: ");
	scanf("%lf", &n);
	printf("m: ");
	scanf("%lf", &m);
	printf("\n");

	printf("calcolo: %lf\n", s(p(n), r(n-m)));

	return 0;
}

double p(double n) {
	return pow(n, 2) - pow(n, 3) + sin(n);
}

double r(double n) {
	return sqrt(pow(n, 2) + 12);
}

double s(double a, double b) {
	return 13*a + (a+b)/3;
}
