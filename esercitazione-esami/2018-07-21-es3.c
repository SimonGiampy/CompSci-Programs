/*
   Si supponga di voler analizzare un file di testo nel quale ogni riga è un messaggio twitter rappresentato con la seguente
   struttura:
   Questo è un esempio #fi #secondoappello #esercizio3
   Dove Questo è un esempio #fi #secondoappello #esercizio3 è il testo del messaggio, fi,
   secondoappello e esercizio3 sono i 3 hashtag contenuti nel messaggio. Gli hasthag nel messaggio non possono
   essere più di 100, non possono avere più di 279 caratteri e non possono contenere spazi. Il testo del messaggio
   complessivamente non può contenere più di 280 caratteri (hashtag inclusi).
   Si implementi la seguente funzione C:
   int conta(char filename[], char hashtag[]),
   che riceve in ingresso il nome (filename) di un file di testo contenente messaggi twitter, rappresentati nel formato
   descritto in precedenza, e una stringa contenente uno specifico hashtag; la funzione ha il compito di leggere tutti i
   messaggi twitter contenuti nel file filename e restituire il numero di messaggi che contengono l’hashtag passato come
   parametro di ingresso.
   Nota. È possibile assumere che lo stesso hashtag non possa essere ripetuto più di una volta all’interno dello stesso
   messaggio twitter.
 */
#include <string.h>
#include <stdio.h>
int read(char filename[100], char hashtag[280]);
int read2(char filename[100], char hashtag[280]);

int main() {
	printf("found: %d\n", read2("twitter.txt", "maiala"));
	return 0;
}

//version 2 without strstr
int read2(char filename[100], char hashtag[280]) {
	FILE *file = fopen(filename, "r");
	int amount = 0;
	char line[281];
	while (fgets(line, 281, file) != NULL) {
		//fgets(line, 281, file);
		printf("line reading: %s\n", line);
		int i = 0;
		while (i<strlen(line)) {
			if (line[i] == '#') {
				printf("found the #\n");
				++i;
				int check = 1, k;
				for (k = 0; k < strlen(hashtag) && check == 1; k++, i++) {
					if (line[i] != hashtag[k]) {
						check = 0;
					}
				}
				if (check == 1 && (line[i] == ' ' || line[i] == '\n')) {
					amount++;
				}
			} else {
				i++;
			}
		}
	}
	return amount;
}

//version 1 with strstr
int read(char filename[100], char hashtag[280]) {
	char hash[280];
	sprintf(hash, "#%s", hashtag);
	FILE *file = fopen(filename, "r");
	int amount = 0;
	char line[281];
	while (!feof(file)) {
		fscanf(file, "%s", line);
		char *index = strstr(line, hash);
		if (index != NULL) {
			amount++;
		}
	}
	fclose(file);
	return amount;
}
