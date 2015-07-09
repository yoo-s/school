//CS 162 001 lab 3
//Soo-Min Yoo
//Munahi Alqahtani
//Faisal Alshehhi

#include <iostream>
#include <vector>
#include <string>

class dog {
	public:
		std::string name;
		std::string owner;
		std::string trainer;
		std::string breed;
		std::string breedclass;

	public:
		void set_breedclass(std::string c) {			// store breedclass name
			breedclass = c;
		}
		void set_name(std::string n) {					// store name
			name = n;
		}
		void set_breed(std::string b) {					// store breed
			breed = b;
		}
		void set_owner(std::string o) {					// store owner name
			owner = o;
		}
		void set_trainer(std::string t) {				// store trainer name
			trainer = t;
		}
		void show();
		void displayInfo();
		void pose();
		//void line();
};

void dog::show() {
	std::cout << "Now showing" << std::endl;
}

// prints dog name, breed, owner, and trainer
void dog::displayInfo() {
	std::cout << name << " " << breed << std::endl;
	std::cout << "Owner- " << owner << std::endl;
	std::cout << "Trainer- " << trainer << std::endl;
}

void dog::pose() {
	std::cout << "Now posing\n" << std::endl;
}


int main() {
	// initialize variables
	std::string breedclass;
	std::string name;
	std::string breed;
	std::string owner;
	std::string trainer;

	// initialize each dog and their respective vectors of breed class
	dog goldie;
	dog pointer;
	dog setter;
	std::vector<std::string> hunters;

	dog collie;
	dog shepherd;
	dog husky;
	std::vector<std::string> workers;

	dog pom;
	dog yorkie;
	dog shihtzu;
	std::vector<std::string> toys;

	// for each of the 9 listed dogs, ask for user input on dog info
	for (int i = 0; i < 9; i++) {
		std::cout << "Dog name? ";
		std::cin >> name;
		std::cout << "Dog breed? ";
		std::cin >> breed;
		std::cout << "Owner? ";
		std::cin >> owner;
		std::cout << "Trainer? ";

	// depending on their breed, store dog info into proper dog object
		if (breed == "goldie") {
			goldie.set_name(name);
			goldie.set_breed(breed);
			goldie.set_owner(owner);
			goldie.set_trainer(trainer);
			hunters.push_back(goldie);			// place goldie into hunters vector
		} else if (breed == "pointer") {
			pointer.set_name(name);
			pointer.set_breed(breed);
			pointer.set_owner(owner);
			pointer.set_trainer(trainer);
			hunters.push_back(pointer);			// place pointer into hunters vector
		} else if (breed == "setter") {
			setter.set_name(name);
			setter.set_breed(breed);
			setter.set_owner(owner);
			setter.set_trainer(trainer);
			hunters.push_back(setter);			// place setter into hunters vector
		} else if (breed == "collie") {
			collie.set_name(name);
			collie.set_breed(breed);
			collie.set_owner(owner);
			collie.set_trainer(trainer);
			workers.push_back(collie);			// place collie into workers vector
		} else if (breed == "shepherd") {
			shepherd.set_name(name);
			shepherd.set_breed(breed);
			shepherd.set_owner(owner);
			shepherd.set_trainer(trainer);
			workers.push_back(shepherd);			// place shepherd into workers vector
		} else if (breed == "husky") {
			husky.set_name(name);
			husky.set_breed(breed);
			husky.set_owner(owner);
			husky.set_trainer(trainer);
			workers.push_back(husky);			// place husky into workers vector
		} else if (breed == "pom") {
			pom.set_name(name);
			pom.set_breed(breed);
			pom.set_owner(owner);
			pom.set_trainer(trainer);
			toys.push_back(pom);			// place pom into toys vector
		} else if (breed == "yorkie") {
			yorkie.set_name(name);
			yorkie.set_breed(breed);
			yorkie.set_owner(owner);
			yorkie.set_trainer(trainer);
			toys.push_back(yorkie);			// place yorkie into toys vector
		} else if (breed == "shihtzu") {
			shihtzu.set_name(name);
			shihtzu.set_breed(breed);
			shihtzu.set_owner(owner);
			shihtzu.set_trainer(trainer);
			toys.push_back(shihtzu);			// place shihtzu into toys vector
		} else {
			std::cout << "Not a valid breed. Please enter one from list: " << std::endl;
		}
	}

	// Start show
	std::cout << "...\n" << "Showing Hunters" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < hunters.size(); i++) {		// display info for each hunter dog
		hunters[i].displayInfo();
		hunters[i].show();
		hunters[i].pose();
		std::cout << "Next dog\n" << "...\n" << std::endl;
	}

	std::cout << "...\n" << "Showing Workers" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < workers.size(); i++) {		// display info for each worker dog
		workers[i].displayInfo();
		workers[i].show();
		workers[i].pose();
		std::cout << "Next dog\n" << "...\n" << std::endl;
	}

	std::cout << "...\n" << "Showing Toys" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < toys.size(); i++) {			// display info for each toy dog
		toys[i].displayInfo();
		toys[i].show();
		toys[i].pose();
		std::cout << "Next dog\n" << "...\n" << std::endl;
	}

	return 0;

}
