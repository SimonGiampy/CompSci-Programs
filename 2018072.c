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

   pezzi: 1 se quadrato (2x2), 2 se verticale (1x3), 3 se orizzontale (3x1)
 */


int fit(int matrix[5][5], int p, int i, int j) {

	if (i<0 || j<0 || i>4 || j>4) {
		return 0;
	}

	if (matrix[i][j] != 0) {
		return 0;
	}

	if (p == 1) {
		//i+1<5 and j+1<5 checks the border of the matrix, so there isn't any bug that access outside the borders of the matrix
		//the other conditions check if the adjacent cells are free and not occupied by any other piece
		return i+1<5 && j+1<5 && matrix[i][j+1] == 0 && matrix[i+1][j] == 0 && matrix[i+1][j+1] == 0; //return 1 if the condition is met (true), otherwise 0
	}

	if (p == 2) {
		//other kind of piece of the puzzle
	}

	//TODO continue this program
}


int solve(int matrix[5][5], int p[], int nPieces) {
	int i = 0, j = 0, found = 0;
	if (nPieces == 1) {
		for (i = 0; i<4 && found == 0; i++) {
			for (j=0; j<4 && found == 0; j++) {
				if (fit (matrix, p[0], i, j) == 1) {
					found = 1;
				}
			}
		}
		return found;
	} else {
		for (i = 0; i<4 && found == 0; i++) {
			for (j=0; j<4 && found == 0; j++) {
				if (fit (matrix, p[0], i, j) == 1) {
					addp(matrix, p[0], i, j); //fill up the matrix
					found = solve(matrix, p+1, nPieces -1);
					if (found == 1) {
						return 1;
					} else {
						removep(matrix, p[0], i, j);
					}
				}
			}
		}
		solve(matrix, p+1, nPieces -1);
	}
	return 0;
}
