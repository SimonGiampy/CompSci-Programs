/*
   Esercizio 1
   Scrivere un programma che chiede all'utente di inserire delle stringhe (senza spazi e di lunghezza al max 100). Il programma termina non appena l'utente inserisce la stringa "stop", stampando il numero di stringhe inserite dall'utente di lunghezza l (dove l è a sua volta inserito dall'utente all'inizio del programma).
 */

#include <string.h>
#include <stdio.h>

#define MAX 100

int main() {
	int l, cont = 0;
	char string[MAX+1];
	printf("inserire l: ");
	scanf("%d", &l);

	do {
		printf("inserisci stringa: ");
		scanf("%s", string);

		if (strlen(string) == l) {
			cont++;
		}

	} while (strcmp(string, "stop") != 0);

	if (l==4) cont--;
	printf("numero stringhe lunghe %d e' %d\n", l, cont);

	return 0;
}
