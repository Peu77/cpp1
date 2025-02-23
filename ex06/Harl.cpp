#include "Harl.h"
#include "colors.h"
#include <iostream>

void Harl::debug(void) {
	std::cout << BLUE << BOLD << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			<< std::endl;
}

void Harl::info(void) {
	std::cout << YELLOW << BOLD << "[ INFO ]" << RESET << std::endl;
	std::cout <<
			"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
			<< std::endl;
}

void Harl::warning(void) {
	std::cout << ORANGE << BOLD << "[ WARNING ]" << RESET << std::endl;
	std::cout <<
			"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
			<< std::endl;
}

void Harl::error(void) {
	std::cout << RED << BOLD << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	const static std::string levels[] = {"debug", "info", "warning", "error"};

	int i = 0;

	while (i < 4 && levels[i] != level)
		i++;

	switch (i) {
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cerr << RED << "Invalid complaint level: " << CYAN << level << RESET << std::endl;
			break;
	}
}
