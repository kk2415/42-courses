/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:46:57 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/22 15:10:07 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

int	whoispreceded(int d1, int d2)
{
	if (d1 < d2)
		return (0);
	else
		return (1);
}

int	is_sorted(t_deque *pdeq)
{
	t_node	*cur;

	cur = pdeq->head;
	while (cur != NULL && cur->next != NULL)
	{
		if (whoispreceded(cur->data, cur->next->data))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	get_mid_data(int arr[], int left, int right)
{
	int	temp[3];

	temp[0] = left;
	temp[1] = (left + right) / 2;
	temp[2] = right;
	if (arr[temp[0]] > arr[temp[1]])
		swap(temp, 0, 1);
	if (arr[temp[1]] > arr[temp[2]])
		swap(temp, 1, 2);
	if (arr[temp[0]] > arr[temp[1]])
		swap(temp, 0, 1);
	return (arr[temp[1]]);
}

int	*get_sorted_arr(int num, t_deque *dq)
{
	int		i;
	int		*arr;
	t_node	*cur;

	i = 0;
	cur = dq->head;
	arr = (int *)malloc(sizeof(int) * (num + 1));
	while (i < num && cur != 0)
	{
		arr[i] = cur->data;
		cur = cur->next;
		i++;
	}
	quicksort(arr, 0, num - 1);
	return (arr);
}

void	*delete_split_mem(char **p)
{
	int	i;

	i = 0;
	while (p[i] != (void *)0)
	{
		free((p[i]));
		i++;
	}
	return (NULL);
}
