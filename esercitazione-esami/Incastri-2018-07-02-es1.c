/*
   INCASTRI è un semplice rompicapo con le seguenti regole. Per risolvere il rompicapo, è necessario posizionare il set di
   pezzi fornito su una griglia di dimensione 5x5. Ogni pezzo può essere posizionato ovunque, ma (i) non è possibile ruotarlo
   e (ii) non può sovrapporsi (neanche parzialmente) ad altri pezzi.
   I pezzi del gioco sono di tre diverse forme (quadrato, barra verticale e barra orizzontale) come mostrato dalla seguente
   figura (in cui è anche riportato un numero che identifica ciascuno dei tre diversi pezzi del gioco):

   Il rompicapo viene risolto se tutti i pezzi vengono posizionati sulla griglia, come nel seguente esempio (attenzione,
   perché la soluzione sia valida NON è necessario che la griglia sia completamente piena):

   Si assuma di rappresentare la griglia 5x5 nella memoria del calcolatore come una matrice di interi, in cui il valore 0 è usato
   per rappresentare una cella vuota e il valore 1 per rappresentare una cella occupata; inoltre si assuma di rappresentare
   con il valore 1, 2 e 3 rispettivamente i pezzi di forma quadrata, barra verticale e barra orizzontale.
   Implementare in C le seguenti due funzioni:
   A) int fit(int G[5][5], int p, int i, int j)
   che restituisce 1 se è possible posizionare nella cella <i,j> della griglia G, un pezzo la cui forma è definita dal
   parametro di ingresso p, viceversa restituisce 0.
   Note. La matrice G può avere delle celle occupate (cioè non reppresenta necessariamente una griglia
   completamente vuota). Per posizionare un pezzo nella cella <i,j>, si intende posizionare il pezzo nella griglia in
   modo che la sua cella in alto a sinistra si trovi nella posizione <i,j> della griglia.
   B) int solve(int G[5][5], int p[], int npezzi)
   che restituisce 1 se è possibile posizionare tutti i pezzi specificati nel vettore di ingresso p di dimensione npezzi,
   all’interno della griglia G. Viceversa, la funzione restituisce 0.
   Nell’implementare questa funzione è possibile utilizzare sia la funzione implementata al punto A sia le seguenti
   due funzioni (che non è necessario implementare):
   - int addp(int G[5][5], int p, int i, int j) che aggiunge un pezzo di forma p alla griglia G
   in posizione <i,j> (occupando le opportune celle). La funzione restituisce 1 se ha successo, 0 altrimenti.
   - int removep(int G[5,5], int p, int i, int j)che rimuove un pezzo di forma p alla griglia
   G in posizione <i,j> (liberando le opportune celle). La funzione restituisce 1 se ha successo, 0 altrimenti.
   Note. Il problema può essere risolto ricorsivamente: è possibile posizionare sulla griglia G, i pezzi contenuti nel
   vettore p, se esiste almeno una posizione <i,j> di G dove può essere posizionato il primo pezzo di p ed è possibile
   posizionare tutti i rimanenti pezzi in p nella griglia G (in cui è stato aggiunto il primo pezzo in posizione <i,j>).
 */

//solve here
//0: cell is empty
//1: cell is full
#include <stdio.h>
int fit(int G[5][5], int p, int i, int j);
int solve(int G[5][5], int p[], int npezzi);

int main() {
    int mat[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int pieces[8] = {3,2,3,3,3,1,2,3};
    int npezzi = 8;
    printf("solvable? \n", solve(mat, pieces, npezzi));
    return 0;
}

int fit(int G[5][5], int p, int i, int j)
{
if
(i<0 || j<0 || i>4
return 0;
if (p==1)
if (i<4 && j<4)
return (G[i][j]==0
if (p==2)
if (i<3)
return (G[i][j]==0
if (p==3)
if (j<3)
return (G[i][j]==0
}

int solve(int G[5][5], int p[], int npezzi)
{
if (npezzi==0)
return 1;
else
{
int i,j;
for (i=0; i<5; i++)
for (j=0; j<5; j++)
if (addp(G,p[0],i,j))
{
if (solve(G,p+1,npezzi-1))
{
removep(G,p[0],i,j);
return 1;
}
else
removep(G,p[0],i,j);
}
return 0;
}
}

int myfit(int mat[5][5], int piece, int i, int j) {
	//error here: i forgot to check these conditions
	if (i<0 || j<0 || i>=5 || j>=5) {
		return 0;
	} else
		switch (piece) {
		case 1: { //square 2x2
            if (!(i >=4 || j>=4)) //error: i forgot to check the boundaries of the piece
			if (mat[i][j] == 0 && mat[i+1][j] == 0 && mat[i][j+1] == 0 && mat[i+1][j+1]) {
				return 1; //good position
			} else {
				return 0; //bad position
			}
		};
		case 2: { //vertical, 1x3
            if (!(i>=3))
			if (mat[i][j] == 0 && mat[i+1][j] == 0 && mat[i+2][j]) {
				return 1; //good position
			} else {
				return 0; //bad position
			}
		};
		case 3: { //horizontal, 3x1
            if (!(j>=3))
			if (mat[i][j] == 0 && mat[i][j+1] == 0 && mat[i][j+2]) {
				return 1; //good position
			} else {
				return 0; //bad position
			}
		};
		}
}
