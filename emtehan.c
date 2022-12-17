#include <stdio.h>

int main(void) {
   int    userInt;
   double userDouble;
   char userChar = 'z';
   char userString[8];
   // FIXME: Define char and string variables similarly
   
   
   

   scanf("%c", &userChar);
   
   scanf("%s", userString);
   
   scanf("%d", &userInt);
   
   
   printf("%d %c %s", userInt, userChar, userString); 

return 0;
}