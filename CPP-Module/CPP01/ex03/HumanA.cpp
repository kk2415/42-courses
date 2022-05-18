# include "HumanA.hpp"

HumanA::HumanA( Weapon &weapon )
{
	this->name = "default";
	this->weapon = &weapon;
}

HumanA::HumanA( std::string name, Weapon &weapon )
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}
