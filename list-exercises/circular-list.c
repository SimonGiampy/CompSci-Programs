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
typedef enum {false = 0, true = !false} bool;
struct loop {
	int data;
	struct loop *next;
};
typedef struct loop *circularList;

void insert(circularList *list, int data);
void printList(circularList list);

void insert(circularList *list, int data) {
	bool found = false;
	circularList temp = *list;
	int i = 0, length = 0, first = 0;
	if (temp != NULL) {
		first = temp->data;
	}
	printf("first element %d\n", first);
	while (temp != NULL && i<10) {
		if (found == false && temp->data == data) {
			found == true;
		}
		printf("iter %d   ", temp->data);
		if (i!= 0 && temp->data == first) {
			temp = NULL;
		} else {
			temp = temp->next;
			i++;
			length++;
		}
	}
	printf("length %d\n", length);
	if (found == false) {

		circularList newList = (circularList) malloc(sizeof(circularList));
		if (*list == NULL) {
			newList->data = data;
			newList->next = newList;
			printf("added %d and next is %d\n", data, newList->next->data);
		} else {
			i = 1;
			printf("data %d, head is %d\n", data, (*list)->data);

			temp = *list;
			while (temp->next != NULL && i<=length) {
				printf("temp is %d and next is %d\n", temp->data, temp->next->data);
				temp = temp->next;
				i++;
			}
			temp->data = data;
			newList = temp;

			/*
			   //temp->next = (*list);
			   temp->next = newList;
			   newList->next = temp;
			   printf("added %d and next is %d\n", newList->data, newList->next->data);
			 */
		}
		*list = newList;
		//printList(list);
		//return list;

	}
}

void printList(circularList list) {
	if (list == NULL) {
		printf("empty list\n");
	}
	int i = 0;
	while (list != NULL && i<10) {
		printf("element %d is %d \n", i, list->data);
		list = list->next;
		i++;
	}
}

int main(int argc, char const *argv[]) {
	circularList list = NULL;
	insert(&list, 5);
	insert(&list, 7);
	insert(&list, 2);
	insert(&list, 6);
	// insert(&list, 3);
	// insert(&list, 1);
	// insert(&list, 9);
	printList(list);
	return 0;
}
