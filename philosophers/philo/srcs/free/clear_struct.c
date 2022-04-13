#include "philosophers.h"

void	clear_resource(t_resource resource)
{
	if (resource.print_mutex)
		free(resource.print_mutex);
	if (resource.num_finish_eating)
		free(resource.num_finish_eating);
	if (resource.stat)
		free(resource.stat);
	if (resource.done_eating_time)
		free(resource.done_eating_time);
	if (resource.eating_mutex)
		free(resource.eating_mutex);
	if (resource.fork)
		free(resource.fork);
}

void	clear_strcut(t_philo *philo, pthread_t *thread)
{
	if (philo == NULL || thread == NULL)
		return ;
	clear_resource(philo[0].resource);
	if (thread)
		free(thread);
	if (philo)
		free(philo);
}
