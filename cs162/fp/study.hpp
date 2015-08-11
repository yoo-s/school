#ifndef STUDY_HPP_
#define STUDY_HPP_

#include <iostream>
#include <string>
#include "room.hpp"

class Study : public Room {
	public:

		Study();

		void options();
		void go(char action, Room*& current, Inventory inv);

/*class Study : public Room {
	private:
		std::string name;
		std::string info;
		Room* link1;
		Room* link2;
		Room* link3;
		Room* link4;

	public:
		// Constructors
		Study(std::string n, std::string i);

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
		
		void input(bool& game, Room*& current, Room*& lookat);
*/
};

#endif /* STUDY_HPP_ */
