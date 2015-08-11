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
		bool flower;
		bool goldkey;

		//void setItem(Item* item);
		void print();
		void addItem(std::vector<Item*>& in, Item* item);
		void dropItem(std::vector<Item*>& in, Item* item);
};


#endif /* INV_HPP_ */
