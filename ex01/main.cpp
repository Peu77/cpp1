#include <iostream>

#include "colors.h"
#include "Zombie.h"

#define HORDE1_SIZE 5
#define HORDE1_NAME "Zombie1"

#define HORDE2_SIZE 3
#define HORDE2_NAME "Zombie2"

#define ARROW_COUNT 2
#define BORDER_SIZE 10
#define BORDER_MARGIN 1

typedef enum {
	BORDER_UP,
	BORDER_DOWN,
} BorderPos;

static void printBorder(const std::string &name, const BorderPos pos) {
	auto printArrow = [pos]() {
		std::string arrow;
		switch (pos) {
			case BORDER_UP:
				arrow = "↓";
				break;
			case BORDER_DOWN:
				arrow = "↑";
				break;
		}
		for (int i = 0; i < ARROW_COUNT; i++)
			std::cout << arrow;
	};

	auto printMargin = []() {
		for (int i = 0; i < BORDER_MARGIN; i++)
			std::cout << std::endl;
	};

	printMargin();
	printArrow();
	std::cout << std::string(BORDER_SIZE, '-') << GREEN << name << RESET << std::string(BORDER_SIZE, '-');
	printArrow();
	std::cout << std::endl;
	printMargin();
}

int main() {
	printBorder(HORDE1_NAME, BORDER_UP);

	auto *horde1 = zombieHorde(HORDE1_SIZE, "Zombie1");
	for (int i = 0; i < HORDE1_SIZE; i++)
		horde1[i].announce();
	delete[] horde1;

	printBorder(HORDE1_NAME, BORDER_DOWN);
	printBorder(HORDE2_NAME, BORDER_UP);

	auto horde2 = zombieHorde(HORDE2_SIZE, "Zombie2");
	for (int i = 0; i < HORDE2_SIZE; i++)
		horde2[i].announce();
	delete[] horde2;

	printBorder(HORDE2_NAME, BORDER_DOWN);
}
