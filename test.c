#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define BLUE 0x0000FF  // Hex code for blue

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
}	t_data;

void    create_blue_image(t_data *data)
{
    int x, y;
    char *pixel;
    int bytes_per_pixel = data->bpp / 8;

    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Calculate the address of the pixel at (x, y)
            pixel = data->addr + (y * data->line_length + x * bytes_per_pixel);
            // Set the pixel to blue
            *(unsigned int *)pixel = 0xcccccc;
        }
    }
    mlx_put_image_to_window(data->mlx, data->win_3d, data->img, 0, 0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
	data.win_3d = mlx_new_window(data.mlx, WIDTH, HEIGHT, "3D VIEW");

    // Create an image

    // Fill the image with blue pixels
    create_blue_image(&data);

    // Put the image into the window

    // Keep the window open
    mlx_loop(data.mlx);
    
    return 0;
}
