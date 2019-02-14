#include <stdio.h>
#include <math.h> //add -lm as gcc compiler parameter
#include <stdlib.h>
#define N 6 //number of disks to play with

typedef enum {false = 0, true = !false} bool;

void showState(int a[N], int b[N], int c[N]);
void debugState(char peg, int vector[N]);
void move(int start[N], int target[N]);
void binary(int value, int a[N], int b[N], int c[N]);
int sum(int b1, int b2);
int nthDigit(int number, int position);
int findOrder(int n);
int findChange(int n1, int n2);
int getTop(int peg[N]);
char getRightPeg(char peg);
int* getArray(char letter, int a[N], int b[N], int c[N]);
bool isEmpty(int peg[N]);
bool isGameCompleted(int binaryState);


int main() {
	//initialization
	int a[N], b[N], c[N];
	for (int i  = 0; i < N; i++) {
		a[i] = N-i;
		b[i] = 0;
		c[i] = 0;
	}

	showState(a, b, c); //shows initial state
	binary(0, a, b, c); //starts the game with the binary value set ot zero
	return 0;
}

void binary(int value, int a[N], int b[N], int c[N]) { //main calculations go here
	//if the games is completed, stops the execution of this function
	if (isGameCompleted(value)) {
		return; //stops the program, and goes back to main
	}

	//associate pegs to the binary state
	int newValue = sum(value, 1); //adds 1 to the value in input
	int disk = findChange(value, newValue); //the position of the changed digit corresponds to the disk to move


	bool found = false;
	char startPeg, destinationPeg;
	//this for loop finds where is the disk located (in which peg)
	for (int i  = 0; i < N && !found; i++) {
		if (a[i] == disk) {
			found = true;
			startPeg = 'a';
		} else if (c[i] == disk) {
			found = true;
			startPeg = 'c';
		} else if (b[i] == disk) {
			found = true;
			startPeg = 'b';
		}
	}

	//calculate destintion peg according to the value of the disk
	char rightPeg = getRightPeg(startPeg);
	if (isEmpty(getArray(rightPeg, a, b, c)) || getTop(getArray(rightPeg, a, b, c)) > disk) {
		destinationPeg = rightPeg;
	} else {
		destinationPeg = getRightPeg(rightPeg); //it's on the other peg, not the one on the immediate left
	}

	move(getArray(startPeg, a, b, c), getArray(destinationPeg, a, b, c)); //apply calculated movemove
	showState(a, b, c); //shows the move done
	binary(newValue, a, b, c); //goes forward in the game, by calling itself recursively
}

bool isGameCompleted(int binaryState) { //returns true if the games is completed
	//the game is completed when the binary state is equal to 2^N-1 (written in binary)
	//which is the same as saying that binary state ha N digits, all equal to one
	for (int i = N; i >= 1; i--) {
		if (nthDigit(binaryState, i) != 1) { //checks if every digit is equal to 1
			return false;
		}
	}
	return true;
}

char getRightPeg(char peg) { //find the peg on the right of the one in input
	switch (peg) {
	case 'a': return 'b'; break;
	case 'b': return 'c'; break;
	case 'c': return 'a'; break;
	}
}

bool isEmpty(int peg[N]) { //returns true is the input peg is empty, false otherwise
	for (int i = 0; i < N; i++) {
		if (peg[i] != 0) {
			return false;
		}
	}
	return true;
}

int* getArray(char letter, int a[N], int b[N], int c[N]) { //converts a character in the corresponding array, which has the same letter
	switch (letter) {
	case 'a': return a; break;
	case 'b': return b; break;
	case 'c': return c; break;
	}
}

int getTop(int peg[N]) { //return the disk placed on top of a peg
	for (int i = N-1; i >= 0; i--) {
		if (peg[i] != 0) {
			return peg[i];
		}
	}
	return 0; //is peg is empty returns 0
}

int findChange(int n1, int n2) { //returns the position of the first digit that changes between n1 and n2, read from left to the right
	bool found = false;
	int i = findOrder(n1)+1; //difference between the two orders is at maximum 1
	while (!found) {
		if (nthDigit(n1, i) != nthDigit(n2, i)) { //one of the two digits is different from the other
			found = true;
		} else {
			i--;
		}
	}
	return i; //i is the position in the number
}

int sum(int b1, int b2) { //sums two positive integer numbers in binary
	int orderb1 = findOrder(b1);
	int orderb2 = findOrder(b2);
	int max = orderb1; //calculates the biggest order of magnitude between b1 and b2
	if (max < orderb2) {
		max = orderb2;
	}
	int result = 0, carry = 0, sum = 0; //these are needed to calculate the result

	for (int i = 1; i <= max+1; i++) { //for each digit calculates the sum, in the classic "analogic" way
		int a = nthDigit(b1, i); //the digit to be summed, from the right
		int b = nthDigit(b2, i); //the other digit to be summed, under value a

		switch (a+b) { //if the digit that are summed up are 1 + 1, or 1 + 0, or 0 + 0
		case 2: case 0: { //if a+b == 2 || 0, which means if a and b == 1 or and b == 0
			sum = carry;
			carry = (int) a+b/2;
		}; break;
		case 1: { //if a or b == 0
			sum = abs(carry-1); //carry remains the same
		}; break;
		}

		result = result + sum * pow(10, i-1); //partial result is calculated
	}
	return result; //this is the result, a binary number, treated as decimal by the program
}

int nthDigit(int number, int position) { //the position is set from the right to the left, in ascending order
	int digit = ((int) number / (pow(10, position-1)));
	return digit % 10;
}

int findOrder(int n) { //calculates order of magnitude of a given number
	int order = 1; //starts from 1, which indicates a single digit number
	bool found = false;
	while (!found) {
		if (n / 10 < 1) {
			found = true;
		} else {
			n = n / 10;
			order++;
		}
	}
	return order;
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

void showState(int a[N], int b[N], int c[N]) { //shows the values for each array (peg)
	debugState('A', a);
	debugState('B', b);
	debugState('C', c);

	for (int i = 1; i <= (N+1)*4; i++) printf("-"); //separation between the moves
	printf("\n");
}

void debugState(char peg, int vector[N]) { //used just for debugging
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
