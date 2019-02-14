#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef enum { false = 0, true = !false} bool;
bool contiene(char input[], char output[], int length);


/*DICHIARAZIONI*/
void salva_in_matrice(char matrix[9], char file_name[]);
int check_parole(FILE *fp);
int checkRighe(FILE *fp, char matrix[][9]);

int main()
{
	FILE *source;
	char file_name[26];
	char matrix[13][9];
	char list[13][9];
	int i, j;

	printf("Inserire nome file: \n");
	scanf("%s", file_name);
	source = fopen(file_name, "r");
	if(source == NULL)
		printf("errore\n");

	for(i=0; i<13; i++) {
		fscanf(source, "%9s", list[i]);
		printf("list i = %s\n", list[i]);

		//for(j=0; j<9; j++) {
		//matrix[i][j] = tolower(fgetc(source));
		//printf("%c ", matrix[i][j]);
		//}
	}

	i = checkRighe(source, list);
	printf("%d\n", i);


	return 0;
}

int checkRighe(FILE *fp, char list[13][9]) {
	char parola[15];
	int ris=0, i= 0;
	

bool contiene(char input[], char output[], int length) {
	bool check = false;
	int start = 0;
	for (start = 0; check == false && start <= strlen(input) - length; start++) {
		char trim[length];
		for (int i = 0; i< length; i++) {
			trim[i] = input[start + i];
		}
		if (strcmp(trim, output) == 0) {
			check = true;
		}
	}
	return check;
}
