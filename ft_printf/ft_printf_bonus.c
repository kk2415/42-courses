/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:04:08 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/15 18:04:17 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_opt(const char *format, t_stat *stat, int idk)
{
	while (!ft_isalpha(format[idk]) && format[idk] != '%')
	{
		if (format[idk] == '0' && format[idk - 1] == '%')
			stat->iszero = 1;
		else if (format[idk] == '*' && format[idk - 1] != '.')
			stat->star.w_check_star = 1;
		else if (format[idk] == '*' && format[idk - 1] == '.')
			stat->star.p_check_star = 1;
		else if (format[idk] == '.')
		{
			stat->pre = 1;
			if (stat->iszero == 1)
				stat->iszero = -1;
		}
		else if (format[idk] == '-')
			stat->dir = 'L';
		idk++;
	}
}

int	opt_work(va_list ap, const char *format, t_stat *stat, int idk)
{
	check_opt(format, stat, idk);
	idk = width_work(ap, format, stat, idk);
	idk = pre_work(ap, format, stat, idk);
	save_val1(ap, format, stat, idk);
	save_val2(ap, format, stat, idk);
	save_val3(ap, format, stat, idk);
	return (idk + 1);
}

void	set_stat(t_stat *stat)
{
	ft_memset(&stat->star, 0, sizeof(stat->star));
	stat->dir = 'R';
	stat->iszero = 0;
	stat->pre = 0;
	stat->sign = '+';
	stat->type = '0';
	stat->val.d = 0;
	stat->val.u = 0;
	stat->val.c = '0';
	stat->val.s = NULL;
}

int	ft_printf(const char *format, ...)
{
	t_stat	*stat;
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	stat = (t_stat *)malloc(sizeof(t_stat));
	stat->byte = 0;
	set_stat(stat);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		while (format[i] == '%')
			i = opt_work(ap, format, stat, i + 1);
		if (format[i] == '\0')
			break ;
		write(1, &(format[i]), 1);
		count++;
		set_stat(stat);
		i++;
	}
	va_end(ap);
	free(stat);
	return (stat->byte + count);
}
