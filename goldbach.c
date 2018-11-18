/*
   Every even number greater than 2 can be written as the sum of two primes

   prove it showing if a number is not part of goldbach conjecture. maybe using recursion
 */

//this program is not optimized at all
//there is a big ram memory consumption, and a lot of superflous calculations

#include <stdio.h>

void initializePrimeSeries(int, int *);
int isPrime(int n);

int main() {

	for (int i = 4; i<=1000; i+=2) { //checks all the even numbers between 4 and 100 (the limit of calculations)

		int primeSeries[i];
		printf("initializing n%d: ", i);
		initializePrimeSeries(i, primeSeries);

		int check = 0;

		for (int n = 0; n < i; n++) {
			for (int m = 0; m < i; m++) {
				/*if (primeSeries[n] + primeSeries[m] == i) {
				    printf("number %d is %d+%d\n", i, primeSeries[n], primeSeries[m]);
				   }*/
				if (primeSeries[n] + primeSeries[m] == i) {
					check = 1; //it is an even number which validates the conjecture
				}
			}
		}

		if (check == 0) {
			printf("FOUND IT\n"); //writes this if it has found a counterargument for the conjecture
			//according to Goldbach, every even number is sum of 2 primes, so it will never prompt this message
		}
	}

	return 0;
}

void initializePrimeSeries(int num, int series[]) {
	//writes in an array all the prime numbers below the number (num) in input
	int index = 0, i = 0;
	for (i = 0; i< num; i++) {
		if (isPrime(i)) {
			//if the number is prime, it is added to the list of prime numbers
			*(series + index) = i;
			index++;
		}
	}

	for (; index < num; index++) {
		*(series + index) = 0; //every number in the array not changed yet is changed to 0 by default
	}
	/*
	    //prints all the numbers in the array
	   for (int i = 0; i < num; i++) {
	    printf("%5d", series[i]);
	   }
	 */
	printf("\n");
}

int isPrime(int n) {
	//returns 1 if the number is prime, 0 if not
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
