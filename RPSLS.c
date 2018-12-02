#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum rpsls {rock, paper, scissors, lizard, spock, error}; //list of possibile inputs
typedef enum rpsls rpsls; //renaming the enum in a single word

enum outcome {win, lose, draw}; //list of all possible outcomes
typedef enum outcome outcome;

void printInstructions(void);
rpsls getInput(char *selection);
outcome compare(rpsls playerChoice, rpsls machineChoice);
char* convert(rpsls choice);

int main(int argc, char const *argv[]) {
	srand(time(NULL)); //initialize random seed
	printf("accepted commands for playing: rock, paper, scissors, lizard, spock. You will play the game 5 times\n\nRules:\n");
	printInstructions();

	unsigned int playerScore = 0, machineScore = 0; //tracking score with these variables

	for (short i = 1; i <= 5; i++) { //game finishes after 5 plays
		printf("starting new game\n");
		char selection[10]; //selection of player
		strcpy(selection, "");

		rpsls playerChoice;
		printf("\nwrite your choice: ");
		scanf("%s", selection);
		playerChoice = getInput(selection); //converts string to equivalent enum

		if (playerChoice == error) {
			i--;
			printf("wrong input. write again please\n");
			continue;
		}

		rpsls machineChoice;
		int random = rand()%5; //random choice betweeen 0 and 4 (valid indexes of enum rpsls)
		machineChoice = (rpsls) random; //converts integer to equivvalent enum
		printf("the machine chose %s\n", convert(machineChoice)); //converts the enum to the equivalent string

		outcome result = compare(playerChoice, machineChoice); //win, lose or draw. calculating score
		switch (result) {
		case win: {
			playerScore++;
		}; break;
		case lose: {
			machineScore++;
		}; break;
		default: break;
		}

		printf("score: player has %d points, the machine has %d points\n", playerScore, machineScore); //showing scores to the user
	}
	printf("game finished. ");
	if (playerScore > machineScore) {
		printf("You won!\n");
	} else if (machineScore > playerScore) {
		printf("You lose!\n");
	} else {
		printf("Tie!\n");
	}

	return 0;
}

void printInstructions() {
	const char *i[] = {"Scissors cut Paper", "Paper covers Rock", "Rock crushes Lizard", "Lizard poisons Spock", "Spock smashes Scissors", "Scissors decapitate Lizard", "Lizard eats Paper", "Paper disproves Spock", "Spock vaporizes Rock", "Rock crushes Scissors﻿"};
	for (unsigned int k = 0; k < (sizeof(i) / sizeof(*i)); k++) {
		printf("%s\n", *(i+k)); //prints every element in the array until there are no more elements
	}
	/*
	   this version works to.. it has a null terminator added by default in the array
	   const char *i[] = {"Scissors cut Paper", "Paper covers Rock", "Rock crushes Lizard", "Lizard poisons Spock", "Spock smashes Scissors", "Scissors decapitate Lizard", "Lizard eats Paper", "Paper disproves Spock", "Spock vaporizes Rock", "Rock crushes Scissors﻿", "\0"};
	   for (unsigned int k = 0; *(*(i+k)) != '\0'; k++) { //repeats until the first character in a string is the null terminator
	    printf("%s\n", *(i+k));
	   }
	 */
}

outcome compare(rpsls player, rpsls machine) { //compares the two plays, and returns if it is a win, lose or draw for the player
	outcome result;
	if (player == machine) {
		result = draw;
	} else {
		if (player == rock)  {
			if (machine == scissors || machine == lizard) {
				result = win;
			} else {
				result = lose;
			}
		} else if (player == paper) {
			if (machine == rock || machine == spock) {
				result = win;
			} else {
				result = lose;
			}
		} else if (player == scissors) {
			if (machine == paper || machine == lizard) {
				result = win;
			} else {
				result = lose;
			}
		} else if (player == lizard) {
			if (machine == paper || machine == spock) {
				result = win;
			} else {
				result = lose;
			}
		} else if (player == spock) {
			if (machine == rock || machine == scissors) {
				result = win;
			} else {
				result = lose;
			}
		}
	}
	return result; //returns the outcome
}

rpsls getInput(char *selection) { //converts the string input from the user in the equivalent data in the enum
	if (!strcmp(selection, "rock")) {
		return rock;
	} else if (!strcmp(selection, "paper")) {
		return paper;
	} else if (!strcmp(selection, "scissors")) {
		return scissors;
	} else if (!strcmp(selection, "lizard")) {
		return lizard;
	} else if (!strcmp(selection, "spock")) {
		return spock;
	} else {
		return error;
	}
}

char* convert(rpsls choice) { //converts the enum data in the equivalent string
	char *string = (char*) malloc(sizeof(char) * 10); //allocating memory that will be passed as return value

	switch (choice) { //choice is implicitly converted from enum to integer
	case rock: strcpy(string, "rock"); break;
	case paper: strcpy(string, "paper"); break;
	case scissors: strcpy(string, "scissors"); break;
	case lizard: strcpy(string, "lizard"); break;
	case spock: strcpy(string, "spock"); break;
	default: strcpy(string, "error");
	}
	return string;
}
