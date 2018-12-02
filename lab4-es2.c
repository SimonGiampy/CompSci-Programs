#include <stdio.h>

void fun1(FILE *f1, FILE *f2) {
	/* exercise about files
	   f1 points to a binary FILE in read mode
	   f2 points to a text file in write mode
	   f1 contains a sequence of a couple of integer values v1 and v2. v1 is the ascii correspondece for a character, v2 the number of times it is repeated
	   the sequences must be separated from a space

	   example:
	   file 1 content: 97 3 98 5
	   file 2 content: aaa bbbbb
	 */

	//FILE *file1 = fopen("compiler/bin", "r");

	while (!feof(f1)) {     //while it hasn't reached the end of file yet
		int arrays[2];     //contains v1 and v2
		//read two integers (v1 and v2)

		//write the character v1 as many times as v2

		int readStuff = fread(arrays, sizeof(int), 2, f1);     //reads binary file, puts the stuff read in the array v, reads the size of an int, 2 times
		if (readStuff != 2) {
			return;     //error in reading file
		}

		for (int i = 0; i<arrays[1]; i++) {
			fputc(arrays[0], f2);
		}
		fputc(' ', f2);
		fprintf(f2, "%s\n", " ");
	}
}

void fun(char *f1, char *f2) {
	FILE *file1 = fopen(f1, "rb");
	if (file1 == NULL) {
		return;
	}
	FILE *file2 = fopen(f2, "w");
	if (file2 == NULL) {
		fclose(file1);
		return;
	}
}

void fun2(FILE *f1, FILE *f2) {
	/*
	   f1 and f2 are two binary files opened in read/write
	   f1 contains a sequence of integer numbers
	   he programs write in f2 the even numbers of the sequence in f1, but in reverse order
	 */

	int x, r;
	r = fseek(f1, -sizeof(int), SEEK_END);
	if (r != 0) {
		return;
	}

	while (r == 0) { //until fseek has success in moving around the file
		//another option is ftell
		fread(&x, sizeof(int), 1, f1);
		if (x%2 == 0) {
			fwrite(&x, sizeof(int), 1, f2);
		}
		r = fseek(f1, -2 * sizeof(int), SEEK_CUR);
	}
}

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}
