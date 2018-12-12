/*
   Scaricare il file album.bin che contiene una sequenza di elementi del seguente tipo:

   typedef struct {
    char artist[50];
    char title[50];
    int id; //numero track
    int minutes;
    int seconds;
   } track;

   Scrivere un programma che:
   legga il contenuto di album.bin
   stampi le informazioni di tutte le tracce del CD
   consenta all’utente di modificare la durata di una track scelta da lui
   salvi la modifica all’interno del file
 */

#include <stdio.h>
#include <stdlib.h>

#define dir "album.bin"

struct audio {
	char artist[50];
	char title[50];
	int id; //number of track
	int minutes;
	int seconds;
};
typedef struct audio track;

void readContent(FILE *file);
void printContent(track thisTrack);

int main(int argc, char const *argv[]) {
	FILE *file = fopen(dir, "rb+");

	if(file == NULL) {
		printf("Error!");
		exit(1);
	}

	readContent(file);
	fseek(file, 0, SEEK_SET);

	int newDuration = 900;
	//modify duration for a specific struct
	//save it to the file, rewriting everything


	fclose(file);

	return 0;
}

void readContent(FILE *file) {
	printf("reading from binary file...\n");
	while(!feof(file)) { //while it hasn't finished reading the file
		track thisTrack; //new variable of type struct
		//the first parameter is the address of the variable track, the second one is the number of elements to read
		//the third parameter is the dimension in bytes of the variable to read, the fourth is the file where to read
		int n = fread(&thisTrack, 1, sizeof(track), file); //reads 1 element, which is an entire struct, then it automatically fills the parameters
		//n is the number of elemts read. it should read just one element (one struct) at a time
		if (n == 0) { //if it doens't read anything, it breaks the cycle and stops reading from the file
			break;
		}
		//prints every information for every field in the struct
		printContent(thisTrack);
	}
}

void printContent(track thisTrack) {
	printf("# %d - %s - %s - duration %d:%02d\n", thisTrack.id, thisTrack.artist, thisTrack.title, thisTrack.minutes, thisTrack.seconds);
}
