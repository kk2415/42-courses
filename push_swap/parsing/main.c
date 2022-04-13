/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:45 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/23 11:27:12 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"
#include <stdio.h>

void	remove_deque(t_deque *pdeq)
{
	while (pdeq->head != NULL)
		dqremovelast(pdeq);
}

int	main(int arc, char *arg[])
{
	t_deque	dq_a;
	t_deque	dq_b;

	if (arc < 2)
		return (0);
	dequeinit(&dq_a);
	dequeinit(&dq_b);
	set_stack(&dq_a, arc, arg);
	if (is_duplicated(&dq_a))
		error(&dq_a);
	if (is_sorted(&dq_a))
	{
		remove_deque(&dq_a);
		return (0);
	}
	push_swap(&dq_a, &dq_b);
	remove_deque(&dq_a);
	return (0);
}
