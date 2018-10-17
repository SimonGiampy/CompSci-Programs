/*
   inserire sequenza numeri interi terminata da zero, dopo dice quale è il min e quale è il max
 */

#include <stdio.h>

int min(int a, int b);
int max(int a, int b);

int main() {
	int numero;

	int massimo = 0;
	int minimo = 0;

	int i = 0;

	do {
		printf("n: ");
		scanf("%d", &numero);

		if (numero == 0) {
			break;
		}

		i++;
		if (i == 1) {
			massimo = numero;
			minimo = numero;
		}

		massimo = max(massimo, numero);
		minimo = min(minimo, numero);

	} while (1);
	if (i>=1) {
		printf("max: %d; min: %d\n", massimo, minimo);
	} else {
		printf("non esiste min o max\n");
	}

	return 0;
}

int min(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
