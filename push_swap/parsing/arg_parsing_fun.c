/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:44:58 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/23 11:37:43 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	set_stack(t_deque *dq_a, int arc, char *arg[])
{
	int		i;
	int		count;
	char	**str;

	i = 1;
	if (arc == 2 && (*arg[1] == ' ' || !*arg[1]))
		error(dq_a);
	while (i < arc)
	{
		count = 0;
		str = ft_split(arg[i], ' ');
		while (str[count] != (void *)0)
			count++;
		arg_2_stack(dq_a, count, str);
		delete_split_mem(str);
		free(str);
		i++;
	}
}

void	arg_2_stack(t_deque *dq_a, int arc, char *arg[])
{
	int			i;

	i = 0;
	while (i < arc)
	{
		if (!str_2_int(arg[i], dq_a))
		{
			delete_split_mem(arg);
			error(dq_a);
		}
		i++;
	}
}

int	str_2_int(char *str, t_deque *dq_a)
{
	long long	num;
	char		sign;

	num = 0;
	sign = *str;
	if (ft_strlen_exception(str) > 11)
		return (0);
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		if ('0' <= *str && *str <= '9')
			num = num * 10 + ((*str++) - '0');
	}
	if (sign == '-')
		num *= -1;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	dqaddlast(dq_a, (int)num);
	return (1);
}

void	error(t_deque *pdeq)
{
	write(1, "Error\n", 6);
	while (pdeq->head != NULL)
		dqremovelast(pdeq);
	exit(-1);
}
