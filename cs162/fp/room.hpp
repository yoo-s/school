#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "inv.hpp"
#include "item.hpp"

class Room {
	protected:
		std::string name;
		std::string info;
		Room* north;
		Room* east;
		Room* south;
		Room* west;

	public:

		// Constructors
		//Room(std::string n, std::string i);
		Room();

		std::vector<Item*> items;

		std::string getName() {
			return name;
		}
		std::string getInfo() {
			return info;
		}
		virtual void links(Room* a, Room* b, Room* c, Room* d);
		virtual Room* getN();
		virtual Room* getE();
		virtual Room* getS();
		virtual Room* getW();
		
		void printRoom() {
			std::cout << "***" << getName() << "***" << std::endl;
			std::cout << getInfo() << std::endl;
		}

		virtual void options();
		virtual void go(char action, Room*& current, Inventory inv);

		virtual void menu(bool& game);

//		virtual void input(bool& game, std::vector<Item*>& inv, Room*& current, Room*& lookat);

};

#endif /* ROOM_HPP_ */
