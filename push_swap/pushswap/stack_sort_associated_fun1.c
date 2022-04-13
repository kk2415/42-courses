/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_associated_fun1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:38 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/23 11:40:53 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_remaining_elements(int num, t_deque *dq_a)
{
	if (num == 2)
	{
		if (dq_a->head->data > dq_a->head->next->data)
			sa(dq_a);
	}
}

void	B_remaining_elements(int num, t_deque *dq_a, t_deque *dq_b)
{
	if (num == 2)
	{
		if (dq_b->head->data < dq_b->head->next->data)
			sb(dq_b);
	}
	while (num--)
		pa(dq_a, dq_b);
}

void	start_rrr(t_deque *dq_a, t_deque *dq_b, int ra_cnt, int rb_cnt)
{
	while (ra_cnt && rb_cnt)
	{
		rrr(dq_a, dq_b);
		ra_cnt--;
		rb_cnt--;
	}
	while (ra_cnt)
	{
		rra(dq_a);
		ra_cnt--;
	}
	while (rb_cnt)
	{
		rrb(dq_b);
		rb_cnt--;
	}
}

void	A_2_B(int num, t_deque *dq_a, t_deque *dq_b)
{
	t_info	info;

	if (num < 3)
	{
		A_remaining_elements(num, dq_a);
		return ;
	}
	set_info(&info, num, dq_a);
	divide_a_stack(num, dq_a, dq_b, &info);
	start_rrr(dq_a, dq_b, info.ra_cnt, info.rb_cnt);
	A_2_B(info.ra_cnt, dq_a, dq_b);
	B_2_A(info.rb_cnt, dq_a, dq_b);
	B_2_A(info.pb_cnt - info.rb_cnt, dq_a, dq_b);
}

void	B_2_A(int num, t_deque *dq_a, t_deque *dq_b)
{
	t_info	info;

	if (num < 3)
	{
		B_remaining_elements(num, dq_a, dq_b);
		return ;
	}
	set_info(&info, num, dq_b);
	divide_b_stack(num, dq_a, dq_b, &info);
	A_2_B(info.pa_cnt - info.ra_cnt, dq_a, dq_b);
	start_rrr(dq_a, dq_b, info.ra_cnt, info.rb_cnt);
	A_2_B(info.ra_cnt, dq_a, dq_b);
	B_2_A(info.rb_cnt, dq_a, dq_b);
}
