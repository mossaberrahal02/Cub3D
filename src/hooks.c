#include "../inc/cub3d.h"

int is_collision(t_data *data, float new_x, float new_y)
{
	if (data->map[(int)new_y][(int)new_x] == '1' || \
		data->map[(int)new_y][(int)new_x] == 'D')
		return (1);
	return (0);
}

int key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W)
		data->player.move_forward = 1;
	if (keycode == S)
		data->player.move_backward = 1;
	if (keycode == A)
		data->player.move_left = 1;
	if (keycode == D)
		data->player.move_right = 1;
	if (keycode == LEFT)
		data->player.rotate_left = 1;
	if (keycode == RIGHT)
		data->player.rotate_right = 1;
	if (keycode == SPACE)
	{
		int map_x = (int)(data->player.x + data->player.dir_x);
		int map_y = (int)(data->player.y + data->player.dir_y);
		if (data->map[map_y][map_x] == 'D')
			data->map[map_y][map_x] = '0';
	}
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.move_forward = 0;
	if (keycode == S)
		data->player.move_backward = 0;
	if (keycode == A)
		data->player.move_left = 0;
	if (keycode == D)
		data->player.move_right = 0;
	if (keycode == LEFT)
		data->player.rotate_left = 0;
	if (keycode == RIGHT)
		data->player.rotate_right = 0;
	return (0);
}

void update_player(t_data *data)
{
	float new_x, new_y;

	if (data->player.move_forward)
	{
		new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.move_backward)
	{
		new_x = data->player.x - data->player.dir_x * MOVE_SPEED;
		new_y = data->player.y - data->player.dir_y * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.move_left)
	{
		new_x = data->player.x + data->player.dir_y * MOVE_SPEED;
		new_y = data->player.y - data->player.dir_x * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.move_right)
	{
		new_x = data->player.x - data->player.dir_y * MOVE_SPEED;
		new_y = data->player.y + data->player.dir_x * MOVE_SPEED;
		if (!is_collision(data, new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (data->player.rotate_left)
	{
		float old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED) - data->player.dir_y * sin(-ROT_SPEED);
		data->player.dir_y = old_dir_x * sin(-ROT_SPEED) + data->player.dir_y * cos(-ROT_SPEED);
	}
	if (data->player.rotate_right)
	{
		float old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(ROT_SPEED) - data->player.dir_y * sin(ROT_SPEED);
		data->player.dir_y = old_dir_x * sin(ROT_SPEED) + data->player.dir_y * cos(ROT_SPEED);
	}
}
