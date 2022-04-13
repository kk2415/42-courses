/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_work_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:06:08 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/15 18:06:14 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	int_work(t_stat *stat)
{
	char	*str;

	get_blk(stat, intlen(stat->val.d));
	get_zero(stat, intlen(stat->val.d));
	if (ignoring_pre(stat))
		stat->star.cnt_bnk++;
	stat->byte += stat->star.cnt_bnk;
	str = my_itoa(stat, intlen(stat->val.d), stat->val.d);
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
	if (!((stat->pre == 1 && stat->star.pcnt == 0) && stat->val.d == 0))
	{
		write(1, str, ft_strlen(str));
		stat->byte += ft_strlen(str);
	}
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
	free(str);
}

void	u_work(t_stat *stat)
{
	char	*str;

	get_blk(stat, ulen(stat->val.u));
	get_zero(stat, ulen(stat->val.u));
	if (ignoring_pre(stat))
		stat->star.cnt_bnk++;
	stat->byte += stat->star.cnt_bnk;
	str = my_itoa(stat, ulen(stat->val.u), stat->val.u);
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
	if (!((stat->pre == 1 && stat->star.pcnt == 0) && stat->val.u == 0))
	{
		write(1, str, ft_strlen(str));
		stat->byte += ft_strlen(str);
	}
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
	free(str);
}

void	string_work(t_stat *stat)
{
	size_t	len;

	get_blk(stat, ft_strlen(stat->val.s));
	len = ft_strlen(stat->val.s);
	if (stat->star.pcnt > 0 && stat->star.pcnt < (int)len)
		len = len - (len - stat->star.pcnt);
	stat->byte += stat->star.cnt_bnk;
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
	if (!(stat->pre == 1 && stat->star.pcnt == 0))
	{
		write(1, stat->val.s, len);
		stat->byte += len;
	}
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk--)
			write(1, " ", 1);
}

void	p_work(t_stat *stat)
{
	size_t	len;

	get_blk(stat, ft_strlen(stat->val.s));
	get_zero(stat, ft_strlen(stat->val.s));
	len = ft_strlen(stat->val.s);
	stat->byte += (stat->star.cnt_bnk + stat->star.cnt_0);
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
	write(1, "0x", 2);
	if (!((stat->pre == 1 && stat->star.pcnt == 0) && stat->val.s[0] == '0'))
	{
		while (stat->star.cnt_0--)
			write(1, "0", 1);
		write(1, stat->val.s, len);
		stat->byte += ft_strlen(stat->val.s) + 2;
	}
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
}

void	x_work(t_stat *stat)
{
	size_t	len;

	get_blk(stat, ft_strlen(stat->val.s));
	get_zero(stat, ft_strlen(stat->val.s));
	len = ft_strlen(stat->val.s);
	if (ignoring_pre(stat))
		stat->star.cnt_bnk++;
	stat->byte += (stat->star.cnt_bnk + stat->star.cnt_0);
	if (stat->dir == 'R')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
	if (!((stat->pre == 1 && stat->star.pcnt == 0) && stat->val.s[0] == '0'))
	{
		while (stat->star.cnt_0--)
			write(1, "0", 1);
		write(1, stat->val.s, len);
		stat->byte += ft_strlen(stat->val.s);
	}
	if (stat->dir == 'L')
		while (stat->star.cnt_bnk > 0 && stat->star.cnt_bnk--)
			write(1, " ", 1);
}
