/*
   Esercizio 2 (8 punti)
   Scrivere un programma C che apre un file testuale contenente una lista di codici utenti (uno per riga) e trascrive in un
   altro file testuale solo i codici utente che hanno un formato corretto (uno per riga). I nomi di entrambi i file devono
   essere acquisiti da tastiera (al più 50 caratteri). Un codice utente è valido se è una sequenza di 10 caratteri in cui i primi
   6 caratteri sono cifre ed i successivi 4 caratteri sono lettere maiuscole.
   Nota. Supporre che ogni riga del file contenente la lista dei codici utenti contenga al più di 12 caratteri (incluso il
   carattere ‘\n’). Supporre inoltre che le operazioni di apertura, lettura e scrittura dei file vadano a buon fine.
 */

#include <stdio.h>
#include <ctype.h>

int check(char string[12]);

int main() {
	char input[50], output[50];
	scanf("%s", input);
	scanf("%s", output);

	FILE *fileInput = fopen(input, "r");
	FILE *fileOutput = fopen(output, "w");
	char string[12];
	do {
		fscanf(fileInput, "%s", string);
		if (check(string)) {
			fprintf(fileOutput, "%s\n", string);
		}
	} while (!feof(fileInput));
	fclose(fileInput);
	fclose(fileOutput);
	return 0;
}

int check(char string[12]) {
	int check = 1, i = 0;
	for (; i<6 && check; i++) {
		if (!isdigit(string[i])) {
			check = 0;
		}
	}
	for (; i < 10 && check; i++) {
		if (!isupper(string[i])) {
			check = 0;
		}
	}
	return check;
}
