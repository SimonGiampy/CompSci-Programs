#include <stdio.h>

int main() {
	/*inserimento di due numeri interi, ed esegue operazione richiesta:
	   con s effettua la somma
	   con p effettua il prodotto
	   mostra poi il risultato, o mostra un errore se viene digitato un carattere diverso da s o p
	 */

	int a, b;
	printf("\n");
	printf("inserisci a: ");
	scanf("%d", &a);
	printf("inserisci b: ");
	scanf("%d%*c", &b); //%*c evita di leggere \n nello strem di input, che poi viene preso dallo scanf(%c) successivo

	printf("inserisci operazione da fare (s o p): ");
	char operazione;
	scanf("%c", &operazione);
	int result;

	if (operazione == 's' || operazione == 'p') {
		if (operazione == 's') {
			result = a+b;
			printf("il risultato è %d\n", result);
		} else {
			result = a*b;
			printf("il risultato è %d\n", result);
		}
	} else {
		printf("carattere non valido\n");
	}

	return 0;
}
