#include "philosophers.h"

void	init_fork_mutex(pthread_mutex_t *forks, int num_of_philo)
{
	int	idx;

	idx = 0;
	while (idx < num_of_philo)
	{
		pthread_mutex_init(&forks[idx], NULL);
		idx++;
	}
}

void	init_eating_mutex(pthread_mutex_t *eating_mutex, int num_of_philo)
{
	int	idx;

	idx = 1;
	while (idx <= num_of_philo)
	{
		pthread_mutex_init(&eating_mutex[idx], NULL);
		idx++;
	}
}

void	init_print_mutex(pthread_mutex_t *print_mutex)
{
	pthread_mutex_init(&(*print_mutex), NULL);
}
