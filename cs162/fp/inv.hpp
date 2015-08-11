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
		void print(std::vector<Item*> in);
		void addItem(std::vector<Item*>& in, Item* item);
		void dropItem(std::vector<Item*>& in, Item* item);
};

Inventory inv;


#endif /* INV_HPP_ */
