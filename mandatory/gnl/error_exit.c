#include "cub3d.h"

void	error_exit(int status, char *str)
{
	if (str)
		perror(str);
	exit(status);
}
