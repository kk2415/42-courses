#include "../inc/pipex.h"

void	print_error(char *output_string)
{
	perror(output_string);
	exit(EXIT_FAILURE);
}
