/*
   chidere all'utente di inserire in input i valori di due array
   stampare:
    valore medio più alto tra a e b
    concatenamento (append) dell'array b ad a
    trovare min e max e dire in quale posizione dell'array si trovano
    calcolare il prodotto scalare dei termini dei due vettori somma di (a[i] * b[i]) per tutti gli i < dimesione array
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int rows = 5;
	int a[rows], b[rows];

	int i;

	//initialize arrays randomly, so the user doesn't bother writing in input all the numbers
	srand(time(NULL)); //use random seed retrieved from time
	for (i=0; i<rows; i++) {
		a[i] = rand() % 9 + 1;     //from 1 to 9 included
		b[i] = rand() % 9 + 1;     //from 1 to 9 included
	}
	//prints the generated numbers so the user can see what he didn't input
	printf("elements of a: ");
	for (i=0; i<rows; i++) {
		printf("%d\t", a[i]);
	}
	printf("\nelements of b: ");
	for (i=0; i<rows; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");

	//calcolo valore medio più alto tra a e b, e stampa
	int sommaA = 0, sommaB = 0;
	for (i = 0; i<rows; i++) {
		sommaA += a[i];
		sommaB += b[i];
	}
	double mediaA = sommaA / rows;
	double mediaB = sommaB / rows;
	if (mediaA >= mediaB) {
		printf("highest average of values among the 2 arrays: %lf\n", mediaA);
	} else {
		printf("highest average of values among the 2 arrays: %lf\n", mediaB);
	}

	//concatenamento dei valori di b a quelli di a
	printf("concatenation of values of a and b: ");
	int ab[rows*2];
	for (i=0; i<rows*2; i++) {
		if (i<rows) {
			ab[i] = a[i];
		} else {
			ab[i] = b[i];
		}
		printf("%d\t", ab[i-rows]);
	}
	printf("\n");

	//trovare min e max e dire in quale posizione dell'array si trovano
	int max = ab[0], min = ab[0], maxPosition = 0, minPosition = 0;
	for (i = 1; i<rows*2; i++) {
		if (ab[i] > max) {
			max = ab[i];
			maxPosition = i;
		}
		if (ab[i] < min) {
			min = ab[i];
			minPosition = i;
		}
	}
	char relevantArray;
	if (minPosition >= rows) {
		relevantArray = 'b';
	} else {
		relevantArray = 'a';
	}
	printf("max number found: %d in position (in %c[5]): %d\n", max, relevantArray, maxPosition);
	printf("min number found: %d in position (in %c[5]): %d\n", min, relevantArray, minPosition);

	//prodotto scalare di a e b (sommatoria da i=0 a dimensione di a[i]*b[i])
	int product = 0;
	for (i = 0; i<rows; i++) {
		product += a[i] * b[i];
	}
	printf("prodotto scalare: %d\n", product);

	return 0;
}
