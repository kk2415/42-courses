#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	int		idx;
	Zombie*	zombies[N];

	for (idx = 0; idx < N; idx++)
	{
		zombies[idx] = new Zombie(name);
	}
	for (idx = 0; idx < (N - 1); idx++)
	{
		zombies[idx]->next = zombies[idx + 1];
	}
	return (zombies[0]);
}
