#include <iostream>

int main() {

   bool answer;
   std::cout << "Do you like vi as an editor?" << std::endl;
   std::cin >> answer;

   if (answer == 1) {
      std::cout << "You love vi!" << std::endl;
   } else {
      std::cout << "You hate vi!" << std::endl;
   }

   return 0;
}

