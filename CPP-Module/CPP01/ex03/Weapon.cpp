#include "Weapon.hpp"

Weapon::Weapon( void )
{
	this->type = "";
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}

std::string	Weapon::getType( void )
{
	std::string	&refType = type;
	return (refType);
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}
