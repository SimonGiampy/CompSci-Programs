/*
   given an array of integers, and a number c to be searched for, the program returns the first recurrence of that number as a pointer. returns null if it can't be found
 */

#include <stdio.h>

int* search(int a[], int dim, int c);

int main() {

	int a[14] = {4,5,6,4,8,6,10,2,5,2,0,3,8,9};
	int c1 = 2, c2 = 6;
	int *pos1 = search(a, 14, c1);
	int *pos2 = search(a, 14, c2);

	//the pointer requires a long int (%ld) parameter in printf function in 64bit systems
	printf("trovato c1 in pos %ld\n", pos1-a);
	printf("trovato c2 in pos %ld\n", pos2-a);

	return 0;
}

int* search(int a[], int dim, int c) {
	int i;
	for (i = 0; i < dim; i++) {
		if (c == *(a+i)) {
			return a+i;
			//return &a[i]; this would be a suitable solution as well
		}
	}
	return NULL;
}
