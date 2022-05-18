#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"
# include <iostream>

class HumanB
{

public:
	Weapon		*weapon;
	std::string	name;

	void	attack( void );
	void	setWeapon( Weapon &weapon );

	HumanB( void );
	HumanB( std::string name );

};

#endif
