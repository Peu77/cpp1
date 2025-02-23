#include "HumanA.h"

#include <iostream>
#include <utility>

HumanA::HumanA(const std::string  &name, Weapon &weapon) : weapon(weapon), name(name) {}

void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
