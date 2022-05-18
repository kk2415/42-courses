#include "Zombie.hpp"

int	main( void )
{
	Zombie*	zombie;

	zombie = newZombie("kyunkim");
	zombie->announce();
	randomChump("Holand");

	delete zombie;
}
