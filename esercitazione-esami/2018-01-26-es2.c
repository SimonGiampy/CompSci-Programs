//exercise 2;
#include <stdio.h>
#include <stdlib.h>

struct list {
	int num;
	struct list *next;
};
typedef struct list *lista;

void insertHeadP(lista *l, int element);
int function(lista listA, lista listB);

int main() {
	lista listA = NULL;
	insertHeadP(&listA, 6);
	insertHeadP(&listA, 1);
	insertHeadP(&listA, 7);
	insertHeadP(&listA, 68);
	insertHeadP(&listA, 5);
	insertHeadP(&listA, 1);
	insertHeadP(&listA, 86);
	insertHeadP(&listA, 9);

	lista listB = NULL;
	insertHeadP(&listB, 6);
	insertHeadP(&listB, 7);
	insertHeadP(&listB, 68);
	insertHeadP(&listB, 69);
	insertHeadP(&listB, 5);
	insertHeadP(&listB, 1);
	insertHeadP(&listB, 33);
	insertHeadP(&listB, 7);
	insertHeadP(&listB, 5);
	insertHeadP(&listB, 9);
	insertHeadP(&listB, 6);
	insertHeadP(&listB, 12);

	printf("result: %d\n", function(listA, listB));
	return 0;
}

void insertHeadP(lista *l, int element) {
	struct list *temp; //new list named temp
	//other version of same line above:     list temp;
	temp = (lista) malloc(sizeof(struct list)); //allocates memory for a new list
	temp->num = element; //points to the first element of the list and sets it as the element in input
	temp->next = *l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	*l = temp;
}

int function(lista listA, lista listB) {
	int check = 1;
	lista temp = listB;
	while (listA != NULL) {
		while (temp != NULL && check == 1) {
			if (listA->num == temp->num) {
				check = 0;
				printf("found %d\n", listA->num);
			} else {
				check = 1;
				printf("not found in b=%d\n", temp->num);
				temp = temp->next;
			}
		}
		if (check == 1) {
			printf("lista a non è strettamente contenuta in b\n");
			return 0;
		}
		listA = listA->next;
		temp = listB;
		check = 1;
	}
	printf("lista a è strettamente contenuta in b\n");
	return 1;
}
