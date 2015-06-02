#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

void printVect(std::vector <int> vec);

int main() {
   const int MONTHS = 12;
   std::vector <int> num(10, 2);
   std::vector <double> num2(5);

   for (int index = 0; index < 10; index++) {
      std::cout << num[index] << " ";
   }
   std::cout << std::endl;
   for (int index = 0; index < 5; index++) {
      std::cout << num2[index] << " ";
   }
   std::cout << std::endl;
   num2.push_back(4);
   std::cout << num2[4] << num2[5] << std::endl;

   printVect(num);

   std::string name[MONTHS] = { "January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August", 
			   "September", "October",  "November", "December" };

   int days[MONTHS] = { 31, 28, 31, 30,
                        31, 30, 31, 31,
                        30, 31, 30, 31 };

   for (int i = 0; i < MONTHS; i++) {
      std::cout << std::setw(9) << name[i] << " has " << days[i] << " days.\n";
   }




   return 0;
}

void printVect(std::vector <int> vec) {
   for (int i = 0; i < vec.size(); i++) {
      std::cout << vec[i] << " ";
   }
   std::cout << std::endl;
}
