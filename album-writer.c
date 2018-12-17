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
#include <string.h>

//binary file created by the professor
#define dir "album.bin"

struct audio {
	char artist[50];
	char title[50];
	int id; //number of track
	int minutes;
	int seconds;
};
typedef struct audio track;

unsigned int readContent(FILE *file, track *songs);
void printContent(track thisTrack);
void save(FILE *file, track *songs, unsigned int count);

int main(int argc, char const *argv[]) {
	FILE *file = fopen(dir, "rb+"); //read and write permissions for the binary file

	if(file == NULL) {
		printf("Error!");
		exit(1);
	}

	track songs[100]; //array with all the read structs (each one is a song)
	unsigned int count = readContent(file, songs); //passes the address of the array songs, so it modifies the values directly
	for (unsigned int i = 0; i< count; i++) {
		printContent(songs[i]);
	}

	int id, minutes, seconds;
	printf("which track do you want to modify: ");
	scanf("%d", &id);
	printf("new duration: minutes: ");
	scanf("%d", &minutes);
	printf("seconds: ");
	scanf("%d", &seconds);
	songs[id-1].minutes = minutes;
	songs[id-1].seconds = seconds;
	printContent(songs[id-1]);
	save(file, songs, count);
	printContent(songs[id-1]);

	//snippet to add a new track to the list. i could make a new function to do this with user input
	count++;
	char artist[50], title[50];
	strcpy(artist, "giustiziano ammalinquore");
	strcpy(title, "piermenti sfracellozzi");
	strcpy(songs[count-1].artist, artist);
	strcpy(songs[count-1].title, title);
	songs[count-1].id = count;
	songs[count-1].minutes = 32432;
	songs[count-1].seconds = 2121;
	printContent(songs[count-1]);
	save(file, songs, count);

	fclose(file);

	return 0;
}

unsigned int readContent(FILE *file, track songs[]) { //modifies and adds new elements (the structs) in the array songs
	printf("reading from binary file...\n");
	fseek(file, 0, SEEK_SET); //sets the position at the start
	unsigned int i = 0; //array index
	while(!feof(file)) { //while it hasn't finished reading the file
		//function fread:
		//the first parameter is the address of the variable where to store the read data, the second one is the number of elements to read
		//the third parameter is the dimension in bytes of the variable to read, the fourth is the file where to read
		int n = fread(&songs[i], 1, sizeof(track), file); //reads 1 element, which is an entire struct, then it automatically fills the parameters

		if (n == 0) { //n is the number of elements read. it should read just one element (one struct) at a time
			break; //if it doens't read anything, it breaks the cycle and stops reading from the file
		} else {
			i++; //next position in the array
		}
	}
	return i;
}

void printContent(track thisTrack) {
	//prints every information for every field in the struct
	printf("# %d - %s - %s - duration %d:%02d\n", thisTrack.id, thisTrack.artist, thisTrack.title, thisTrack.minutes, thisTrack.seconds);
}

void save(FILE *file, track *songs, unsigned int count) {
	printf("saving changes to the file...\n");
	fseek(file, 0, SEEK_SET); //sets the position in writing at the start
	for (unsigned int i = 0; i< count; i++) { //for each element in array songs
		//first parameter is the address of the array in the position i, the second parameter is the dimension in bytes of a single element (struct)
		//the third element is the amount of variables to write, and the fourth is the file where to write the data
		fwrite(&songs[i], sizeof(track), 1, file); //writes a struct at a time, for a total of structs = count
	}
}
