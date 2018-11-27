//modalities

/*
   r read
   w write
   a append
   rb read binary
   wb write binary
   ab append binary

   r+ open a file (if it already exists) in read/write
   w+ creates a file (if the file doesn't exist yet) in read/write

   rb+ same as r+ but for binary
   wb+ sames as w+ but for binary

 */
#include <stdio.h>
//int a = fclose(*p); //returns 0 if everythingis correct, otherwise returns EOF

int main() {
	FILE *file;
	char c;
	file = fopen("bell.txt", "r");
	if (file != NULL) {
		c = fgetc(file);
		while (c != EOF) {
			printf("%c\n", c);
		}
		fclose(file);
	} else {
		printf("can't open the file\n");
	}


	return 0;
}

int copy(char search[], char input[], char output[]) {
	//input = name of file in input
	//output is name of file in output
	char line[1000];
	FILE *fInput = fopen(input, "r"), *fOutput = fopen(output, "w");
	if (fInput == NULL) {
		return -1;
	}
	if (fOutput == NULL) {
		fclose (fInput);
		return -1;
	}

	fInput = fgets(line, 1000, fInput);
	while (fInput != NULL) {
		if (strstr(line, search) != NULL) {
			//strstr searches a substring in the original string
			//returns the position of the string found
			fputs(line, fOutput);
		}
	}

	fclose(fInput);
	fclose(fOutput);
	return 0;

}
