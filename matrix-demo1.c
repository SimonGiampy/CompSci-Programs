#include <stdlib.h>

#define N 100

void sum(int a[][N], int b[][N], int sum[][N], int rows, int columns) {
	int i, j;
	//version 1
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			sum[i][j] = a[i][j] + b[i][j];
		}
	}

	//version 2

}

int main() {
	int a[3][N], b[3][N], sum[3][N];
	sum(a, b, sum, rows, columns)
}
