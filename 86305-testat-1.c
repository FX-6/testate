//include libs
#include <stdio.h>

//start main function
int main() {
   //init vars
   int year, a, b, c, k, p, q, M, d, N, e, Ostern, day, month = 3;

   //get year
   scanf("%d", &year);

   //calculations
   a = year % 19;
   b = year % 4;
   c = year % 7;
   k = year / 100;
   p = ((8 * k) + 13) / 25;
   q = k / 4;
   M = (15 + k - p - q) % 30;
   d = ((19 * a) + M) % 30;
   N = (4 + k - q) % 7;
   e = ((2 * b) + (4 * c) + (6 * d) + N) % 7;
   Ostern = 22 + d + e;

   day = Ostern;
   day -= ((day > 31) * 31);
   month += (Ostern > 31);

   //print date
   printf("%02d.%02d.%04d\n", day, month, year);

   //end main function
   return 0;
}