#include <iostream>
#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap user1("kyunkim");

	user1.attack("monster");
	user1.takeDamage(5);
	user1.beRepaired(5);
	return (0);
}
