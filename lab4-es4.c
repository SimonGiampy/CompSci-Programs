/*reads a sequence of letters repeated a certain amount of times. example:
   input: aaaass
   output: a4s2
 */

#include <stdio.h>
#include <stdlib.h>

//linked list declaration
typedef struct giovanni {
	char character;
	struct giovanni *next;
} gianfranco;
typedef gianfranco *list;

list upload(char filename[]);
void save(list l, char filename[]);
list insert(list, char ch);

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

list upload(char filename[]) {
	FILE *file = fopen(filename, "r");
	list l = NULL;
	if (file == NULL) {
		printf("jonsadnjsadssdklnsanskldklsnkosdnvsdkklnsdvnsklvdnklafnklsdv\n"); //eror message
		exit(1);
	}
	int n;
	char ch;
	int read = fscanf(file, "%c%d", &ch, &n);
	while (read == 2) {
		for (int i = 0; i < n; i++) {
			l = insert(l, ch);
		}
		read = fscanf(file, "%c%d", &ch, &n);
	}

	return l;
}

void save(list l, char filename[]) {
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
	list l;
	l = upload("input.txt");
	l = insert(l, 5);
	save(l, "ouput.txt");
	return 0;
}
