/*
   Split the nodes of the given list into front and back halves, and return the two lists using the reference parameters.
   If the length is odd, the extra node should go in the front list.
 */
#include "linked-list.h"

void frontBackSplit(list l, list *front, list *back);


void frontBackSplit(list l, list *front, list *back) {
	//find the half of the list, and make the back head point to the second half of the list

	//compute count to see where is the middle of the list
	int length = 0;
	list copy = l;
	while(copy != NULL) {
		length++;
		copy = copy->next;
	}
	copy = l; //reset head of list

	int half;
	if (length % 2 == 0) { //even number of elements
		half = length/2;
	} else {
		half = (int) (length/2.0 + 0.5);
	}
	printf("length = %d, half is %d\n", length, half);

	int i = 1;

	//stops in the middle of the list
	while (i < half) { //from 1 to half excluded
		copy = copy->next;
		i++;
	}

	*front = l; //the first half of the list if the same as the input list l
	*back = copy->next; //copy is now equal to the rest of the list (what comes after the first half), which is what we require for back pointer
	copy->next = NULL; //this command is awesome
	//try to understand this later on...
}

void FrontBackSplit(list source, list *frontRef, list *backRef) { //second version, of the pdf
	int len = length(source);
	int i;
	list current = source;
	if (len < 2) {
		*frontRef = source;
		*backRef = NULL;
	} else {
		int hopCount = (int) (len-1)/2; //approximation by excess
		//(figured these with a few drawings)
		for (i = 0; i<hopCount; i++) {
			current = current->next;
		}
		// Now cut at current
		*frontRef = source;
		*backRef = current->next;
		current->next = NULL;
	}
}


int main() {
	list series = NULL;
	printf("inserting stuff\n");
	insertTailP(&series, 5);
	insertTailP(&series, 7);
	insertTailP(&series, 10);
	insertTailP(&series, 3);
	insertTailP(&series, 8);
	insertTailP(&series, 8);
	printList(series);

	list front = NULL, back = NULL;
	printf("calling frontBackSplit\n");
	frontBackSplit(series, &front, &back);
	printf("now printing results\n");
	printList(front);
	printList(back);

	return 0;
}
