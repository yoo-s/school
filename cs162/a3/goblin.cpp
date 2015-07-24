#include <iostream>
#include "goblin.hpp"

Goblin::Goblin() : Character() {
	armor = 3;
	strength = 8;
}

Goblin::~Goblin() {}

int Goblin::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

int Goblin::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

