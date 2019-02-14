/*
   Problema 1
   Scrivere un programma che legge in input un numero intero positivo N e che costruisca la piramide di Fibonacci fino all’iterazione N.
   Salvare la serie su un file di nome fibonacci_N.txt, con N il numero scelto.

   versione senza usare le formule del coefficiente binomiale, ma solo con le matrici
 */

#include <stdio.h>

void stampa_piramide(unsigned int n, FILE * f);

void stampa_piramide(unsigned int n, FILE * f) {
	unsigned int pyramid[n+1][n+1];
	unsigned int row = 0, column;
	while (row <= n) {
		column = 0;
		while (column <= row) {
			if (column == 0 || column == row) {
				pyramid[row][column] = 1;
			} else {
				pyramid[row][column] = pyramid[row-1][column-1] + pyramid[row-1][column];
			}
			column++;
		}
		//if (row != n) {
		//	pyramid[row][column] = 0;
		//}
		row++;
	}
	for (unsigned int i = 0, k; i <= n; i++) {
		k = 0;
		while (k <= i) {
			fprintf(f, "%d ", pyramid[i][k]);
			k++;
		}
		fprintf(f, "\n");
	}

	return;
}

int main() {
	unsigned int N;
	char nome_file[30];
	FILE *f;

	printf("Inserire un numero intero positivo:\n");
	scanf("%u", &N);

	sprintf(nome_file, "fibonacci_%u.txt", N);
	f = fopen(nome_file, "w");
	if (f == NULL) {
		printf("Impossibile aprire il file %s\n", nome_file);
		return 1;
	}
	stampa_piramide(N, f);
	fclose(f);
	return 0;
}
