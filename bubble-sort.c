/*write a swap function that allow to swap the value of two float variables*/
//note: use pointers

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define X 20 //number of generated numbers to be sorted

void swap(int *a, int *b); //swaps two integers
void printAllOfThem(int numbers[]); //prints all the numbers

int main() {
	int numbers[X]; //sequence of numbers randomly generated, then swapped
	srand(time(NULL)); //initialize random seed

	printf("sequence: ");
	//creates a series of random generated numbers and saves them in an array
	for (int i = 0; i < X; i++) {
		numbers[i] = rand()%100 + 1; //numbers from 1 to 100
	}

	printAllOfThem(numbers); //shows the generated sequence of numbers

	int swapped = 0, stop = 0;

	printf("swapped sequence: ");
	while (stop == 0) { //continues until the program doesn't do any swaps in a single cycle
		for (int i = 0; i < X -1; i++) { //iterate the sequence of numbers
			if (*(numbers+i) > *(numbers+i+1)) {
				swap((numbers+i), (numbers+i+1)); //swaps them when the first is greater than the latter
				swapped = 1;
			} else {
				stop += 1;
			}
		}
		if (swapped == 1) { //if it has swapped one cople of numbers, it has to continue and does the other cycles
			stop = 0;
			swapped = 0;
		}
	}

	printAllOfThem(numbers); //shows the sorted list of numbers

	return 0;
}

void swap(int *a, int *b) {
	//swaps the integers
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printAllOfThem(int numbers[]) {
	//prints every number memorized in the array numbers
	for (int i = 0; i < X; i++) {
		printf("%6d", *(numbers + i)); //writes the sequence of numbers with some space in between (at maximum 6 characters including the sequence of spaces)
	}
	printf("\n");
}
