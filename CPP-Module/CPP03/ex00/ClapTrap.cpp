#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { }

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " be created " << std::endl;
	this->name = name;
	this->attackDamage = 0;
	this->energyPoints = 10;
	this->hitPoints = 10;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << name << " attack " << target << ", "
		<< "causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " take damage " << amount << std::endl;
	this->energyPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " be repaired " << amount << std::endl;
	this->energyPoints += amount;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is dead " << std::endl;
}
