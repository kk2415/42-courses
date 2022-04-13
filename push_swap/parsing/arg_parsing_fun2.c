/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing_fun2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:44:58 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/22 14:53:16 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

int	is_duplicated(t_deque *dq_a)
{
	t_node	*i_node;
	t_node	*j_node;

	i_node = dq_a->head;
	while (i_node != NULL)
	{
		j_node = i_node->next;
		while (j_node != NULL)
		{
			if (i_node->data == j_node->data)
				return (1);
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return (0);
}

int	ft_strlen_exception(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && ft_isdigit(str[i]))
			count++;
		i++;
	}
	return (count);
}
