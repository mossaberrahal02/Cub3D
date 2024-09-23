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
typedef struct s_rgb	t_rgb;
typedef struct s_texture	t_texture;

typedef struct s_rgb
{
	char				*r;
	char				*g;
	char				*b;
}						t_rgb;

typedef struct s_texture
{
	int					c_count;
	int					f_count;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	int					no_count;
	int					so_count;
	int					we_count;
	int					ea_count;
}	t_texture;

typedef struct s_all
{
	t_rgb				c;
	t_rgb				f;
	char				**map;
	t_texture			textures;
	int					first_sex_valid_lines;
	int					fd;
	int					height_full_map;
	char				**full_map;
	int					ac;
	char				**av;
}						t_all;

# define SUCCESS 0
# define FAILURE 1

/* FUNCTIONS */
int						fetch_full_map(t_all *all);
int						check_file_extention(t_all *all);
int						count_mapfile_height(t_all *all);
void					ft_close(int fd);

#endif