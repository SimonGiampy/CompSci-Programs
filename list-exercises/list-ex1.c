//insert integer numbers in ascending order inside a linked list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//double linked list declaration
struct node {
	int data;
	struct node *previous;
	struct node *next;
};
typedef struct node item;
typedef item *list;


list insert2(list l, int data) {
	//adds an element, respecting the ascending order
	//the list mustn't contain duplicates, so if it is asked to add a duplicate, it should't do anything
	struct node *current = l, *previous = NULL, *p = NULL;

	while (current != NULL && current->data < data) {
		previous = current;
		current = current->next;
	}

	if (current == NULL || data != current->data) {
		p = malloc(sizeof(struct node));
		p->data = data;
		if (previous != NULL) {
			previous->next = p;
		}
		p->next = current;
		if (current != NULL) {
			current->previous = p;
		}
		p->previous = previous;
	}

	if (previous == NULL && p != NULL) {
		return p;
	} else {
		return l;
	}
}

int main() {
	/*
	   list l = NULL;
	   srand(time(NULL));
	   int value;
	   for (int i = 0; i < 10; i++) {
	    value = rand() % 100;
	    printf("inserting value: %d\n", value);
	    l = insertAscending(l, value);
	   }
	   printAllRecursive(l);
	 */

	list l = NULL;
	srand(time(NULL));
	int value;
	for (int i = 0; i < 10; i++) {
		value = rand() % 10;
		printf("inserting value: %d\n", value);
	}
	//TODO modify main to make the program work correctly
	return 0;
}
