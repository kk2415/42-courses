#include "philosophers.h"

int	main(int arc, char *argv[])
{
	t_philo		*philo;
	pthread_t	*thread;

	if (check_argument(arc, argv) == FALSE)
		return (FAILURE);
	if (init_philo(&philo, argv) == ERROR)
		return (FAILURE);
	if (init_thread(&thread, argv) == ERROR)
		return (FAILURE);
	if (creat_thread(thread, philo) == ERROR)
		return (FAILURE);
	monitoring(philo);
	join_thread(thread, philo[0].num_of_philo);
	destroy_mutex(philo);
	clear_strcut(philo, thread);
	return (SUCCESS);
}
