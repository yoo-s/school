#include <iostream>
#include "reptile.hpp"

Reptile::Reptile() : Character() {}

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

void Reptile::set_armor() {
	armor = 7;
}

void Reptile::set_strength() {
	strength = 18;
}

