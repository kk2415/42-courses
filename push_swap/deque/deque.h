/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:20 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 18:45:22 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef struct _node
{
	int				data;
	struct _node	*next;
	struct _node	*prev;
}	t_node;

typedef struct _Deque
{
	t_node			*head;
	t_node			*tail;
	int				numofdata;
}	t_deque;

void				dequeinit(t_deque *pdeq);
void				dqaddfirst(t_deque *pdeq, int data);
void				dqaddlast(t_deque *pdeq, int data);
int					dqremovefirst(t_deque *pdeq);
int					dqremovelast(t_deque *pdeq);
#endif
