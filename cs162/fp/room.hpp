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
		/*void setRoom(Room* r) {
			this->link1 = r->link1;
			this->link2 = r->link2;
			this->link3 = r->link3;
			this->link4 = r->link4;
		}*/

		// Constructors
		Room(std::string n, std::string i);

		std::string getName() {
			return name;
		}
		std::string getInfo() {
			return info;
		}
		void links(Room* a, Room* b, Room* c, Room* d);

		void printRoom() {
			std::cout << "***" << getName() << "***" << std::endl;
			std::cout << getInfo() << std::endl;
		}

		void menu(bool& game);
		void input(bool& game, Room*& lookat);

};

#endif /* ROOM_HPP_ */
