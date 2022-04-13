/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:59:12 by kyunkim           #+#    #+#             */
/*   Updated: 2021/07/08 15:59:13 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./Libft/libft.h"

typedef struct _opt_type
{
	unsigned int	u;
	char			*s;
	int				d;
	char			c;
}	t_opt_type;

typedef struct _star_value
{
	int				w_cnt;
	int				pcnt;
	int				p_check_star;
	int				w_check_star;
	int				cnt_0;
	int				cnt_bnk;
}	t_star;

typedef struct _t_stat
{
	char			dir;
	char			sign;
	char			type;
	int				pre;
	int				iszero;
	size_t			byte;
	t_opt_type		val;
	t_star			star;
}	t_stat;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
char		*my_itoa(t_stat *stat, unsigned int len, unsigned int num);
int			intlen(int n);
size_t		ulen(unsigned int n);
void		get_zero(t_stat *stat, size_t len);
void		get_blk(t_stat *stat, size_t len);
int			fmt_atoi(const char *format, int idk);
char		*conv_to_hex(unsigned long long hex, int opt);
int			width_work(va_list ap, const char *format, t_stat *stat, int idk);
int			pre_work(va_list ap, const char *format, t_stat *stat, int idk);
void		int_work(t_stat *stat);
void		u_work(t_stat *stat);
void		p_work(t_stat *stat);
void		x_work(t_stat *stat);
void		c_work(t_stat *stat);
int			ignoring_pre(t_stat *stat);
void		string_work(t_stat *stat);
void		save_val1(va_list ap, const char *format, t_stat *stat, int idk);
void		save_val2(va_list ap, const char *format, t_stat *stat, int idk);
void		save_val3(va_list ap, const char *format, t_stat *stat, int idk);
void		check_opt(const char *format, t_stat *stat, int idk);
int			opt_work(va_list ap, const char *format, t_stat *stat, int idk);
void		set_stat(t_stat *stat);
int			ft_printf(const char *format, ...);

#endif
