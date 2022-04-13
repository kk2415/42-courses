/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_associated_fun2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:43 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 19:06:45 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_a_stack(int num, t_deque *dq_a, t_deque *dq_b, t_info *info)
{
	while (num--)
	{
		if (dq_a->head->data >= info->max_pivot)
		{
			ra(dq_a);
			info->ra_cnt++;
		}
		else
		{
			pb(dq_a, dq_b);
			info->pb_cnt++;
			if (dq_b->head->data >= info->min_pivot)
			{
				rb(dq_b);
				info->rb_cnt++;
			}
		}
	}
}

void	divide_b_stack(int num, t_deque *dq_a, t_deque *dq_b, t_info *info)
{
	while (num--)
	{
		if (dq_b->head->data < info->min_pivot)
		{
			rb(dq_b);
			info->rb_cnt++;
		}
		else
		{
			pa(dq_a, dq_b);
			info->pa_cnt++;
			if (dq_a->head->data < info->max_pivot)
			{
				ra(dq_a);
				info->ra_cnt++;
			}
		}
	}
}

void	set_info(t_info *info, int num, t_deque *pdeq)
{
	int	*arr;

	ft_memset(info, 0, sizeof(*info));
	arr = get_sorted_arr(num, pdeq);
	info->min_pivot = arr[num / 3];
	info->max_pivot = arr[num / 3 * 2];
	free(arr);
}
