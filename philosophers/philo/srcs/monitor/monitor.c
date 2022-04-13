#include "philosophers.h"

/*
* done_eating_time 배열 초기화를 모니터링 쓰레드에서 하는 이유!
* 모니터링 쓰레드에서 get_current_time()와 monitor->done_eating_time[philo_id]의
* 시간 차가 time_to_die보다 크면 굶은 걸로 판단함
* 맨 처음 get_current_time()와 monitor->done_eating_time[philo_id] 시간 차는 0이 나와야하기 때문에
* 최대한~~~ 저 조건문에서 가까운 코드에서 done_eating_time 초기화를 해주는게 좋다
*/
void	set_done_eating_time(t_monitor *monitor)
{
	int	idx;

	idx = 1;
	while (idx <= monitor->num_of_philo)
	{
		monitor->resource.done_eating_time[idx] = get_current_time();
		idx++;
	}
}

void	kill_thread(t_monitor *monitor, int philo_id)
{
	*monitor->resource.stat = DEATH;
	pthread_mutex_lock(&monitor->resource.eating_mutex[philo_id + 1]);
	monitor->timestamp = get_current_time()
		- monitor->resource.done_eating_time[philo_id + 1];
	monitor->philo_id = philo_id + 1;
	monitor_timestamp(monitor, DIE_MSG);
	pthread_mutex_unlock(&monitor->resource.eating_mutex[philo_id + 1]);
	if (monitor->num_of_philo <= 1)
		pthread_mutex_unlock(&monitor->resource.fork[0]);
}

void	monitoring(t_philo *philo)
{
	int			philo_id;
	t_monitor	*monitor;
	long		elapsed_time;

	philo_id = 0;
	monitor = (t_monitor *)&philo[0];
	set_done_eating_time(monitor);
	while (TRUE)
	{
		elapsed_time = get_current_time()
			- monitor->resource.done_eating_time[philo_id + 1];
		if (elapsed_time >= monitor->time_to_die)
		{
			kill_thread(monitor, philo_id);
			break ;
		}
		if (*monitor->resource.num_finish_eating >= monitor->num_of_philo)
		{
			*monitor->resource.stat = DEATH;
			printf(RED "%s", ALL_EATEN);
			printf(EOC);
			break ;
		}
		philo_id = (philo_id + 1) % monitor->num_of_philo;
	}
}
