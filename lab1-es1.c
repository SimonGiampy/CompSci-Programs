/*Istruzioni condizionali
   Problema 2
   Implementare un programma che genera casualmente i coefficienti a, b, c (interi compresi fra 0 e 5, e a maggiore di zero) di una parabola (y = ax^2 + bx + c) e chiede all’utente di calcolare le coordinate del vertice (il vertice è il punto della parabola con ascissa x=-b/2a). Quindi il programma calcola la correttezza delle coordinate del vertice inserito stampando un messaggio.
 */

#include <stdio.h>
#include <stdlib.h> //srand e rand (random numbers)
#include <time.h> //timestamp
#include <math.h>

int  main() {
	float a, b, c;
	//srand takes as parameters <unsigned int seed>, where seed is a number
	//the seed is used to generate a sequence of random numbers, so at every execution the sequence of numbers veries
	//in this case the seed is the timestamp, so it's a number which is different at every execution of the program
	srand(time(NULL));
	//a equals to a random number (generated from 0 to 1) times 5 (maximum number requested from the exercise)
	//rand()%N will return as result always a number between 0 and N-1, whatever is the value of N
	a = rand()%5 + 1;
	b = rand()%6;
	c = rand()%6;
	//prints sequence of generated random numbers
	printf("n1: %d; n2: %d; n3: %d\n", (int) a, (int) b, (int) c);
	printf("parabola: y = %dx^2 + %dx + %d\n", (int) a, (int) b, (int) c);

	//calculate the values of the abscissa (x-axis) and the ordinate (y-axis)
	float xAxis = -(b / (2*a));
	if (xAxis == -0) xAxis = 0; //fixes the bug when b = 0, it shows the xAxis value = -0.00000
	float ordinate = a * pow(xAxis, 2.f) + b * xAxis + (float) c;
	//prints the values of the x-axis and y-axis
	printf("il valore corretto del vertice della parabola è %f, e la sua y è %f\n", xAxis, ordinate);

	//asks the user to guess the value of the vertex with an approximation of 3 decimal digits
	printf("secondo te quanto vale il vertice x (approssimazione a 3 cifre decimali)?\n");
	float guess;
	scanf("%f", &guess);

	//checks if the input is correct, accounting an accuracy of 10^-3
	//so it is only correct if the first 3 digits in the input value are correct
	if (fabs(xAxis - guess) < 0.001) {
		printf("hai ragione\n");
	} else {
		printf("hai sbagliato\n");
	}

	return 0;
}
