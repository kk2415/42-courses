/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:07:46 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/15 15:20:17 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_itoa(t_stat *stat, unsigned int len, unsigned int num)
{
	char	*ptr;

	len += stat->star.cnt_0;
	if (stat->val.d < 0)
	{
		num = stat->val.d * -1;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	ptr[0] = '0';
	while (num)
	{
		ptr[--len] = (num % 10) + '0';
		num = num / 10;
	}
	while (stat->star.cnt_0--)
		ptr[--len] = '0';
	if (stat->val.d < 0)
		ptr[0] = '-';
	return (ptr);
}

int	fmt_atoi(const char *format, int idk)
{
	unsigned long long	sum;

	sum = 0;
	if (format[idk] == '-')
		idk++;
	while (format[idk] == '0')
		idk++;
	while (format[idk] != '.' && !ft_isalpha(format[idk]) && format[idk] != '%')
	{
		sum = sum * 10 + (format[idk] - '0');
		idk++;
	}
	return (sum);
}

char	*conv_to_hex(unsigned long long hex, int opt)
{
	size_t	i;
	char	temp;
	char	*hex_arr;

	i = 0;
	hex_arr = (char *)malloc(sizeof(char *) * 21);
	ft_memset(hex_arr, 0, 21);
	while (1)
	{
		hex_arr[i] = "0123456789abcdef"[hex % 16];
		if (ft_isalpha(hex_arr[i]))
			hex_arr[i] -= opt;
		hex /= 16;
		i++;
		if (hex == 0)
			break ;
	}
	i = -1;
	while (++i < ft_strlen(hex_arr) / 2)
	{
		temp = hex_arr[i];
		hex_arr[i] = hex_arr[ft_strlen(hex_arr) - 1 - i];
		hex_arr[ft_strlen(hex_arr) - 1 - i] = temp;
	}
	return (hex_arr);
}

void	get_zero(t_stat *stat, size_t len)
{
	if (stat->star.pcnt > 0)
	{
		stat->star.cnt_0 = (stat->star.pcnt - len);
		if (stat->star.cnt_0 < 0)
			stat->star.cnt_0 = 0;
	}
	else if (stat->iszero == 1 && stat->pre == 0 && stat->dir == 'R')
		stat->star.cnt_0 = stat->star.w_cnt - len;
	else if (stat->iszero == 1 && stat->pre == 1 && stat->val.c != '%')
	{
		stat->star.cnt_0 = 0;
		stat->iszero = 0;
	}
	if (stat->iszero == 1 && stat->star.cnt_0 > 0 && stat->sign == '-')
		stat->star.cnt_0--;
	if (stat->star.cnt_0 < 0)
		stat->star.cnt_0 = 0;
}

void	get_blk(t_stat *stat, size_t len)
{
	if (stat->type == 's' || stat->type == 'p')
	{
		if (stat->star.pcnt < (int)len && stat->pre == 1 && stat->type == 's')
			len = stat->star.pcnt;
		if (stat->type == 'p')
			len += 2;
	}
	if (stat->star.w_cnt > 0 && stat->star.pcnt > (int)len && stat->type != 's')
		stat->star.cnt_bnk = stat->star.w_cnt - stat->star.pcnt;
	else if (stat->star.w_cnt > (int)len && stat->iszero <= 0)
		stat->star.cnt_bnk = stat->star.w_cnt - len;
	if (stat->sign == '-' && stat->star.cnt_bnk > 0)
		stat->star.cnt_bnk--;
	if (stat->star.cnt_bnk < 0)
		stat->star.cnt_bnk = 0;
}
