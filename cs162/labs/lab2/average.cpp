/**
 *  * This function should output the average of an array 
 *   * (the array should have hard coded values)
 *    **/

#include <iostream>
#define SIZE 4

double average(int* valueArray, int size);

int main(){
	int array[SIZE] = {1, 2, 3, 4};
	double average_answer;
	average_answer = average(array, SIZE);
	std::cout << average_answer << std::endl;
}

/**
 *  * Function to calculate average of 
 *   * @param valueArray (populated array of values)
 *    * @param size (number of values inside array)
 *     * @return the average value of the array contents
 *      **/ 

double average(int* valueArray, int size){
	int i;
	int sum = 0;
	double result;

	/* average calculation*/
	for(i = 0; i < size; i++){
		sum = sum + valueArray[i];
	}

	result = (double)sum / size;
	return result;
}

