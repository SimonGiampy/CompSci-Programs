//input di 3 numeri, e dice se la sequenza è crescente oppure descrescente, oppure nessuno dei due casi
//si termina la sequenza con l'input di uno 0

#include <stdio.h>

int main() {

	int continua = 0;
	int i = 0;

	int a = 0, b = 0, c, change;

	int risultato = 0; // = 1 se crescente, 2 se descrescente, 3 niente

	printf("scrivi n:%d: \n", i);
	scanf("%d", &a);
	++i;

	do {
		printf("scrivi n:%d: \n", i);
		scanf("%d", &b);
		++i;

		if (b == 0) {
			break;
		}

		if (i > 2) {
			if (a < b && risultato == 1) {
				//avanti
			} else if (a > b && risultato == 2) {
				//avanti
			} else if (a < b && risultato != 1) {
				risultato = 3;
			}
		} else {
			if (a < b) {
				risultato = 1;
			} else if (a > b) {
				risultato = 2;
			} else {
				risultato = 3;
			}

			change = a;
			a = b;
			b = change;
		}
		/*
		   if (b < 0) {
		    printf("rimmetti il numero\n");
		    i--;
		   } else if (b == 0 && risultato == 0) {
		    continua = 1;
		    risultato = 3;
		   } else {
		    if (a < b && risultato == 1) {
		        i++;
		    } else if (a > b && risultato == 2) {
		        i++;
		    } else if (a == b) {
		        risultato = 3;
		    }
		   }
		 */
	} while (continua == 0);

	switch (risultato) {
	case 1: printf("crescente\n"); break;
	case 2: printf("descrescente\n"); break;
	case 3: printf("non descrescente nè crescente\n");
	}

	return 0;
}
