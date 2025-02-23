#include "Harl.h"
#include "colors.h"
#include <iostream>

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			<< std::endl;
}

void Harl::info(void) {
	std::cout <<
			"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
			<< std::endl;
}

void Harl::warning(void) {
	std::cout <<
			"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
			<< std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	const static  std::pair<std::string, void (Harl::*)(void)> complaints[] = {
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error}
	};

	for (const auto &[complaint, fn] : complaints) {
		if (level == complaint) {
			(this->*fn)();
			return;
		}
	}

	std::cerr << RED << "Invalid complaint level: " << CYAN << level << RESET << std::endl;
}
