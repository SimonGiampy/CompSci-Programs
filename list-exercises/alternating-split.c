/*
   Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists.
   The sublists should be made from alternating elements in the original list. So if the original list is {a, b, a, b, a},
   then one sublist should be {a, a, a} and the other should be {b, b}.
 */

#include <stdlib.h>
#include <stdio.h>

struct node {
	int element;
	struct node *next; //recursive declaration of struct
};
typedef struct node *list;  //struct of pointers, this is the declaration of a linked list


void alternatingSplit(list l, list *halfA, list *halfB);
void add(list *l, int element);
void printList(list l);

void alternatingSplit(list l, list *halfA, list *halfB) {
	list copy = l;
	list a = NULL, b = NULL; //creates two new lists
	while (copy != NULL) { //whiel the list is not yet finished
		add(&a, copy->element); //inserts the first value in the list a
		if (copy->next != NULL) {
			add(&b, copy->next->element); //inserts the next value of l to b if it's not null
		} else {
			break; //if the next is null the list has a odd number of elements, so it can't access the next element
			//so it stops the execution of the while cycle because it can't give b a new element
		}
		copy = copy->next->next; //goes forward of two elements
	}
	//assign the data in the new lists a and b to the input pointer lists halfA and halfB
	*halfA = a;
	*halfB = b;
	//doesn't return anything because it modifies the data directly to the cells of memory pointed by the two pointers
}

void add(list *l, int element) { //inserts at the end of the list, like insertTailRecursiveP in linked-list.h header file
	//recursive function to add a new element at the end iof the list, receives a pointer to a head of a list as input
	if (*l == NULL) {
		//normal add at the head of the list
		list temp = (list) malloc(sizeof(struct node));
		temp->element = element;
		temp->next = *l;
		*l = temp;
	} else {
		add(&((*l)->next), element);
	}
}

void printList(list l) {
	if (l == NULL) {
		printf("NULL\n");
	} else {
		printf("%d -> ", l->element);
		printList(l->next);
	}
}

int main() {
	list series = NULL;
	printf("inserting stuff\n");
	add(&series, 5);
	add(&series, 7);
	add(&series, 10);
	add(&series, 3);
	add(&series, 8);
	add(&series, 8);
	printList(series);

	//debug and show results
	list a = NULL, b = NULL;
	printf("calling alternatingSplit\n");
	alternatingSplit(series, &a, &b);
	printf("first list (a): ");
	printList(a);
	printf("second list (b): ");
	printList(b);

	return 0;
}
