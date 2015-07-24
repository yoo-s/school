#include <iostream>
#include "shadow.hpp"

Shadow::Shadow() : Character() {}

Shadow::~Shadow() {}

int Shadow::attack() {
	int a = (rand() % 10 + 1);
	int b = (rand() % 10 + 1);
	return a+b;
}

int Shadow::defend() {
	int a = (rand() % 6 + 1);
	return a;
}

void Shadow::set_armor() {
	armor = 0;
}

void Shadow::set_strength() {
	strength = 12;
}

