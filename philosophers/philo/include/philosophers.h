#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

/*
**==============================================================================
**	Macro Declaration
**==============================================================================
*/
# define TRUE 1
# define FALSE 0

# define ERROR -1
# define NORMAL 0

# define FAILURE 1
# define SUCCESS 0

# define DEATH 0
# define ALIVE 1

# define PICK 1
# define PUT 0

# define THREAD_SUCCESS 0

# define EDEADLK 11
# define EINVAL 22
# define ESRCH 3

# define BLACK "\033[0;30m"
# define GRAY "\033[1;30m"
# define RED	 "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define EOC	 "\033[0;0m"
# define LINE_CLEAR "\x1b[1A\x1b[M"

# define EATING_MSG "is eating"
# define SLEEPING_MSG "is sleeping"
# define THINKING_MSG "is thinking"
# define TAKE_FORK_MSG "has taken a fork"
# define DIE_MSG "died"
# define ALL_EATEN "==============================================\n\
==========All philosophers have eaten=========\n\
=============Program will exit now============\n\
==============================================\n"

/*
**==============================================================================
**	Struct type Definition
**==============================================================================
*/
typedef struct s_resource
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eating_mutex;
	int				*stat;
	int				*num_finish_eating;
	long			*done_eating_time;
}	t_resource;

typedef struct s_philo
{
	t_resource	resource;
	int			philo_id;
	int			time_to_die;
	int			time_to_eat;
	int			num_of_philo;
	int			time_to_sleep;
	int			must_eat_flag;
	int			num_philos_must_eat;
	int			left_fork;
	int			right_fork;
	long		death_time;
	long		program_start_time;
	long		timestamp;
}	t_philo;

typedef struct timeval	t_timeval;

typedef t_philo			t_monitor;

typedef int				t_boolean;

/*
**==============================================================================
**	Init Function
**==============================================================================
*/
int		init_philo(t_philo **philo, char *argv[]);
int		init_thread(pthread_t **thread, char *argv[]);
int		init_monitor(t_philo **philo, t_monitor **monitor);
int		init_resource_data(t_philo *philo);
void	init_fork_mutex(pthread_mutex_t *forks, int num_of_philo);
void	init_eating_mutex(pthread_mutex_t *eating_mutex, int num_of_philo);
void	init_print_mutex(pthread_mutex_t *print_mutex);

/*
**==============================================================================
**	Monitor Function
**==============================================================================
*/
void	monitoring(t_monitor *monitor);
// void	*monitoring(void *arg);

/*
**==============================================================================
**	Time Function
**==============================================================================
*/
long	get_current_time(void);
void	print_timestamp(t_philo *philo, char *report_str, char *color);
void	monitor_timestamp(t_monitor *monitor, char *report_str);

/*
**==============================================================================
**	Fork Function
**==============================================================================
*/
void	pick_up_fork(t_philo *philo);
void	put_down_fork(t_philo *philo);

/*
**==============================================================================
**	Philo Action Function
**==============================================================================
*/
void	*philosopher_action(void *arg);
void	set_thinking_start_time(t_philo *philo);
void	set_thinking_end_time(t_philo *philo);
void	msleep(t_philo *philo, int millisecond);

/*
**==============================================================================
**	Mutex Function
**==============================================================================
*/
void	destroy_mutex(t_philo *philo);

/*
**==============================================================================
**	Thread Function
**==============================================================================
*/
int		creat_thread(pthread_t *thread, t_philo *philo);
void	join_thread(pthread_t *thread, int num_of_philo);

/*
**==============================================================================
**	Libft Function
**==============================================================================
*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

/*
**==============================================================================
**	Error Function
**==============================================================================
*/
int		is_alloc_error(void *addr);
int		check_argument(int arc, char *argv[]);

/*
**==============================================================================
**	Free Function
**==============================================================================
*/
void	clear_strcut(t_philo *philo, pthread_t *thread);

#endif // PHILOSOPHERS_H
