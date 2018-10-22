/*
   Scrivere un programma che chieda all’utente di inserire un numero intero n e ne calcoli la scomposizione in fattori primi (e.g., 10 = 1x2x5, 18 = 1x2x3x3).
 */
#include <stdio.h>

//function that shows if a number is prime or not
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
	} else {
		//checks if the number is divisible for the prime numbers below the number itself
		for (int i = num-1; i >= 1; i--) {
			//terminates the sequence with a 1 when it ends the iteration
			if (i == 1) {
				printf("1\n");
			} else {
				//checks if a determined number is prime and takes 1 or 0 (function primo)
				if (primo(i)) {
					//if it is prime (so it is a possible divisor) checks if the number is divisible for it
					if (num % i == 0) {
						//shows the divisor found
						printf("%d * ", i);
						//divides the number for i, so it checks the other numbers below it
						num = num / i;

						//sets the iterator at a position which is equal to the factor just found
						if (i > num) {
							i = num;
						}

						//i is increased by one, so the cycle checks if the number is divisible again
						//for the prime number found. example:20 = 5*2*2 (2 is checked as divisor multiple times
						//as long as the result of the division is not divisible anymore)
						i++;
					}
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
