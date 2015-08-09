#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <string>

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
		Room(std::string n, std::string i);

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

		virtual void menu(bool& game);
		virtual void input(bool& game, Room*& current, Room*& lookat);

};

#endif /* ROOM_HPP_ */
