#include <iostream>

int main() {

   int sellprice;
   float commission;

   std::cout << "What is the selling price? " << std::endl;
   std::cin >> sellprice;
   std::cout << "The selling price is $" << sellprice << std::endl;

   if (sellprice < 50000) {
      commission = (int)(.01 * sellprice);
   } else if (50000 < sellprice && sellprice < 100000) {
      commission = (int)(.03 * sellprice);
   } else if (100000 < sellprice && sellprice < 200000) {
      commission = (int)(.05 * sellprice);
   } else if (200000 < sellprice && sellprice < 500000) {
      commission = (int)(.075 * sellprice);
   } else if (500000 < sellprice && sellprice < 1000000) {
      commission = (int)(.1 * sellprice);
   } else if (sellprice > 1000000) {
      commission = (int)(.02 * sellprice);
   }

   std::cout << "The commission will be $" << commission << std::endl;
   std::cout << "In addition, any selling price greater than $200,000 earns a nomination for REALTOR of the month." << std::endl;

   return 0;
}
