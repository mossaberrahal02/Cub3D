#include "cub3d.h"

void set_player_col_row(t_all *all, int i, int j)
{
	if(all->two_d_map[i][j] == 'N' || all->two_d_map[i][j] == 'S' || all->two_d_map[i][j] == 'E' || all->two_d_map[i][j] == 'W')
	{
		all->player.row = i + 1;
		all->player.column = j + 1;
	}
}

void set_player_direction(t_all *all)
{
	int i = 0;
	size_t j = 0;
	all->player.dir_x = 0;
	all->player.dir_y = 0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			set_player_col_row(all, i, j);
			if(all->two_d_map[i][j] == 'N')
				all->player.dir_y = -1;
			else if(all->two_d_map[i][j] == 'S')
				all->player.dir_y = 1;
			else if(all->two_d_map[i][j] == 'E')
				all->player.dir_x = 1;
			else if(all->two_d_map[i][j] == 'W')
				all->player.dir_x = -1;
			j++;
		}
		i++;
	}
}
