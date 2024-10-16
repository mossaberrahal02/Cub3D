#include "../inc/cub3d.h"

void	raycast_init(t_data *data, t_raycast *raycast)
{
	raycast->map_x = (int)data->player.x;
	raycast->map_y = (int)data->player.y;
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (data->player.x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - data->player.x) * raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (data->player.y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - data->player.y) * raycast->delta_dist_y;
	}
}

int	dda_loop(t_data *data, t_raycast *raycast)
{
	int	side;
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			side = 1;
		}
		if (data->map[raycast->map_y][raycast->map_x] == '1')
			hit = 1;
	}
	return (side);
}

float	distance_to_wall(t_data *data, t_raycast *raycast, int i)
{
	int			side;
	float		perp_dist;

	raycast_init(data, raycast);
	side = dda_loop(data, raycast);
	if (side == 0)
	{
		if (raycast->ray_dir_x < 0)
			raycast->wall_sides[i] = 'w';
		else
			raycast->wall_sides[i] = 'e';
		// perp_dist = (raycast.map_x - data->player.x + (1 - raycast.step_x) / 2) / ray_dir_x;
		perp_dist = raycast->side_dist_x - raycast->delta_dist_x;
	}
	else
	{
		if (raycast->ray_dir_y < 0)
			raycast->wall_sides[i] = 'n';
		else
			raycast->wall_sides[i] = 's';
		// perp_dist = (raycast.map_y - data->player.y + (1 - raycast.step_y) / 2) / ray_dir_y;
		perp_dist = raycast->side_dist_y - raycast->delta_dist_y;
	}
	return (perp_dist * BLOCK_SIZE);
}

/*void	line_put(t_data *data, float end_x, float end_y)
{
	float	start_x;
	float	start_y;
	float	delta_x;
	float	delta_y;
	int		steps;

	start_x = data->player.x * BLOCK_SIZE;
	start_y = data->player.y * BLOCK_SIZE;
	delta_x = end_x - start_x;
	delta_y = end_y - start_y;
	if (fabs(delta_x) > fabs(delta_y))
		steps = (int)fabs(delta_x);
	else
		steps = (int)fabs(delta_y);
	data->ray_img = mlx_new_image(data->mlx, end_x - start_x, end_y - start_y);
	data->ray_img_addr = mlx_get_data_addr(data->ray_img, &data->bpp, &data->line_length, &data->endian);
	for (int i = 0; i <= steps; i++)
	{
		// mlx_pixel_put(data->mlx, data->win, (int)start_x, (int)start_y, 0xFFFF00);
		char *pixel = data->ray_img_addr + (int)(start_y * data->line_length + start_x * (data->bpp / 8));
		*(unsigned int *)pixel = 0xFFFF00;
		start_x += delta_x / (float)steps;
		start_y += delta_y / (float)steps;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->ray_img, start_x, start_y);
}*/
void	line_put(t_data *data, float end_x, float end_y)
{
	float	start_x;
	float	start_y;
	float	delta_x;
	float	delta_y;
	int		steps;

	start_x = data->player.x * BLOCK_SIZE;
	start_y = data->player.y * BLOCK_SIZE;
	delta_x = end_x - start_x;
	delta_y = end_y - start_y;
	if (fabs(delta_x) > fabs(delta_y))
		steps = (int)fabs(delta_x);
	else
		steps = (int)fabs(delta_y);
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(data->mlx, data->win, (int)start_x, (int)start_y, 0xFFFF00);
		start_x += delta_x / (float)steps;
		start_y += delta_y / (float)steps;
	}
	// if (!(data->ray_img))
	// {
	// 	printf("ray_image not found\n");
	// 	data->ray_img = mlx_new_image(data->mlx, data->map_width * BLOCK_SIZE, data->map_height * BLOCK_SIZE);
	// 	data->ray_img_addr = mlx_get_data_addr(data->ray_img, &data->bpp, &data->line_length, &data->endian);
	// }
	// 	for (int i = 0; i <= steps; i++)
	// 	{
	// 		int pixel_x = (int)start_x;
	// 		int pixel_y = (int)start_y;

	// 		// Make sure pixel is within the window bounds before drawing
	// 		// if (pixel_x >= 0 && pixel_x < data->map_width * BLOCK_SIZE && pixel_y < data->map_height * BLOCK_SIZE)
	// 		// {
	// 			// Calculate pixel position in the image buffer and set color
	// 			char *pixel = data->ray_img_addr + (pixel_y * data->line_length + pixel_x * (data->bpp / 8));
	// 			*(unsigned int *)pixel = 0xFFFF00;
	// 		// }
	// 		// Increment positions for next step
	// 		pixel_x += delta_x / (float)steps;
	// 		pixel_y += delta_y / (float)steps;
	// 	}
}

void	cast_rays(t_data *data)
{
	t_raycast	raycast;
	float	player_angle;
	float	ray_angle;	
	float	ray_end_x;
	float	ray_end_y;

	raycast.distances = malloc(sizeof(float) * NUM_RAYS);
	raycast.wall_sides = malloc(sizeof(float) * NUM_RAYS);
	player_angle = atan2(data->player.dir_y, data->player.dir_x);
	for (int i = 0; i < NUM_RAYS; i++)
	{
		ray_angle = player_angle - (FOV / 2) + (i * FOV / NUM_RAYS);
		raycast.ray_dir_x = cos(ray_angle);
		raycast.ray_dir_y = sin(ray_angle);
		raycast.distances[i] = distance_to_wall(data, &raycast, i);
		ray_end_x = data->player.x * BLOCK_SIZE + cos(ray_angle) * raycast.distances[i];
		ray_end_y = data->player.y * BLOCK_SIZE + sin(ray_angle) * raycast.distances[i];
		line_put(data, ray_end_x, ray_end_y);
	}
	render_3d_view(data, &raycast);
	// mlx_put_image_to_window(data->mlx, data->win, data->ray_img, data->map_width * BLOCK_SIZE, data->map_height * BLOCK_SIZE);
}
