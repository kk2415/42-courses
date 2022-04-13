#include "philosophers.h"

void	join_thread(pthread_t *thread, int num_of_philo)
{
	int	idx;
	int	reval;
	int	status;

	idx = 0;
	while (idx < num_of_philo)
	{
		reval = pthread_join(thread[idx], (void **)&status);
		if (&status == PTHREAD_CANCELED
			|| reval == EDEADLK
			|| reval == EINVAL
			|| reval == ESRCH)
			printf("Pthread join error\n");
		idx++;
	}
}
