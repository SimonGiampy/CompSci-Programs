//takes in input a list, then moves the nodes in the list so the numbers in the nodes are sorted in ascending order
//basically it modifies the list in input without adding more elements
//implement bubble sort algorithm in the program of the list
#include "linked-list.h"
#include <stdio.h>

list sort(list list);
void removeNode(list *series, int element);

list sort(list series) {
	if (series == NULL) {
		return NULL;
	}
	list sorted = NULL; //it will return this
	list copy = series, original = series;

	while (original != NULL) {
		int max = original->element;
		copy = original; //first element
		while (copy != NULL) {
			if (max < copy->element) {
				max = copy->element;
			}
			copy = copy->next;
		}

		insertHeadP(&sorted, max);
		removeNode(&original, max);
	}
	return sorted;
}

void removeNode(list *series, int element) { //custom function that finds an elements and deletes it
	if (*series == NULL) {
		return;
	}

	list copy = *series, prev = NULL;
	int removed = 0; //check

	while (copy != NULL && removed == 0) {
		if (copy->element == element) {
			if (prev == NULL) {
				*series = copy->next;
				removed = 1;
			} else if (copy->next == NULL && prev != NULL) {
				free(copy);
				prev->next = NULL;
				removed = 1;
			} else if (prev != NULL && copy->next != NULL) {
				prev->next = copy->next;
				free(copy);
				removed = 1;
			}
		} else {
			prev = copy;
			copy = copy->next;
		}
	}

	if (copy == NULL && removed == 0) {
		printf("element not found\n");
	}
}


int main() {
	list series = NULL;
	printf("inserting new elements in random order\n");
	insertTailP(&series, 5);
	insertTailP(&series, 7);
	insertTailP(&series, 10);
	insertTailP(&series, 3);
	insertTailP(&series, 8);
	printList(series);

	printf("calling sort function\n");
	list sorted = sort(series);
	printList(sorted);

	//printf("calling remove function\n");
	//removeNode(&series, 5);
	//printList(series);

	return 0;
}
