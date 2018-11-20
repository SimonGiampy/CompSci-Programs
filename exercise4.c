/*
   write a recursive function minimum that returns the minimum value of the array void
   this functions receives an array v of float numbers, and the length of that array
 */

#include <stdio.h>

float minimum(float* v, int dim);

int main() {
	float v[] = {41.5, 3.8, 9.0, -43.1, -16.2, 28.3, 1.1};

	printf("the minimum value is %f\n", minimum(v, 5));

	return 0;
}

float minimum(float* v, int dim) {
	//receives the array of floats v, and dim is the dimension of that array
	float min; //minimum value in the array

	if (dim == 1) {
		min = v[0]; //the minimum is the only number of the array
	} else if (dim == 2) {
		//general case, an array of dimension dim, is reduced recursively until it is long only 2 numbers
		if (v[0] < v[1]) {
			min = v[0];
		} else {
			min = v[1];
		}
	} else {
		//if the array is bigger than 2, then the array is being reduced of dimension
		//then it considers the minimum from the second value of the array, until the last
		if (dim > 1) {
			return minimum(v+1, dim-1);
		}
		//example: min(3,5,6,8,1); ---> = min(3, min(5,6,8,1)); ---> = min(min 3, min(5, min(6,8,1)); ---> = min(3, min(5, min(6, min(8,1))));
		//so the min(8,1) = 1; min(6,1) = 1; min(5, 1) = 1; min(3, 1) = 1; min = 1;
	}

	return min;
}
