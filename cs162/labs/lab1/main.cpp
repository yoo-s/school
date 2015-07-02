//====================================
//Name: main.cpp
//Author:
//Version: 
//Copyright: 
//Description: Test for makefile
//====================================

#include <iostream>
#include "average.h"
//#include "summation.h"
int main() {
   int size;
   double num;
   std::cout << "Array size? ";
   std::cin >> size;
   const double series[size];

   for (int i = 0; i < size; i++) {
      std::cout << "Enter number: ";
      std::cin >> num;
      series[i] = num;
   }

   series = arr;
   std::cout << "The average is: " << avg(series, size) << std::endl;
   //std::cout << "The summation is " << sum(series, size) << std::endl;

   return 0;
}
