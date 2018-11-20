/*
   given an array of integers, and a number c to be searched for, the program returns the first recurrence of that number as a pointer. returns null if it can't be found

   second task:
   return all the occurences for the searched value in the array
 */

#include <stdio.h>

int* search(int a[], int dim, int c);
int searchAll(int *a, int dim, int c, int *pos);

int main() {

	int a[14] = {4,5,6,4,8,6,10,2,5,2,0,3,8,9}; //default array
	int c1 = 2, c2 = 6; //values to be looked for

	int *pos1 = search(a, 14, c1);
	int *pos2 = search(a, 14, c2);

	//the pointer requires a long int (%ld) parameter in printf function in 64bit systems
	printf("trovato %d in pos %ld\n", c1, pos1-a);
	printf("trovato %d in pos %ld\n", c2, pos2-a);

	int positions[14], c3 = 5;
	int amount = searchAll(a, 14, c3, positions);
	printf("found number %d in positions: ", c3);
	for (int i = 0; i < amount; i++) {
		printf("%d ", positions[i]);
	}
	printf("\n");

	return 0;
}

int* search(int a[], int dim, int c) {
	//default search functions, returns only the first occurrence
	int i;
	for (i = 0; i < dim; i++) {
		if (c == *(a+i)) {
			return a+i; //returns the pointer to the reult of the search
			//return &a[i]; this would be a suitable solution as well
		}
	}
	return NULL; //returns null if the number c is not found
}

int searchAll(int *a, int dim, int c, int *pos) {
	//second search function, which searches for all the occurences in the given array
	//c is the number, *pos
	int found = 0, i = 0;
	for (; i < dim; i++) {
		if (c == *(a+i)) {
			pos[found] = i;
			found++;
		}
	}
	return found;
}
