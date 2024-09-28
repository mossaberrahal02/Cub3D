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
# include <string.h>
# include <ctype.h>


typedef struct s_all		t_all;
typedef struct s_rgb		t_rgb;
typedef struct s_texture	t_texture;

typedef struct s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct s_texture
{
	int						c_count;
	int						f_count;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	int						no_count;
	int						so_count;
	int						we_count;
	int						ea_count;
}							t_texture;

typedef struct s_all
{
	t_rgb					c;
	t_rgb					f;
	int						p_count;
	char					**map;
	t_texture				textures;
	int						first_sex_valid_lines;
	int						fd;
	int						height_full_map;
	size_t					mini_map_height;
	size_t					mini_map_width;
	char					**full_map;
	char					**full_map2;
	char					**two_d_map;
	int						ac;
	char					**av;
}							t_all;

# define SUCCESS 0
# define FAILURE 1
# define GREEN "\033[92m"
# define RED "\033[91m"
# define YELLOW "\033[93m"
# define ENDC "\033[0m"
/* FUNCTIONS */
size_t						ft_strcpy(char *dest, const char *src);
int							count_mapfile_height(t_all *all);
int							fetch_full_map(t_all *all);
int							check_file_extention(t_all *all);
void						ft_close(int fd);

#endif