/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:59:09 by kyunkim           #+#    #+#             */
/*   Updated: 2021/09/03 11:21:44 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	while (i < size - 1)
	{
		if (src[i] == '\0')
			break ;
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (length);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	j = ft_strlen(dest);
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dest);
	if (size == 0)
		return (src_length);
	if (size <= dst_length)
		return (size + src_length);
	while (src[i] && dst_length + i < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (dst_length > size)
		return (src_length + size);
	else
		return (src_length + dst_length);
}

char	*ft_strdup(const char *src)
{
	int		length;
	char	*ptr;

	length = ft_strlen(src);
	ptr = (char *)malloc(length + 1);
	ft_strlcpy(ptr, src, (length + 1));
	return (ptr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*ret;
	int			s1_len;
	int			s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	ret = (char *)malloc(s1_len + s2_len + 1);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret, s2, s2_len + s1_len + 1);
	free(s1);
	return (ret);
}
