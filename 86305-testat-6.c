#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testat-6-neu.h"

// Vorgegeben
void print_polynome(polynom p[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%5.2lf x^2 + %5.2lf x + %5.2lf\n", p[i].a, p[i].b, p[i].c);
}

int main() {
	polynom p1[] = {
		{1,2,3},
		{2,5,-19},
		{2,6,-19},
		{0,0,0},
		{0,5,0},
		{0,7,0},
		{-1,0,0}
	};
	int n = sizeof(p1) / sizeof(polynom);
	polynom * p2 = (polynom *) malloc(n * sizeof(polynom));
	memcpy(p2, p1, sizeof(p1));
	printf("Vor Sortierung:\n");
	print_polynome(p1, n);
	qsort(p1, n, sizeof(polynom), cmp_polynom);
	printf("Nach Quicksort:\n");
	print_polynome(p1, n);
	bsort(p2, n, sizeof(polynom), cmp_polynom);
	printf("Nach Bubblesort:\n");
	print_polynome(p2, n);
	return 0;
}

// Ab hier: Aufgabe

// Ggf Hilfsfunktionen


// Aufgabe a), zu testen mit qsort
int cmp_polynom(const void * pp1, const void  * pp2) {
	int rc;
	
   double *polynom1 = (double *) pp1;
   double *polynom2 = (double *) pp2;
   rc = 0;

   for (int i = 0; i < 3; i++) {
      double p1i = *(polynom1 + i);
      double p2i = *(polynom2 + i);

      if (p1i < p2i) {
         rc = -1;
         break;
      } else if (p1i > p2i) {
         rc = 1;
         break;
      }
   }
	
	return rc;
}

// Aufgabe b)
void bsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {
   size_t n = nel - 1;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < (n - i); j++) {
         if ((*compar)((((char*)base) + (j * width)), (((char*)base) + ((j + 1) * width))) > 0) {
            do {
               size_t m = width;
               char *first = (((char*)base) + (j * width)), *second = (((char*)base) + ((j + 1) * width));
               do {
                  char tmp = *first;
                  *first++ = *second;
                  *second++ = tmp;
               } while (--m > 0);
            } while (0);
         }
      }
   }
}
