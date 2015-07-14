/*********************************************
 ** Program: assign2.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/13/15
 ** Description: program that uses overloaded operators to solve arithmetic problems with rational numbers.
 ** Input: none
 ** Output: none
 ********************************************/

#include <iostream>

/*********************************************
 ** Class: Rational
 ** Description: 
 ** Pre-Conditions: none
 ********************************************/
class Rational {
	public:
		int num;
		int den;
		
		Rational(int n, int d) {
			num = n;
			den = d;
		}
		int gcf(int x, int y);
		void reduce();

		friend Rational operator +(const Rational &fr1, const Rational &fr2);
		friend Rational operator -(const Rational &fr1, const Rational &fr2);
		friend Rational operator *(const Rational &fr1, const Rational &fr2);
		friend Rational operator /(const Rational &fr1, const Rational &fr2);

		friend std::ostream& operator <<(std::ostream& os, const Rational &fr);
};

/*********************************************
 ** Function: overloaded operator +
 ** Description: finds numerator/denominator of a sum of two fractions
 ** Parameters: const Rational &fr1, const Rational &fr2
 ********************************************/
Rational operator +(const Rational &fr1, const Rational &fr2) {
	int n, d;
	n = fr1.num*fr2.den + fr1.num*fr2.den;
	d = fr1.den*fr2.den;
	return Rational(n, d);
}

/*********************************************
 ** Function: overloaded operator -
 ** Description: finds numerator/denominator of a difference of two fractions
 ** Parameters: const Rational &fr1, const Rational &fr2
 ********************************************/
Rational operator -(const Rational &fr1, const Rational &fr2) {
	int n, d;
	n = fr1.num*fr2.den - fr1.num*fr2.den;
	d = fr1.den*fr2.den;
	return Rational(n, d);
}

/*********************************************
 ** Function: overloaded operator *
 ** Description: finds numerator/denominator of a product of two fractions
 ** Parameters: const Rational &fr1, const Rational &fr2
 ********************************************/
Rational operator *(const Rational &fr1, const Rational &fr2) {
	int n, d;
	n = fr1.num * fr2.num;
	d = fr1.den * fr2.den;
	return Rational(n, d);
}

/*********************************************
 ** Function: overloaded operator /
 ** Description: finds numerator/denominator of a quotient of two fractions
 ** Parameters: const Rational &fr1, const Rational &fr2
 ********************************************/
Rational operator /(const Rational &fr1, const Rational &fr2) {
	int n, d;
	n = fr1.num * fr2.den;
	d = fr1.den * fr2.num;
	return Rational(n, d);
}

/*********************************************
 ** Function: Rational::gcf
 ** Description: finds the greatest common factor of a Rational's numerator/denominator
 ** Parameters: int x, int y
 ********************************************/
int Rational::gcf(int x, int y) {
	//find GCD of num and den
	while (x != y) {
		if (x > y) {
			x -= y;
		} else {
			y -= x;
		}
	}
	return x;
}

/*********************************************
 ** Function: Rational::reduce
 ** Description: reduces a Rational to simplest form
 ** Parameters: none
 ********************************************/
void Rational::reduce() {
	int div = gcf(num, den);
	num /= div;
	den /= div;

	if (den < 0) {
		num *= -1;
		den *= -1;
	}
	std::cout << num << "/ ";
	std::cout << den;
}

/*********************************************
 ** Function: overloaded operator <<
 ** Description: prints out objects of type Rational
 ** Parameters: std::ostream &os, const Rational &fr
 ********************************************/
std::ostream& operator <<(std::ostream &os, const Rational &fr) {
	std::cout << fr.num << "/" << fr.den << std::endl;
	return os;
}

/*********************************************
 ** Function: main
 ** Description: runs program
 ********************************************/
int main() {

	Rational fr1(2, 5), fr2(1, 4);
	int option;

	Rational sum = fr1 + fr2;
	Rational dif = fr1 - fr2;
	Rational pro = fr1 * fr2;
	Rational quo = fr1 / fr2;

	sum.reduce();
	dif.reduce();
	pro.reduce();
	quo.reduce();

	std::cout << sum << std::endl;
	std::cout << dif << std::endl;
	std::cout << pro << std::endl;
	std::cout << quo << std::endl;
	/*
	std::cout << "2) Subtraction" << std::endl;
	std::cout << "3) Multiplication" << std::endl;
	std::cout << "4) Division" << std::endl;
	std::cout << "Please select operator to test:" << std::endl;
	std::cin >> option;

	if (option == 1) {
		//addition
	} else if (option == 2) {
		//subtraction
	} else if (option == 3) {
		//multiplication
	} else if (option == 4) {
		//division
	} else {
		std::cout << "Not a valid option. Please try again." << std::endl;
	}
*/

	return 0;

}
