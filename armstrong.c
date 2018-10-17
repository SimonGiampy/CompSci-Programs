/*
   somma dei cubi delle sue cifre è il numero stesso
   numero di armstrong 371:
    3^3 = 27
    7^3 = 343
    1^3 = 1
    somma 21+343+1=371
 */

#include <math.h>
#include <stdio.h>

int isArmstrong(unsigned int a);
unsigned int ordine(unsigned int n);
unsigned int cifraInPosizione(unsigned int input, unsigned int n);

int main() {
	unsigned int i;

	int a = 1, b = 1000; //numeri compresi tra a e b

	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
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
	int order = ordine(num);
	for (int i = 1; i <= order; i++) {
		cifra = cifraInPosizione(num, i);
		somma = somma + pow(cifra, 3);
	}

	if (somma == num) {
		return 1;
	} else {
		return 0;
	}
}

unsigned int ordine(unsigned int num) {
	int ordine = 0;
	do  {
		num = num / 10;
		ordine++;
	} while (num != 0);

	return ordine;
}


unsigned int cifraInPosizione(unsigned int input, unsigned int n) {
	for (int i = 0; i<n-1; i++) {
		input = input / 10;
	}
	return input % 10;
}
