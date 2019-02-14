/*
   Esercizio 3 (8 punti)
   Implementare in C la funzione ricorsiva int trova_somma (int somma, int v[], int n) che riceve in
   ingresso un vettore v di lunghezza n e restituisce 1 se il vettore v contiene uno o più elementi che sommati insieme hanno
   valore pari al parametro somma, viceversa restituisce 0.
   Esempi
   Sia v={3,7,9,4,12}, trova_somma(13,v,5) restituirà 1 (9+4=13), trova_somma(31,v,5) restituirà 0
   (anche se 3+7+9+12=31, gli elementi non sono consecutivi), trova_somma(19,v,5) restituirà 1 (3+7+9=19).
 */
 #include <stdio.h>
int trova_somma (int somma, int v[], int n);
int main() {
	int v[] ={3,7,9,4,12};
	printf("trova somma %d\n", trova_somma(19, v, 5));
	return 0;
}


int trova_somma (int somma, int v[], int n) {
	if (n==1) {
		if (somma == v[0]) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int parz = 0;
		for (int i = 0; i < n; i++) {
			parz+=v[i];
			if (parz == somma) {
				return 1;
			}
		}
		trova_somma(somma, v+1, n-1);
	}
}
