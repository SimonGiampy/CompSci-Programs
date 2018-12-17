/*
   Si implementi la funzione lista interseca(lista a, lista b), che riceve in ingresso la testa di due liste (a e
   b) e restituisce la testa di una lista che contiene tutti gli elementi che sono presenti sia nella lista a che nella lista b.
   Note. Gli elementi nella lista restituita possono comparire in qualsiasi ordine. È possibile richiamare una funzione per
   l’inserimento di un elemento (in coda o in testa), ma è necessario fornirne l’implementazione.
 */

//creates a newList list which is the intersection of two different lists
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node *list;

list insert(list l, int element);
list intersect (list a, list b);

list intersect (list a, list b) { //creates a new list, which has only the elements present in both list a and b
	list newList = (list) malloc(sizeof(list)); //new list created
	while (a != NULL) { //for each element in the list a
		while (b != NULL) { //for each element in the list b
			if (a->data == b->data) {
				newList = insert(newList, a->data);
			}
			b = b->next;
		}
		a = a->next;
	}

	return newList; //this is the intersection list
}

list insert(list l, int element) { //insert at the head of the list
	list temp = (list) malloc(sizeof(list));
	temp->data = element;
	temp->next = l;
	return temp;
}
