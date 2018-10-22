/*
   Scrivere un programma che chieda all’utente di inserire un numero intero n e ne calcoli la scomposizione in fattori primi (e.g., 10 = 1x2x5, 18 = 1x2x3x3).
 */

#include <stdio.h>

int primo(int n);

int main() {

	//asks the user to write a number and saves it to the variable num;
	int num;
	printf("insert: ");
	scanf("%d", &num);

	//if the number is a prime number, it shows 1 * num, so it doesn't do all the operations
	//and the program doesn't get confused
	if (primo(num)) {
		printf("1 * %d\n", num);
	}

	//checks if the number is divisible for the prime numbers below the number itself
	for (int i = num-1; i >= 1; i--) {
		//terminates the sequence with a 1 when it ends the iteration
		if (i == 1) {
			printf("1\n");
		} else {
			//shows if a determined number is prime and shows 1 or 0 (function primo)
			printf("pri(%d):%d\n", i, primo(i));
			if (primo(i)) {
				if (num % i == 0) {
					//printf("%d * ", i);
				}
			}
		}
	}
	return 0;
}

//checks if the number in input is prime
//returns 1 (is prime) and 0 (not prime)
int primo(int number) {
	//return true if number = 2, so it doesn't do all the iterations
	if (number == 2) {
		return 1;
	}

	//initialize the counter from 2 because 1 and 2 are two exceptions of prime numbers
	int primo = 0, i = 2;
	//checks all the possible divisors, and executes the cycle as long as the number inserted is not prime
	while (primo == 0) {
		if (number % i != 0) {
			i++;
			if (i==number) {
				return 1; //true, number is prime
			}
		} else {
			return 0; //false, number is not prime
		}
	}
}
