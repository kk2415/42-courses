#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " be created " << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << name << " attack " << target << "!!" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << name << " has enterred in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " is dead " << std::endl;
}
