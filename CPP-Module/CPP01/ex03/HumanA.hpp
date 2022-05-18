#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"
# include <iostream>

class HumanA
{

public:
	Weapon		*weapon;
	std::string	name;

	void		attack( void );

	HumanA( Weapon &weapon );
	HumanA( std::string name, Weapon &weapon );

};

#endif
