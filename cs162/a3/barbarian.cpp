#include <iostream>
#include "barbarian.hpp"

Barbarian::Barbarian() : Character() {
	armor = 0;
	strength = 12;
}

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

