/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:13 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 18:45:15 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dequeinit(t_deque *pdeq)
{
	pdeq->numofdata = 0;
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

void	dqaddfirst(t_deque *pdeq, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = pdeq->head;
	if (pdeq->head == NULL)
		pdeq->tail = newnode;
	else
		pdeq->head->prev = newnode;
	newnode->prev = NULL;
	pdeq->head = newnode;
	(pdeq->numofdata)++;
}

void	dqaddlast(t_deque *pdeq, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->prev = pdeq->tail;
	if (pdeq->head == NULL)
		pdeq->head = newnode;
	else
		pdeq->tail->next = newnode;
	newnode->next = NULL;
	pdeq->tail = newnode;
	(pdeq->numofdata)++;
}

int	dqremovefirst(t_deque *pdeq)
{
	t_node	*rnode;
	int		data;

	rnode = pdeq->head;
	if (pdeq->head == NULL)
		exit(-1);
	data = rnode->data;
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	(pdeq->numofdata)--;
	return (data);
}

int	dqremovelast(t_deque *pdeq)
{
	t_node	*rnode;
	int		data;

	rnode = pdeq->tail;
	if (pdeq->head == NULL)
		exit(-1);
	data = rnode->data;
	pdeq->tail = pdeq->tail->prev;
	free(rnode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	(pdeq->numofdata)--;
	return (data);
}
