#include <iostream>
#include <string>
#include "colors.h"

int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << CYAN << "Address of string:    " << &brain     << RESET << std::endl;
	std::cout << CYAN << "Address of stringPTR: " << stringPTR  << RESET << std::endl;
	std::cout << CYAN << "Address of stringREF: " << &stringREF << RESET << std::endl;

	std::cout << GREEN << "Value of string:      " << brain      << RESET << std::endl;
	std::cout << GREEN << "Value of stringPTR:   " << *stringPTR << RESET << std::endl;
	std::cout << GREEN << "Value of stringREF:   " << stringREF  << RESET << std::endl;
}
