#include <iostream>
#include <string.h>

//

int main (int argc, char *argv[]) {
   char *input = NULL;

   int i = 0;

   std::cin >> input;

   for (i = strlen(input); i >= 0; i--) {
      std::cout << input[i];
   }
   std::cout << std::endl;

   return 0;
}
