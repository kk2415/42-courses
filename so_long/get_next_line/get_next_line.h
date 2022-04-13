/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:59:18 by kyunkim           #+#    #+#             */
/*   Updated: 2021/05/18 14:59:19 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include "../inc/so_long.h"

char	*gnl_strjoin(char *s1, char const *s2);
int		gnl_check_line_feed(char *save);
int		gnl_check_len(char **line, char **save);
int		gnl_return(char **line, char **save);
int		get_next_line(int fd, char **line);

#endif
