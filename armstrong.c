// Scrivere un programma che, dati in input due interi a e b non negativi,
// stampi a video tutti i numeri di Armstrong compresi tra a e b.
//
// NOTA: un numero di 3 cifre e' di Armstrong se la somma dei cubi delle sue
// cifre e' uguale al numero stesso.
// Esempio: 371 e' di Armstrong perche'
//      3^3 = 27
//      7^3 = 343
//      1^3 = 1
//      e 27 + 343 + 1 = 371
#include <math.h>
#include <stdio.h>

int isArmstrong(unsigned int a);
unsigned int ordine(unsigned int n);
unsigned int cifraInPosizione(unsigned int input, unsigned int n);

int main() {
	unsigned int i;
	int a, b;

	printf("numero di partenza: \n");
	scanf("%d", &a);
	printf("numero di arrivo: \n");
	scanf("%d", &b);
	printf("\n");

	for (i = a; i < b; i++) {
		if (isArmstrong(i)) {
			printf("numero arm trovato: %d\n", i);
		}
	}

	return 0;
}

int isArmstrong(unsigned int num) {
	int somma = 0;
	int cifra;
	int grandezza = ordine(num);
	for (int i = 1; i <= grandezza; i++) {
		cifra = cifraInPosizione(num, i);
		somma = somma + pow(cifra, grandezza);
	}

	if (somma == num) {
		return 1;
	} else {
		return 0;
	}
}

unsigned int ordine(unsigned int num) {
	int ordine = 0;
	while (num != 0) {
		num = num / 10;
		ordine++;
	}
	return ordine;
}


unsigned int cifraInPosizione(unsigned int input, unsigned int n) {
	for (int i = 0; i<n-1; i++) {
		input = input / 10;
	}
	return input % 10;
}
