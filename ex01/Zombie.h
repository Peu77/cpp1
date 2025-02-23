#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>


class Zombie {
public:
	Zombie();
	Zombie(std::string& name);
	~Zombie();
	void announce() const;
	void setName(const std::string& name);
private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);


#endif //ZOMBIE_H
