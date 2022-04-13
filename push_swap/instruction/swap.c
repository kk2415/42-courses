/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:50 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 21:55:07 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	sa(t_deque *dq_a)
{
	int	data1;
	int	data2;

	if (dq_a->numofdata < 2)
		exit(-1);
	data1 = dq_a->head->data;
	data2 = dq_a->head->next->data;
	dqremovefirst(dq_a);
	dqremovefirst(dq_a);
	dqaddfirst(dq_a, data1);
	dqaddfirst(dq_a, data2);
	write(1, "sa\n", 3);
}

void	sb(t_deque *dq_b)
{
	int	data1;
	int	data2;

	if (dq_b->numofdata < 2)
		exit(-1);
	data1 = dq_b->head->data;
	data2 = dq_b->head->next->data;
	dqremovefirst(dq_b);
	dqremovefirst(dq_b);
	dqaddfirst(dq_b, data1);
	dqaddfirst(dq_b, data2);
	write(1, "sb\n", 3);
}

void	ss(t_deque *dq_a, t_deque *dq_b)
{
	sa(dq_a);
	sb(dq_b);
	write(1, "ss\n", 3);
}
