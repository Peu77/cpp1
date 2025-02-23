#include "HumanB.h"
#include "colors.h"
#include <iostream>

HumanB::HumanB(std::string name) : weapon(nullptr), name(std::move(name)) {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	if(weapon == nullptr) {
		std::cout << RED << name << " has no weapon to attack with" << RESET << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
