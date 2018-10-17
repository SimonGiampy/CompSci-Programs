#include <stdio.h>

#define vero 1

int main() {
	char c;
	scanf("%c", &c);
	printf("equivalente: %c\n", c+32);


	enum {falso, vero} num1, num2;
	num1 = 8;
	num2 = 5;
	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);

	typedef enum {lun,mar,merc,gio,ven,sab,dom} giorno;
	giorno oggi;
	oggi = gio;

	enum {rosso, giallo, blu} semaforo1, semaforo2, semaforo3;


	const int pi = 3.14;
	return 0
}
