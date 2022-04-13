/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:35:37 by kyunkim           #+#    #+#             */
/*   Updated: 2021/03/10 03:13:30 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		length;
	char	*ptr;

	length = ft_strlen(src) + 1;
	ptr = (char *)malloc(length);
	if (ptr == (void *) '\0')
		return (0);
	my_strcpy(ptr, src);
	return (ptr);
}
