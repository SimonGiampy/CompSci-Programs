/*
   Si consideri il gioco “Alberi”, costituito da una griglia quadrata, in cui in ogni elemento può esserci un albero o meno. Le dimensioni della griglia variano da gioco a gioco, ma sono di al più 12 elementi per lato. La griglia `e occupata da aree di colore diverso, cui appartengono uno o più elementi, e le regole per la corretta presenza degli alberi sono le seguenti:
   i) ci devono essere 2 alberi per riga
   ii) ci devono essere 2 alberi per colonna
   iii) ci devono essere 2 alberi per colore
   iv) negli elementi adiacenti ad un albero non ci devono essere alberi.


   Gli schemi più piccoli (con dimensione minore o uguale a 6) contengono 1 solo albero per riga, colonna e colore.

   Si realizzi un programma che acquisisce in ingresso la specifica della disposizione delle aree e dei colori (nel formato indicato di seguito) e scrive in output se lo schema ricevuto in ingresso `e corretto, 0 altrimenti. Si organizzi il codice in sottoprogrammi.
   Si suggerisce di sviluppare, tra gli altri, i seguenti sottoprogrammi:
   checkGriglia
   restitusce 1 se il numero di alberi e la loro disposizione `e corretta
   checkRiga
   restitusce 1 se il numero di alberi nella riga della griglia `e quello richiesto
   checkColonna
   restitusce 1 se il numero di alberi nella colonna della griglia `e quello richiesto
   checkColore
   restitusce 1 se il numero di alberi in un’area di colore della griglia `e quello richiesto
   checkDistanza
   restitusce 1 se quando si incontra un albero nella griglia esso non ha alberi negli elementi adiacenti.


 */

#include <stdio.h>
#include <string.h>
#define dim 5
#define num 1
typedef enum {false = 0, true = !false} bool;

void saveConfig(char *demoScheme, char scheme[dim][dim]);
void print_mat(char m[dim][dim]);
bool checkGrid(int trees[][2], int type);
bool checkColors(char scheme[dim][dim], int trees[][2]);
bool checkDistance(int trees[][2]);

int main() {
	char demoScheme[dim*dim+1] = "AABBBAAAAAAAAACDDDEEDDDEE";
	int trees[dim * num][2] = {{0,2}, {1,0}, {2,4}, {3,1}, {4,3}}; //position of trees, as xy coordinates
	char scheme[dim][dim];
	saveConfig(demoScheme, scheme); //saves the configuration of colors as a matrix of chars
	printf("check rows %d\n", checkGrid(trees, 0));
	printf("check columns %d\n", checkGrid(trees, 1));
	printf("check colors %d\n", checkColors(scheme, trees));
	printf("check distance %d\n", checkDistance(trees));
	return 0;
}

bool checkGrid(int trees[][2], int type) { //type is 0 for rows, 1 for columns
	bool check = true;
	int count;
	for (int i = 0; i < dim * num && check; i++) {
		count = 0;
		for (int k = 0; k < dim * num; k++) {
			if (trees[i][type] == trees[k][type]) {
				count++;
			}
		}
		if (count != num) { //variable number with dimension of matrix
			check = false;
		}
	}
	return check;
}

bool checkColors(char scheme[dim][dim], int trees[][2]) {
	char colors[dim * num];
	bool check = true;
	printf("colors ");
	for (int i = 0; i < dim * num; i++) {
		colors[i] = scheme[(trees[i][0])][(trees[i][1])];
		printf("%c", colors[i]);
	}
	printf("\n");

	int count, k;
	for (int i = 0; i < dim * num && check == true; i++) {
		for (k = 0, count = 0; k < dim * num; k++) {
			if (colors[i] == colors[k]) {
				count++;
			}
		}
		if (count != num) {
			check = false;
		}
	}
	return check;
}

bool checkDistance(int trees[][2]) {
	bool check = true;
	for (int i = 0; i < dim * num && check == true; i++) {
		int x = trees[i][0];
		int y = trees[i][1];
		for (int k = 0; k < dim * num; k++) {
			int x2 = trees[k][0];
			int y2 = trees[k][1];
			//printf("x %d y %d --- x2 %d y2 %d\n", x,y,x2,y2);
			if (k!=i && ((x==x2 || x==x2+1 || x==x2-1) && (y==y2 || y==y2+1 || y==y2-1))) {
				check = false;
			}
		}
	}
	return check;
}

void saveConfig(char *demoScheme, char scheme[dim][dim]) {
	int j = 0,k =0;
	for(unsigned int i=0; i < strlen(demoScheme); i++) {
		k = i % dim;
		j = i / dim;
		scheme[j][k] = demoScheme[i];
		printf("%c ", scheme[j][k]);
		if (k==dim-1) {
			printf("\n");
		}
	}
}

void print_mat(char m[dim][dim]) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("\t%c", m[i][j]);
		}
		printf("\n");
	}
}
