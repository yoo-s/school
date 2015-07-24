#include <iostream>
#include "shadow.hpp"

Shadow::Shadow() : Character() {
	armor = 0;
	strength = 12;
}

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

