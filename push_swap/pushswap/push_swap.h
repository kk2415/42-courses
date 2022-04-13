/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:47:58 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/22 15:11:05 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../deque/deque.h"
# include "../quicksort/quicksort.h"
# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"

typedef struct _info
{
	int		ra_cnt;
	int		rb_cnt;
	int		pa_cnt;
	int		pb_cnt;
	int		max_pivot;
	int		min_pivot;
}	t_info;

void		pa(t_deque *dq_a, t_deque *dq_b);
void		pb(t_deque *dq_a, t_deque *dq_b);
void		ra(t_deque *dq_a);
void		rb(t_deque *dq_b);
void		rr(t_deque *dq_a, t_deque *dq_b);
void		sa(t_deque *dq_a);
void		sb(t_deque *dq_b);
void		ss(t_deque *dq_a, t_deque *dq_b);
void		rra(t_deque *dq_a);
void		rrb(t_deque *dq_b);
void		rrr(t_deque *dq_a, t_deque *dq_b);
int			whoispreceded(int d1, int d2);
int			is_sorted(t_deque *pdeq);
int			is_duplicated(t_deque *dq_a);
int			ft_strlen_exception(char	*str);
void		*delete_split_mem(char **p);
int			str_2_int(char *str, t_deque *dq_a);
void		arg_2_stack(t_deque *dq_a, int arc, char *arg[]);
void		set_stack(t_deque *dq_a, int arc, char *arg[]);
char		check_sign(char	*str, t_deque *dq_a);
void		error(t_deque *pdeq);
void		case_3(t_deque *dq_a);
void		case_5(int arr[], t_deque *dq_a, t_deque *dq_b);
int			*get_sorted_arr(int num, t_deque *dq);
void		A_remaining_elements(int num, t_deque *dq_a);
void		B_remaining_elements(int num, t_deque *dq_a, t_deque *dq_b);
void		divide_a_stack(int num, t_deque *dq_a, t_deque *dq_b, t_info *info);
void		divide_b_stack(int num, t_deque *dq_a, t_deque *dq_b, t_info *info);
void		set_info(t_info *info, int num, t_deque *pdeq);
void		start_rrr(t_deque *dq_a, t_deque *dq_b, int ra_cnt, int rb_cnt);
void		A_2_B(int num, t_deque *dq_a, t_deque *dq_b);
void		B_2_A(int num, t_deque *dq_a, t_deque *dq_b);
void		push_swap(t_deque *dq_a, t_deque *dq_b);

#endif
