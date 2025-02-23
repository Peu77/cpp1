#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
	std::string type;

public:
	Weapon(std::string type);
	std::string const &getType();

	void setType(std::string type);
};


#endif //WEAPON_H
