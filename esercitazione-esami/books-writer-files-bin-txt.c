/*
   Esercizio 4
   Data la seguente struttura dati:
   typedef struct
   {
    char titolo[101];
    char autore[101];
    int anno;
   } libro;

   typedef struct {
    libro libri[100];
    int n_libri;
   } libreria;
   Si implementino delle funzioni di lettura e scrittura, che consentano di (i) leggere e scrivere una sequenza di libri da un file e memorizzarli in una variabile libreria e (ii) a partire da una variabile libreria, salvi i libri in essa contenuta (separatamente) su file. Si implementi una coppia di funzioni di lettura/scrittura che “lavorino” in modalità binaria ed una coppia di funzioni che “lavorino” in modalità testuale (per queste ultime due, scegliere il formato dell’output testuale desiderato).

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book {
	char title[101];
	char author[101];
	int year;
};

struct library {
	struct book books[100];
	int amount;
};

void saveTxt(char filename[11], struct library *library);
void saveBin(char filename[11], struct library *library);
struct library* readBin(char filename[11]);

int main() {
	struct library library;
	library.amount = 4;

	struct book book1;
	strcpy(book1.title, "la magia del diocane");
	strcpy(book1.author, "Cristo");
	book1.year = 1337;
	struct book book2;
	strcpy(book2.title, "la magia del porcodio");
	strcpy(book2.author, "Allah");
	book2.year = 420;
	struct book book3;
	strcpy(book3.title, "la magia della madonna puttana");
	strcpy(book3.author, "Gesù");
	book3.year = 2020;
	struct book book4;
	strcpy(book4.title, "la magia del cazzo in culo");
	strcpy(book4.author, "Buddha");
	book4.year = 6969;

	library.books[0] = book1;
	library.books[1] = book2;
	library.books[2] = book3;
	library.books[3] = book4;

	//initialization completed
	//filenames
	char outputBinary[12] = "library.bin";
	char outputText[12] = "library.txt";

	//write a function that saves these data to both binary and text file
	saveTxt(outputText, &library);
	saveBin(outputBinary, &library);
	struct library *lib2 = (struct library*) malloc(sizeof(struct library));
	lib2 = readBin(outputBinary);
	printf("lib2 amount %d\n", lib2->amount);

	//write a function that reads the data from these files, saves them in new variables of type library and prints on the terminal the result

	return 0;
}

void saveTxt(char filename[12], struct library *library) {
	FILE *file = fopen(filename, "w");
	fprintf(file, "this is the library content: contains %d books\n", library->amount);
	for (int i = 0; i < library->amount; i++) {
		fprintf(file, "book n.%d: title is %s, author is %s, published in year %d\n", i, library->books[i].title, library->books[i].author, library->books[i].year);
	}
	fclose(file);
}

void saveBin(char filename[12], struct library *library) {
	FILE *file = fopen(filename, "wb");
	fseek(file, 0, SEEK_SET); //sets the position at the start

	fwrite(&(library->amount), sizeof(int), 1, file);

	for (int i = 0; i < library->amount; i++) {
		fwrite(&(library->books[i]), sizeof(struct book), library->amount, file);
		//fprintf(file, "book n.%d: title is %s, author is %s, published in year \n", i, library.book[i].title, library.book[i].author, library.book[i].year);
	}
	fclose(file);
}

struct library* readBin(char filename[12]) {
	FILE *file = fopen(filename, "rb");
	fseek(file, 0, SEEK_SET); //sets the position at the start
	struct library *library = (struct library*) malloc(sizeof(struct library));

	fread(&(library->amount), sizeof(int), 1, file);
	for (int i = 0; i < library->amount; i++) {
		fread(&(library->books[i]), sizeof(struct book), library->amount, file);
	}

	fclose(file);

	printf("this is the library content (after reading): contains %d books\n", library->amount);
	for (int i = 0; i < library->amount; i++) {
		printf("book n.%d: title is %s, author is %s, published in year %d\n", i, library->books[i].title, library->books[i].author, library->books[i].year);
	}
	return library;
}
