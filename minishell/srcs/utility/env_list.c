/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:26:47 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/11/01 15:26:48 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_env_node(void)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	merror(new);
	ft_memset(new, 0, sizeof(t_env));
	return (new);
}

void	link_env_node(t_env *front, t_env *back)
{
	if (front == NULL & back == NULL)
		return ;
	if (front != NULL)
		front->next = back;
	if (back != NULL)
		back->prev = front;
}

t_env	*make_env_list(char **envp)
{
	int		i;
	char	**env_str;
	t_env	*env_list;
	t_env	*cur;
	t_env	*tmp;

	env_list = create_env_node();
	cur = env_list;
	i = -1;
	while (envp[++i])
	{
		if (i != 0)
		{
			tmp = create_env_node();
			tmp->prev = cur;
			cur->next = tmp;
			cur = cur->next;
		}
		env_str = env_split(envp[i]);
		cur->key = ft_strdup(env_str[KEY]);
		cur->value = ft_strdup(env_str[VALUE]);
		cur->env_flag = TRUE;
		free_double_string(env_str);
	}
	return (env_list);
}
