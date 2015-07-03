/*********************************************
 ** Program: matrix.cpp
 ** Author: Soo-Min Yoo
 ** Date: 07/02/15
 ** Description: program that takes two matrices and prints its product matrix.
 ** Input: none
 ** Output: return 0
 ********************************************/

#include <iostream>

/*********************************************
 ** Function: matrix
 ** Description: loops through the two input matrices and assigns product values
 ** to each element in third matrix.
 ** Parameters: int (*arr1)[3], int (*arr2)[2], int (*arr3)[2]
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ********************************************/
void matrix(int (*arr1)[3], int (*arr2)[2], int (*arr3)[2]) {
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			arr3[i][k] = 0;
			for (int j = 0; j < 3; j++) {
				arr3[i][k] += arr1[i][j]*arr2[j][k];
			}
		}
	}

	std::cout << "Product matrix:" << std::endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << arr3[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/*********************************************
 ** Function: main
 ** Description: fills two matrices and prints them and its product matrix
 ** through the matrix function.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {

	int arr1[2][3];
	int arr2[3][2];
	int arr3[2][2];

	// Fills input matrices with input integers
	std::cout << "Fill array 1" << std::endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "Enter a number: ";
			std::cin >> arr1[i][j];
		}
	}
	std::cout << std::endl;
	std::cout << "Fill array 2" << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << "Enter a number: ";
			std::cin >> arr2[i][j];
		}
	}

	std::cout << std::endl;

	// Prints input matrices
	std::cout << "Array 1:" << std::endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Array 2:" << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << arr2[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// Calculates and prints product matrix
	matrix(arr1, arr2, arr3);

	return 0;
}
