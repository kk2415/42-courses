#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap " << name << " be created " << std::endl;
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	ClapTrap::energyPoints = 50;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " <<  this->name << std::endl;
	std::cout << "ClapTrap name is " <<  ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is dead " << std::endl;
}
