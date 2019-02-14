/*
   Si implementi la funzione lista interseca(lista a, lista b), che riceve in ingresso la testa di due liste (a e
   b) e restituisce la testa di una lista che contiene tutti gli elementi che sono presenti sia nella lista a che nella lista b.
   Note. Gli elementi nella lista restituita possono comparire in qualsiasi ordine. È possibile richiamare una funzione per
   l’inserimento di un elemento (in coda o in testa), ma è necessario fornirne l’implementazione.
 */
#include <stdlib.h>

struct nodo
{
	int data;
	struct nodo *next;
};
typedef struct nodo *lista;

lista interseca(lista a, lista b) {
	lista intersezione = NULL, temp = b;
	while (a!= NULL) {
		while (temp!= NULL) {
			if (temp->data == a->data) {
				intersezione = inserisciTesta(intersezione, a->data);
			}
			temp = temp->next;
		}
		a = a->next;
		temp = b;
	}
	return intersezione;
}

lista inserisciTesta(lista l, int data) {
	lista *temp = malloc(sizeof(struct nodo));
	temp->data = data;
	temp->next = l;
	return temp;
}
