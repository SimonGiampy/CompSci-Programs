/*
   Problema 4
   Implementare una funzione ricorsiva binary_search con il seguente prototipo:

   int binary_search(int v[], int elem, int a, int b)

   dove v è un vettore ordinato, a e b sono due posizioni valide di v con (a<b).
   La funzione deve cercare se v contiene il valore elem, in caso positivo ne restituisce la posizione, in caso negativo restituisce -1.
   Nota: Se elem compare più volte in v, è sufficiente restituire una delle posizioni in cui compare.
 */

#include <stdio.h>

int binary_search(int v[], int elem, int a, int b);

int main() {

	int vector[] = {3,5,6,9,10,11,13,18,23,30,31}; //array of numbers
	int a = 2; //starts the search at this index
	int b = 8; //finishes the search at this index
	int element1 = 18, element2 = 16; //elements to be looked for

	printf("%d found in position %d\n", element1, binary_search(vector, element1, a, b));
	printf("%d found in position %d\n", element2, binary_search(vector, element2, a, b));

	return 0;
}

int binary_search(int v[], int elem, int a, int b) {
	if (a == b+1) {
		return -1; //returns -1 if the elementis not present in the array
	} else {
		if (*(v+a) == elem) {
			return a; //returns the position of the elementfound
		} else {
			return binary_search(v, elem, a+1, b); //searches again, but from the next element
		}
	}
}
