#include "HumanB.hpp"

HumanB::HumanB( void )
{
	this->name = "default";
	weapon = new Weapon();
}

HumanB::HumanB( std::string name )
{
	this->name = name;
	weapon = new Weapon();
}

void	HumanB::attack( void )
{
	std::string	str = weapon->getType();

	if (str.empty())
		std::cout << name << " attacks with his punch" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
}
