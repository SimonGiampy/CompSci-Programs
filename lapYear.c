#include <stdio.h>

int main() {
	printf("\n");

	//scrivere un programma che dato un int, verifica se l'anno è bisestile oppure no
	//ma gli anni secolari sono bisestili solo se divisibili per 400 (quindi non solo per 100)

	int anno = 0;
	printf("inserisci anno: ");
	scanf("%d", &anno);

	int bisestile = 0;

	if (anno % 400 == 0) {
		//a year which is a multiple of 400 is a lap year, while a year multiple of 100 (and not 400) is not
		bisestile = 1;
	} else if (anno % 4 == 0 && anno % 100 != 0) {
		bisestile = 1;
	}

	if (bisestile == 1) {
		printf("anno è bisestile!\n");
	} else {
		printf("anno non è bisestile\n");
	}

	return 0;
}
