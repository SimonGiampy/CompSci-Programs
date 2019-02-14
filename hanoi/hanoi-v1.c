/*
   Esercizio 6
   Si implementi una funzione ricorsiva per risolvere la torre di hanoi che, invece di stampare a video le istruzioni testuali, stampi su un file (aperto in modalità testuale e passato come argomento alla funzione) la sequenza di mosse e lo stato dei pioli dopo ogni mossa.
   example result 1: https://drive.google.com/open?id=0B4rpp0ph9e5hMFBFRldnMHpZYWs
   example result 2: https://drive.google.com/open?id=0B4rpp0ph9e5hXzNkNE5SOUhtN28
 */
#include <stdio.h>
typedef enum {false, true} bool;
#define N 3

void debugState(char peg, int vector[N]);
void showState(int a[N], int b[N], int c[N], int config);
int getTop(int peg[N]);
bool isEmpty(int peg[N]);

void move(int start[N], int spare[N], int target[N], int config);
void moveRecursive(int amount, int a[N], int b[N], int c[N], int config);

int main() {
	//int N = 0;
	//printf("how many elements do you want to use? ");
	//scanf("%d", &N);
	//initialization
	int a[N], b[N], c[N];
	for (int i  = 0; i < N; i++) {
		a[i] = N-i;
		b[i] = 0;
		c[i] = 0;
	}

	//solving
	showState(a, b, c, 123);
	moveRecursive(N, a, b, c, 123);
	//showState(a, b, c);
	return 0;
}

void moveRecursive(int amount, int a[N], int b[N], int c[N], int config) {
	int c0, c1, c2; //case 123, case 132, case 213
	printf("config now: %d", config);
	switch (config) {
	case 213: {c0 = 213; c1 = 231; c2 = 123;}; break;
	case 132: {c0 = 123; c1 = 213; c2 = 312;}; break;
	case 123: {c0 = 132; c1 = 123; c2 = 213;}; break;
	case 231: {c0 = 231; c1 = 213; c2 = 321;}; break;
	case 312: {c0 = 312; c1 = 321; c2 = 132;}; break;
	case 321: {c0 = 321; c1 = 312; c2 = 231;}; break;
	}
	printf(" - config changed: c0=%d c1=%d c2=%d\n", c0, c1, c2);
	if (amount == 0) return;
	if (amount == 1) {
		move(a, b, c, c0); //a = start, b = spare, c = target, config =
		return;
	}
	printf("calling config c1=%d\n", c1);
	moveRecursive(amount-1, a, c, b, c1); //c1 standard = 132
	printf("calling config c0=%d\n", c0);
	moveRecursive(1, a, b, c, c0); //c0 standard = 123
	printf("calling config c2=%d\n", c2);
	moveRecursive(amount-1, b, a, c, c2); //c2 standard = 213
}

int getTop(int peg[N]) { //return the disk placed on top of a peg
	for (int i = N-1; i >= 0; i--) {
		if (peg[i] != 0) {
			return peg[i];
		}
	}
	return 0; //is peg is empty returns 0
}

bool isEmpty(int peg[N]) { //returns true is peg is empty, false otherwise
	for (int i = 0; i < N; i++) {
		if (peg[i] != 0) {
			return false;
		}
	}
	return true;
}

void move(int start[N], int spare[N], int target[N], int config) { //moves a disk for the peg start to the destination peg
	int completed = 0; //checking if the change is already done
	for (int i = N-1; i >= 0  && completed == 0; i--) { //finds last occupied element
		if (start[i] != 0) { //top non-null element found

			for (int i2 = 0; i2 < N && completed == 0; i2++) { //finds first non occupied element
				if (target[i2] == 0) { //bottom null element found
					//replacing values
					target[i2] = start[i];
					start[i] = 0;
					completed = 1;
				}
			}

		}
	}

	showState(start, spare, target, config);
}

void showState(int a[N], int b[N], int c[N], int config) {
	int first = config / 100, second = (config/10)% 10, third = (config % 100) % 10;

	switch (first) {
	case 1: debugState('A', a); break;
	case 2: debugState('A', b); break;
	case 3: debugState('A', c); break;
	}
	switch (second) {
	case 1: debugState('B', a); break;
	case 2: debugState('B', b); break;
	case 3: debugState('B', c); break;
	}
	switch (third) {
	case 1: debugState('C', a); break;
	case 2: debugState('C', b); break;
	case 3: debugState('C', c); break;
	}

	printf("config here %d%d%d\n", first, second, third);
	for (int i = 1; i <= (N+1)*4; i++) printf("-");
	printf("\n");
}

void debugState(char peg, int vector[N]) {
	printf("%c = ", peg);
	for (int i = 0; i < N; i++) {
		if (vector[i] == 0) {
			printf("- - ");
		} else {
			printf("%d - ", vector[i]);
		}
	}
	printf("\n");
}
