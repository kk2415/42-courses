#include "philosophers.h"

static int	creat_philo_thread(pthread_t *thread, t_philo *philo)
{
	int	idx;
	int	reval;

	idx = 0;
	while (idx < philo[0].num_of_philo)
	{
		reval = pthread_create(&thread[idx], NULL, philosopher_action,
				(void *)&philo[idx]);
		if (reval != THREAD_SUCCESS)
		{
			printf("pthread create error\n");
			return (ERROR);
		}
		idx++;
		usleep(100);
	}
	return (NORMAL);
}

int	creat_thread(pthread_t *thread, t_philo *philo)
{
	int	philo_reval;

	philo_reval = creat_philo_thread(thread, philo);
	if (philo_reval == ERROR)
		return (ERROR);
	return (NORMAL);
}
