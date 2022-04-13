#include "philosophers.h"

static t_boolean	destroy_fork_mutex(pthread_mutex_t *forks, int num_of_philo)
{
	int	idx;
	int	reval;

	idx = 0;
	while (idx < num_of_philo)
	{
		pthread_mutex_unlock(&forks[idx]);
		reval = pthread_mutex_destroy(&forks[idx]);
		if (reval != 0)
			return (ERROR);
		idx++;
	}
	return (NORMAL);
}

static t_boolean	destroy_eat_mutex(pthread_mutex_t *eating_mutex,
	int num_of_philo)
{
	int	idx;
	int	reval;

	idx = 1;
	while (idx <= num_of_philo)
	{
		pthread_mutex_unlock(&eating_mutex[idx]);
		reval = pthread_mutex_destroy(&eating_mutex[idx]);
		if (reval != 0)
			return (ERROR);
		idx++;
	}
	return (NORMAL);
}

static t_boolean	destroy_print_mutex(pthread_mutex_t *print_mutex)
{
	int	reval;

	reval = pthread_mutex_destroy(&(*print_mutex));
	if (reval != 0)
		return (ERROR);
	return (NORMAL);
}

void	destroy_mutex(t_philo *philo)
{
	if (destroy_fork_mutex(philo[0].resource.fork, philo->num_of_philo)
		== ERROR)
		printf("Fork Mutex destroy error\n");
	if (destroy_eat_mutex(philo[0].resource.eating_mutex, philo->num_of_philo)
		== ERROR)
		printf("Eating Mutex destroy error\n");
	if (destroy_print_mutex(philo[0].resource.print_mutex) == ERROR)
		printf("Print Mutex destroy error\n");
}
