/*write a swap function that allow to swap the value of two float variables*/
//note: use pointers

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define X 20

void swap(int *a, int *b);
void printAllOfThem(int numbers[]);

int main() {
	int numbers[X];
	srand(time(NULL));

	printf("sequence: ");
	for (int i = 0; i < X; i++) {
		numbers[i] = rand()%100 + 1;
	}

	printAllOfThem(numbers);

	int swapped = 0, stop = 0;

	printf("swapped sequence: ");
	//for (int j = 0; j < X-2; j++) {
	while (stop == 0) {
		for (int i = 0; i < X -1; i++) {
			if (*(numbers+i) > *(numbers+i+1)) {
				swap((numbers+i), (numbers+i+1));
				swapped = 1;
			} else {
				stop += 1;
			}
		}
		if (swapped == 1) {
			stop = 0;
			swapped = 0;
		}
	}
	//}
	printAllOfThem(numbers);

	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printAllOfThem(int numbers[]) {
	for (int i = 0; i < X; i++) {
		printf("%d   ", *(numbers + i));
	}
	printf("\n");
}
