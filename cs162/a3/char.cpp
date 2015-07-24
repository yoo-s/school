#include <iostream>
#include "char.hpp"

/*********************************************
 ** Function: Character::Character
 ** Description: constructor for Character
 ** Parameters: none
 ********************************************/
Character::Character() {}

/*********************************************
 ** Function: Character::~Character
 ** Description: destructor for Character
 ** Parameters: none
 ********************************************/
Character::~Character() {}

/*********************************************
 ** Function: Character::set_name
 ** Description: sets name for character
 ** Parameters: std::string name
 ********************************************/
void Character::set_name(std::string name) {
	charname = name;
}

/*********************************************
 ** Function: Character::attack
 ** Description: attacks target
 ** Parameters: none
 ********************************************/
int Character::attack() {}

/*********************************************
 ** Function: Character::defend
 ** Description: defends against attacker
 ** Parameters: none
 ********************************************/
int Character::defend() {}

