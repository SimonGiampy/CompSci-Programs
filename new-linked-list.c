/*
   this is a new exercise with linked list but the main struct has 3 pointers to 3 other struct. there is a triple recursion
   this exercise shows how to handle multiple pointers in a single struct and their data
   it adds some elements in the linked list, then it prints every information which comes in with every element
   every elemtent is a number, wich can be linked to other numbers in the list whether it's even or odd
 */

#include <stdlib.h>
#include <stdio.h>

struct node { //new kind of linked list, with 3 links
	int data;
	struct node *next; //next element in the list
	struct node *nextEven; //points to the next EVEN integer in the list. if there aren't at all, it points to null
	struct node *nextOdd; //points to the next ODD integer in the list. if there aren't at all, it points to null
};
typedef struct node *list; //dynamic linked list with triple pointers

list insert(list l, int number);
void printList(list l);

int main(int argc, char const *argv[]) {
	list l = NULL;
	l = insert(l, 43);
	l = insert(l, 32);
	l = insert(l, 3);
	l = insert(l, 1);
	l = insert(l, 3);
	l = insert(l, 4);
	l = insert(l, 7);
	l = insert(l, 12);
	l = insert(l, -9);
	l = insert(l, 10);
	//adds some numbers, then prints everything
	printList(l);
	return 0;
}

void printList(list l) {
	if (l == NULL) {
		printf("list is empty you dumbass\n");
		return;
	}
	printf("printing list:\n");
	do {
		printf("element %d;", l->data);
		if (l->next != NULL) {
			printf(" next %d;", (l->next)->data); //next element in the series
			if (l->nextEven != NULL) {
				printf(" nextEven %d;", (l->nextEven)->data); //next even element in the list
			}
			if (l->nextOdd != NULL) {
				printf(" nextOdd %d", (l->nextOdd)->data); //next odd element in the list
			}
		} else {
			printf(" --> end of list");
		}
		printf("\n");
		l = l->next;
	} while (l != NULL); //checks whether it should continue in the iteration process
}

list insert(list l, int number) { //inserts a new number at the tail of the list, according to the structure given
	list p = (list) malloc(sizeof(struct node)); //initialization of support variable p, with the new number
	list current; //temporary variable

	p->data = number; //new number added in the list. the values for the next struct in the list are set to null
	p->next = NULL;
	p->nextEven = NULL;
	p->nextOdd = NULL;

	if (l == NULL) { //empty list
		return p; //return head of new list the list
	} else { //changes the pointers to the specific numbers
		current = l; //support variable
		while(current->next != NULL) { //until the list is not empty
			if (current->nextEven == NULL && number%2 == 0) { //even number
				current->nextEven = p;
			}
			if (current->nextOdd == NULL && number%2 == 1) { //odd number
				current->nextOdd = p;
			}
			current = current->next; //goes forward in the iteration of the list
		}
		current->next = p; //adds the next element of the list, with the 3 corresponding fields
		if (number % 2 == 0) {
			current->nextEven = p;
		} else {
			current->nextOdd = p;
		}
		return l;
	}
}
