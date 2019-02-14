//this library is set up with a lot of different functions, which handle a lot of different case usages for linked lists
//the functions are divided into different categories, each one described with a specific name. every function has its own explanation

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//best method to define a dynamic single linked list
//this is the struct used in the whole library
typedef int data;
struct node {
	data element;
	struct node *next; //recursive declaration of struct
};
typedef struct node *list; //struct of pointers, this is the declaration of a linked list

//this is the form of a double linked list, with two pointers to structs. one of them points to the previous element, the other one to the next element
//double linked list can be very useful in many cases, as they avoid to declare multiple variable to handle several values of the list at the same time.
struct doubleNode {
	data element;
	struct doubleNode *prev;
	struct doubleNode *next;
};
typedef struct doubleNode *doubleList;

//-------------------------------------------------------------------------------------------------------------------
//declarations of all the functions. they are divided in groups: normal, pointer type, and recursive
//all the functions with the same name do the same thing, but with some variants:
//recursive functions are simply recursive. the pointer function (declared with a P in the name) accept the parameter list as a pointer
//the P in the functions with a pointer as parameter is necessary as C doesn't support OOP, and consequently neither overloading and polymorphism
int length(list l);
int lengthRecursive(list l);
void search(list l, data element);
int searchRecursive(list l, data element);
list insertHead(list l, data element);
void insertHeadP(list *l, data element);
void insertTailP(list *l, data element);
list insertTailRecursive(list l, data element);
void insertTailRecursiveP(list *l, data element);
list removeHead(list l);
void removeHeadP(list *l);
list removeTail(list l);
void removeTailP(list *l);
void removeTailRecursiveP(list *l);
list removeElement(list l, data element);
void removeElementP(list *l, data element);
void removeElementRecursiveP(list *l, data element);
void printList(list l);
void printListRecursive(list l);
list insertAscending(list l, int element);
list insertAscendingRecursive(list l, int element);
//-------------------------------------------------------------------------------------------------------------------

//retrieves the length of a given list in input
int length(list l) {
	int num = 0;
	while (l != NULL) { //iterates as long as the node in the list is not null
		//continues in this cycle as long as the list is not finished
		num++;
		l = l->next; //ppints to the next element of the list
	}
	return num;
}
//-------------------------------------------------------------------------------------------------------------------
//other recursive method that retrieves the length of a given list
int lengthRecursive(list l) {
	if (l == NULL) { //list is empty
		return 0;
	} else {
		return 1 + lengthRecursive(l->next); //1 plus the length of the same list
		//this considers the length of the same list minus the first element (counted as 1)
	}
}
//-------------------------------------------------------------------------------------------------------------------
//search in the elements of the list
void search(list l, data element) { //returns an element of the list if the element in input as parameter is found
	printf("searching element %d with normal method in the list: ", element);
	while (l != NULL) { //iterates until there are not elements in the list anymore
		if (l->element == element) { //element in the list is equal to the element to be searched
			printf("element has been found in the list\n");
			return; //element found in the list, so stops the execution
		} else {
			l = l->next; //move to the next element in the list to see if the element can be found
		}
	}
	printf("no matches found in the list\n"); //no correspondences are found if it reaches this line
}
//-------------------------------------------------------------------------------------------------------------------
//second method of searching an element in a list
int searchRecursive(list l, data element) {
	if (l==NULL) {
		printf("searching element %d with recursive method in the list: ", element);
		printf("no matches found in the list\n");
		return 0;
	}
	if (l != NULL && l->element == element) { //if the elementis found returns the element of the list
		printf("searching element %d with recursive method in the list: ", element);
		//the line above is here, so it doesn't prompt it multiple times when calling itself during recursion
		printf("element has been found in the list\n");
		return 1; //stops the execution
	} else {
		return searchRecursive(l->next, element); //recursive way of searching the next element withouth having to add 1
	}
	printf("searching element %d with recursive method in the list: ", element);
	//the line above is here, so it doesn't prompt it multiple times when calling itself during recursion
	printf("no matches found in the list\n");
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------
//with this function it is possible to add an element at the head (start) of the list
list insertHead(list l, data element) {
	//printf("adding new element at the start of the list %d\n", element);
	list temp; //new supporting list named temp
	//other version of same line above:     list temp;
	temp = (struct node*) malloc(sizeof(list)); //allocates memory for a new list
	temp->element = element; //points to the first element of the list and sets it as the element in input
	temp->next = l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	return temp;
}
//same version, but with the pointer of the list as parameter
void insertHeadP(list *l, data element) {
	struct node *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = (list) malloc(sizeof(struct node)); //allocates memory for a new list
	temp->element = element; //points to the first element of the list and sets it as the element in input
	temp->next = *l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	*l = temp;
}
//-------------------------------------------------------------------------------------------------------------------
//inserts a new element at the tail (end) of the given list
void insertTailP(list *l, data element) {
	if ((*l)==NULL) { //if the list is empty, then it adds the new value at the start of the list
		insertHeadP(l, element); //calls the other function to add the elementat the top of the list
	} else { //general case, it iterates until it finds the end of the list
		list current = *l;
		while (current->next != NULL) {
			current = current->next;
		}
		//reaches the end of the list. current now points to the last element
		insertHeadP(&(current->next), element); //puts the new element at the "start of the end" of the list
	}
}
//inserts a new element at the tail (end) of the given list in a recursive way. same thing as above more or less
list insertTailRecursive(list l, data element) {
	if (l == NULL) {
		return insertHead(l, element);
	} else {
		l->next = insertTailRecursive(l->next, element);
		return l; //returns the modified list
	}
}
//same function but with the pointer to the list
void insertTailRecursiveP(list *l, data element) {
	if (*l == NULL) {
		insertHeadP(l, element);
	} else {
		insertTailRecursiveP(&((*l)->next), element);
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes the first element in the list, so the second element becomes the first
list removeHead(list l) {
	if (l!= NULL) {
		l = l->next; //simply skips the first element in the list (if it is not null)
		return l;
	} else {
		printf("list is null, it's impossible to delete an element\n");
		return NULL;
	}
}
//same function, but with the pointer of the list
void removeHeadP(list *l) {
	if (*l!=NULL) {
		*l = (*l)->next;
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes the last element in the list, so the second to last becomes the new last element
list removeTail(list l) {
	if (l!=NULL) {
		if (l->next == NULL) {
			return removeHead(l); //the second element in the selected list is null, so it deletes the one before
		} else {
			l->next = removeTail(l->next);
			return l;
		}
	} else {
		printf("list is null, it's impossible to delete an element\n");
		return NULL;
	}
}
//removes the last element in the lits, but with a pointer as parameter. basically the same thing
void removeTailP(list *l) {
	if (*l!=NULL) {
		list current = *l;
		list previous = NULL;
		while (current->next !=NULL) {
			previous = current;
			current = current->next;
		}
		if (previous!=NULL) {
			previous->next = NULL;
		} else {
			*l = NULL;
		}
		free (current);
	}
}
//same function as above, but it removes it recursively
void removeTailRecursiveP(list *l) {
	if (*l!=NULL) {
		if ((*l)->next == NULL) {
			removeHeadP(l);
		} else {
			removeTailRecursiveP(&((*l)->next));
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------
//removes a specific element from the list
//so if the element is in position n, the elementin position n-1 points to the element that was in position n+1
//the pointers related to the element removed, are now reassigned to provide correct pointing and continuity in the list
list removeElement(list l, data element) {
	printf("removing the specific element %d: ", element);
	if (l!=NULL) {
		list current = l, previous = NULL; //current pointer element of the list, and the previous element with his pointer
		//the error is here in the while cycle
		while (current!=NULL && current->element != element) { //tries to find the specific element
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
			current = current->next;
		}
		free(current);
		printf("element removed correctly\n");
		return l;
	}
	return NULL;
}
//removes a specific element from the list, with the list passed as a pointer parameter
void removeElementP(list *l, data element) {
	printf("removing the specific element (pointer function) %d: ", element);
	list previous = NULL, current = *l;
	while (current != NULL && current->element != element) {
		previous = current;
		current = current->next;
	}
	//similar code to the function removeElement, but this time the function is void
	if (current !=NULL) {
		if (previous !=NULL) {
			previous->next = current->next;
		} else {
			*l = current->next;
		}
		printf("element removed correctly\n");
		free(current); //frees the memory created for that element
	} else {
		printf("element not found, can't be removed\n");
	}
}
//removes a specific element from the list recursively, with the list passed as a pointer parameter
void removeElementRecursiveP(list *l, data element) {
	if (*l!=NULL) {
		if ((*l)->element == element) {
			*l = (*l)->next;
			printf("element %d removed correctly (pointer, recursive function)\n", element);
		} else {
			removeElementRecursiveP(&((*l)->next), element);
		}
	} else {
		printf("element not found, can't be removed\n");
	}
}
//-------------------------------------------------------------------------------------------------------------------
//prints every single element in the list
void printList(list l) {
	if (l == NULL) {
		printf("list is empty\n");
	} else {
		printf("printing list non recursively: ");
		while (l != NULL) {
			printf("%4d", l->element); //puts some space between a number and another
			l = l->next;
		}
		printf("\n");
	}
}
//prints every single element but in a recursive way
void printListRecursive(list l) {
	if (l == NULL) {
		printf("\n");
	} else {
		printf("%4d", l->element); //prints first element
		printListRecursive(l->next); //then prints all the other elementsby calling the same function
	}
}
//-------------------------------------------------------------------------------------------------------------------
//adds a new item so the entire list is always written in ascending order
list insertAscending(list l, int element) {
	struct node *p, *current = l, *previous = NULL;
	p = (list) malloc(sizeof(struct node)); //support variable
	p->element = element;

	while (current != NULL &&current->element < element) {
		//it checks the first condition, then, if it is met, it checks the second one
		previous = current;
		current = current->next;
	}

	p->next = current;
	if (previous!= NULL) {
		previous->next = p;
	}
	//long way to return a variable list
	if (previous !=  NULL) {
		return l;
	} else {
		return p;
	}
}
//it's the same thing as the function above, but it does it in a recursive way
list insertAscendingRecursive(list l, int element)  {
	list p; //support variable
	if (l == NULL || element < l->element) {
		p = (list) malloc(sizeof(list)); //support variable to handle the next element without writing again the same values
		p->element = element;
		p->next = l;
		l = p;
	} else {
		l->next = insertAscendingRecursive(l->next, element); //calls itself again, but checks the values from the next one
	}
	return l;
}
//-------------------------------------------------------------------------------------------------------------------
//end of library functions
