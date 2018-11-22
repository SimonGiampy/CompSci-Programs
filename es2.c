/* Scrivere una funzione che consenta di effettuare la somma di due matrici*/
#define N 100
#include <stdlib.h>

//VERSIONE 1
void somma1(int a[][N],int b[][N],int sum[][N],int r, int c)
//[N] va sempre indicato ed indica il n di colonne ed è limitante perchè
//limita ad un solo tipo di matrice tutte con colonne n
{
  int i,j;
  for(i=0; i<r; i++)
    for(i=0;j<c;j++)
      sum[i][j] = a[i][j] + b[i][j]
}
int main()
{
  int a[M][N],b[M][N],sum[M][N];
  int r,c;
  //.........Leggo
  somma(a,b,sum,r,c)
}

//VERSIONE 2

void somma2(int a[],int b[],int sum[],int r, int c)

{
  int i,j;
  for(i=0; i<r; i++)
    for(i=0;j<c;j++)
      sum[i*c+j] = a[i*c+j] + b[i*c+j];
//Non avendo [][N] e utilizzando un array sum[ij]
}
int main()
{
  int a[2][3],b[2][3],sum[2][3];
  //.....Leggo a e b.........
  somma2(&a[0][0],&b[0][0],&sum[0][0],2,3)
}

//VERSIONE 3
typedef int (*matrix_pointer)[N];
matrix_pointer somma3(int a[][N],int b[][N],int sum[][N],int r, int c)
{
  int i,j;
  matrix_pointer sum = malloc(r*c*sizeof(int)) //Scritto così posso essere dinamico per numero di righe ma non di colonne(?? o inverso???)
  for(i=0; i<r; i++)
    for(i=0;j<c;j++)
      sum[i][j] = a[i][j] + b[i][j]
      return sum;
}
int main()
{
  int a[2][N],b[2][N],sum[2][N];
  matrix_pointer sum;
  //.....Leggo a e b.........
  sum= somma2(a,b,2,3)
}

//VERSIONE 4
int **somma2(int a[],int b[],int r, int c)
