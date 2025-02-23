#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"


class HumanA {
private:
	Weapon &weapon;
	std::string name;

public:
	HumanA(const std::string &name, Weapon &weapon);
	void attack() const;
};


#endif //HUMANA_H
