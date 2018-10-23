/*
   cheidere all'utente di inserire in input i valori di due array
   stampare:
    valore medio più alto tra a e b
 */
#include <stdio.h>

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

	//calcolo valore medio più alto tra a e b, e stampa
	int sommaA = 0, sommaB = 0;
	for (i = 0; i<rows; i++) {
		sommaA += a[i];
		sommaB += b[i];
	}
	double mediaA = sommaA / rows;
	double mediaB = sommaB / rows;
	if (mediaA >= mediaB) {
		printf("media più alta: %lf\n", mediaA);
	} else {
		printf("media più alta: %lf\n", mediaB);
	}


	return 0;
}
