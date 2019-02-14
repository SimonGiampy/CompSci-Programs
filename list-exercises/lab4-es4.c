/*reads a sequence of letters repeated a certain amount of times. example:
   input: aaaass
   output: a4s2
 */

#include <stdio.h>
#include <stdlib.h>


#define DIR "textfile.tmp.txt"

//linked list declaration
typedef struct giovanni {
	char character;
	struct giovanni *next;
} gianfranco;
typedef gianfranco *list;

list upload(char const filename[]);
void save(list l, char const filename[]);
list insert(list, char ch);
void printList(list l);

void printList(list l) {
	if (l == NULL) {
		printf("list is empty\n");
	} else {
		printf("printing list:");
		while (l != NULL) {
			printf("%4c", l->character); //puts some space between a number and another
			l = l->next;
		}
		printf("\n");
	}
}

list insert(list l, char ch) { //inserts new values in a linked list
	list current = l, previous = NULL;
	list p; //support variable

	while (current != NULL && ch > current->character) {
		previous = current;
		current = current->next;
	}

	p = (list) malloc(sizeof(list));
	p->character = ch;
	p->next = current;

	if(previous != NULL) {
		previous->next = p;
	} else {
		l = p;
	}
	return l;
}

list upload(char const filename[]) {
	FILE *file = fopen(filename, "r");
	list l = NULL;
	if (file == NULL) {
		printf("generic error message here\n"); //error message
		exit(1);
	}
	int n;
	char ch;
	int read = fscanf(file, "%c%d", &ch, &n); //returns the number of data read from the input file
	while (read == 2) {
		for (int i = 0; i < n; i++) {
			l = insert(l, ch);
		}
		read = fscanf(file, "%c%d", &ch, &n);
	}

	return l;
}

void save(list l, char const filename[]) {
	//writes the sequence in a text file
	FILE *file; //file where to put all the values
	char c; //character repeated
	int n; //number of times a character is repeated
	list current;
	file = fopen(filename, "w");
	if (file != NULL) {
		current = l;
		while (current != NULL) { //while there are any characters in the list
			if (current == l) { //first position
				c = current->character;
				n = 1;
			} else if (current->character != c) { //if it is a new character, n is reset back to 1
				fprintf(file, "%c%d", c, n);
				c = current->character;
				n = 1;
			} else {
				n++; //increase amount of repeated letters
			}
			current = current->next; //next character in the list is selected
		}

		if (l != NULL) {
			fprintf(file, "%c%d", c, n);
		}
		fclose(file);
	}
}

int main(int argc, char const *argv[]) {
	/*
	   list l = NULL;
	   l = insert(l, 'b');
	   l = insert(l, 'b');
	   l = insert(l, 'b');
	   l = insert(l, 'b');
	   l = insert(l, 'x');
	   l = insert(l, 'x');
	   l = insert(l, 'c');
	   l = insert(l, 'c');
	   l = insert(l, 'c');
	   save(l, DIR);
	   printList(l);
	 */
	list l2 = upload(DIR);
	printList(l2);

	return 0;
}
