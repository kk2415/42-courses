/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:19 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 21:54:41 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	pa(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_b->head == NULL)
		exit(-1);
	dqaddfirst(dq_a, dq_b->head->data);
	dqremovefirst(dq_b);
	write(1, "pa\n", 3);
}

void	pb(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_a->head == NULL)
		exit(-1);
	dqaddfirst(dq_b, dq_a->head->data);
	dqremovefirst(dq_a);
	write(1, "pb\n", 3);
}

void	ra(t_deque *dq_a)
{
	if (dq_a->head == NULL)
		exit(-1);
	dqaddlast(dq_a, dq_a->head->data);
	dqremovefirst(dq_a);
	write(1, "ra\n", 3);
}

void	rb(t_deque *dq_b)
{
	if (dq_b->head == NULL)
		exit(-1);
	dqaddlast(dq_b, dq_b->head->data);
	dqremovefirst(dq_b);
	write(1, "rb\n", 3);
}

void	rr(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_a->head == NULL || dq_b->head == NULL)
		exit(-1);
	dqaddlast(dq_a, dq_a->head->data);
	dqremovefirst(dq_a);
	dqaddlast(dq_b, dq_b->head->data);
	dqremovefirst(dq_b);
	write(1, "rr\n", 3);
}
