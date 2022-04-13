#include "../inc/pipex.h"

static void	add_slash_at_end_of_path(t_pipex *pipex, char **environment_path)
{
	int		idx;
	char	*temp_for_substr;

	idx = 0;
	while (environment_path[idx])
	{	
		if (idx == 0)
		{
			temp_for_substr = ft_substr(environment_path[0],
					5, ft_strlen(environment_path[0]) - 5);
			pipex->environment_path[idx] = ft_strjoin(temp_for_substr, "/");
			free(temp_for_substr);
		}
		else
			pipex->environment_path[idx]
				= ft_strjoin(environment_path[idx], "/");
		idx++;
	}
}

void	set_environment_path(t_pipex *pipex, char *envp[])
{
	int		idx;
	char	**environment_path;

	idx = 0;
	environment_path = NULL;
	while (envp[idx])
	{
		if (ft_strnstr(envp[idx], "PATH", 8))
		{
			environment_path = ft_split(envp[idx], ':');
			pipex->environment_path = (char **)malloc(sizeof(char *)
					* (sizeof(environment_path) + 1));
			add_slash_at_end_of_path(pipex, environment_path);
			pipex->environment_path[sizeof(environment_path)] = NULL;
			break ;
		}
		idx++;
	}
	free_two_dimensional(environment_path);
}

void	set_infile_name(t_pipex *pipex, char *argv[])
{
	if (!(pipex->is_here_doc))
	{
		pipex->infile_name = argv[1];
		if (access(pipex->infile_name, F_OK) == -1)
			print_error(pipex->infile_name);
	}
}

void	set_limiter(t_pipex *pipex, char *argv[])
{
	if (pipex->is_here_doc)
		pipex->limiter = argv[2];
}

void	set_command_total_number(t_pipex *pipex, int arc)
{
	pipex->command_total_number = arc - 3;
	if (pipex->is_here_doc)
		pipex->command_total_number = 2;
}
