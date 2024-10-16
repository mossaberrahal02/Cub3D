#ifndef DRAW_MAP_H
#define DRAW_MAP_H

#include "cub3d.h"

typedef struct s_data	t_data;

void    create_block_image(t_data *data);
void    draw_map(t_data *data);
void    draw_player(t_data *data);

#endif