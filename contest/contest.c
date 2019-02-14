#include <stdio.h>
#include <ctype.h>
#include <string.h>
typedef enum { false = 0, true = !false} bool;

int checkRiga(char riga[]);
bool contiene(char input[], char output[], int length);


int main () {
	int i = 0;
	char string[] = "e**spider";
	while(string[i] ) {
		string[i] = tolower(string[i]);
		i++;
	}
	checkRiga(string);


	return(0);
}

int checkRiga(char riga[], char controllo[]) {
	int length = strlen(controllo);
	printf("risultato %d\n", riga, controllo, contiene(riga, controllo, length));
	return contiene(riga, controllo, length);
}

bool contiene(char input[], char output[], int length) {
	bool check = false;
	int start = 0;
	for (start = 0; check == false && start <= strlen(input) - length; start++) {
		char trim[length];
		for (int i = 0; i< length; i++) {
			trim[i] = input[start + i];
		}
		if (strcmp(trim, output) == 0) {
			check = true;
		}
	}
	return check;
}
