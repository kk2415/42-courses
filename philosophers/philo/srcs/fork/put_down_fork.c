#include "philosophers.h"

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->resource.fork[philo->philo_id - 1]);
	pthread_mutex_unlock(&philo->resource.fork[philo->philo_id
		% philo->num_of_philo]);
}
