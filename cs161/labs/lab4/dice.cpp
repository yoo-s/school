#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

   int point;

   
   srand(time(NULL));

   while (true) {
      int roll = rand()%6+1;
      int roll2 = rand()%6+1;
      int result = roll+roll2;

      std::cout << "The result is " << result << "." << std::endl;

      if (result == 2 || result == 3 || result == 12) {
	 std::cout << "You lose!" << std::endl;
      } else if (result == 7 || result == 11) {
	 std::cout << "You win!" << std::endl;
      } else {
	 point = result;
	 int roll3 = rand()%6+1;
	 int roll4 = rand()%6+1;
	 int result2 = roll3+roll4;

	 std::cout << "The second result is " << result2 << "." << std::endl;
	 if (result2 == 7) {
	    std::cout << "You lose!" << std::endl;
	    break;
	 } else if (result2 == point) {
	    std::cout << "You win!" << std::endl;
	    break;
	 }
      }
   }

   return 0;
}
