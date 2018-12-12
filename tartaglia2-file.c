/*
   Problema 1
   Scrivere un programma che legge in input un numero intero positivo N e che costruisca la piramide di Fibonacci fino all’iterazione N.
   Salvare la serie su un file di nome fibonacci_N.txt, con N il numero scelto.

   versione del professore, senza usare le formule del coefficiente binomiale, ma solo con le matrici
 */

#include <stdio.h>

void stampa_piramide(unsigned int n, FILE * f)
{
	int piramide[n][n];
	unsigned int i, j;
	// PRIMA RIEMPIO LA PIRAMIDE
	// la prima riga contiene solo 1
	piramide[0][0] = 1;
	// scorro le righe, dalla seconda
	for (i = 1; i < n; i++)
	{
		// la prima e l'ultima colonna stampate sono sempre 1
		// per ogni riga della piramide
		piramide[i][0] = 1;
		piramide[i][i] = 1;
		// scorro per ogni riga le colonne fino alla diagonale
		for (j = 1; j < i; j++)
		{
			// calcolo la posizione basata sulla riga precedente
			piramide[i][j] = piramide[i-1][j-1] + piramide[i-1][j];
		}

	}
	// POI LA STAMPO A FILE
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			fprintf(f, "%d ",piramide[i][j]);
		fprintf(f, "\n");
	}
	return;
}

int main()
{
	unsigned int N;
	char nome_file[30];
	FILE * f;

	printf("Inserire un numero intero positivo:\n");
	scanf("%u", &N);

	sprintf(nome_file, "fibonacci_%u.txt", N);
	f = fopen(nome_file, "w");
	if (f == NULL)
	{
		printf("Impossibile aprire il file %s\n", nome_file);
		return 1;
	}
	stampa_piramide(N, f);
	fclose(f);
	f = NULL;
	return 0;
}
