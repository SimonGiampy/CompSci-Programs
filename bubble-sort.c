/*write a swap function that allow to swap the value of two float variables*/
//note: use pointers

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define X 10

void swap(int *a, int *b);

int main() {
	int numbers[X];
	srand(time(NULL));

	printf("sequence: ");
	for (int i = 0; i < X; i++) {
		numbers[i] = rand()%100 + 1;
		printf("%d   ", numbers[i]);
	}
	printf("\n");

	printf("swapped sequence: ");
	for (int j = 0; j < X-2; j++) {
		for (int i = 0; i < X -1; i++) {
			if (numbers[i] > numbers[i+1]) {
				swap(&numbers[i], &numbers[i+1]);
			}
			printf("%d   ", numbers[i]);
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
