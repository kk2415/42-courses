#include "../../inc/pipex_bonus.h"

void	is_here_doc(t_pipex *pipex, int arc, char *argv[])
{
	pipex->is_here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		pipex->is_here_doc = 1;
		if (arc < 6)
		{
			ft_putstr_fd("error: too few arguments to pipex\n", 1);
			exit(EXIT_FAILURE);
		}
	}
}