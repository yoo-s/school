#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>
#include <string>

class Item {
	private:
		std::string name;
		std::string info;

	public:
		// Constructors
		Item(std::string n, std::string i);

		std::string getName() {
			return name;
		}
		std::string getInfo() {
			return info;
		}

		void printItem() {
			std::cout << getInfo() << std::endl;
		}

};

#endif /* ITEM_HPP_ */
