#ifndef CUB3D_H
#define CUB3D_H

#include "draw_map.h"
#include "hooks.h"
#include "map_parser.h"
#include "raycasting.h"
#include "render_3d.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define BLOCK_SIZE 20
# define REFRESH_RATE	60000
# define MOVE_SPEED	REFRESH_RATE * 0.0000075
# define ROT_SPEED	REFRESH_RATE * 0.0000050
# define WIDTH		1000
# define HEIGHT		500
# define PROJECTION_PLANE_DIST	60
# define ESC		65307
# define W			119
# define S			115
# define A			97
# define D			100
# define LEFT		65361
# define RIGHT		65363
# define SPACE		32
# define FOV		M_PI / 3
# define NUM_RAYS	1000

# define CEILING	0x00ffff // cyan
# define NORTH		0xeeeeee // 
# define SOUTH		0xdddddd // 
# define WEST		0xcccccc // 
# define EAST		0xbbbbbb // 
# define FLOOR		0x117c13 // grass green

typedef struct s_player {
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
} t_player;

typedef struct  s_data {
	void		*mlx;
	void		*win;
    void		*img;
    char		*addr;
	void		*win_3d;
	void		*wall_img;
	char		*wall_img_addr;
	void		*door_img;
	char		*door_img_addr;
	void		*ray_img;
	char		*ray_img_addr;
	void		*render_img;
	char		*render_img_addr;
	char		**map;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
    int     bpp;
    int     line_length;
    int     endian;
	t_player	player;
}	t_data;

int game_loop(t_data *data);

#endif