#include "philosophers.h"

void	thinking(t_philo *philo)
{
	if (philo->resource.stat == DEATH)
		return ;
	print_timestamp(philo, THINKING_MSG, PURPLE);
}

void	sleeping(t_philo *philo)
{
	if (philo->resource.stat == DEATH)
		return ;
	print_timestamp(philo, SLEEPING_MSG, GREEN);
	msleep(philo, philo->time_to_sleep);
}

void	eating(t_philo *philo, int *eating_count)
{
	if (philo->resource.stat == DEATH)
		return ;
	pthread_mutex_lock(&philo->resource.eating_mutex[philo->philo_id]);
	print_timestamp(philo, EATING_MSG, YELLOW);
	philo->resource.done_eating_time[philo->philo_id] = get_current_time();
	msleep(philo, philo->time_to_eat);
	(*eating_count)++;
	if (philo->must_eat_flag && (*eating_count >= philo->num_philos_must_eat))
	{
		(*philo->resource.num_finish_eating)++;
		philo->must_eat_flag = FALSE;
	}
	pthread_mutex_unlock(&philo->resource.eating_mutex[philo->philo_id]);
}

void	*philosopher_action(void *arg)
{
	t_philo	*philo;
	int		eating_count;

	eating_count = 0;
	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0 || philo->philo_id == philo->num_of_philo)
		usleep(1000);
	while (*philo->resource.stat == ALIVE)
	{
		pick_up_fork(philo);
		eating(philo, &eating_count);
		put_down_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}
