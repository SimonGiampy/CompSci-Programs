/*
   write a function that reduces the size of a string by removing all of its vowels
   the program reads two strings, and verify if these are equals except for the consonants
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeVowels(char *string);
void removeVowelsRecursive(char *string);
char* removeVowelsRecursive2(char *s);
void prints(char *s);

int main(int argc, char const *argv[]) {
	char s1[] = "nculu a chitemmuartu";
	char s2[] = "dio rabozzi";
	char *s3;
	scanf("%[^\n]%*c", s3);
	prints(s1);
	removeVowels(s1);
	prints(s1);
	prints(s2);
	removeVowelsRecursive(s2);
	prints(s2);
	prints(s3);
	s3 = removeVowelsRecursive2(s3);
	prints(s3);

	return 0;
}

void removeVowels(char *string) {
	int i, j = 0; //j is the index for the consonants, because the vowels are not saved in a new string
	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u') { //if it is not a vowel
			string[j] = string[i];
			j++; //increment j to write in the next spot
		}
	}
	string[j] = '\0'; //terminates the string
}

void removeVowelsRecursive(char *string) {
	if (strlen(string) != 0) {
		removeVowelsRecursive(string + 1);
		if (string[0] == 'a' || string[0] == 'e' || string[0] == 'i' || string[0] == 'o' || string[0] == 'u') {
			for (unsigned int i = 1; i < strlen(string) + 1; i++) {
				string[i-1] = string[i];
			}
		}
	}
}

char* removeVowelsRecursive2(char *string) {
	if (strlen(string) == 0) {
		return "";
	}
	int i = 0;
	if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u')  {
		return removeVowelsRecursive2(string+1);
	} else {
		char *newString = (char*) malloc(sizeof(char) * (strlen(string) + 1));
		char *suffix = removeVowelsRecursive2(string+1);
		newString[0] = string[0];
		newString[1] = '\0';
		strcat(newString, suffix);
		if (strlen(suffix) > 0) {
			free(suffix);
		}
		return newString;
	}
}

void prints(char *s) {
	printf("%s\n", s);
}
