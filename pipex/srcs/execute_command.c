#include "../inc/pipex.h"

char	*get_path_of_command(char **environment_path, char *command)
{
	int		idx;
	int		end;
	char	*path_of_commnad;

	idx = 0;
	end = sizeof(environment_path);
	path_of_commnad = NULL;
	while (idx < end)
	{
		if (access(command, F_OK) == 0)
			return (command);
		path_of_commnad = ft_strjoin(environment_path[idx], command);
		if (access(path_of_commnad, F_OK) == 0)
			return (path_of_commnad);
		free(path_of_commnad);
		path_of_commnad = NULL;
		idx++;
	}
	return (path_of_commnad);
}

void	execute_execve(t_pipex *pipex, char **command, int depth)
{
	char	*path_of_commnad;

	path_of_commnad
		= get_path_of_command(pipex->environment_path, command[0]);
	switch_stdio(pipex, depth);
	execve(path_of_commnad, command, pipex->environment);
	if (path_of_commnad)
		free(path_of_commnad);
	print_error(command[0]);
}
