/*
   La moltiplicazione fra due numeri interi x e y entrambi di n cifre (con n=2 k ), si può calcolare ricorsivamente usando la
   seguente formula:

   x*y = 10^n * xs *ys + 10^(n/2) *( xd * ys + xs * yd) + xd * yd

   dove xs e ys sono le metà (cioè le n/2 cifre) più significative di x e y, mentre xd e yd sono le metà (cioè le n/2 cifre) meno 4 significative di x e y. Ad esempio 1234 ⋅ 5678 = 10 ' ⋅ 12 ⋅ 56 + 10 5 34 ⋅ 56 + 12 ⋅ 78 + 34 ⋅ 78
   Quindi utilizzando la formula appena descritta, implementare la seguente funzione ricorsiva in C per effettuare il
   prodotto fra due interi con n cifre:
   int prodotto (int x[], int y[], int n)
   dove x e y sono due array che contengono le cifre dei numeri da moltiplicare ed n è il numero di cifre contenute negli
   array; la funzione dovrà ritornare il risultato del prodotto come una variabile intera.

   Esempio
   Per effettuare il prodotto 15*10, sarà possibile utilizzare la funzione prodotto nel modo seguente:
   int x[2]={1,5}, y[2]={1,0}, ris;
   ris = prodotto(x,y,2);
   La variabile ris, conterrà alla fine il valore 150.
   Suggerimenti: se x e y contengono una sola cifra, la loro moltiplicazione non richiede di essere ulteriormente
   scomposta; per calcolare le potenze del 10 (10 n e 10 n/2 ) è possibile usare la funzione pow(a,b) (inclusa nella libreria
   math.h)che ritorna a b ; si ipotizzi che x e y abbiano entrambi sempre lo stesso numero di cifre.
 */
#include <stdio.h>
#include <math.h>

int product(int x[], int y[], int n);

int main(int argc, char const *argv[]) {
	int x[]={1,5,6}, y[]={1,0,9}, risultato;
	risultato = product(x,y,3);
	printf("risultato %d\n", risultato);
	return 0;
}


int product(int x[], int y[], int n) { //recursive product
	if (n == 1) { //base case, when the iteration gets reduced to n = 1
		return x[0] * y[0];
	} else { //transcript of formula, recursive function
		return pow(10, n) * product(x, y, n/2) + pow(10, n/2) * ( product(x + n/2, y, n/2) + product(x, y + n/2, n/2) ) + product(x + n/2, y + n/2, n/2);
	}
}
