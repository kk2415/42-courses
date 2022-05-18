#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap user1("kyunkim");

	user1.attack("monster");
	user1.takeDamage(5);
	user1.beRepaired(5);
	user1.guardGate();
	return (0);
}
