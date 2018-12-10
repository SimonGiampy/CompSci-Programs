/*
   Problema 1
   Scrivere un programma che legge in input un numero intero positivo N e che costruisca la piramide di Fibonacci fino all’iterazione N.
   Salvare la serie su un file di nome fibonacci_N.txt, con N il numero scelto.

   Nota: un esempio di output per N=2 è:
   1
   11
   121
 */
//piramide di tartaglia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int f);
int getBinomial(int i, int k);

int main(int argc, char const *argv[]) {
	int input = 6;
	char* dir;
	sprintf(dir, "tartaglia_%d.txt", input); //takes the fromatted string, and saves it in the string dir
	//dir will be "tartaglia_6.txt"
	FILE *file = fopen(dir, "w"); //writes to file

	//iterate for every number to be printed
	for (int i = 0; i < input + 1; i++) {
		for (int k = 0; k < input +1; k++)  {
			if (i >= k) { //if i is less than k, the binomial coefficient can't be calculated
				fprintf(file, "%d ", getBinomial(i, k)); //writes formatted string to the file
			}
		}
		fprintf(file, "\n"); //puts space between lines
	}
	fclose(file);

	return 0;
}

int getBinomial(int i, int k) { //takes in input the positions of the number
	//returns the binomial coefficient for that 2 numbers (n is actually i)
	return (factorial(i))/(factorial(k)*factorial(i-k));
}

int factorial(int f) {
	//returns factorial of a number
	if (f == 0) return 1;
	return(f * factorial(f - 1));
}
