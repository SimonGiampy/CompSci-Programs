//this is the final version of the contest program, coded after the contest

//TODO: fix program so it can work also for the files t7 and t5 (they should return false, not true)

//warning: i don't know what's wrong with the file t5, seems correct to me. the only file to correct if t7

//TODO: adde the check in the program that reads every word of 3 or more characters in the completedScheme,
// and checks if all the words are present in the lists of words, both horizontals and verticals
//in file t7 the word rai is present in the completedScheme but not in the horizontals array
// "non compaiono vocaboli non elencati"   scritto sul foglio della descrizione del programma per il contest

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {false = 0, true = !false} bool;

void readScheme(FILE *file, char completedScheme[13][10]);
int readVertical(FILE *file, char verticals[20][14]);
int readHorizontals(FILE *file, char horizontals[20][10]);

bool checkColumns(char completedScheme[13][10], char verticals[][14], int size);
bool checkRows(char completedScheme[13][10], char horizontals[][10], int size);
bool checkScheme(char horizontals[][10], char verticals[][14], int sizeHorizontal, int sizeVerticals);

bool isPresentInCol(char completedScheme[13][10], int column, char word[14]);
bool isPresentInRow(char completedScheme[13][10], int row, char word[10]);

//current limits:
//length of fileName is 25
//number of rows in the scheme: 13
//number of columns in the scheme: 9
//length of each row : 9+1=10
//how many words in each list (horizontals and verticals): 20 each


int main() {
	printf("what file do you want to analize?\n");
	char fileName[25];
	scanf("%s", fileName);
	FILE *file = fopen(fileName, "r"); //the name of the file should be the input from the user
	if (file == NULL) {
		printf("error in reading.\n");
		exit(0); //this function is present in the library stdlib.h
	}

	//saving data
	char completedScheme[13][10];
	readScheme(file, completedScheme);

	char horizontals[20][10], verticals[20][14];
	int numberHorizontal = readHorizontals(file, horizontals);
	int numberVertical = readVertical(file, verticals);

	//printing out the results
	for (int i = 0; i < 13; i++) {
		for (int k=0; k<9; k++) {
			printf("%c ", completedScheme[i][k]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < numberHorizontal; i++) {
		printf("%s\n", horizontals[i]);
	}
	printf("----\n");
	for (int i = 0; i < numberVertical; i++) {
		printf("%s\n", verticals[i]);
	}
	printf("----\n\n");

	//actual checks
	bool rows = checkRows(completedScheme, horizontals, numberHorizontal);
	printf("bool check rows %d\n", rows);
	bool columns = checkColumns(completedScheme, verticals, numberVertical);
	printf("bool check columns %d\n", columns);
	bool scheme = checkScheme(horizontals, verticals, numberHorizontal, numberVertical);
	printf("bool check scheme duplicates %d\n", scheme);

	if (rows && columns && scheme) {
		printf("funziona\n");
	} else {
		printf("non funge una minchia\n");
	}
	return 0;
}

//memorize the entire scheme in a matrix
void readScheme(FILE *file, char completedScheme[13][10]) {
	char string[13*9+1];
	fscanf(file, "%s", string);
	//printf("read this string: %s\n", string);
	for (int i = 0, j=0; i < 13; i++) {
		for (int k=0; k<9; k++) {
			completedScheme[i][k] = tolower(string[j]);
			j++;
		}
	}
}
//memorizes the words of the horizontal group in an array of strings
int readHorizontals(FILE *file, char horizontals[20][10]) {
	char word[10];
	int i = 0;
	fscanf(file, "%s", word);
	while (strcmp(word, "---")) {
		//lowercase letters in the string word
		for (int c = 0; c < strlen(word); c++) word[c] = tolower(word[c]);
		strcpy(horizontals[i], word);
		i++;
		fscanf(file, "%s", word);
	}
	return i;
}
//memorizes the words of the vertical group in an array of strings
int readVertical(FILE *file, char verticals[20][14]) {
	char word[14];
	int i=0;
	fscanf(file, "%s", word);
	while (!feof(file)) {
		//lowercase letters in the string word
		for (int c = 0; c < strlen(word); c++) word[c] = tolower(word[c]);
		strcpy(verticals[i], word); //memorize each line in the array verticals
		i++;
		fscanf(file, "%s", word);
	}
	return i;
}

//check if all the words listed are present in the rows
bool checkRows(char completedScheme[13][10], char horizontals[][10], int size) {
	bool check = true, found = false;
	for (int i = 0; i<size && check; i++) {
		for (int k = 0; k < 13 && !found; k++) {
			if (isPresentInRow(completedScheme, k, horizontals[i])) {
				found = true;
			}
		}
		if (found) { //continues in the cycle, resetting the value of the bool found
			found = false;
		} else {
			check = false;
		}
	}
	return check; //true if all the words in horizontals are present in the completedScheme
}

//check if all the words listed are present in the columns
bool checkColumns(char completedScheme[13][10], char verticals[][14], int size) {
	bool check = true, found = false;
	for (int i = 0; i<size && check; i++) {
		for (int k = 0; k < 9 && !found; k++) {
			if (isPresentInCol(completedScheme, k, verticals[i])) {
				found = true;
			}
		}
		if (found) { //continues in the cycle, resetting the value of the bool found
			found = false;
		} else {
			check = false;
		}
	}
	return check; //true if all the words in verticals are present in the completedScheme
}

//check for duplicates in the list of words provided
bool checkScheme(char horizontals[][10], char verticals[][14], int sizeHorizontal, int sizeVerticals) {
	bool checkRows = true, checkColumns = true;
	for (int i = 0; i<sizeHorizontal && checkRows; i++) {
		for (int k=i; k<sizeHorizontal && checkRows; k++) {
			if (k != i && !strcmp(horizontals[i], horizontals[k])) {
				checkRows = false;
			}
		}
	}
	for (int i = 0; i<sizeVerticals && checkColumns; i++) {
		for (int k=i; k<sizeVerticals && checkColumns; k++) {
			if (k != i && !strcmp(verticals[i], verticals[k])) {
				checkColumns = false;
			}
		}
	}

	return (checkRows && checkColumns);
}

bool isPresentInRow(char completedScheme[13][10], int row, char word[10]) {
	int length = strlen(word);
	//printf("looking for word %s\n", word);
	bool check = false;
	char line[10];
	memcpy(line, completedScheme[row], 10); //copies first 10 characters from the specific row of completedScheme in the string line

	if (strstr(line, word) != NULL) { //if the string word is contained in the string line, this is returns true
		check = true;
		//printf("found correspondence of word %s in line %s\n", word, line);
	}
	return check;
}

bool isPresentInCol(char completedScheme[13][10], int column, char word[14]) {
	char line[14];
	int length = strlen(word);
	for (int i=0; i<14; i++) { //creating the line to analize
		line[i] = completedScheme[i][column];
	}
	bool check = false;
	if (strstr(line, word) != NULL) { //if the string word is contained in the string line, this is returns true
		check = true;
		//printf("found correspondence of word %s in line %s\n", word, line);
	}
	return check;
}
