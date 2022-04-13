#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../get_next_line/get_next_line.h"

# define WRITE 1
# define READ 0

typedef struct s_pipex
{
	char	**command;
	int		command_sequence;
	int		command_total_number;
	char	*infile_name;
	char	*outfile_name;
	char	**environment;
	char	**environment_path;
	int		new_pipe[2];
	int		old_pipe[2];
	char	*limiter;
	int		is_here_doc;
	int		**pipe_fd;
	int		*pid;
	int		n_pipeline;
}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *str, char charset);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	ft_putstr_fd(char *s, int fd);

void	pipex_init(t_pipex *pipe, int arc, char *argv[], char *envp[]);

void	execute_command_main(t_pipex *pipex, int depth);
void	execute_command(t_pipex *pipex, int depth);
void	execute_execve(t_pipex *pipex, char **command, int depth);

void	switch_stdio(t_pipex *pipex, int depth);

int		get_fd_will_be_stdin(t_pipex *pipex, int is_redirection);
int		get_fd_will_be_stdout(t_pipex *pipex, int is_redirection);

void	free_two_dimensional(char **two_dimensional);
void	print_error(char *output_string);

void	is_here_doc(t_pipex *pipex, int arc, char *argv[]);
void	set_command(t_pipex *pipex, int arc, char *argv[]);
void	set_environment_path(t_pipex *pipex, char *envp[]);
void	set_infile_name(t_pipex *pipex, char *argv[]);
void	set_limiter(t_pipex *pipex, char *argv[]);
void	set_command_total_number(t_pipex *pipex, int arc);

char	*get_path_of_command(char **environment_path, char *command);

int		read_string_from_stdin(t_pipex *pipex);

#endif
