/*Problema 5
   Scrivere un programma che calcola l’approssimazione di pigreco, utilizzando il metodo descritto di seguito (noto come metodo Monte-Carlo).
   Sia M un punto di coordinate (x,y) con 0<x<1 e 0<y<1.
   Scegliamo casualmente i valori di x e y.
   Sia x^2 + y^2 < 1 allora il punto M appartiene al disco di centro (0,0) di raggio 1.
   La formula per determinare l'area di un disco è il r^2 * π (dove r è il raggio). Nell'esempio il raggio è uno quindi l'area è π. Il punto può cadere quindi o nel cerchio o nel quadrato circoscritto al cerchio. L'area del quadrato circoscritto al cerchio è uguale al lato^2 e cioè (1+1)^2 = 4. La probabilità che il punto cada all'interno della circonferenza è quindi pari al rapporto tra l'area del cerchio di raggio unitario (π) e l'area del quadrato circoscritto (4) e cioè π/4.
   Facendo il rapporto del numero dei punti che cadono nel disco con il numero dei totale dei punti generati in modo casuale si ottiene un'approssimazione del numero π/4 se il numero dei tiri è grande.
   Implementare un programma che chieda all’utente quanti punti utilizzare per calcolare l’approssimazione di π e quindi stampi a video il risultato ottenuto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define randmax (double) RAND_MAX

double generateMx(void);
double generateMy(void);

int main() {
	double mX, mY; //coordinatees 0<x<1 & 0<y<1
	//assign random values to mX and mY
	srand(time(NULL));

	unsigned long int points = 10000000000, i; //the more the points are, the more precise the calculation is. here I used 10B
	unsigned long int inside = 0;
	unsigned long int outside = 0;
	double radius;

	//calculation of the position of the points
	for (i = 0; i < points; i++) {
		mX = generateMx();
		mY = generateMy();
		radius = sqrt(mX * mX + mY * mY);
		if (radius < 1.0) { //inside the circle
			inside++;
		} else { //outside the circle
			outside++;
		}
	}

	printf("outside: %lu\n", outside);
	printf("inside: %lu\n", inside);

	double pi = (double) inside / ((double) points) * 4.0;
	printf("pi greco (interni / punti tot) *4 = %.15lf\n", pi);

	return 0;
}

double generateMx() {
	return (double) rand() / randmax;
}

double generateMy() {
	return (double) rand() / randmax;
}
