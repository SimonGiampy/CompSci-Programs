/*
   definition of a circular list:
   it's a dynamic list in which the last element points to the first element. the pointer at the head points to an arbitrary element
   an element of the list is described with the type of the following...
   every element in a circular list is unique, in fact there aren't duplicates of the same values

   given as input a circular list and an integer, the program adds the integer in a random position in the lists, making sure there aren't any other
   elements equal to the one that is being added. so there mustn't be any duplicates

   the function print, shows all the elements
 */
#include <stdlib.h>
#include <stdio.h>

struct circular {
	int data;
	struct circular *next;
};
typedef struct circular circularList;
typedef circularList *list;

list insert(list l, int data) {
	int found = 0;
	struct circular *current = l, *p;

	if (l != NULL) {
		//insert element in the list
		//search if data isalready present in the list
		do {
			if (data == current->data) {
				found = 1;
			}
			current = current->next;
		} while (current != l && found == 0);
	}

	if (found) {
		return l;
	} else {
		p = malloc(sizeof(struct circular));
		p->data = data;
		if (l == NULL) {
			p->next = p;
		} else {
			p->next = l->next;
			l->next = p;
		}
	}
	return l;
}

void print(list l) {
	circularList *current;
	current = l;

	if (l == NULL) {
		printf("empty list\n");
	} else {
		do {
			printf("%d\n", current->data);
			current = current->next;
		} while (current != l);
	}


}
