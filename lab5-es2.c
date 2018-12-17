/*
   the function printDistinct opens the specified file in input and prints the first n distinct characters, separated by a space

   Esercizio 3 (files, arrays)
   Implementare una funzione, stampa_distinti, che riceve come parametri in ingresso una stringa nomefile, contenente il nome di un file testuale, ed un numero intero n. La funzione ha il compito di aprire il file specificato attraverso il parametro nomefile e stampare a video i primi n caratteri distinti (cioè diversi fra loro) separati da uno spazio.

   Note. Il file può contenere qualsiasi carattere ASCII.

 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = !false} bool; //standard way to define booleans in old C standard

void printDistinct(const char fileName[], int n); //the function requested from the exercise

int main(int argc, char const *argv[]) {
	printDistinct("textfile.tmp.txt", 20); //prints the first 20 distinct letters read from the file
	return 0;
}

void printDistinct(const char fileName[], int n) {
	FILE *file = fopen(fileName, "r");
	if (file == NULL) exit(1);

	char trimmed[100] = ""; //string where the chosen letters will be stored

	while (!feof(file)) { //while file is not yet finished
		char c;
		bool check = false;
		c = fgetc(file); //reads one char at a time
		int i;
		for (i = 0; check == false && i < strlen(trimmed); i++) { //searches if there is already a character in the trimmed string
			if (c == trimmed[i]) { //this char is already present in the trimmed string
				check = true;
			}
		}
		if (check == false) { //saves the new character in the trimmed string only if it is a new character
			//puts a new character in the string trimmed, so the length is increased by 1
			trimmed[strlen(trimmed)] = c; //new character
			trimmed[strlen(trimmed)+1] = '\0'; //null terminator for the string is moved to the last possible position
		}
	}
	printf("trimmed string is: \n%s\n", trimmed);

	fclose(file);
}
