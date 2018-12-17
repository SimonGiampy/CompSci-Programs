/*
   La società E Corp. è in possesso di una grande quantità di messaggi twitter su cui vuole condurre indagini di mercato. Per
   ogni messaggio twitter, devono essere memorizzate le seguenti informazioni: testo del messaggio (non più di 280
   caratteri), lista degli hashtag contenuti nel messaggio (ogni hashtag è una sequenza di caratteri senza spazi e di lunghezza
   non superiore a 279 caratteri, che l’autore del messaggio indica come parola chiave), numero di hastag contenuti nel
   messaggio (che sono sicuramente inferiori a 100), account twitter dell’autore del messaggio (non più di 50 caratteri e
   senza spazi).
   A. Creare il tipo di dato C, tweet, in grado di contenere tutte le informazioni rilevanti di un messaggio twitter sopra
   elencate.
   B. Implementare la funzione, float analizza(tweet collezione[], int n, char hashtag[])
   che riceve in ingresso una collezione di n messaggi twitter ed un hashtag. La funzione restituisce la frazione di
   messaggi twitter contenuti nel parametro in ingresso collezione che (i) contengono l’hashtag passato come
   parametro in ingresso e (ii) hanno una lunghezza non superiore a 140 caratteri.
 */
#include <stdio.h>
#include <string.h>

struct tweet {
	char text[281]; //280 characters + 1 (end char)
	char account[51]; // characters for the account name
	char tags[280][100]; //string of maximum 100 tags, each one of maximum 280 characters
	int ntag; //number of tags
};
typedef struct tweet tweet;

float analyze(tweet collection[], int n, char tag[]);
//n is the number of tweets in the collection
float analyze(tweet collection[], int n, char tag[]) {
	int found;
	float ris = 0;
	for (int i = 0; i<n; i++) {
		if (strlen(collection[i].text) <= 140) {
			for (int j = 0; j<collection[i].ntag && found == 0; j++) {
				if (strcmp(collection[i].tags[j], tag) == 0) { //they are equal
					found = 1;
				}
			}
			ris = ris + found;
		}
	}
	return ris/n;
}
