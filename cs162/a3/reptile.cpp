#include <iostream>
#include "reptile.hpp"

Reptile::Reptile() : Character() {
	armor = 7;
	strength = 18;
}

Reptile::~Reptile() {}

int Reptile::attack() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	int c = (rand() % 6 + 1);
	return a+b+c;
}

int Reptile::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

