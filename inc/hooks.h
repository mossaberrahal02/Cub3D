#ifndef HOOKS_H
#define HOOKS_H

#include "cub3d.h"

int key_press(int keycode, t_data *data);
int key_release(int keycode, t_data *data);
void update_player(t_data *data);
int is_collision(t_data *data, float new_x, float new_y);

#endif