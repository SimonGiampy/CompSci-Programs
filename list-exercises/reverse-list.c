//reverse the order of the elements of a given list in input. use two different methods: iterative and recursive methods
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//struct taht handles a list of character, created by converting a string
struct revLink {
	char c;
	struct revLink *next;
};
typedef struct revLink *link;

//3 methods of reversing a linked list
link reverse3Pointers(link l);
link reverseStandard(link list);
link reverseRecursive(link list);

//basic function utilities
link stringToList(char string[100]);
void insertTail(link *list, char letter);
link insertHead(link list, char letter);
void printList(link list);

/*
   Reverses the given linked list by changing its .next pointers and its head pointer. Takes a pointer (reference) to the head pointer.
   Plan for this loop: move three pointers: front, middle, back down the list in order. Middle is the main pointer running
   down the list. Front leads it and Back trails it. For each step, reverse the middle pointer and then advance all three to get the next node.
 */
link reverse3Pointers(link l) {
	if (l == NULL) { //list is empty
		return NULL;
	} else if (l->next == NULL) { //list has only one element
		return l;
	} else if (l->next->next == NULL) { //list has just two elements: the first becomes the second and viceversa
		link newOne = (link) malloc(sizeof(struct revLink)); //new list
		newOne->c = l->next->c; //this is the procedure to add data to the head of the list
		l->next = NULL;
		newOne->next = l;
		return newOne;
	}

	//general case of iteration (for lists of 3+ elements). method of the three iterating pointers down the list
	link back = NULL, middle = l, front = middle->next; //the three pointers
	printf("start::: back NULL -- middle %c -- front %c\n", middle->c, front->c);
	while (1) { //continues until front is null, so there is nothing ahead oh middle,
		//and middle becomes the head of the list

		middle->next = back; //switches middle pointer direction, so it points to the opposide side of front
		if (front == NULL) break; // stops here
		//advancement of the 3 pointers, each one moves forward
		back = middle;
		middle = front;
		front = front->next;
	}
	return middle; //returns the main list. middle is the head pointer of the list
}

link reverseRecursive(link list)  { //very tricky recursive method
	link first, rest;
	if (list == NULL) return NULL; // empty list base case

	first = list; //suppose first = {1, 2, 3}
	rest = first->next; //rest = {2, 3}

	if (rest == NULL) return first; // empty rest base case
	rest = reverseRecursive(rest); // Recursively reverse the smaller {2, 3} case. After: rest = {3, 2}
	first->next->next = first; // put the first elem on the end of the list
	first->next = NULL; // fix the head pointer

	return rest;
}

link reverseStandard(link list) { //for each element in the list, it adds it to the head of the list
	link reversed = (link) malloc(sizeof(struct revLink));
	while (list != NULL) {
		reversed = insertHead(reversed, list->c); //puts each letter in the list at the top of the new reversed list
		list = list->next; //continues in the cycle
	}
	return reversed;
}

link insertHead(link list, char letter) { //returns the head of a list containg the letter as first element, and the tail is composed of the rest
	link temp = (link) malloc(sizeof(struct revLink)); //allocating memory for the new list
	temp->c = letter;
	temp->next = list;
	return temp;
}

link stringToList(char string[100]) { //converts a string in a linked list with the characters in the right order
	link list = NULL;
	for (int i=0; i< strlen(string); i++) {
		insertTail(&list, string[i]);
	}
	return list;
}

void insertTail(link *list, char letter) { //recursive
	if (*list == NULL) {
		*list = insertHead(*list, letter);
	} else {
		insertTail(&((*list)->next), letter);
	}
}

void printList(link list) {
	if (list == NULL) {
		printf("NULL\n");
	} else {
		printf("%c -> ", list->c);
		printList(list->next);
	}
}

int main() {
	char input[100];
	printf("enter the string, so it get converted in alist and then reversed: ");
	scanf("%[^\n]s", input); //including spaces in the input from the user
	link list = stringToList(input);
	printf("list before: \n");
	printList(list); //show preview of string

	printf("reversing process started, final result: \n");
	//link reversed = reverse3Pointers(list); //method of the 3 pointers
	//link reversed = reverseStandard(list); //my standard method
	link reversed = reverseRecursive(list);
	printList(reversed);

	return 0;
}
