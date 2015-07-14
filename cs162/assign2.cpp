/*********************************************
 ** Program: assign2.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/13/15
 ** Description: program that uses overloaded operators to solve arithmetic problems with rational numbers.
 ** Input: none
 ** Output: none
 ********************************************/

#include <iostream>
#include <string>

/*********************************************
 ** Class: Rational
 ** Description: creates object representing a rational number
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

		// overloaded arithmetic operators
		friend Rational operator +(const Rational &fr1, const Rational &fr2);
		friend Rational operator -(const Rational &fr1, const Rational &fr2);
		friend Rational operator *(const Rational &fr1, const Rational &fr2);
		friend Rational operator /(const Rational &fr1, const Rational &fr2);

		// overloaded << operator
		friend std::ostream& operator <<(std::ostream& os, const Rational &fr);
};

/*********************************************
 ** Function: overloaded operator +
 ** Description: finds numerator/denominator of a sum of two fractions
 ** Parameters: const Rational &fr1, const Rational &fr2
 ********************************************/
Rational operator +(const Rational &fr1, const Rational &fr2) {
	int n, d;
	n = fr1.num*fr2.den + fr2.num*fr1.den;
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
	n = fr1.num*fr2.den - fr2.num*fr1.den;
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
	if (y == 0) {
		return x;
	} else {
		return gcf(y, x % y);
	}
}

/*********************************************
 ** Function: Rational::reduce
 ** Description: reduces a Rational to simplest form
 ** Parameters: none
 ********************************************/
void Rational::reduce() {
	int div = gcf(num, den);
	// simplify fraction
	num /= div;
	den /= div;

	// check if denominator is negative, switch negation to numerator if it is
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
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
	Rational fr1(0, 0), fr2(0, 0);
	char op;

	// Prompt user for arithmetic expression. For negative numbers type the
	//		negative sign next to the number w/o spacing, i.e. -2 and not - 2
	// Any-digit integers, positive or negative, are valid as input numerators or
	//		denominators.
	std::cout << "Enter arithmetic problem of the form, 3 / 4 + 5 / 9: ";
	std::cin >> fr1.num;
	std::cin.ignore(3, '\n');			// this skips the apaces until next number
	std::cin >> fr1.den;
	std::cin >> op;						// character representing arithmetic operator
	std::cin >> fr2.num;
	std::cin.ignore(3, '\n');
	std::cin >> fr2.den;
	std::cout << std::endl;

	if (op == '+') {					// addition case
		Rational sum = fr1 + fr2;
		sum.reduce();
		std::cout << sum << std::endl;
	} else if (op == '-') {				// subtraction case
		Rational dif = fr1 - fr2;
		dif.reduce();
		std::cout << dif << std::endl;
	} else if (op == '*') {				// multiplication case
		Rational pro = fr1 * fr2;
		pro.reduce();
		std::cout << pro << std::endl;
	} else if (op == '/') {				// division case
		Rational quo = fr1 / fr2;
		quo.reduce();
		std::cout << quo << std::endl;
	} else {
		std::cout << "Not a valid expression. Please try again." << std::endl;
	}

	return 0;

}
