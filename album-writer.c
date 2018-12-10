/*
   Scaricare il file album.bin che contiene una sequenza di elementi del seguente tipo:

   typedef struct
   {
    char artista[50];
    char titolo[50];
    int num; //numero traccia
    int minuti;
    int secondi;
   } traccia;

   Scrivere un programma che:
   legga il contenuto di album.bin
   stampi le informazioni di tutte le tracce del CD
   consenta all’utente di modificare la durata di una traccia scelta da lui
   salvi la modifica all’interno del file

 */

#include <stdio.h>
#include <stdlib.h>

#define dir "album.bin"

struct traccia {
	char artista[50];
	char titolo[50];
	int num; //numero traccia
	int minuti;
	int secondi;
};
typedef struct traccia track;

void readContent(FILE *file);

int main(int argc, char const *argv[]) {
	FILE *file = fopen(dir, "rb+");

	if(file == NULL) {
		printf("Error!");
		exit(1);
	}

	readContent(file);
	fseek(file, 0, SEEK_SET);
	fclose(file);

	return 0;
}

void readContent(FILE *file) {
	while(!feof(file)) { //while it hasn't finished reading the file
		track track1; //new variable of type struct
		//the first parameter is the address of the variable track, the second one is the number of elements to read
		//the third parameter is the dimension in bytes of the variable to read, the fourth is the file where to read
		fread(&track1, 1, sizeof(track), file); //reads 1 element, which is an entire struct, it is automatically fills the parameters

		//prints every data
		printf("string read binary:\nartsista: %s\ntitolo: %s\nnumero traccia %d\nnumero minuti: %d\nnumero secondi: %d\n\n", track1.artista, track1.titolo, track1.num, track1.minuti, track1.secondi);
	}
}

void printContent() {

}

void saveModifications() {


}
