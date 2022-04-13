#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include "../inc/pipex_bonus.h"

char	*gnl_strjoin(char *s1, char const *s2);
int		gnl_check_line_feed(char *save);
int		gnl_check_len(char **line, char **save);
int		gnl_return(char **line, char **save);
int		get_next_line(int fd, char **line);

#endif
