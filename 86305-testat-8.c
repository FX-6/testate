#include <stdlib.h> 
#include <malloc.h>
#include "testat-8.h"

/**********************************************************************
 * Die folgenden drei Funktionen duerfen nicht veraendert werden!!
 **********************************************************************/

matrix matrix_create(int n) {
	matrix m = {n, malloc(n * n * sizeof(double))};
	return m;
}

void matrix_destroy(matrix m) {
	free(m.p);
}

double * matrix_element(matrix A, int z, int s) {
	return A.p + (z - 1) * A.n + (s - 1);
}

/**********************************************************************
 * Implementiern Sie die folgenden beiden Funktionen.
 **********************************************************************/

double matrix_det(matrix A) {
	double d = 0;
	
   //check for base case (base case: A.n == 1)
   if (A.n > 1) {
      //not base case, add averything up
      for (int k = 1; k <= A.n; k++) {
         //check if -1^(k+1) is -1 or +1 (-1 -> -=; +1 -> +=), calculate the rest (a₁ₖ * |A₁ₖ|)
         if ((k + 1) % 2 == 1) {
            d -= *matrix_element(A, 1, k) * matrix_det(matrix_sub(A, k));
         } else {
            d += *matrix_element(A, 1, k) * matrix_det(matrix_sub(A, k));
         }
      }
   } else {
      //handle base case
      d = *matrix_element(A, 1, 1);
   }

	return d;
}

matrix matrix_sub(matrix A, int k) {
	matrix B;

   //check for base case (base case: A.n == 1)
   if (A.n > 1) {
      //new n, create smaller matrix
      int n = A.n - 1;
      B = matrix_create(n);

      //recreate for loops from pdf
      for (int z = 1; z <= n; z++) {
         for (int s = 1; s <= n; s++) {
            if (s < k) {
               *matrix_element(B, z, s) = *matrix_element(A, (z + 1), s);
            } else {
               *matrix_element(B, z, s) = *matrix_element(A, (z + 1), (s + 1));
            }
         }
      }
   } else {
      //handle base case
      B = matrix_create(1);
      *matrix_element(B, 1, 1) = *matrix_element(A, 1, 1);
   }

	return B;
}
