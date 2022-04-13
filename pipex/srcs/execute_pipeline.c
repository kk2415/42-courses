#include "../inc/pipex.h"

void	init_pipe_fd(t_pipex *pipex)
{
	int	idx;

	idx = 0;
	pipex->pipe_fd = (int **)malloc(sizeof(int * ) * pipex->command_total_number + 1);
	while (idx < pipex->command_total_number)
	{
		pipex->pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
		idx++;
	}
}

void	make_pipeline(t_pipex *pipex, int depth)
{
	if (depth < (pipex->command_total_number - 1))
	{
		if (pipe(pipex->pipe_fd[depth]) < 0)
		{
			perror("pipe error\n");
			exit(1);
		}
	}
}

void	close_pipe_fd(t_pipex *pipex)
{
	int	idx;

	idx = 0;
	while (idx < pipex->command_total_number)
	{
		close(pipex->pipe_fd[idx][READ]);
		close(pipex->pipe_fd[idx][WRITE]);
		idx++;
	}
}

void	switch_stdio(t_pipex *pipex, int depth)
{
	int fd;

	if (depth == 0)
	{
		fd = open(pipex->infile_name, O_RDWR);
		if (fd == -1)
		{
			perror("open error");
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		dup2(pipex->pipe_fd[depth][WRITE], STDOUT_FILENO);
		close(fd);
	}
	else if (depth > 0 && depth < pipex->command_total_number - 1)
	{
		dup2(pipex->pipe_fd[depth - 1][READ], STDIN_FILENO);
		dup2(pipex->pipe_fd[depth][WRITE], STDOUT_FILENO);
	}
	else
	{
		fd = open(pipex->outfile_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open error");
			exit(1);
		}
		if (dup2(pipex->pipe_fd[depth - 1][READ], STDIN_FILENO) == -1)
			perror("ERROR!!");
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	close_pipe_fd(pipex);
}

static void	child_process(t_pipex *pipex, int depth)
{
	char	**command;

	command = ft_split(pipex->command[depth], ' ');
	execute_execve(pipex, command, depth);
	free_two_dimensional(command);
}

void	execute_command(t_pipex *pipex, int depth)
{
	int	status;
	make_pipeline(pipex, depth);
	pipex->pid[depth] = fork();
	if (pipex->pid[depth] == -1)
		exit(1);
	if (pipex->pid[depth] > 0)
	{
		if (depth == pipex->command_total_number - 1)
		{
			close_pipe_fd(pipex);
			while (wait(&status) != -1)
			{
				;
			}
			return ;
		}
		execute_command(pipex, depth + 1);
	}
	if (pipex->pid[depth] == 0)
		child_process(pipex, depth);
}

void	execute_command_main(t_pipex *pipex, int depth)
{
	init_pipe_fd(pipex);
	pipex->pid = (int *)malloc(sizeof(int) * pipex->command_total_number);
	execute_command(pipex, depth);
}
