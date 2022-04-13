#include "../inc/pipex_bonus.h"

int	main(int arc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (arc < 5)
	{
		ft_putstr_fd("error: too few arguments to pipex\n", 1);
		exit(EXIT_FAILURE);
	}
	is_here_doc(&pipex, arc, argv);
	pipex_init(&pipex, arc, argv, envp);
	execute_cmd_main(&pipex, 0);
	free_two_dimensional(pipex.environment_path);
	free(pipex.command);
	return (EXIT_SUCCESS);
}
