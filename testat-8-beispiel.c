#include <stdio.h>
#include <string.h>
#include "testat-8.h"

matrix m0() {
   matrix m = matrix_create(3);
	double d[3][3] = {
		{1,2,3},
		{5,4,3},
		{6,4,2}};
	memcpy(m.p, d, 3 * 3 * sizeof(double));
	return m;
}

matrix m1() {
/* Matrix:
 1 2 3
 4 5 6
 7 8 9
 
 Determinante davon: 0
 */
	matrix m = matrix_create(3);
	int z, s;
	for (z = 1; z <= 3; z++)
		for (s = 1; s <= 3; s++)
			*matrix_element(m, z, s) = 3 * z  + s - 3;
	return m;
}

matrix m2() {
	matrix m = matrix_create(4);
	double d[4][4] = {
		{1,2,3,4},
		{5,4,3,2},
		{6,4,2,1},
		{9,8,7,6}};
	memcpy(m.p, d, 4 * 4 * sizeof(double));
	return m;
}

matrix matrix_input() {
	int z, s, n;
	matrix m;
	printf("n: ");
	scanf("%d", &n);
	m = matrix_create(n);
	for (z = 1; z <= n; z++) {
		for (s = 1; s <= n; s++) {
			printf("A[%d][%d]: ", z, s);
			scanf("%lf", matrix_element(m, z, s));
		}
	}
	return m;
}

void matrix_print(matrix A) {
	int z, s;
	for (z = 1; z <= A.n; z++) {
		for (s = 1; s <= A.n; s++)
			printf("%10.2lf", *matrix_element(A, z, s));
		printf("\n");
	}
}

int main() {
	matrix m;

	/* m = m0();
   printf("m:\n");
	matrix_print(m);
   printf("m1:\n");
   matrix_print(matrix_sub(m, 1));
   printf("m2:\n");
   matrix_print(matrix_sub(m, 2));
   printf("m3:\n");
   matrix_print(matrix_sub(m, 3));
	matrix_destroy(m); */

   m = m1();
	matrix_print(m);
	printf("Determinante: %lf\n", matrix_det(m));
	matrix_destroy(m);

	m = m2();
	matrix_print(m);
	printf("Determinante: %lf\n", matrix_det(m));
	matrix_destroy(m);

	m = matrix_input();
	matrix_print(m);
	printf("Determinante: %lf\n", matrix_det(m));
	matrix_destroy(m);

	return 0;
}
