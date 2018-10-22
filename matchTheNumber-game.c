/*game match the number
   ci sono due giocatori

   il giocatore 1 inserisce due numeri interi non negativi p e t compresi tra 0 e 1000
   nella seconda fase di gioco, il giocatore 2 deve cercare di ottenere il numero target t partendo da p in meno di 10 mosse
   ad ogni mossa, il giocatore 2 può aggiornare il numero p eseguendo una delle due operazioni:
   1) aggiungi 1 a p
   2) moltiplica p per 2
   3) aggiorna p con il resto della divisione di p per 31

   se il giocatore 2 ottiene il numero t in meno di 10 mosse vince, altrimenti vince il giocatore 1
 */

#include <stdio.h>

int leggiNumero(int min, int max);

int main() {
	int p, t;

	//fase1
	printf("giocatore 1: inserisci numero partenza\n");
	p = leggiNumero(0, 1000);
	printf("giocatore 1: inserisci numero target\n");
	t = leggiNumero(0, 1000);

	//fase 2
	int scelta = 0;
	int mosse = 0;

	do {
		printf("scegli le opzioni: 1 (p++) 2 (p*=2) 3 (p mod=31)\n");
		scanf("%d", &scelta);
		mosse++;
		switch (scelta) {
		case 1: p++; break;
		case 2: p*=2; break;
		case 3: p%=31; break;
		}
		printf("p = %d\n", p);

		if (p == t) {
			printf("vinto in %d mosse\n", mosse);
			break;
		} else if (mosse == 10) {
			printf("perso\n");
			mosse++;
		}
	} while(mosse <= 10);

	return 0;
}

int leggiNumero(int min, int max) {
	int n;
	do {
		printf("inserisci numero tra %d e %d: ", min, max);
		scanf("%d", &n);
	} while(n < min || n > max);
	return n;
}
