#include <stdio.h>
#include <string.h>

#define MAX_DIM 12

typedef struct {
	char colore;
	int albero;
} cella;

int leggiGriglia(cella griglia[][MAX_DIM], int *dim);
int checkGriglia(cella griglia[][MAX_DIM], int dim);
int checkRiga(cella griglia[][MAX_DIM], int dim, int riga);
int checkColonna(cella griglia[][MAX_DIM], int dim, int colonna);
int checkColore(cella griglia[][MAX_DIM], int dim, char colore);
int checkDistanza(cella griglia[][MAX_DIM], int dim, int riga, int colonna);
int checkNumAlberi(int dim, int n_alberi);
int max(int a, int b);
int min(int a, int b);

int main()
{
	cella griglia[MAX_DIM][MAX_DIM];
	int dim, ris, corretta;

	ris = leggiGriglia(griglia, &dim);
	if(!ris) {
		printf("La griglia in input non e' formattata correttamente.\n");
	} else {
		corretta = checkGriglia(griglia, dim);

		if(corretta)
			printf("La griglia e' corretta!\n");
		else
			printf("La griglia non e' corretta.\n");
	}
}

int leggiGriglia(cella griglia[][MAX_DIM], int *dim)
{
	int i, riga, colonna, n_alberi;
	char str[MAX_DIM+1];

	// leggo la dimensione della griglia
	scanf("%d", dim); //dim è già l'indirizzo della variabile

	if(*dim < 1 || *dim > MAX_DIM)
		return 0; // dimensione griglia non valida

	// leggo i colori della griglia ed inizializzo il numero di alberi a 0
	for(riga = 0; riga < *dim; riga++) {
		scanf("%s", str);
		if(strlen(str) != *dim)
			return 0; // lunghezza stringa dei colori non corretta

		for(colonna = 0; colonna < *dim; colonna++) {
			griglia[riga][colonna].colore = str[colonna];
			griglia[riga][colonna].albero = 0;
		}
	}

	// leggo il numero di alberi
	scanf("%d", &n_alberi);

	// leggo le coordinate di tutti gli alberi e li inserisco nella griglia
	for(i = 0; i < *dim; i++) {
		scanf("%d", &riga);
		scanf("%d", &colonna);

		if(riga < 0 || colonna < 0 || riga >= *dim || colonna >= *dim)
			return 0; // coordinate albero fuori dalla griglia

		griglia[riga][colonna].albero = 1;
	}

	return 1; // lettura corretta
}


int checkGriglia(cella griglia[][MAX_DIM], int dim)
{
	//può ancora essere ottimizzata, interrompendo il controllo se nel frattempo si è già visto che non va bene
	int riga, colonna;
	int corretto = 1;

	// verifico che ciascuna riga abbia il numero di alberi corretto
	for(riga = 0; riga < dim && corretto; riga++)
		corretto = checkRiga(griglia, dim, riga);

	// verifico che ciascuna colonna abbia il numero di alberi corretto
	for(colonna = 0; colonna < dim && corretto; colonna++)
		corretto = checkColonna(griglia, dim, colonna);

	// verifico che il numero di alberi per ciascun colore presente
	// nella griglia sia corretto
	for(riga = 0; riga < dim && corretto; riga++)
		for(colonna = 0; colonna < dim && corretto; colonna++)
			corretto = checkColore(griglia, dim, griglia[riga][colonna].colore);

	// verifica che ogni albero sia distanziato correttamente dagli altri
	for(riga = 0; riga < dim && corretto; riga++)
		for(colonna = 0; colonna < dim && corretto; colonna++)
			if(griglia[riga][colonna].albero > 0)
				corretto = checkDistanza(griglia, dim, riga, colonna);

	return corretto;
}

int checkNumAlberi(int dim, int n_alberi)
{
	return (dim <= 6 && n_alberi == 1) || (dim > 6 && n_alberi == 2);
}

int checkRiga(cella griglia[][MAX_DIM], int dim, int riga)
{
	int colonna, n_alberi = 0;
	for(colonna = 0; colonna < dim; colonna++)
		if(griglia[riga][colonna].albero > 0)
			n_alberi++;

	return checkNumAlberi(dim, n_alberi);
}

int checkColonna(cella griglia[][MAX_DIM], int dim, int colonna)
{
	int riga, n_alberi = 0;
	for(riga = 0; riga < dim; riga++)
		if(griglia[riga][colonna].albero > 0)
			n_alberi++;

	return checkNumAlberi(dim, n_alberi);
}

int checkColore(cella griglia[][MAX_DIM], int dim, char colore)
{
	int riga, colonna, n_alberi = 0;
	for(riga = 0; riga < dim; riga++)
		for(colonna = 0; colonna < dim; colonna++)
			if(griglia[riga][colonna].colore == colore &&
			   griglia[riga][colonna].albero > 0)
				n_alberi++;

	return checkNumAlberi(dim, n_alberi);
}

int min(int a, int b) {
	//return a < b ? a : b;
	if (a<b) {
		return a;
	} else {
		return b;
	}
}

int max(int a, int b)
{
	//return a > b ? a : b;
	if (a>b) {
		return a;
	} else {
		return b;
	}
}

int checkDistanza(cella griglia[][MAX_DIM], int dim, int riga, int colonna)
{
	int r, c, n_alberi;
	n_alberi = 0;
	for(r = max(0, riga - 1); r <= min(riga + 1, dim - 1); r++)
		for(c = max(0, colonna - 1); c <= min(colonna + 1, dim - 1); c++)
			if(griglia[r][c].albero > 0 && r != riga && c != colonna)
				n_alberi++;

	return n_alberi == 0;
}
