//how dynamic lists work, and how to do basic operations, like searching an element, getting the length of the list
//notes taken from class
//TODO fix the errors and bugs, then add other calls in the main method. when everything is complete, create a library to access the functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//main method to define a dynamic list
typedef int data;
struct node {
	data element;
	struct node *next; //recursive declaration of struct
};
typedef struct node *list; //strut of pointers, this is the declaration of a list

//declarations
int length(list l);
int lengthRecursive(list l);
list search(list l, data element);
list search2(list l, data element);
list insertHead(list l, data element);
list insertTail(list l, data element);
list removeHead(list l);
list removeTail(list l);
list removeElement(list l, data element);
void printList(list l);

/*
   //-------------------------------------------------------------------------------------------------------------------
   //other equivalent method
   typedef int data2;
   typedef struct {
    data2 element;
    node2 *next2;
   } node2;
   //-------------------------------------------------------------------------------------------------------------------
 */
//-------------------------------------------------------------------------------------------------------------------
//retrieves length of a given list in input
int length(list l) {
	int num = 0;
	while (l != NULL) { //iterates as long as the node in the list is not null
		//continues in this cycle as long as the list is not finished
		num++;
		l = l->next; //ppints to the next element of the list
	}
	printf("lenth of list (normal method) is %d\n", num);
	return num;
}
//-------------------------------------------------------------------------------------------------------------------
//other recursive method to retrieve the length of a given list
int lengthRecursive(list l) {
	if (l == NULL) { //list is empty
		printf("list is empty (recursive method)\n");
		return 0;
	} else {
		return 1 + lengthRecursive(l->next); //1 plus the length of the same list
		//this considers the length of the same list minus the first element (counted as 1)
	}
}
//-------------------------------------------------------------------------------------------------------------------
//search in the elements of the list
list search(list l, data element) { //returns an elementof the list if the element in input as parameter is found
	printf("searching element %d with method 1 in the list: \n", element);
	while (l != NULL) { //iterates until there are not elements in the list anymore
		if (l->next == element) { //element in the list is equal to the element to be searched
			printf("element has been found in the list\n");
			return l; //element found in the list
		} else {
			l = l->next; //move to the next element in the list to see if the element can be found
		}
	}
	printf("no matches found in the list\n");
	return NULL; //if in the cycle no correspondences are found, it returns the null value
}
//-------------------------------------------------------------------------------------------------------------------
//second method of searching an element in a list
list search2(list l, data element) {
	printf("searching element %d with method 2 in the list: \n", element);
	if (l == NULL || l->element == element) { //if the elementis found returns the element of the list
		printf("element has been found in the list\n");
		return l; //returns also null if the element in input is null
	} else {
		return search2(l->next, element); //recursive way of searching the next element withouth having to add 1
	}
	printf("no matches found in the list\n");
}
//-------------------------------------------------------------------------------------------------------------------
//with this function it is possible to add an element at the head (start) of the list
list insertHead(list l, data element) {
	printf("adding new element at the start of the list %d\n", element);
	struct node *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = malloc(sizeof(struct node)); //allocates memory for a new list
	temp->element = element; //points to the first element of the list and sets it as the element in input
	temp->next = l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	return temp;
}
//same version, but with the pointer of the list as parameter
void insertHead2(list *l, data element) {
	printf("adding new element at the start of the list %d (method 2)\n", element);
	struct node *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = malloc(sizeof(struct node)); //allocates memory for a new list
	temp->element = element; //points to the first element of the list and sets it as the element in input
	temp->next = *l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	*l = temp;
}
//-------------------------------------------------------------------------------------------------------------------
//inserts a new element at the tail (end) of the given lists
//TODO exercise: write this exact function in a non recursive way
list insertTail(list l, data element) {
	printf("adding new element at the end of the list %d\n", element);
	if (l == NULL) {
		return insertHead(l, element);
	} else {
		l->next = insertTail(l->next, element);
		return l;
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes the first elementin the list, so the second element becomes the first
list removeHead(list l) {
	printf("removing first element in the list\n");
	if (l!= NULL) {
		list temp = l;
		l = l->next;
		free(temp);
		return l;
	} else {
		printf("list is null, it's impossible to delete an element\n");
		return NULL;
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes the last element in the list, so the second to last becomes the new last element
list removeTail(list l) {
	printf("removing last element in the list\n");
	if (l!=NULL) {
		if (l->next == NULL) {
			return removeHead(l);
		} else {
			l->next = removeTail(l->next);
			return l;
		}
	} else {
		printf("list is null, it's impossible to delete an element\n");
		return NULL;
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes a specific element from the list
//so if the element is in position n, the elementin position n-1 points to the element that was in position n+1
//the pointers related to the element removed, are now reassigned to provide correct pointing and continuity in the list
list removeElement(list l, data element) {
	printf("removing a specific element %d\n", element);
	if (l!=NULL) {
		list current = l, previous = NULL; //current pointer element of the list, and the previous element with his pointer
		while (l!=NULL && l->element != element) { //tries to find the specific element
			previous = current;
			current = current->next;
		}

		if (current==NULL) {
			printf("element not found, can't be removed\n");
			return l;
		}
		if (previous != NULL) {
			previous->next = current->next;
		} else {
			l = l->next;
		}
		free(current);
		printf("element removed correctly\n");
		return l;
	}
	return NULL;
}
//-------------------------------------------------------------------------------------------------------------------
//prints every single element in the list
void printList(list l) {
	if (l == NULL) {
		printf("list is empty\n");
	} else {
		printf("list: ");
		while (l->next != NULL) {
			printf("%3d", l->next);
		}
		printf("\n");
	}
}

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

int main() {
	list l1 = NULL; //head of a new list is initialized as NULL
	l1 = insertHead(l1, 5);
	l1 = insertHead(l1, 6);
	l1 = insertHead2(&l1, 7); //variation with address of list

	//TODO add other methods, and debug all of them
	//TODO create a library to access all the methods of the list, instead of writing all of them again
}
