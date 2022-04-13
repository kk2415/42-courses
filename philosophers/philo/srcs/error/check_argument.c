#include "philosophers.h"

int	is_negative_number(int num)
{
	if (num <= 0)
		return (TRUE);
	return (FALSE);
}

int	is_digit(char *num)
{
	int	idx;
	int	len;

	idx = 0;
	len = ft_strlen(num);
	while (idx < len)
	{
		if (!ft_isdigit(num[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

int	check_no_one(char *argv[])
{
	if (!ft_strncmp("0", argv[1], ft_strlen(argv[1])))
		return (TRUE);
	return (FALSE);
}

void	print_error_msg(int reval)
{
	if (reval == 1)
		printf("Philo: too few arguments\n");
	else if (reval == 2)
		printf("Philo: Enter at least one philosopher\n");
	else if (reval == 3)
		printf("Philo: Negative number are included\n");
	else if (reval == 4)
		printf("Philo: value that is not number is included\n");
}

int	check_argument(int arc, char *argv[])
{
	int	idx;
	int	reval;

	idx = 1;
	reval = 0;
	if (arc < 5)
		reval = 1;
	else if (check_no_one(argv))
		reval = 2;
	while (idx < arc)
	{
		if (is_negative_number(ft_atoi(argv[idx])))
			reval = 3;
		if (!is_digit(argv[idx]))
			reval = 4;
		idx++;
	}
	if (reval != 0)
	{
		print_error_msg(reval);
		return (FALSE);
	}
	return (TRUE);
}
