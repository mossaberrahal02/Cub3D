#include "../inc/cub3d.h"

void create_block_image(t_data *data)
{
	int x, y;

	data->wall_img = mlx_new_image(data->mlx, BLOCK_SIZE, BLOCK_SIZE);
	data->wall_img_addr = mlx_get_data_addr(data->wall_img, &data->bpp, &data->line_length, &data->endian);
	data->door_img = mlx_new_image(data->mlx, BLOCK_SIZE, BLOCK_SIZE);
	data->door_img_addr = mlx_get_data_addr(data->door_img, &data->bpp, &data->line_length, &data->endian);

	for (y = 1; y < BLOCK_SIZE - 1; y++)
	{
		for (x = 1; x < BLOCK_SIZE - 1; x++)
		{
			char *pixel = data->wall_img_addr + (y * data->line_length + x * (data->bpp / 8));
			*(unsigned int *)pixel = 0xFFFFFF;
		}
	}
	for (y = 1; y < BLOCK_SIZE - 1; y++)
	{
		for (x = 1; x < BLOCK_SIZE - 1; x++)
		{
			char *pixel = data->door_img_addr + (y * data->line_length + x * (data->bpp / 8));
			*(unsigned int *)pixel = 0x00FF00;
		}
	}
}

void draw_map(t_data *data)
{
	create_block_image(data);
	for (int y = 0; y < data->map_height; y++)
	{
		for (int x = 0; x < data->map_width; x++)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
			else if (data->map[y][x] == 'D')
				mlx_put_image_to_window(data->mlx, data->win, data->door_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
		}
	}
}

void draw_player(t_data *data)
{
	int player_radius = BLOCK_SIZE / 2;
	int x = data->player.x * BLOCK_SIZE;
	int y = data->player.y * BLOCK_SIZE;
	for (int i = -player_radius; i <= player_radius; i++)
	{
		for (int j = -player_radius; j <= player_radius; j++)
		{
			if (sqrt(i * i + j * j) <= player_radius) // the player is a circle
				mlx_pixel_put(data->mlx, data->win, x + i, y + j, 0xFF0000);
		}
	}
}
