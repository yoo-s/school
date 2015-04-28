#include <iostream>

int main() {
   int num;
   int value;
   int sum = 0;

   std::cout << "Please enter a number: " << std::endl;
   std::cin >> num;
   std::cout << std::endl;

   for (int i = 1; i <= num; i++) {
      std::cout << "Enter value: " << std::endl;
      std::cin >> value;
      sum += value;
   }

   double average = (double)sum/num;
   std::cout << "The average is: " << average << std::endl;
   
   return 0;
}
