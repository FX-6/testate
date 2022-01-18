#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "86305-testat-6-own.h"

void print_polynome(polynom p[], int n){
   int i;
   for (i = 0; i < n; i++) {
      printf("%5.2lf x^2 + %5.2lf x + %5.2lf\n", p[i].a, p[i].b, p[i].c);
   }
}

int main() {
   polynom p1[] = {
      {1, 2, 3},
      {2, 5, -19},
      {2, 6, -19},
      {0, 0, 0},
      {0, 5, 0},
      {0, 7, 0},
      {-1, 0, 0}
   };
   int n = sizeof(p1) / sizeof(polynom);
   polynom *p2 = (polynom *)malloc(n * sizeof(polynom));
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

//declare cmp_polynom
int cmp_polynom(const void *pp1, const void *pp2) {
   //init local vars, double array pointers for the arguments
   int rc = 0;
   double *polynom1 = (double *) pp1;
   double *polynom2 = (double *) pp2;

   //loop through the 3 polynom entrys
   for (int i = 0; i < 3; i++) {
      double p1i = *(polynom1 + i); // assign double value at position i of polynom1 to double p1i
      double p2i = *(polynom2 + i); // works because polyonom1 is 3 double values but you can only store one of them in p1i, which one is determined by i

      //compare them, if 1st is smaller set returnValue to -1, if second one is smaller set returnValue to 1, else returnValue stays 0 from init
      if (p1i < p2i) {
         rc = -1;
         break;
      } else if (p1i > p2i) {
         rc = 1;
         break;
      }
   }

   //return rc (being either 1, 0 or -1)
   return rc;
}

//declare bsort()
void bsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {
   //init local vars
   size_t n = nel - 1;

   //loop numberOfElements (nel) - 1, times through the whole array
   for (int i = 0; i < n; i++) {
      //compare numberOfElements - 1(n) - numberOfLoops(i) times two parts of the array 
      for (int j = 0; j < (n - i); j++) {
         //pass them into the compare function (link down below for more explanation)
         if ((*compar)((((char*)base) + (j * width)), (((char*)base) + ((j + 1) * width))) > 0) {
            // swap elements if not in right order (function copyed from original bsort, visti link down below for source)
            do {
               size_t m = width;
               char *a = (((char*)base) + (j * width)), *b = (((char*)base) + ((j + 1) * width));
               do {
                  char tmp = *a;
                  *a++ = *b;
                  *b++ = tmp;
               } while (--m > 0);
            } while (0);
            /* do {} while(0) (switch pos j and j+1) (https://code.woboq.org/userspace/glibc/stdlib/qsort.c.html))*/
            /* base[j] = (((char*)base) + (j * width)) (https://stackoverflow.com/questions/14119680/how-to-get-an-item-from-a-void-pointer-to-array-when-i-know-each-elements-size) */
         }
      }
   }
}