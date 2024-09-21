#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gnl.h"
#include "libft.h"

typedef struct s_all t_all;

typedef struct s_all
{
	char	**full_map;
	char	**map;
	int		ac;
	char	**av;
}			t_all;


/* FUNCTIONS */
void	fetch_full_map(t_all *all)
;
void	check_file_extention(t_all *all)
;
int	count_mapfile_height(t_all *all)
;
void	ft_close(int fd)
;

#endif