#include "Zombie.h"
#include <iostream>
#include <thread>

#include "colors.h"

Zombie::Zombie() {
}

Zombie::Zombie(std::string &name): name(name) {
}

Zombie::~Zombie() {
	const std::string message = name + " is dead";
	for (size_t i = 0; i < message.length(); i++) {
		std::cout << RED << message[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
	std::cout << RESET << std::endl;
}

void Zombie::setName(const std::string &name) {
	this->name = name;
}

void Zombie::announce() const {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *zombieHorde(int N, std::string name) {
	auto *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
