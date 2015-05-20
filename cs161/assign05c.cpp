#include <iostream>
#include <stdlib.h>
#include <cstring>

char* reverse (char* a, int SIZE);

int main (int argc, char *argv[]) {
   const int SIZE = 50;
   char input[SIZE];

   std::cout << "Input string: " << std::endl;
   std::cin.getline(input, SIZE);

   char* rev = reverse(input, SIZE);

   std::cout << "Original: " << input << std::endl;
   std::cout << "Reversed: " << rev << std::endl;

   return 0;
}

char* reverse (char* a, int SIZE) {
   char* r = new char[SIZE];
   int j = 0;
   
   for (int i = strlen(a)-1; i >= 0; i--) {
      r[j] = a[i];
      j++;
   }
   
   return r;
}
