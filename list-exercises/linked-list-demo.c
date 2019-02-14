#include "linked-list.h"

int main() {
	//this main is used to show the usages of the functions implemented in this library
	//some of them require the pointers as parameters, others return a value that needs to be handled

	list l1 = NULL; //head of a new list is initialized as NULL
	l1 = insertHead(l1, 5);
	insertHeadP(&l1, 9);
	insertTailP(&l1, 4);
	insertTailRecursiveP(&l1, 12);
	l1 = insertTailRecursive(l1, 7);
	l1 = insertHead(l1, 8);
	insertHeadP(&l1, 11);
	insertTailP(&l1, 1);
	insertTailRecursiveP(&l1, 0);
	l1 = insertTailRecursive(l1, -3);
	printf("added some elements\n");
	printList(l1);

	//the number returned in the searches is not handled, but it's not necessary, since the print statements are written already in the function
	search(l1, 6);
	searchRecursive(l1, 9);

	l1 = removeHead(l1);
	removeHeadP(&l1);
	printf("removed twice head of list\n");
	l1 = removeTail(l1);
	removeTailP(&l1);
	removeTailRecursiveP(&l1);
	printf("removed 3 times the tail of list\n");
	printList(l1);

	l1 = removeElement(l1, 31);
	removeElementP(&l1, 11);
	removeElementRecursiveP(&l1, 12);

	printf("printing list recursively: ");
	printListRecursive(l1);
	printf("length of list (normal method) is %d\n", length(l1));
	printf("length of list (recursive method) is %d\n", lengthRecursive(l1));


	list l2 = NULL; //new ordered list to show the usage of inserting vallues in ascending order
	//the recursive functions are the equivalent of the normal ones
	l2 = insertAscending(l2, 0);
	l2 = insertAscendingRecursive(l2, 9);
	l2 = insertAscending(l2, 2);
	l2 = insertAscendingRecursive(l2, -3);
	l2 = insertAscending(l2, 6);
	l2 = insertAscendingRecursive(l2, 15);

	printf("printing list2 recursively: ");
	printListRecursive(l2);

	return 0;
}
