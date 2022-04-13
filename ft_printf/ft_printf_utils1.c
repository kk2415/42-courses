/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:07:39 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/15 16:45:36 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_work(va_list ap, const char *format, t_stat *stat, int i)
{
	while (format[i] == '0' || format[i] == '-')
		i++;
	if (ft_isdigit(format[i]))
	{
		stat->star.w_cnt = fmt_atoi(format, i);
		i += intlen(stat->star.w_cnt);
	}
	else if (stat->star.w_check_star == 1)
	{
		stat->star.w_cnt = va_arg(ap, int);
		if (stat->star.w_cnt < 0)
		{
			stat->star.w_cnt = -stat->star.w_cnt;
			stat->dir = 'L';
			stat->iszero = 0;
		}
		i++;
	}
	return (i);
}

int	pre_work(va_list ap, const char *format, t_stat *stat, int i)
{
	if (format[i] == '.')
	{
		i++;
		if (ft_isdigit(format[i]))
		{
			while (format[i] == '0' && ft_isdigit(format[i + 1]))
				i++;
			stat->star.pcnt = fmt_atoi(format, i);
			i += intlen(stat->star.pcnt);
		}
		else if (stat->star.p_check_star == 1)
		{
			stat->star.pcnt = va_arg(ap, int);
			i++;
		}
	}
	if (stat->star.pcnt < 0)
	{
		stat->star.pcnt = 0;
		stat->pre = 0;
		if (stat->iszero == -1)
			stat->iszero = 1;
	}
	return (i);
}

void	save_val1(va_list ap, const char *format, t_stat *stat, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
	{
		stat->type = 'd';
		stat->val.d = va_arg(ap, int);
		if (stat->val.d < 0)
			stat->sign = '-';
		int_work(stat);
	}
	else if (format[i] == 'u')
	{
		stat->type = 'u';
		stat->val.u = va_arg(ap, unsigned int);
		u_work(stat);
	}
}

void	save_val2(va_list ap, const char *format, t_stat *stat, int i)
{
	if (format[i] == 'p')
	{
		stat->type = 'p';
		stat->val.s = conv_to_hex(va_arg(ap, unsigned long long), 0);
		if (stat->pre == 1 && stat->star.pcnt == 0 && stat->val.s[0] == '0')
			stat->val.s[0] = '\0';
		p_work(stat);
		//free(stat->val.s);
	}
	else if (format[i] == 's')
	{
		stat->type = 's';
		stat->val.s = va_arg(ap, char *);
		if (!stat->val.s)
			stat->val.s = "(null)";
		string_work(stat);
	}
}

void	save_val3(va_list ap, const char *format, t_stat *stat, int i)
{
	if (format[i] == 'x' || format[i] == 'X')
	{
		stat->type = 'x';
		if (format[i] == 'X')
			stat->val.s = conv_to_hex(va_arg(ap, unsigned int), 32);
		else
			stat->val.s = conv_to_hex(va_arg(ap, unsigned int), 0);
		x_work(stat);
		//free(stat->val.s);
	}
	else if (format[i] == 'c' || format[i] == '%')
	{
		stat->type = 'c';
		if (format[i] != '%')
			stat->val.c = va_arg(ap, int);
		if (format[i] == '%')
		{
			if (stat->iszero == -1)
				stat->iszero = 1;
			stat->pre = 0;
			stat->star.pcnt = 0;
			stat->val.c = '%';
		}
		c_work(stat);
	}
}
