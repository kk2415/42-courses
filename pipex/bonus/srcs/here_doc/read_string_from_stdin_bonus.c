#include "../../inc/pipex_bonus.h"

static void	call_get_next_line(t_pipex *pipex, int pipe_fd[])
{
	char	*str;

	while (1)
	{
		get_next_line(0, &str);
		if (strncmp(str, pipex->limiter, ft_strlen(pipex->limiter)) == 0)
			break ;
		ft_putstr_fd(str, pipe_fd[1]);
		ft_putstr_fd("\n", pipe_fd[1]);
		free(str);
	}
}

int	read_string_from_stdin(t_pipex *pipex)
{
	int		pid;
	int		pipe_fd[2];
	int		exit_status_of_child;

	if (pipe(pipe_fd) == -1)
		print_error("pipe error");
	pid = fork();
	if (pid == -1)
		print_error("fork error");
	else if (pid > 0)
	{
		close(pipe_fd[1]);
		waitpid(pid, &exit_status_of_child, 0);
	}
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		call_get_next_line(pipex, pipe_fd);
		exit(EXIT_SUCCESS);
	}
	return (pipe_fd[0]);
}
