#include <iostream>

void fill (int a1[], int size) {
   for (int i = 0; i < size; i++) {
      std::cin >> a1[i];
   }
   std::cout << '\n' << std::endl;
}

void reverse (int a1[], int a2[], int size) {
   int j = 0;
   for (int i = size-1; i >= 0; i--) {
      a2[j] = a1[i];
      j++;
   }
   std::cout << '\n' << std::endl;
   for (int i = 0; i < size; i++) {
      std::cout << a2[i] << " ";
   }
}

int main (int argc, char *argv[]) {
   int orig[5];
   int rev[5];

   fill (orig, 5);
   reverse (orig, rev, 5);

   return 0;
}
