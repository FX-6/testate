//include libs
#include <stdio.h>

//start main function
int main() {
   //init vars
   double bruttogehalt, steuersatz, verheiratetensteuer, kinderbonus, steuern;
   int verheiratet, kinder;

   //get input
   scanf("%lf%d%d", &bruttogehalt, &verheiratet, &kinder);

   //check input
   if ((bruttogehalt >= 0) && (verheiratet == 1 || verheiratet == 0) && (kinder >= 0)) {
      //clac steuersatz
      if (bruttogehalt > 30000) {
         steuersatz = 0.25;
      } else if (bruttogehalt > 20000) {
         steuersatz = 0.2;
      } else if (bruttogehalt > 12000) {
         steuersatz = 0.15;
      } else {
         steuersatz = 0.12;
      }
      
      //calc verheiratetensteuer
      if (verheiratet) {
         verheiratetensteuer = 0.2;
      } else {
         verheiratetensteuer = 0;
      }

      //calc kinderbonus
      kinderbonus = kinder * 0.1;

      //calc Steuern
      steuern = bruttogehalt * steuersatz * (1 - (verheiratetensteuer + kinderbonus));

      //correct Steuern
      if (steuern < 0) {
         steuern = 0;
      }

      //print Steuern
      printf("%.2lf\n", steuern);
   } else {
      //error
      printf("Eingabefehler\n");
   }
   
   //end main function
   return 0;
}