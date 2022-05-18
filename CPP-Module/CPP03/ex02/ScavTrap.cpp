#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " be created " << std::endl;
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << name << " attack " << target << ", "
		<< "causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " is dead " << std::endl;
}
