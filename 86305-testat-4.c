//include libs
#include <stdio.h>

//init functions
int primfaktor(int input);

//start main function
int main() {
   int pf;

   while ((pf = primfaktor(12)) > 1) {
      printf("%d\n", pf);
   }

   while ((pf = primfaktor(7)) > 1) {
      printf("%d\n", pf);
   }

   printf("%d\n", primfaktor(1));

   return 0;
}

//declare primfaktor()
int primfaktor(int input) {
   //init local vars
   static int divider = 2, lastNumber = 0, numberToCheck = 0, lastOutput = 0;

   //check input for error
   if (input < 2) {
      return -2;
   }

   //adjust vars if new number
   if (input != lastNumber) {
      lastNumber = input;
      numberToCheck = input;
      divider = 2;
      lastOutput = 0;
   }

   //get smallest prime that divides
   while (numberToCheck % divider != 0) {
      divider++;
   }

   //ckeck if last output happend
   if (lastOutput == 1) {
      return -1;
   } else {
      if (numberToCheck == divider) {
         lastOutput = 1;
      } else {
         //update numberToCheck only if not last output
         numberToCheck /= divider;
      }

      //return divider
      return divider;
   }
}