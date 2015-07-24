#include <iostream>
#include "bluemen.hpp"

Bluemen::Bluemen() : Character() {}

Bluemen::~Bluemen() {}

int Bluemen::attack() {
	int a = (rand() % 10 + 1);
	int b = (rand() % 10 + 1);
	return a+b;
}

int Bluemen::defend() {
	int a = (rand() % 6 + 1);
	int b = (rand() % 6 + 1);
	int c = (rand() % 6 + 1);
	return a+b+c;
}

void Bluemen::set_armor() {
	armor = 3;
}

void Bluemen::set_strength() {
	strength = 12;
}

