/*
   Esercizio 2
   Scrivere un programma che legga un testo (max 1000 caratteri) costituito da una sequenza di parole separate da ',' senza spazi.Il programma deve poi contare il numero di parole e il numero medio di caratteri per parola.
   Esempio:  "ciao,casa,sta,tutto,vero"--> 5 parole, media caratteri 4
 */
#include <stdio.h>
#include <string.h>

int main() {
	char string[1000+1];
	printf("write a string of maximum 1000 characters\n");
	scanf("%s", string);
	int length = strlen(string);

	int words = 0;

	for (int i = 0; i<length; i++) {
		if (string[i] == ',') {
			words++;
		}
	}

	printf("number of words: %d\n", words +1);
	printf("average number of letters per word is: %f\n", (length-words) / (words+1.0));


	return 0;
}
