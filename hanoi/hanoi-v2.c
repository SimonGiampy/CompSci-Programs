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
void showState(int a[N], int b[N], int c[N]);
int getTop(int peg[N]);
bool isEmpty(int peg[N]);

void move(int start[N], int target[N]);
void moveRecursive(int amount, int a[N], int b[N], int c[N]);

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
	showState(a, b, c);
	moveRecursive(N, a, b, c);
	return 0;
}


void moveRecursive(int amount, int a[N], int b[N], int c[N]) {
	if (amount == 1) {
		move(a, c); //a = start, b = spare, c = target
		showState(a, b, c);
		return;
	}
	moveRecursive(amount-1, a, c, b);
	moveRecursive(1, a, b, c);
	moveRecursive(amount-1, b, a, c);
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

void move(int start[N], int target[N]) { //moves a disk for the peg start to the destination peg
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
}

void showState(int a[N], int b[N], int c[N]) {
	//the order with which the arrays are displayed is wrong
	debugState('A', a);
	debugState('B', b);
	debugState('C', c);

	for (int i = 1; i <= (N+1)*4; i++) {
		printf("-");
	}
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
