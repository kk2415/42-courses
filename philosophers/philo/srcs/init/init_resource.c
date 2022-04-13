#include "philosophers.h"

int	malloc_resource(t_resource *resource, int num_of_philo)
{
	resource->stat = (int *)malloc(sizeof(int));
	resource->num_finish_eating = (int *)malloc(sizeof(int));
	resource->done_eating_time = (long *)malloc(sizeof(long)
			* (num_of_philo + 1));
	resource->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* num_of_philo);
	resource->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	resource->eating_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (num_of_philo + 1));
	if (is_alloc_error(resource->fork)
		|| is_alloc_error(resource->stat)
		|| is_alloc_error(resource->print_mutex)
		|| is_alloc_error(resource->eating_mutex)
		|| is_alloc_error(resource->done_eating_time)
		|| is_alloc_error(resource->num_finish_eating))
		return (ERROR);
	return (NORMAL);
}

void	set_resource(t_resource *resource, int num_of_philo)
{
	*(resource->stat) = ALIVE;
	*(resource->num_finish_eating) = 0;
	init_fork_mutex(resource->fork, num_of_philo);
	init_print_mutex(resource->print_mutex);
	init_eating_mutex(resource->eating_mutex, num_of_philo);
	memset(resource->done_eating_time, 0, sizeof(int) * (num_of_philo + 1));
}

int	init_resource_data(t_philo *philo)
{
	int				idx;
	int				num_of_philo;
	t_resource		resource;

	idx = 0;
	num_of_philo = philo[0].num_of_philo;
	if (malloc_resource(&resource, num_of_philo) == ERROR)
		return (ERROR);
	set_resource(&resource, num_of_philo);
	while (idx < num_of_philo)
	{
		philo[idx].resource.stat = resource.stat;
		philo[idx].resource.fork = resource.fork;
		philo[idx].resource.num_finish_eating = resource.num_finish_eating;
		philo[idx].resource.done_eating_time = resource.done_eating_time;
		philo[idx].resource.print_mutex = resource.print_mutex;
		philo[idx].resource.eating_mutex = resource.eating_mutex;
		idx++;
	}
	return (NORMAL);
}
