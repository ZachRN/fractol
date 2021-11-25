#include "fractol.h"
#include <mlx.h>

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    iteration_paint(t_pixel *pixel, t_data *img, int cycle, int max)
{
	static const int color[15] =
	{
		4333071,
		1640218,
		590127,
		263241,
		1892,
		797834,
		1594033,
		3767761,
		8828389,
		13888760,
		16304479,
		16755200,
		13402112,
		10049280,
		6960131
	};
    int i;
    int x;
    int y;

    x = pixel->truex;
    y = pixel->truey;
    i = cycle % 16;
	if (cycle < max && cycle > 0)
		return (my_mlx_pixel_put(img, x, y, color[i]));
    return (my_mlx_pixel_put(img, x, y, 0x00000000));
}