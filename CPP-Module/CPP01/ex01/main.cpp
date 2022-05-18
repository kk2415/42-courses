#include "Zombie.hpp"

void	zombieHordeDel( Zombie* zombie )
{
	Zombie	*cur;
	Zombie	*next;

	cur = zombie;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
}

void	allZombieAnnounce( Zombie* zombie )
{
	Zombie	*cur;
	Zombie	*next;

	cur = zombie;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->announce();
		cur = next;
	}
}

int	main( void )
{
	int		zombieNum;
	Zombie*	zombie;

	zombieNum = 10;
	zombie = zombieHorde(zombieNum, "kyunkim");

	allZombieAnnounce(zombie);
	zombieHordeDel(zombie);
}
