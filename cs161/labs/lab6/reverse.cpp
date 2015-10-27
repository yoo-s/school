#include <iostream>

int main () {
   int size = 5;
   int orig[size];
   int rev[size];
   int j = 0;

   for (int i = 0; i < size; i++) {
      std::cin >> orig[i];
   }
   
   for (int i = size-1; i >= 0; i--) {
      rev[j] = orig[i];
      j++;
   }
   std::cout << '\n' << std::endl;

   for (int i = 0; i < size; i++) {
      std::cout << rev[i] << " ";
   }

   return 0;
}
