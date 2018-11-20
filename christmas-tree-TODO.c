/*
   Scrivere una funzione ricorsiva che, dato un numero intero N, stampa a video la sequenza “+*|*+”, dove * corrisponde ad un numero i=0,1,...N di segni ‘-’.
   Creare quindi una ulteriore funzione, che riceve in ingresso un intero M (maggiore o uguale a 1) e utilizza la funzione precedente per stampare un albero di Natale di M righe.
   Ad esempio l’output per M=4 dovrà essere:
 +
 +|+
 +-|-+
 +--|--+
 +---|---+
   Nota: Provare ad implementare ricorsivamente anche la funzione che stampa l’intero albero di Natale.
 */
#include <stdio.h>

void printRow(int n);

int main() {
	int length;
	scanf("%d", &length);

	printRow(length);

	return 0;
}

void printRow(int n) {
	if (n == 1) {
		printf("    +\n");
	} else {

	}
}

/*temp:
   for (int i = 0; i <= n; i++) {
   if (i==0 || i==n) {
     printf("+");
   } else if (n % 2 != 0 && i == (n/2)) {
     printf("|-");
     i++;
   } else if (n % 2 == 0 && i == (n/2)) {
     printf("|");
     i++;
   } else {
     printf("-");
   }
   }
 */
