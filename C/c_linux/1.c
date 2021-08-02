#include <stdio.h>
 
const int MAX = 4;
 
int main () {

   char *names[4] = {
      "Zara Ali",
      "Hina Ali",
      "Nuha Ali",
      "Sara Ali"
   };
   
   int i = 0;
 names[i]="abc";
   for ( i = 0; i < MAX; i++) {
      printf("Value of names[%d] = %s\n", i, names[i] );
   }
  
   
   return 0;
}
