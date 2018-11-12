/*
   Definire un tipo di dato strutturato che consenta di rappresentare una schedina del totocalcio con le seguenti informazioni:
   -        data della giocata
   -        gli esiti (1,X,2) delle 14 partite di calcio
   Scrivere un programma che generi casualmente una schedina (usando come data della giocata 3/11/2014), chieda all’utente di inserire gli esiti delle 14 partite ed infine calcoli il punteggio della schedina generata casualmente.

   i possibili esiti di una partita di calcio sono rappresentati con 3 possibili diversi caratteri: 1, X o 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//this struct defines the date of the play
struct date {
	int day;
	int month;
	int year;
};

struct gamesheet { //gamesheet is "schedina" in italian
	struct date date; //date of play refers to the other struct
	char result[14]; //14 different results
} gamesheet, gambler; //2 different sets, each representing (in order): the winning gamesheet and the gambler one

char convertResult(int n); //converts a randomly generated number in a character representing the result of a single match

int main() {
	//instantiates the day when the winning gamesheet is created
	//this specific date is given by the assignment
	gamesheet.date.day = 3;
	gamesheet.date.month = 11;
	gamesheet.date.year = 2014;

	printf("matches on %d/%d/%d (randomly generated match results): ", gamesheet.date.day, gamesheet.date.month, gamesheet.date.year);

	//random seed for random number generation
	srand(time(NULL));

	int n;
	for (int i = 0; i<14; i++) {
		n = rand()%3 + 1;
		gamesheet.result[i] = convertResult(n);
		//prints the results of the matches
		printf("%c   ", gamesheet.result[i]);
	}
	printf("\n");

	printf("your guesses for the gamesheet are (randomly generated): ");
	//copies the date from the other variable of type "gamesheet"
	gambler.date = gamesheet.date;
	for (int i = 0; i<14; i++) {
		//insted of asking the user to input their guesses on the 14 mathes, it generates randomly the result
		n = rand()%3 + 1;
		gambler.result[i] = convertResult(n);
		//prints the guesses of the user (instead of asking for them to input evry single bet)
		printf("%c   ", gambler.result[i]);
	}
	printf("\n");

	//score calculation is based on the number of bets won. if the gambler bets 1 for example of one match, and the result of that match is 1,
	//then the gambler wins and earns 1 point
	int score = 0;
	for (int i = 0; i<14; i++) {
		if (gambler.result[i] == gamesheet.result[i]) {
			score++;
		}
	}
	//prints the score of the gambler
	printf("gambler score is %d out of 14\n", score);

	return 0;
}

//converts the randomly generated number (1, 2 or 3) into the corresponding character for the result of the gamesheet
char convertResult(int n) {
	char conversion;
	switch (n) {
	case 1: conversion = '1'; break;
	case 2: conversion = '2'; break;
	case 3: conversion = 'X'; break;
	}
	return conversion;
}
