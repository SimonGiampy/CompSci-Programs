/*
   the function printDistinct opens the specified file in input and prints the first n distinct characters, separated by a space


   Esercizio 3 (files, arrays)
   Implementare una funzione, stampa_distinti, che riceve come parametri in ingresso una stringa nomefile, contenente il nome di un file testuale, ed un numero intero n. La funzione ha il compito di aprire il file specificato attraverso il parametro nomefile e stampare a video i primi n caratteri distinti (cioè diversi fra loro) separati da uno spazio.

   Note. Il file può contenere qualsiasi carattere ASCII.

   Esempio
   Si supponga che il file nomefile abbia questo contenuto: "Ad esempio, abbiamo questo contenuto"
   La chiamata stampa_distinti(nomefile, 12) stamperà a video i seguenti caratteri :
   "ad esmpio"
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printDistinct(char fileName[], int n) {
	FILE *file = fopen(fileName, "r");
	if (file == NULL) exit(1);

	int distinct = 0, found[256], i;
	char *newString;

	for (int i = 0; i< 256; i++) {
		found[i] = 0;
	}

	//TODO check this


	while (distinct < n) {
		char c;
		fscanf(file, "%c", &c);
		printf("log char c: %c\n", c);
		distinct++;


	}




	fclose(file);
}
