#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Item {
	private:
		std::string name;

	public:
		// Constructors
		Item(std::string n);

		std::string getName() {
			return name;
		}

};

#endif /* ITEM_HPP_ */
