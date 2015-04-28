#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int  sides;

	// find number of sides on die
	cout << "How many sides does the die have? ";
	cin >> sides;

	cout << "The die has " << sides << " sides." << endl;

	int roll;
	srand(time(NULL));
	roll = rand()%sides+1;

	cout << "*rolls die*" << endl;
	cout << "The rolled die is " << roll << endl;

	return 0;
}
