#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>


class Zombie {
public:
	Zombie(std::string& name);
	~Zombie();
	void announce();
private:
	std::string name;
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);


#endif //ZOMBIE_H
