#include <stdio.h>
#include <stdlib.h>
#include "testat-7.h"

int fbsort(char * filename, size_t width, int (*compar)(const void *, const void *)) {
	int nel;

   //init local vars and open file (f)
   int fSize;
   FILE * f = fopen(filename, "r+");

   //check if file is valid
   if (f == NULL) {
      return -1;
   }

   //get fileSize (fSize), check if valid, get number of elements (nel)
   fseek(f, 0, SEEK_END);
   fSize = ftell(f);
   if (fSize % width != 0) {
      return -2;
   }
   nel = fSize / width;

   //get numberOfElements again (n) (I know n = nel, there is no need for n, used it anyways)
   size_t n = fSize / width;
   //make 2 char type buffers with malloc
   char *buf1, *buf2;
   buf1 = (char*) malloc(width);
   buf2 = (char*) malloc(width);

   //loop through array n times
   for (int i = 0; i < n; i++) {
      //compare n - 1 times the array values (a bit less efficent than the other bsort, because - 1 instead of - i)
      for (int j = 0; j < (n - 1); j++) {
         //go to the element with index j, copy two elements to the buffers
         fseek(f, (width * j), SEEK_SET);
         fread(buf1, width, 1, f);
         fread(buf2, width, 1, f);

         //pass them to the compar function, if wrong order change them
         if ((*compar)(buf1, buf2) > 0) {
            //go with fseek to first of the two elements
            fseek(f, (j * width), SEEK_SET);
            //write second buffer to that place
            fwrite(buf2, width, 1, f);
            //second fseek is useless, gonna keep it anyways
            fseek(f, ((j + 1) * width), SEEK_SET);
            //write first buffer to second place
            fwrite(buf1, width, 1, f);
         }
      }
   }

   //free memory of mallocs
   free(buf1);
   free(buf2);

   //return number of elements, only reached if no -1 or -2 error
	return nel;
}
//DU KEK lul
