#include <iostream>
#include <string>

class Fraction {
   public:
      int numerator;
      int denominator;
   public:
      void setNum(int n) {
	 numerator = n;
      }

      void setDen(int d) {
	 denominator = d;
      }

      double getRatio() {
	 return (double)numerator/denominator;
      }

      void getFraction();
};

void Fraction::getFraction() {
   int gcd = 0;
   
   for (int i = 2; i <= numerator && i <= denominator; i++) {
      if (numerator % i == 0 && denominator % i == 0) {
	 gcd = i;
      } else {
	 gcd = gcd;
      }
   }

   if (gcd == 0) {
      std::cout << numerator << "/" << denominator << std::endl;
   } else {
      std::cout << (numerator/gcd) << "/" << (denominator/gcd) << std::endl;
   }
}

int main() {
   Fraction test;

   test.setNum(20);
   test.setDen(60);

   std::cout << "The ratio of the two numbers is: " << test.getRatio() << std::endl;
   std::cout << "The simplified fraction is: ";
   test.getFraction();

   return 0;
}
