#include "../inc/pipex.h"

static void	set_command_if_here_doc(t_pipex *pipex, char *argv[])
{
	int	idx;

	idx = 0;
	pipex->command = (char **)malloc(sizeof(char *) * 3);
	while (idx < 2)
	{
		pipex->command[idx] = argv[idx + 3];
		idx++;
	}
	pipex->command[idx] = NULL;
}

void	set_command(t_pipex *pipex, int arc, char *argv[])
{
	int	idx;

	if (pipex->is_here_doc)
	{
		set_command_if_here_doc(pipex, argv);
		return ;
	}
	idx = 0;
	pipex->command = (char **)malloc(sizeof(char *) * (arc - 2));
	while (idx < arc - 3)
	{
		pipex->command[idx] = argv[idx + 2];
		idx++;
	}
	pipex->command[idx] = NULL;
}
