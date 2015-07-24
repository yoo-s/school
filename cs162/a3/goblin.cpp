#include <iostream>
#include "goblin.hpp"

Goblin::Goblin() : Character() {}

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

void Goblin::set_armor() {
	armor = 3;
}

void Goblin::set_strength() {
	strength = 8;
}

