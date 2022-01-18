#include <stdio.h>
#include <stdlib.h>
#include "testat-7.h"

int fbsort(char * filename, size_t width, int (*compar)(const void *, const void *)) {
	int nel;
   
   int fSize;
   FILE * f = fopen(filename, "r+");

   if (f == NULL) {
      return -1;
   }

   fseek(f, 0, SEEK_END);
   fSize = ftell(f);
   if (fSize % width != 0) {
      return -2;
   }
   nel = fSize / width;

   size_t n = fSize / width;
   char *buf1, *buf2;
   buf1 = (char*) malloc(width);
   buf2 = (char*) malloc(width);

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < (n - 1); j++) {
         fseek(f, (width * j), SEEK_SET);
         fread(buf1, width, 1, f);
         fread(buf2, width, 1, f);

         if ((*compar)(buf1, buf2) > 0) {
            fseek(f, (j * width), SEEK_SET);
            fwrite(buf2, width, 1, f);
            fseek(f, ((j + 1) * width), SEEK_SET);
            fwrite(buf1, width, 1, f);
         }
      }
   }

   free(buf1);
   free(buf2);

	return nel;
}
