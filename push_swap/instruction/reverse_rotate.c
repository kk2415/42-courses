/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:29 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 21:54:54 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	rra(t_deque *dq_a)
{
	if (dq_a->head == NULL)
		exit(-1);
	dqaddfirst(dq_a, dq_a->tail->data);
	dqremovelast(dq_a);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *dq_b)
{
	if (dq_b->head == NULL)
		exit(-1);
	dqaddfirst(dq_b, dq_b->tail->data);
	dqremovelast(dq_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_a->head == NULL || dq_b->head == NULL)
		exit(-1);
	dqaddfirst(dq_a, dq_a->tail->data);
	dqremovelast(dq_a);
	dqaddfirst(dq_b, dq_b->tail->data);
	dqremovelast(dq_b);
	write(1, "rrr\n", 4);
}
