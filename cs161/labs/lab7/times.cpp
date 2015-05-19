#include <iostream>
#include <stdlib.h>
#include <iomanip>

int main() {

   int size;

   std::cout << "Multiplication Table:\n" << std::endl;
   std::cout << "Table size: ";
   std::cin >> size;

   int table[size+1][size+1];


   // Populates top row heading
   for (int i = 1; i < size+1; i++) {
      table[0][i] = i;
   }
   // Populates left column heading
   for (int i = 1; i < size+1; i++) {
      table[i][0] = i;
   }
   // Populates table values
   for (int i = 1; i < size+1; i++) {
      for (int j = 1; j < size+1; j++) {
	 table[i][j] = i*j;
      }
   }

   // Prints table
   for (int i = 0; i < size+1; i++) {
      for (int j = 0; j < size+1; j++) {
	 if (i == 0 && j == 0) {
	    std::cout << "    ";
	 }
	 else {
	    std::cout << std::setw(3) << table[i][j] << " ";
	 }
      }
      std::cout << std::endl;
   }

   return 0;

}

