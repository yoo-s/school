#include <iostream>
#include "barbarian.hpp"

Barbarian::Barbarian() : Character() {}

Barbarian::~Barbarian() {}

int Barbarian::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

int Barbarian::defend() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	return a+b;
}

void Barbarian::set_armor() {
	armor = 0;
}

void Barbarian::set_strength() {
	strength = 12;
}
