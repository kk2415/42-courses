#include "../inc/pipex.h"

int	get_fd_will_be_stdin(t_pipex *pipex, int is_redirection)
{
	int		fd;

	if (pipex->is_here_doc)
		fd = read_string_from_stdin(pipex);
	else if (is_redirection)
	{
		fd = open(pipex->infile_name, O_RDWR);
		if (fd == -1)
			print_error(pipex->infile_name);
	}
	else
		fd = pipex->new_pipe[READ];
	return (fd);
}

int	get_fd_will_be_stdout(t_pipex *pipex, int is_redirection)
{
	int		fd;

	if (is_redirection)
	{
		if (pipex->is_here_doc)
			fd = open(pipex->outfile_name, O_CREAT | O_RDWR | O_APPEND, 0644);
		else
			fd = open(pipex->outfile_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
			print_error(pipex->outfile_name);
	}
	else
		fd = pipex->old_pipe[WRITE];
	return (fd);
}
