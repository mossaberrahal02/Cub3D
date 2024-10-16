#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include "cub3d.h"

typedef struct s_player	t_player;

char **parse_map(const char *filename, int *width, int *height, t_player *player);

#endif