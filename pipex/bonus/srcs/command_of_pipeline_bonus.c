#include "../inc/pipex_bonus.h"

// void	input_command_of_pipeline(t_pipex *pipex, int is_redirection)
// {
// 	char	**command;
// 	int		fd_for_standard_in;

// 	fd_for_standard_in = get_fd_will_be_stdin(pipex, is_redirection);
// 	dup2(pipex->new_pipe[WRITE], 1);
// 	close(pipex->new_pipe[READ]);
// 	close(pipex->new_pipe[WRITE]);
// 	command = ft_split(pipex->command[pipex->command_sequence], ' ');
// 	execute_input_command(pipex, command, fd_for_standard_in);
// 	close(fd_for_standard_in);
// 	free_two_dimensional(command);
// }

// void	output_command_of_pipeline(t_pipex *pipex, int is_redirection)
// {
// 	char	**command;
// 	int		fd_for_standard_out;

// 	fd_for_standard_out = get_fd_will_be_stdout(pipex, is_redirection);
// 	dup2(pipex->new_pipe[READ], 0);
// 	close(pipex->new_pipe[WRITE]);
// 	close(pipex->new_pipe[READ]);
// 	command = ft_split(pipex->command[pipex->command_sequence], ' ');
// 	execute_output_command(pipex, command, fd_for_standard_out);
// 	close(fd_for_standard_out);
// 	free_two_dimensional(command);
// }
