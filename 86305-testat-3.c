//include libs
#include <stdio.h>

//start main function
int main() {
   //init vars
   int numberToCheck, divider = 2, outputs = 0;

   //get input
   scanf("%d", &numberToCheck);

   //check input
   if (numberToCheck < 2) {
      printf("%d kann nicht zerlegt werden.\n", numberToCheck);
   } else {
      //get smallest prime that divides
      while (numberToCheck % divider != 0) {
         divider++;
      }

      //start dividing
      while (numberToCheck % divider == 0) {
         //if no outputs and is prime => input is prime
         if (numberToCheck == divider && outputs == 0) {
            printf("%d ist prim.\n", numberToCheck);
            break;
         }

         //adjust number and output prime
         numberToCheck /= divider;
         printf("%d\n", divider);
         outputs++;

         //adjust prime to smallest dividing prime if necessary
         while (numberToCheck % divider != 0) {
            divider++;
         }

         //if number to check == prime, but outputs > 0 => last divider found
         if (numberToCheck == divider && outputs > 0) {
            printf("%d\n", divider);
            break;
         }
      }
   }

   //end main function
   return 0;
}