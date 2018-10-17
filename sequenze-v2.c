//input di 3 numeri, e dice se la sequenza è crescente oppure descrescente, oppure nessuno dei due casi
//si termina la sequenza con l'input di uno 0
#include <stdio.h>
int main() {
	int num, precedente;
	int crescente = 1, descrescente = 1;

	int i = 0;

	do {
		scanf("%d", &num);
		i++;

		if (num == 0) {
			break;
		}

		if (i>1) {
			if (num >= precedente) {
				descrescente = 0;
			}
			if (num <= precedente) {
				crescente = 0;
			}
		}

		precedente = num;
	} while (num != 0);

	if (crescente == 1) {
		printf("crescente\n");
	}
	if (descrescente == 1) {
		printf("descrescente\n");
	}
	if (crescente == 0 && descrescente == 0) {
		printf("nessuno dei due casi\n");
	}
	//fix bug: se si immette 0 fix the bug
	return 0;
}
