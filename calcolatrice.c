#include <stdio.h>

int main()
{
	float a, b;
	char o;

	printf("Inserisci 2 numeri reali\n");
	scanf("%f%*c", &a);
	scanf("%f%*c", &b);

	printf("Inserisci un operatore matematico\n");
	scanf("%c%*c", &o);

	switch (o) {
	case '+':
		printf("Risultato: %f\n", a+b);
		break;
	case '-':
		printf("Risultato: %f\n", a-b);
		break;
	case '*':
		printf("Risultato: %f\n", a*b);
		break;
	case '/':
		printf("Risultato: %f\n", (float)a/b);
		break;
	default:
		printf("Operatore non valido");
	}

	return 0;
}
