//include libs
#include <stdio.h>
#include <string.h>

//init function
void skytale(char *in, int n, char *out);

//start main function
int main() {
   //init local vars
   char in[] = "encrypt this string", out[100];
   int n = 3;

   //call skytale()
   skytale(in, n, out);

   //print result
   printf("%s\n", out);

   //end main function
   return 0;
}

//declare skytale()
void skytale(char *in, int n, char *out) {
   //init local vars, n2 is used to loop through the string vertically, k is used to count the outputs
   int n2 = (strlen(in) / n), k = 0;

   //for every column
   for (int i = 0; i < n; i++) {
      //for every row in that column
      for (int j = 0; j <= n2; j++) {
         //check if the char is the escape sequence
         if (in[((j * n) + i)] == '\0') {
            //dont read the last row if it is not in the string anymore
            n2--;
         } else {
            //add the char to the output
            out[k] = in[((j * n) + i)];
            k++;
         }
      }
   }

   //add an end to the string
   out[k] = '\0';
}