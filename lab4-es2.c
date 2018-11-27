#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int data;
struct nodo {
	data el;
	struct nodo *next;
};
typedef struct nodo *lista;

// Tutte le seguenti funzioni hanno un parametro intero ric se uguale ad 1 viene
// eseguita la versione ricorsiva, altrimenti vieni eseguita quella iterativa

// Calcola e ritorna la lunghezza della lista
int lunghezza (lista l, int ric);

// Ricerca (il primo) elemento el nella lista l e ritorna il puntatore a
// quell'elemento (o NULL se l'elemento non è presente)
lista ricerca (lista l, data el, int ric);

// Inserisce un elemento el in testa alla lista l modificandola
void inserisci_in_testa (lista *l, data el);

// Inserisce un elemento el in coda alla lista l modificandola
void inserisci_in_coda (lista *l, data el, int ric);

// Rimuove l'elemento in testa alla lista l modificandola
void rimuovi_in_testa (lista *l);

// Rimuove l'elemento in coda alla lista l modificandola
void rimuovi_in_coda (lista *l, int ric);

// Rimuove (il primo) elemento el nella lista l (se presente) modificandola
void rimuovi (lista *l, data el, int ric);

// Stampa il contenuto della lista l
void stampa (lista l, int ric);


/* VERSIONI ITERATIVE/RICORSIVE DA IMPLEMENTARE */
int lunghezza_ric(lista l);
int lunghezza_iter(lista l);

lista ricerca_ric(lista l, data el);
lista ricerca_iter(lista l, data el);

void inserisci_in_coda_ric (lista *l, data el);
void inserisci_in_coda_iter (lista *l, data el);

void rimuovi_in_coda_ric (lista *l);
void rimuovi_in_coda_iter (lista *l);

void rimuovi_ric (lista *l, data el);
void rimuovi_iter (lista *l, data el);

void  stampa_ric (lista l);
void  stampa_iter (lista l);

/*************************************************/

int lunghezza (lista l, int ric) {
	if (ric==1)
		return lunghezza_ric(l);
	else
		return lunghezza_iter(l);
}
lista ricerca (lista l, data el, int ric) {
	if (ric==1)
		return ricerca_ric(l,el);
	else
		return ricerca_iter(l,el);
}
void inserisci_in_coda (lista *l, data el, int ric) {
	if (ric==1)
		inserisci_in_coda_ric(l,el);
	else
		inserisci_in_coda_iter(l,el);
}
void rimuovi_in_coda (lista *l, int ric) {
	if (ric==1)
		rimuovi_in_coda_ric(l);
	else
		rimuovi_in_coda_iter(l);
}
void rimuovi (lista *l, data el, int ric) {
	if (ric==1)
		rimuovi_ric(l,el);
	else
		rimuovi_iter(l,el);
}
void stampa (lista l, int ric) {
	if (ric==1)
		stampa_ric(l);
	else
		stampa_iter(l);
}
//done
int lunghezza_ric(lista l) {
	if (l==NULL)
		return 0;
	else
		return 1 + lunghezza_ric(l->next);
}
//done
int lunghezza_iter(lista l) {
	int num = 0;
	while (l != NULL) { //iterates as long as the node in the list is not null
		//continues in this cycle as long as the list is not finished
		num++;
		l = l->next; //ppints to the next element of the list
	}
	return num;
}

lista ricerca_ric(lista l, data el) {
	if (l == NULL || l->el == el)
		return l;
	else
		return ricerca_ric(l->next,el);
}

lista ricerca_iter(lista l, data el) {
	while (l!= NULL) {
		if ((*l).el == el) {
			return l;
		} else {
			l = (*l).next;
		}
	}
	return NULL;
}

void inserisci_in_coda_ric (lista *l, data el) {
	//TODO
}

void inserisci_in_coda_iter (lista *l, data el) {


}

void inserisci_in_testa(lista *l, data el) {
	lista temp; //new list named temp
	//other version of same line above:     list temp;
	temp = NULL; //allocates memory for a new list
	temp->el = el; //points to the first element of the list and sets it as the element in input
	temp->next = *l; //the next element points to the old first element of the list
	//returns a new element of the list, which is the one inserted at the head
	*l = temp;
}

void rimuovi_in_coda_ric (lista *l) {
	//TODO
}

void rimuovi_in_coda_iter (lista *l) {
	//TODO
}

void rimuovi_in_testa (lista *l) {
	//TODO
}

void rimuovi_ric (lista *l, data el) {
	//TODO
}

void rimuovi_iter (lista *l, data el) {
	//TODO
}

void  stampa_ric (lista l) {
	//TODO
}

void  stampa_iter (lista l) {
	//TODO
}





int main() {
	lista l=NULL;
	int i,n,ric;
	srand(time(NULL));
	printf("Che versione vuoi testare? (0 iterativa, 1 ricorsiva) ");
	scanf("%d%*c",&ric);
	n = rand()%10 +1;
	for (i=0; i<n; i++) {
		int x = rand()%10;
		if (rand()%2>0) {
			printf("Inserisci in testa %d\n",x);
			inserisci_in_testa(&l,x);
		} else {
			printf("Inserisci in coda %d\n",x);
			inserisci_in_coda(&l,x,ric);
		}
		printf("Lista (l=%d): ",lunghezza(l,ric));
		stampa(l,ric);
	}
	//ricerca
	for (i=0; i<n; i++) {
		int x = rand()%10;
		printf("Ricerca di %d: ",x);
		if (ricerca(l,x,ric)==NULL)
			printf("non trovato\n");
		else
			printf("trovato\n");
	}

	for (i=0; i<n+n/2; i++) {
		int choice = rand()%3;
		if (choice==0)      {
			printf("Rimuovi in testa\n");
			rimuovi_in_testa(&l);
		}
		else if (choice==1) {
			printf("Rimuovi in coda\n");
			rimuovi_in_coda(&l,ric);
		} else {
			int x = rand()%10;
			printf("Rimuovi %d\n",x);
			rimuovi(&l,x,ric);
		}
		printf("Lista (l=%d): ",lunghezza(l,ric));
		stampa(l,ric);
	}

	return 0;
}
