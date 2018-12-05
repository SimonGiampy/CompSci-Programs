#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//writes string to a file
//reads string from a file
//reads specific pattern from a file with a fscanf
//write strings in specific patterns in a file
//uploads the data read to a dynamic double linked list
//saves some data written in a struct about movies into a file

#define DIR "textfile.tmp.txt"
#define DIR_BIN "textfile.tmp.bin"

void readEveryCharacter(void);
void readString(void);
void readAll(void);
void readFScanf(void);
void writeString(const char input[]);
void writeStuff(const char stuff[]);

void readBinary();
void writeBinary(const char stuff[]);

int main(int argc, char const *argv[]) {
	//calls read functions...
	/*
	   readEveryCharacter();
	   readString();
	   readAll();
	   readFScanf();

	   writeString("stringa di testo da scrivere riga 1\n");
	   writeStuff("testo stringa riga numero 2\n");
	 */

	writeBinary("buongiorno al latte buongiorno a te\nuisagiu<ghu\ngfhgfhfh\nnhdhfhf\nfhhfdjdjd");
	readBinary();

	//TODO repeat everything for binary files
	//TODO feof function sample
	return 0;
}

//first method, function fgetc (related to the characters)
void readEveryCharacter() {
	FILE *file = fopen(DIR, "r");
	if (file == NULL) {
		printf("error\n");
		return;
	}

	char c;
	do {
		c = fgetc(file); //reads a character in the file, then moves the index forward of 1 character
		printf("%c", c); //prints the character read
	} while(c != EOF); //repeats until it finds the end of the file
	printf("finished first\n\n");

	fclose(file);
}

//second method, function fgets (related to the strings) (buggy method)
void readString() {
	FILE *file = fopen(DIR, "r");
	if (file == NULL) {
		printf("error\n");
		return; //stops the execution
	}

	//this function is bugged. reads only the first line of the two written in the file. \n bugs the system
	char string[1000];
	//reads the first 100 characters from the current index, and stores them in a string
	if (fgets(string, 1000, file) != NULL) { //string is the array where the data read stored, 1000 is the max size of the array, and file is the file
		printf("%s", string);  //shows the string read from the file to the user
	}
	//TODO fix this and ask professor
	printf("\nfinished second\n\n"); //logging
	fclose(file);
}

//third method, with function fread
void readAll() {
	FILE *file = fopen(DIR, "r");
	if (file == NULL) {
		printf("error\n");
		return;
	}

	char buffer[100]; //data read goes here
	fread(buffer, 100, sizeof(char), file); //reads 100 elements of size 1 byte (one char), then stores the data in the string buffer, from the file file
	printf("%s\n", buffer); //prints the buffer to the stdout
	printf("completato metodo 3\n\n");
	fclose(file);
}

//fourth method, fscanf function. works as fread but with a specific pattern
void readFScanf() {
	FILE *file = fopen(DIR, "r");
	if (file == NULL) {
		printf("error\n");
		return; //stops the execution
	}

	char string[100];
	int n;
	int read = fscanf(file, "%s%d", string, &n);
	if (read == 2) {
		//here the problem is that it stops reading when encouters a space between words.
		//consequently it skips what comes next, and it doesn't read the number
		printf("%s and number %d\n", string, n);
	} else {
		printf("method 4 nothing works here\n");
	}
	fclose(file);
}

//method 1 function fputs (strings)
void writeString(const char string[]) {
	FILE *file = fopen(DIR, "w"); //access file with write permissions
	if (file == NULL) {
		printf("error\n");
		return;
	}

	//fputs(string, file) writes a string in the specified file
	fputs(string, file); //puts the string passed as parameter in the function in the file
	fclose(file);
}

//method 2 function fwrite and fseek
void writeStuff(char const stuff[]) {
	FILE *file = fopen(DIR, "r+"); //Open existing file with both reading and writing permissions
	if (file == NULL) {
		printf("error\n");
		return;
	}

	fseek(file, 0, SEEK_END); //sets the position at the end of the file, so it uses the append function
	//write data to the file. parameters: strings to be written, size of a character in bytes, length of the string (total dimension of the array), the file
	fwrite(stuff, 1, strlen(stuff), file);
	fclose(file);
}

//binary functions start here
void readBinary() {
	FILE *file = fopen(DIR_BIN, "rb"); //Open existing file with reading permissions for binary files
	if (file == NULL) {
		printf("error\n");
		return;
	}

	char string[100];
	fread(string, sizeof(string), 1, file);
	printf("string read binary %s\n", string);
	fclose(file);
}
//write in binary file
void writeBinary(const char stuff[]) {
	FILE *file = fopen(DIR_BIN, "wb"); //Open existing file with writing permissions for binary files
	if (file == NULL) {
		printf("error\n");
		return;
	}

	fwrite(stuff, strlen(stuff), 1, file); //string to write, length (size in bytes of the string array, size of a char, binary file)
	fclose(file);
}













//sample exercises to do at home

//this exercise: a linked list is created with a series numbers. everything is randomly generated.
//the program creates dinamically two files for each number in the list. one of them is binary, the other one with simple text
//each file contains a number repeated as many times as the number is. example: file named 56.txt contains the number 56 repeated 56 times
//each number in each file is separated by a \n, so every number has one other below and over it
//then after everything is done, a function reads the content of each file created, and writes to a new single file all the stuff created.
//then, writes again each file in a specific point, which is in the middle of the file, and adds the string "\n cyka blyat \n"

//another program
//creates a file with the string cyka blyat
//then writes N lines (where N is the length of cyka blyat) where in each line a random chosen letter is capitalized and added at the end of the line.
//at the end of every line it writes a number which corresponds to the position of that letter
//example: cyka blyat \n cyka blyat L 7
//make the program working with all possible differenet strings put in input by the user
