#include <stdio.h>
int main() {
	printf("quanti numeri da mettere in input? (puoi mettere solo positivi):");
	int n, somma = 0;
	scanf("%d\n", &n);
	if (n<1) {
		printf("coglione che cazzo fai");
		n = -n;
	}

	for (int i=0; i<n; i++) {
		int x;
		scanf("%d%*c", &x);
		if (x<1) {
			printf("coglione che cazzo fai\n");
			x = -x;
		}
		printf("num %d: %d\n", i, x);
		somma += x;
	}

	return 0;
}
