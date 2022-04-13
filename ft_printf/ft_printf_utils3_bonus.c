/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:05:34 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/15 18:05:45 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	intlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

size_t	ulen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ignoring_pre(t_stat *stat)
{
	if (stat->pre == 1 && stat->star.pcnt == 0)
	{
		if (stat->type == 'x' && stat->val.s[0] == '0' && stat->star.w_cnt > 0)
			return (1);
		else if (stat->type == 'u' && stat->val.u == 0 && stat->star.w_cnt > 0)
			return (1);
		else if (stat->type == 'd' && stat->val.d == 0 && stat->star.w_cnt > 0)
			return (1);
	}
	return (0);
}

void	c_work(t_stat *stat)
{
	get_blk(stat, 1);
	get_zero(stat, 1);
	stat->byte += (stat->star.cnt_bnk + stat->star.cnt_0) + 1;
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
	while (stat->star.cnt_0--)
		write(1, "0", 1);
	write(1, &stat->val.c, 1);
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
}
