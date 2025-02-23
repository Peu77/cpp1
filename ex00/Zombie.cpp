#include "Zombie.h"
#include <iostream>
#include "colors.h"

Zombie::Zombie(std::string& name): name(name) {
}

Zombie::~Zombie() {
	std::cout << RED << name << " is dead." << RESET << std::endl;
}

void Zombie::announce() {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
