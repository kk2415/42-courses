
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " be created " << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "Let's high fives!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is dead " << std::endl;
}
