#include <iostream>
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap user1("kyunkim");

	user1.attack("monster");
	user1.takeDamage(5);
	user1.beRepaired(5);
	user1.whoAmI();
	return (0);
}
