
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "Let's high fives!!" << std::endl;
}

FragTrap::~FragTrap() { }
