#include "philosophers.h"

void	pick_up_fork(t_philo *philo)
{
	if (philo->resource.stat == DEATH)
		return ;
	usleep(100);
	pthread_mutex_lock(&philo->resource.fork[philo->philo_id - 1]);
	philo->left_fork = PICK;
	print_timestamp(philo, TAKE_FORK_MSG, CYAN);
	pthread_mutex_lock(&philo->resource.fork[philo->philo_id
		% philo->num_of_philo]);
	philo->right_fork = PICK;
	print_timestamp(philo, TAKE_FORK_MSG, CYAN);
}
