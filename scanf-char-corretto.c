#include <stdio.h>

int main() {
	//prima di prendere in input un carattere, la scanf va a vedere se nell'ultimo spazio di memoria c'è un carattere valido
	//infatti prende anche \n come carattere valido, quindi manda accapo senza dare la possibilità di scrivere un altro carattere
	//quindi per leggere lo scanf basta specificare il carattere come %c%*c anzichè %c e basta

	char char1, char2, char3;
	printf("inserisci char1: ");
	scanf("%c%*c", &char1);
	printf("inserisci char2: ");
	scanf("%c%*c", &char2);
	printf("inserisci char3: ");
	scanf("%c%*c", &char3);

	printf("%c %c %c\n", char1, char2, char3);




	return 0;
}
