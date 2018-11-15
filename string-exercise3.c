/*
   scrivere un programma che legga una sequenza di interi, lunga al massimo 100, e terminata da uno zero. dopo, chiede all'utente di inserire un intero N e stampa gli elementi della sequenza precedemente inserita che sono maggiori di N
 */

int v[100], i = 0, l, n;
do {
	scanf("%d", &v[l]);
	l++;
} while (v[l-1] != 0 && l<100);

scanf("%d", &n);

for (l=0; i<l; i++) {
	if (v[i]>n) {
		printf("%d\n", v[i]);
	}
}


//2nd version with pointers

int v[100], i, l = 0, n;
do {
	scanf("%d", v+l);
	l++;
} while (*(v+l-1) != 0 && l<100);

scanf("%d", &n);

for (l=0; i<l; i++) {
	if (*(v+i)>n) {
		printf("%d\n", *(v+i));
	}
}
