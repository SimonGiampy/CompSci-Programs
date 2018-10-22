/*
   Problema 2
   Scrivere un programma che legga due interi, n e k, e stampi la una griglia dei primi k elementi delle tabelline degli interi fra 2 e n. Ad esempio, per n = 5 e k = 8, stampa:
        1   2   3   4   5   6   7   8
    ---------------------------------
   2 :  2   4   6   8  10  12  14  16
   3 :  3   6   9  12  15  18  21  24
   4 :  4   8  12  16  20  24  28  32
   5 :  5  10  15  20  25  30  35  40
 */
#include <stdio.h>

int main() {
	printf("quante righe?\n");
	int k;
	scanf("%d", &k);
	printf("quante colonne?\n");
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= k; i++) {
		for (int j= 1; j <= n; j++) {
			if (i==1) {
				printf("\t%d", j);
			} else {

				if (j == 1) {
					printf("%d :\t%d", i, j*i);
				} else {
					printf("\t%d", j*i);
				}
			}
		}
		printf("\n");
		if (i==1) {
			for (int j = 0; j<=n; j++) {
				printf("-------");
				//there is a bug here that doens't show aligned hyphens with the columns
			}
			printf("\n");
		}
	}


	return 0;
}
