#ifndef PIANO_HPP_
#define PIANO_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Piano : public Room {
/*	private:
		std::string name;
		std::string info;
		Room* link1;
		Room* link2;
		Room* link3;
		Room* link4;
*/
	public:
		// Constructors
		Piano(std::string n, std::string i);

		std::string getName() {
			return name;
		}
		std::string getInfo() {
			return info;
		}

		void printRoom() {
			std::cout << "***" << getName() << "***" << std::endl;
			std::cout << getInfo() << std::endl;
		}
		
		void input(bool& game, std::vector<Item*>& inv, Room*& current, Room*& lookat);

};

#endif /* PIANO_HPP_ */
