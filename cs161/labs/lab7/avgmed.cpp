#include <iostream>
#include <stdlib.h>

double average(int a, int b, int c, int d, int e);
int median(int a1[]);
void sortArray(int array[], int size);

int main(int argc, char *argv[]) {
   
   // Lists the 5 integers
   std::cout << "Integers: ";
   for (int i = 2; i <= 6; i++) {
      std::cout << argv[i] << " ";
   }

   // Prints error message if not enough command line arguments
   if (argc <= 1) {
      std::cerr << "Usage: " << argv[0] << " int1, int2, int3, int4, int5";
      return 1;
   }

   bool med = true;
   if (argv[1][0] == 'a') {		// If a, calculate average
      med = false;
   }
   else if (argv[1][0] == 'm') {	// If m, calculate median
      med = true;
   }
   int a = atoi(argv[2]);
   int b = atoi(argv[3]);
   int c = atoi(argv[4]);
   int d = atoi(argv[5]);
   int e = atoi(argv[6]);
   int a1[5] = {a, b, c, d, e};

   std::cout << std::endl;
   
   if (med) {
      std::cout << "The median is: " << median(a1) << "\n" << std::endl;
   }
   else {
      std::cout << "The average is: " << average(a, b, c, d, e) << "\n" << std::endl;
   }

   return 0;

}

// Returns average of 5 integers
double average (int a, int b, int c, int d, int e) {
   
   return (double)(a+b+c+d+e)/5;

}

// Returns median of 5 integers
int median (int a1[]) {
   
   sortArray(a1, 5);
   
   return a1[2];
}

// Source: Gaddis et al, Starting Out with C++; Early Objects (8th Ed.). pg 607
// Sorts array
void sortArray (int array[], int size) {
   
   int temp;
   bool swap;

   do {
      swap = false;
      for (int count = 0; count < (size-1); count++) {
	 if (array[count] > array[count+1]) {
	    temp = array[count];
	    array[count] = array[count+1];
	    array[count+1] = temp;
	    swap = true;
	 }
      }
   } while (swap);	// Loop again if a swap occurred on this pass.
}
