#include "../inc/cub3d.h"

int game_loop(t_data *data)
{
	static int	nframes = 0; // or you can put it in the struct, use with %
if (nframes == REFRESH_RATE)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_clear_window(data->mlx, data->win_3d);
	update_player(data);
	draw_map(data);
	draw_player(data);
	cast_rays(data);
	nframes = 0;
}
	nframes++;
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./cub3d map.cub\n");
		return (1);
	}

	t_data data = {}; // initialis
	// data.player = {0,0,0,0,0,0,0,0,0,0};

	data.map = parse_map(argv[1], &data.map_width, &data.map_height, &data.player);
	if (!data.map)
		return (1);

	data.mlx = mlx_init();
	data.win_3d = mlx_new_window(data.mlx, WIDTH, HEIGHT, "3D VIEW");
	data.win = mlx_new_window(data.mlx, data.map_width * BLOCK_SIZE, data.map_height * BLOCK_SIZE, "2D MAP");
	draw_map(&data);
	draw_player(&data);
	cast_rays(&data);
	
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);

	mlx_loop(data.mlx);

	return (0);
}