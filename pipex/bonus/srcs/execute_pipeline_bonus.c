#include "../inc/pipex_bonus.h"

void	init_pipe_fd(t_pipex *pipex)
{
	int	idx;

	idx = 0;
	pipex->pipe_fd = (int **)malloc(sizeof(int * ) * pipex->command_total_number);
	while (idx < pipex->command_total_number)
	{
		pipex->pipe_fd[idx] = (int *)malloc(sizeof(int) * 2);
		idx++;
	}
}

void	make_pipeline(t_pipex *pipex)
{
	int	idx;

	idx = 0;
	while (idx < pipex->command_total_number)
	{
		if (pipe(pipex->pipe_fd[idx]) < 0)
			exit(1);
		idx++;
	}
}

void	execute_command(t_pipex *pipex, char **command)
{
	int		pid;
	char	*path_of_commnad;

	pid = fork();
	if (pid == -1)
		print_error("fork error");
	else if (pid > 0)
	{
		;
	}
	else if (pid == 0)
	{
		path_of_commnad
			= get_path_of_command(pipex->environment_path, command[0]);
		execve(path_of_commnad, command, pipex->environment);
		free(path_of_commnad);
		print_error(command[0]);
	}
}

void	switch_stdio(t_pipex *pipex, int depth)
{
	int	idx;
	int fd;

	idx = 0;
	if (depth == 0)
	{
		fd = open(pipex->infile_name, O_RDWR);
		if (fd == -1)
		{
			perror("open error");
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		dup2(pipex->pipe_fd[depth + 1][WRITE], STDOUT_FILENO);
	}
	else if (depth >= 1 && depth < pipex->command_total_number - 1)
	{
		dup2(pipex->pipe_fd[depth][READ], STDIN_FILENO);
		dup2(pipex->pipe_fd[depth + 1][WRITE], STDOUT_FILENO);
	}
	else
	{
		fd = open(pipex->outfile_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("open error");
			exit(1);
		}
		dup2(pipex->pipe_fd[depth][READ], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
	}
	while (idx < pipex->command_total_number)
	{
		close(pipex->pipe_fd[idx][0]);
		close(pipex->pipe_fd[idx][1]);
		idx++;
	}
}

static void	child_process(t_pipex *pipex, int depth)
{
	char	**command;

	command = ft_split(pipex->command[pipex->command_sequence], ' ');
	switch_stdio(pipex, depth);
	execute_command(pipex, command);
	free_two_dimensional(command);
}

void	execute_pipeline(t_pipex *pipex, int depth)
{
	if (depth >= pipex->command_total_number)
		return ;
	pipex->command_sequence = depth;
	pipex->pid[depth] = fork();
	if (pipex->pid[depth] == -1)
		exit(1);
	if (pipex->pid[depth] == 0)
		child_process(pipex, depth);
	if (pipex->pid[depth] > 0)
		execute_pipeline(pipex, depth + 1);
}

void	execute_cmd_main(t_pipex *pipex, int depth)
{
	int	pid;
	int	status;
	int	idx;

	idx = 0;
	init_pipe_fd(pipex);
	make_pipeline(pipex);
	pipex->pid = (int *)malloc(sizeof(int) * pipex->command_total_number);
	pid = fork();
	if (pid > 0)
	{
		while (waitpid(pid, &status, 0) == -1)
		{
			;
		}
		while (idx < pipex->command_total_number)
		{
			close(pipex->pipe_fd[idx][0]);
			close(pipex->pipe_fd[idx][1]);
			idx++;
		}
	}
	if (pid == 0)
		execute_pipeline(pipex, depth);
}