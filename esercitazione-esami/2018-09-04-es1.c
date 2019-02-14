/*
   Implementare la seguente funzione:
   void inverti(int v[], int n),
   che riceve in ingresso un vettore v di lunghezza n e lo inverte, in modo che l’ultimo elemento di v diventi il primo, il
   penultimo diventi il secondo e così via. Si implementi una funzione in grado di invertire il vettore v senza crearne una
   copia e senza utilizzare un ulteriore variabile array a supporto.
   Esempio: Il vettore {1,2,3,4,5} deve essere trasformato in {5,4,3,2,1}.
 */
#include <stdio.h>
//start at 17:30
void inverti(int v[], int n);
void inverti(int v[], int n) {
	int temp;
	for (int k = 0; k < n-1; k++) {
		for (int i = 0; i < n-k-1; i++) {
			//swap v[i] and v[i+1] with support variable temp
			temp = v[i];
			v[i] = v[i+1];
			v[i+1] = temp;
		}
	}
}

int main() {
	int v[8] = {1,2,3,4,5,6,7,8};
	inverti(v, 8);
	for (int k = 0; k < 8; k++) {
		printf("%d \n", v[k]);
	}
	return 0;
}
