#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << name << " attack " << target << ", "
		<< "causing " << attackDamage << " points of damage!" << std::endl;
	hitPoints += attackDamage;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap() { }
