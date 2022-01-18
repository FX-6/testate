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
   char s[100][100];
   int k = 0, m = 0;

   for (int i = 0; i <= (strlen(in) / n); i++) {
      for (int j = 0; j < n; j++) {
         s[i][j] = in[k];
         k++;
      }
   }

   k = 0;
   m = (strlen(in) / n);

   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
         if (s[j][i] == '\0') {
            m--;
         } else {
            out[k] = s[j][i];
            k++;
         }
      }
   }

   out[k] = '\0';
}
