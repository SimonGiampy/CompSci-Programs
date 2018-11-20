/*
   write a recursive function that:
   given a string s and a char c (the parameteres of the function)
   calculate the occurences of c in s, so it returns how many times does c appear in the string s
 */
#include <stdio.h>
#include <string.h>

int countChars(char* string, char query);

int main() {
	char string[] = "tre tigri contro tre tigri";
	char string2[] = "sopra la panca la capra campa, sotto la panca la capra crepa";
	printf("trovato il carattere t nella stringa 1 %d volte\n", countChars(string, 't'));
	printf("trovato il carattere c nella stringa 2 %d volte\n", countChars(string2, 'c'));
	return 0;
}

int countChars(char* string, char query) {
	int found = 0;

	if (strlen(string) >= 1)  {
		if (string[0] == query) {
			found++;
		}
		found += countChars(string+1, query);
	}

	return found;
}
