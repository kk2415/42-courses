/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:59:00 by kyunkim           #+#    #+#             */
/*   Updated: 2021/09/03 11:23:15 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char const *s2)
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

int	gnl_check_line_feed(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i] != 0)
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_check_len(char **line, char **save)
{
	char	*backup;
	size_t	bk_len;
	int		i;

	i = gnl_check_line_feed(*save);
	bk_len = ft_strlen(*save) - (i + 1);
	*(*save + i) = '\0';
	*line = ft_strdup(*save);
	if (bk_len == 0)
	{
		free(*save);
		*save = NULL;
	}
	else
	{
		backup = ft_strdup(*save + i + 1);
		free(*save);
		*save = backup;
	}
	return (1);
}

int	gnl_return(char **line, char **save)
{
	int		length;

	length = gnl_check_line_feed(*save);
	if (length >= 0)
		return (gnl_check_len(line, save));
	if (*save)
	{
		*line = *save;
		*save = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	static char	*save[OPEN_MAX];
	char		*buff;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (gnl_check_line_feed(save[fd]) == -1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buff[read_size] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buff);
		else
			save[fd] = gnl_strjoin(save[fd], buff);
	}
	free(buff);
	if (read_size < 0)
		return (-1);
	return (gnl_return(line, &save[fd]));
}
