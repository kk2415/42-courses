#include "philosophers.h"

int	init_thread(pthread_t **thread, char *argv[])
{
	int	num_of_philo;

	num_of_philo = ft_atoi(argv[1]);
	*thread = (pthread_t *)malloc(sizeof(pthread_t) * num_of_philo);
	if (is_alloc_error(*thread))
		return (ERROR);
	return (NORMAL);
}
