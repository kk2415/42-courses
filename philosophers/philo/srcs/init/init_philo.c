#include "philosophers.h"

void	set_philo_members(t_philo *philo, char *argv[], long program_start_time,
	int num_of_philo)
{
	philo->timestamp = 0;
	philo->num_of_philo = num_of_philo;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->program_start_time = program_start_time;
	philo->must_eat_flag = FALSE;
	philo->left_fork = PUT;
	philo->right_fork = PUT;
	philo->num_philos_must_eat = -1;
	if (argv[5])
	{
		philo->must_eat_flag = TRUE;
		philo->num_philos_must_eat = ft_atoi(argv[5]);
	}
}

void	set_philo_id(t_philo *philo, int philo_id)
{
	philo->philo_id = philo_id;
}

int	init_philo(t_philo **philo, char *argv[])
{
	int		idx;
	int		num_of_philo;
	long	program_start_time;

	idx = 0;
	num_of_philo = ft_atoi(argv[1]);
	program_start_time = get_current_time();
	*philo = (t_philo *)malloc(sizeof(t_philo) * num_of_philo);
	if (is_alloc_error(*philo))
		return (ERROR);
	while (idx < num_of_philo)
	{
		set_philo_members(&(*philo)[idx], argv, program_start_time,
			num_of_philo);
		set_philo_id(&(*philo)[idx], idx + 1);
		idx++;
	}
	if (init_resource_data(*philo) == ERROR)
		return (ERROR);
	return (NORMAL);
}
