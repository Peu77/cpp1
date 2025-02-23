#include "Weapon.h"

Weapon::Weapon(std::string type) : type(std::move(type)) {}

std::string const &Weapon::getType() {
	return type;
}

void Weapon::setType(std::string type) {
	this->type = std::move(type);
}