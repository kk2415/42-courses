#include "../inc/pipex_bonus.h"

void	pipex_init(t_pipex *pipex, int arc, char *argv[], char *envp[])
{
	pipex->outfile_name = argv[arc - 1];
	pipex->environment = envp;
	pipex->command_sequence = 0;
	pipex->n_pipeline = 1;
	set_infile_name(pipex, argv);
	set_limiter(pipex, argv);
	set_command_total_number(pipex, arc);
	set_command(pipex, arc, argv);
	set_environment_path(pipex, envp);
}
