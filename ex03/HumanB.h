#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
private:
	Weapon *weapon;
	std::string name;

public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
};



#endif //HUMANB_H
