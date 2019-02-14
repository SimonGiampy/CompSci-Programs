/*
   Si implementi la seguente funzione:
   float piccolo(float M[R][C], int i, int j)
   la funzione restituisce un elemento piccolo della matrice in ingresso M[R][C] (dove R e C sono il numero di righe e
   colonne della matrice M e sono due costanti definite precedentemente) calcolato come segue. La ricerca dell’elemento
   da restituire deve essere implementata come segue, a partire dalla posizione <i,j> della matrice M (dove i e j sono i
   parametri di ingresso della funzione). Ad ogni passo, la ricerca si sposta in una fra le posizioni adiacenti alla posizione
   corrente (muovendosi lungo le 8 direzioni possibili), scegliendo quella in cui M assume il valore minore. La ricerca non
   può proseguire in una posizione già visitata precedentemente o in cui il valore di M è maggiore di quello alla posizione
   corrente. Nel caso non vi sia, fra quelle adiacenti, una posizione che rispetta queste due condizioni, la ricerca termina e
   la funzione ritorna il valore della matrice M nella posizione corrente.
   Note. Nel caso vi siano più posizioni adiacenti con lo stesso valore minimo di M, l’algoritmo di ricerca ne sceglie una
   arbitrariamente. Quando la posizione corrente si trova sul bordo della matrice, vengono analizzate solo le celle adiacenti
   in posizioni valide.
   Esempio
   Ipotizzando i=1 e j=1, e la seguente matrice M su cui effettuare la ricerca, la ricerca restituisce 0.4
 */

#include <stdio.h>
#define R 4
#define C 4

float piccolo(float M[R][C], int i, int j);
float piccolo2(float M[R][C], int i, int j);

int main() {

	float M[R][C] =  {{1.2, 1.2, 1.2, 0.3}, {1.2, 3.4, 1.2, 0.6}, {1.2, 1.2, 1.2, 1.1}, {7.9, 0.3, 0.5, 3.7}};
	for (int i = 0; i<4; i++) {
		for (int k =0; k<4; k++) {
			printf("%.1f ", M[i][k]);
		}
		printf("\n");
	}
	printf("\n");

	printf("piccolo 1: %.1f\n", piccolo(M, 1, 1));
	printf("piccolo2: %.1f\n", piccolo2(M, 1, 1));

	return 0;
}

//professor version
float piccolo2(float M[R][C], int i, int j)
{
	int V[R*C]={0},ii,jj,imin,jmin,stop=0;
	do {
		V[i*C+j] = 1;
		stop=1;
		for (ii=i-1; ii<=i+1; ii++)
			for (jj=j-1; jj<=j+1; jj++)
			{
				if (ii>=0 && ii<R && jj>=0 && jj<C && V[ii*C+jj] == 0 &&
				    M[i][j]>=M[ii][jj] && (stop==1 || M[ii][jj]<M[imin][jmin]))
				{
					imin = ii;
					jmin = jj;
					stop=0;
				}
			}
		if (stop==0)
		{
			i = imin;
			j = jmin;
		}
	} while(stop==0);
	return M[i][j];
}

float piccolo(float M[R][C], int i, int j)  {

	int row, col;
	float current = M[i][j];
	int minI = i, minJ = j;
	int startX = i, startY = j;
	float prev = current;
	//printf("prev: %.1f\n", prev);

	do {

		for (row = startX-1; row < startX+2; row++) {
			for (col = startY-1; col < startY+2; col++) {
				if (row != R && col != C && row != -1 && col != -1) {
					if (current > M[row][col]) {
						minI = row;
						minJ = col;
						current = M[minI][minJ];
					}
				}
			}
		}
		if (current == prev) {
			return current;
		} else {
			printf("value %.1f in position [%d %d]\n", current, minI, minJ);
			startX = minI;
			startY = minJ;
			prev = current;
		}
	} while (1);

}
