/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:55 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 18:46:10 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_deque *dq_a)
{
	t_node	*cur;
	t_node	*dou_n;

	if (is_sorted(dq_a))
		return ;
	cur = dq_a->head;
	dou_n = cur->next->next;
	if (dou_n->data > cur->data && cur->data > cur->next->data)
		sa(dq_a);
	else if (cur->data > cur->next->data && cur->next->data > dou_n->data)
	{
		sa(dq_a);
		rra(dq_a);
	}
	else if (cur->data > dou_n->data && dou_n->data > cur->next->data)
		ra(dq_a);
	else if (dou_n->data > cur->data && cur->next->data > dou_n->data)
	{
		sa(dq_a);
		ra(dq_a);
	}
	else
		rra(dq_a);
}

void	case_5(int arr[], t_deque *dq_a, t_deque *dq_b)
{
	int	mid;

	mid = arr[2];
	while (dq_a->numofdata > 3)
	{
		if (dq_a->head->data < mid)
			pb(dq_a, dq_b);
		else
			ra(dq_a);
	}
	case_3(dq_a);
	if (dq_b->head->data < dq_b->tail->data)
		sb(dq_b);
	while (dq_b->numofdata)
		pa(dq_a, dq_b);
	while (!is_sorted(dq_a))
	{
		sa(dq_a);
		if (dq_a->head->next->data < dq_a->head->next->next->data)
			break ;
		ra(dq_a);
	}
	while (!is_sorted(dq_a))
		rra(dq_a);
}

void	push_swap(t_deque *dq_a, t_deque *dq_b)
{
	int	*arr;

	if (dq_a->numofdata == 2)
	{
		if (dq_a->head->data > dq_a->tail->data)
			sa(dq_a);
	}
	else if (dq_a->numofdata == 3)
		case_3(dq_a);
	else if (dq_a->numofdata > 3 && dq_a->numofdata < 6)
	{
		arr = get_sorted_arr(dq_a->numofdata, dq_a);
		case_5(arr, dq_a, dq_b);
		free(arr);
	}
	else
		A_2_B(dq_a->numofdata, dq_a, dq_b);
}
