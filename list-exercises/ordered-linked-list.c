//Add the new elements so they are always in ascending and descending order
#include "linked-list.h"

void addSortDescending(list *l, int el);
void addAscending(list *l, int el);
void addDescending(list *l, int el);

int main() {
	list list = NULL;
	printf("inserting new elements in ascending order\n");

	addDescending(&list, 9);
	addDescending(&list, 5);
	addDescending(&list, 10);
	addDescending(&list, 7);
	printList(list);
	return 0;
}

void addDescending(list *l, int el) { //almost the same as add ascending
	list newNode = (list) malloc(sizeof(list));
	newNode->element = el;

	//2 main cases: first one when the point of insertion is at the head or tail of the list
	if ((*l) == NULL || (*l)->element < el) { //insert head
		newNode->next = *l;
		*l = newNode;
	} else { //find insertion point in the list
		list current = *l;
		while (current->next != NULL && current->next->element > el) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void addAscending(list *l, int el) {
	list newNode = malloc(sizeof(list)); //this is the node to be inserted in the list
	newNode->element = el;

	//2 main cases
	if (*l == NULL || (*l)->element >= el) { //insert at the head of the list
		newNode->next = *l;
		*l = newNode; //modifies pointer value
	} else { //otherwise the point of insertion is somewhere in the middle of the list
		list current = *l; //used for iteration and scrollling down the list
		// Locate the node before the point of insertion
		while (current->next!=NULL && current->next->element < el) {
			//first check in while is if the list has a next element
			//the second check in while is if the next element (if exists) is less than or equal to the input element el
			current = current->next; //iteration down the list
		}
		//at this point it current represent the point of insertion of the element
		newNode->next = current->next;
		current->next = newNode;
	}
}
