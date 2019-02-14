/*
   Esercizio 3 (8 punti)
   Definire un tipo di dato opportuno clista per realizzare una lista dinamica di caratteri (ogni elemento è un
   carattere) e serve per gestire sequenze di caratteri. Si definisce inciso una sequenza di caratteri compresa tra una
   parentesi tonda aperta ed una parentesi tonda chiusa. Implementare una funzione che riceve in ingresso un puntatore
   alla testa di una lista che rappresenta una sequenza di caratteri e la modifica sostituendo tutti gli incisi con uno
   spazio. Si supponga che la sequenza di caratteri nella lista in ingresso sia ben formata, cioè (i) ogni parentesi tonda
   aperta corrisponde ad una successiva parantesi tonda chiusa, (ii) non può esserci una parentesi tonda chiusa che non sia
   preceduta da una parentesi tonda aperta e (iii) non possono esserci altri incisi né parentesi all’interno di un inciso.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct clist {
	char alpha;
	struct clist *next;
	struct clist *prev;
};
typedef struct clist *list;

void clean(list *list);
void printList(list l);
void insertHeadP(list *l, char element);
void insertTailP(list *l, char element);

void clean(list *l) { //takes a pointer to the head of the list as input parameter
	list copy = *l, backup = NULL, temp = NULL; //three support variables
	//copy is used for iteration until it reaches the end of the string
	//backup is used to link the first parenthesis (replaces with a space) to the character after the closing bracket
	//temp is used to delete the elements between the parenthesis

	while (copy != NULL) { //until the list (the string) is not terminated, check for every sequence of 2 parenthesis

		if (copy->alpha == '(') { //has found the opening bracket
			copy->alpha = ' '; //quickly replaces it with a single space

			backup = copy; //takes the element before the characters which will be removed in the while cycle
			while (copy->alpha != ')') { //repeates until it has found the closing bracket
				temp = copy; //this element will be removed soon
				copy = copy->next; //goes forward in the sequence of characters between the parenthesis
				free(temp); //removes the element in the bracket
			}
			backup->next = copy->next; //the space created has the next charcater after the closing bracket as next element
		} else {
			copy = copy->next; //continues the search for the opening bracket
		}
	}
	//the list l is dinamically modified using a pointer. it's the same as before except that some data is now deleted
}

int main() {
	char string[100] = "Hello this is a(sample)string that I(personally)created";
	//result should be = "Hello this is a string that I created"

	//creates the list so the function clean can be tested
	list list = NULL;
	//converts a string in a ordered linked list
	for (int i=0; i< strlen(string); i++) {
		insertTailP(&list, string[i]);
	}

	//before the cleaning function is called
	printList(list);
	//removes the parenthesis and their contents, and substitutes them with a single space
	clean(&list);
	//after the function is called. shows the result
	printList(list);
	return 0;
}

void insertHeadP(list *l, char element) {
	struct clist *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = malloc(sizeof(struct clist)); //allocates memory for a new list
	temp->alpha = element; //points to the first element of the list and sets it as the element in input
	temp->next = *l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	*l = temp;
}

void insertTailP(list *l, char element) {
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
void printList(list l) {
	if (l == NULL) {
		printf("list is empty\n");
	} else {
		printf("printing list non recursively: ");
		while (l != NULL) {
			printf("%c", l->alpha); //puts some space between a number and another
			l = l->next;
		}
		printf("\n");
	}
}
