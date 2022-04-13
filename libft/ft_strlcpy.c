/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:03:43 by kyunkim           #+#    #+#             */
/*   Updated: 2021/02/24 16:04:03 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	if (!dest || !src)
		return (0);
	i = 0;
	length = ft_strlen(src);
	if (!size)
		return (length);
	while (i < size)
	{
		if (src[i] == '\0')
			break ;
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i - 1] = '\0';
	return (length);
}
