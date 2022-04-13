#include "philosophers.h"

void	print_timestamp(t_philo *philo, char *report_str, char *color)
{
	long	current_time;
	long	timestamp;

	pthread_mutex_lock(&(*philo->resource.print_mutex));
	current_time = get_current_time();
	timestamp = current_time - philo->program_start_time;
	if (*philo->resource.stat == ALIVE)
	{
		printf("%s" "%ld %d %s\n", color, timestamp, philo->philo_id,
			report_str);
		printf(EOC);
	}
	pthread_mutex_unlock(&(*philo->resource.print_mutex));
}

void	monitor_timestamp(t_monitor *monitor, char *report_str)
{
	long	current_time;
	long	timestamp;

	pthread_mutex_lock(&(*monitor->resource.print_mutex));
	current_time = get_current_time();
	timestamp = current_time - monitor->program_start_time;
	printf(RED "%ld %d %s\n", timestamp, monitor->philo_id, report_str);
	printf(EOC);
	pthread_mutex_unlock(&(*monitor->resource.print_mutex));
}
