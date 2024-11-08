/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:22:00 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/08 16:18:42 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gc.h"
# include "gnl.h"
# include "libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

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

typedef struct s_player
{
	int dir_x;
	int dir_y;
	int row;
	int column;
}t_player;

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
	t_player				player;
}							t_all;

# define SUCCESS 0
# define FAILURE 1
# define GREEN "\033[92m"
# define RED "\033[91m"
# define YELLOW "\033[93m"
# define ENDC "\033[0m"
/* FUNCTIONS */
void set_player_col_row(t_all *all, int i, int j)
;
void set_player_direction(t_all *all);
int							parsing(t_all *all, int ac, char **av);
int							check_full_map_content(t_all *all);
int							check_comma(t_all *all);
int							count(char **to_count);
int							ft_isspace(char *to_check);
int							parse_f_c(t_all *all);
void						ft_open(t_all *all, char **xpm_file);
int							finish_with_xpm(char *to_check_xpm);
int							count_q(t_all *all, char **splitted);
int							f_c_are_valid(t_all *all, char **splitted);
void						convert_rgb(t_all *all, char **splitted, char c);
int							check_white_space_in_the_mini_map(t_all *all);
int							parse_mini_map(t_all *all);
int							start_end_with_one(t_all *all, char *line);
int							is_player(t_all *all, char *line, int i);
int							has_only_ones(char *line);
int							parse_textures_colors(t_all *all);
int							isnt_valid(char *splitted, t_texture *tmp);
int							has_more_than_six_lines(t_all *all);
size_t						ft_strcpy(char *dest, const char *src);
int							count_mapfile_height(t_all *all);
int							fetch_full_map(t_all *all);
int							check_file_extention(t_all *all);
void						ft_close(int fd);

#endif