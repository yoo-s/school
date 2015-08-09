#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <string>

class Room {
	private:
		std::string name;
		std::string info;
		Room* link1;
		Room* link2;
		Room* link3;
		Room* link4;

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

		void printRoom() {
			std::cout << "***" << getName() << "***" << std::endl;
			std::cout << getInfo() << std::endl;
		}

		virtual void menu(bool& game);
		virtual void input(bool& game, Room*& current, Room*& lookat);

};

#endif /* ROOM_HPP_ */
