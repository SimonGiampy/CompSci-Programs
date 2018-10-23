#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//this program generate random numbers and assign them to a matrix of m rows, and n columns
int main() {
	int rows = 5;
	int columns = 5;

	int a[rows][columns], b[rows][columns];
	//use this code to retrieve the lenght of the array: (int)(sizeof(array) / sizeof(array[0])

	srand(time(NULL)); //generate random see using the time in seconds, calculated from 1970 to the present

	for (int i=0; i<rows; i++) {
		for (int j=0; j<columns; j++) {
			a[i][j] = rand() % 9 + 1; //from 1 to 9 included
			printf("%d\t", a[i][j]); //prints the value and format all of them in a table
		}
		printf("\n");
	}

	return 0;
}
