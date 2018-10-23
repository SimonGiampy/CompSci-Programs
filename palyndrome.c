/*
   legge in input una stringa e scrive se è palindroma o no
 */
#include <stdio.h>
#include <string.h>

int main() {
	char string[100];
	scanf("%s", string); //in realtà questa scanf prende l'input fino alla pressione di uno spazio
	//accetta infatti una sola parola. per accettare una frase intera, bisogna scrivere scanf("s[^\n]", string);

	int stringLength = strlen(string);

	int palyndrome = 0;
	for (int i = 0; i<100; i++) {
		if (string[i] == string[stringLength - 1 - i]) {
			palyndrome = 1;
		}
	}
	if (palyndrome) {
		printf("it's not palyndrome\n");
	} else {
		printf("it's palyndrome\n");
	}

	return 0;
}
