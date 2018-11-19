//how dynamic lists work, and how to do basic operations, like searching an element, getting the length of the list
//notes taken from class

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

//-------------------------------------------------------------------------------------------------------------------
//other equivalent method
typedef int data2;
typedef struct {
	data2 element;
	node2 *next;
} node2;
//-------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------
//retrieves length of a given list in input
int length(list l) {
	int num = 0;
	while (l != NULL) { //iterates as long as the node in the list is not null
		//continues in this cycle as long as the list is not finished
		num++;
		l = l.next; //ppints to the next element of the list
	}
	return num;
}
//-------------------------------------------------------------------------------------------------------------------
//other recursive method to retrieve the length of a given list
int lengthRecursive(list l) {
	if (l == NULL) { //list is empty
		return 0;
	} else {
		return 1 + lengthRecursive(l.next); //1 plus the length of the same list
		//this considers the length of the same list minus the first element (counted as 1)
	}
}
//-------------------------------------------------------------------------------------------------------------------
//search in the elements of the list
list search(list l, data element) { //returns an elementof the list if the element in input as parameter is found
	while (l != NULL) { //iterates until there are not elements in the list anymore
		if (l.next == element) { //elementin the list is equal to the element to be searched
			return l; //element found in the list
		} else {
			l = l.next; //move to the next element in the list to see if the element can be found
		}
	}
	return NULL; //if in the cycle no correspondences are found, it returns the null value
}
//-------------------------------------------------------------------------------------------------------------------
//second method of searching an element in a list
list search2(list l, data element) {
	if (l == NULL || l.element == element) { //if the elementis found returns the element of the list
		return l; //returns also null if the element in input is null
	} else {
		return search2(l.next, element); //recursive way of searching the next element withouth having to add 1
	}
}
//-------------------------------------------------------------------------------------------------------------------
//with this function it is possible to add an element at the head (start) of the list
list insertHead(list l, data element) {
	struct node *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = malloc(sizeof(struct node)); //allocates memory for a new list
	temp.element = element; //points to the first element of the list and sets it as the element in input
	temp.next = l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	return temp;
}
//-------------------------------------------------------------------------------------------------------------------
//inserts a new element at the tail (end) of the given lists
//exercise: write this exact function in a non recursive way
list insertTail(list l, data element) {
	if (l == NULL) {
		return insertHead(l, element);
	} else {
		l.next = insertTail(l.next, element);
		return l;
	}
}

int main() {
	list l1 = NULL; //head of a new list is initialized as NULL
	l1 = insertHead(l1, 5);
	l1 = insertHead(l1, 6);
	l1 = insertHead(l1, 7);

}
