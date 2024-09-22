#ifndef CUB3D_H
# define CUB3D_H

# include "gc.h"
# include "gnl.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_all	t_all;

typedef struct s_all
{
	char				*color_textures;
	int					fd;
	int					height_full_map;
	char				**full_map;
	char				**map;
	int					ac;
	char				**av;
}						t_all;

/* FUNCTIONS */
int						fetch_full_map(t_all *all);
int						check_file_extention(t_all *all);
int						count_mapfile_height(t_all *all);
void					ft_close(int fd);

#endif