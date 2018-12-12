#include <stdio.h>

typedef struct
{
	char artista[50];
	char titolo[50];
	int num; //numero traccia
	int minuti;
	int secondi;
} traccia;


int carica(FILE *fp, traccia cd[]);
void stampa(traccia cd[], int n);
void aggiorna(FILE *fp, traccia t, int pos);

int main()
{
	FILE *fp;
	traccia cd[100];
	int n,i;

	fp = fopen("album.bin","rb+");
	n = carica(fp,cd);
	stampa(cd,n);

	printf("Quale traccia vuoi aggiornare? ");
	scanf("%d",&i);

	if (i>0 && i<=n)
	{
		printf("minuti: ");
		scanf("%d",&cd[i-1].minuti);
		printf("secondi: ");
		scanf("%d",&cd[i-1].secondi);

		aggiorna(fp,cd[i-1],i-1);
	}
	else
	{
		printf("Traccia non valida\n");
	}
	fclose(fp);

	return 0;
}

int carica(FILE *fp, traccia cd[])
{
	int n=0;
	while (fread(cd+n,sizeof(traccia),1,fp)==1)
		n++;
	return n;
}

void stampa(traccia cd[], int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("#%d - %s  - %s (%d:%02d)\n",cd[i].num,cd[i].artista,cd[i].titolo,cd[i].minuti,cd[i].secondi);
}

void aggiorna(FILE *fp, traccia t, int pos)
{
	fseek(fp, sizeof(traccia)*pos,SEEK_SET);
	fwrite(&t,sizeof(traccia),1,fp);
}
