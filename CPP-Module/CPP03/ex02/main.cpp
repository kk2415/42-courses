#include <iostream>
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap user1("kyunkim");

	user1.attack("monster");
	user1.takeDamage(5);
	user1.beRepaired(5);
	user1.highFivesGuys();
	return (0);
}
