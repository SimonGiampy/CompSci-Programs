/*
   i consideri la seguente struttura dati per rappresentare una lista di numeri interi:
   struct nodo
   {
   int data;
   struct nodo *next;
   };
   typedef struct nodo *lista;
   Si implementi la funzione lista unici(lista a, lista b), che riceve in ingresso la testa di due liste (a e b) e
   restituisce la testa di una nuova lista che contiene solo gli elementi che sono presenti soltanto nella lista a oppure soltanto
   nella lista b.
   Note. Gli elementi nella lista restituita possono comparire in qualsiasi ordine. È possibile utilizzare funzioni di supporto
   (ad esempio per inserire un elemento nella lista), parchè ne sia fornita l’implementazione. Si può assumere che le liste
   non contengano elementi ripetuti.
 */
#include "../linked-list.h"
/*
   struct node {
    int data;
    struct node *next;
   };
   typedef struct node *list;
 */
list unique(list a, list b);
int cerca(list a, int data);
list unici(list a, list b);

int main() {

	list l1 = NULL, l2 = NULL;     //head of a new list is initialized as NULL
	l1 = insertHead(l1, 5);
	insertTailP(&l1, 4);
	l1 = insertTailRecursive(l1, 7);
	l1 = insertHead(l1, 6);
	insertHeadP(&l1, 11);
	l1 = insertTailRecursive(l1, -3);
	printf("adding some elements l1\n");
	printList(l1);
	printf("adding some elements l2\n");
	insertHeadP(&l2, 12);
	insertHeadP(&l2, 8);
	insertHeadP(&l2, 11);
	insertTailP(&l2, 8);
	insertTailP(&l2, 7);
	insertTailRecursiveP(&l2, 0);
	printList(l2);
	printf("unique elements: \n");
	list new = unique(l1, l2);
	printList(new);
	list new2 = unici(l1, l2);
	printList(new2);
	return 0;
}

list unique(list a, list b) {
	list new = NULL, a2 = a, temp = b;
	while (a != NULL) {
		int unique = 0;
		while (temp!= NULL && unique==0) {
			if (a->element == temp->element) {
				unique++;
			}
			temp = temp->next;
		}

		if (unique == 0) {
			//insert new value
			list temp2 = malloc(sizeof(struct node));
			temp2->element = a->element;
			temp2->next = new;
			new = temp2;
		}
		a = a->next;
		temp = b;
	}

	temp = a2;
	while (b != NULL) {
		int unique = 0;
		while (temp!= NULL && unique==0) {
			if (b->element == temp->element) {
				unique++;
			}
			temp = temp->next;
		}

		if (unique == 0) {
			//insert new value
			list temp2 = malloc(sizeof(struct node));
			temp2->element = b->element;
			temp2->next = new;
			new = temp2;
		}
		b = b->next;
		temp = a2;
	}

	return new;
}

int cerca(list a, int data)
{
	if (a==NULL)
		return 0;
	else if (a->element == data)
		return 1;
	else
		return cerca(a->next, data);
}
list unici(list a, list b)
{
	list c=NULL, cur;
	cur = a;
	while (cur!=NULL)
	{
		if (cerca(b, cur->element)==0)
			insertHeadP(&c, cur->element);
		cur = cur->next;
	}
	cur = b;
	while (cur!=NULL)
	{
		if (cerca(a, cur->element)==0)
			insertHeadP(&c, cur->element);
		cur = cur->next;
	}
	return c;
}
