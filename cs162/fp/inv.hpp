#ifndef INV_HPP_
#define INV_HPP_

#include <iostream>
#include <string>

class Item;

class Inventory {
	public:

		Inventory();

		bool woodenkey;
		bool velvetkey;
		bool dogfood;
		bool bowl;
		bool goldkey;

		void print();
};


#endif /* INV_HPP_ */
