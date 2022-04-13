#include "philosophers.h"

void	msleep(t_philo *philo, int millisecond)
{
	long	current_time;
	long	end_time;

	current_time = get_current_time();
	end_time = current_time + millisecond;
	while (get_current_time() < end_time && *philo->resource.stat == ALIVE)
	{
		usleep(300);
	}
}
