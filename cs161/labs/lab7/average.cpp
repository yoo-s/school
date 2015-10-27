#include <iostream>
#include <stdlib.h>

double average(int a, int b, int c, int d, int e);

int main(int argc, char *argv[]) {

   std::cout << "Average Calculation\n" << std::endl;
   
   std::cout << "Integers: ";
   for (int i = 1; i <= 5; i++) {
      std::cout << argv[i] << " ";
   }

   if (argc <= 1) {
      std::cerr << "Usage: " << argv[0] << " int1, int2, int3, int4, int5";
      return 1;
   }

   int a = atoi(argv[1]);
   int b = atoi(argv[2]);
   int c = atoi(argv[3]);
   int d = atoi(argv[4]);
   int e = atoi(argv[5]);

   std::cout << std::endl;
   std::cout << "The average is: " << average(a, b, c, d, e) << "\n" << std::endl;


   return 0;

}

double average (int a, int b, int c, int d, int e) {
   
   return (double)(a+b+c+d+e)/5;

}
