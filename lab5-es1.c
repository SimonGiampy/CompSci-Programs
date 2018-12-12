#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct conv {
	char letter; //single letter in the string
	unsigned int count; //how many times this letter is repeated
	struct conv *next; //next element in dynamic list
};
typedef struct conv *list;


list stringToList(char string[]);
list insert(list l, char c);
void printList(list l);

//second method
void inserisci(list *l, char ch);
list string2list(char str[]);

int main(int argc, char const *argv[]) {
	char string [] = "converted string"; //sample string

	//first method
	list l = stringToList(string);
	printList(l);

	//second method
	list l2 = string2list(string);
	printf("\nsecond method:\n");
	printList(l2);

	return 0;
}

void printList(list l) {
	printf("printing list: ");
	while (l != NULL) {
		printf("%c%d  >  ", l->letter, l->count);  //puts some space between a number and another
		l = l->next;
	}
	printf("end\n");
}
//first method
list stringToList(char string[]) {
	list l = NULL;
	for (unsigned int i=0; i<strlen(string); i++) {
		l = insert(l, string[i]);
	}
	return l;
}
//first method, without the pointer as a parameter
list insert(list l, char c) { //inserts at the head of the list
	list current = l;
	int found = 0;
	while (current !=  NULL && found == 0) { //while there are elements in the list and it hasn't found a duplicate yet
		if (current->letter == c) {
			current->count++; //increment how many times the letter is repeated in the string
			found = 1; //found a duplicate of a letter
		}
		current = current->next;
	}

	if (found == 1) {
		return l;
	} else {
		current = (list) malloc(sizeof(list));
		current->letter = c;
		current->count = 1;
		current->next = l;
		return current;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------
//second method
list string2list(char str[]) {
	int i;
	list l = NULL;

	for(i = 0; str[i] != '\0'; i++)
		inserisci(&l, str[i]);

	return l;
}

void inserisci(list *l, char ch) { //takes the list as a pointer, so it directly modifies the values of the list
	//inserts at the tail of the list
	while(*l != NULL)
	{
		if((*l)->letter == ch) {
			(*l)->count++;
			break;
		}

		l = &((*l)->next);
	}

	if(*l == NULL)
	{
		*l = malloc(sizeof(struct conv));
		(*l)->letter = ch;
		(*l)->count = 1;
		(*l)->next = NULL;
	}
}
