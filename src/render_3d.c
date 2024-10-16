#include "../inc/cub3d.h"

int	return_wall_side(t_raycast *raycast, int i)
{
	if (raycast->wall_sides[i] == 'n')
		return (NORTH);
	else if (raycast->wall_sides[i] == 's')
		return (SOUTH);
	else if (raycast->wall_sides[i] == 'w')
		return (WEST);
	else if (raycast->wall_sides[i] == 'e')
		return (EAST);
	return (0xffffff);
}

void	render_3d_view(t_data *data, t_raycast *raycast)
{
	int	color;
	int	i, y;
	char	*pixel;

	data->render_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->render_img)
		return ;
	data->render_img_addr = mlx_get_data_addr(data->render_img, &data->bpp, &data->line_length, &data->endian);
	if (!data->render_img_addr)
		return ;
	for (i = 0; i < NUM_RAYS; i++)
	{
		int wall_height = (int)((HEIGHT / raycast->distances[i]) * PROJECTION_PLANE_DIST);	

		int start_y = (HEIGHT / 2) - (wall_height / 2);
		if (start_y < 0) start_y = 0;	

		int end_y = (HEIGHT / 2) + (wall_height / 2);
		if (end_y >= HEIGHT) end_y = HEIGHT - 1;	

		int screen_x = (i * WIDTH) / NUM_RAYS;	

		// color the ceiling
		for (y = 0; y < start_y; y++)
		{
			if (y < 0 || y > HEIGHT)
				continue ;
			if (screen_x < 0 || screen_x > WIDTH)
				continue ;
			pixel = data->render_img_addr + (y * data->line_length + screen_x * (data->bpp / 8));
			if (pixel)
				*(unsigned int *)pixel = CEILING;
			mlx_pixel_put(data->mlx, data->win_3d, screen_x, y, CEILING);
		}
		// color the walls
		for (y = start_y; y < end_y; y++)
		{
			color = return_wall_side(raycast, i);
			mlx_pixel_put(data->mlx, data->win_3d, screen_x, y, color);
		}
		// color the floor
		for (y = end_y; y < HEIGHT; y++)
			mlx_pixel_put(data->mlx, data->win_3d, screen_x, y, FLOOR);
	}
	// printf("not here1\n");
	// mlx_put_image_to_window(data->mlx, data->win_3d, data->render_img, 0, 0);
	// printf("not here2\n");
}
