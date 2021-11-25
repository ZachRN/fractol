#include <stdio.h>
#include <mlx.h> 
#include "fractol.h"
#include <math.h>

void	julia_initalize(t_julia *vars)
{
	vars->cycle = 10;
	vars->pause = 1;
	vars->zoom_amt = 1;
	vars->xre_min = -1.5;
	vars->xre_max = 1.5;
	vars->yre_max = 1.5;
	vars->yre_min = -1.5;
	vars->zoom = 1;
}

void	julia_set(t_julia *vars)
{
	julia_initalize(vars);
	julia_draw(vars);
	mlx_key_hook(vars->win, julia_key_hook, vars);
	mlx_hook(vars->win, 6, 1L << 6, julia_mouse_move, vars);
	mlx_hook(vars->win, 17, 1L << 17, julia_x_close_program, vars);
	mlx_mouse_hook(vars->win, julia_mouse_hook, vars);
	mlx_loop(vars->mlx);
}

static void	julia_draw_sub(t_data *img, t_pixel *pixel, t_julia *vars)
{
	pixel->y = (((vars->yre_max - vars->yre_min)
				 * (pixel->truey / (long double)vars->max_y)) + vars->yre_min);
	pixel->x = (((vars->xre_max - vars->xre_min)
				 * (pixel->truex / (long double)vars->max_x)) + vars->xre_min);
	iteration_paint(pixel, img, julia_plot(vars, pixel), vars->cycle);
}

void	julia_draw(t_julia *vars)
{
	t_pixel		pixel;
	t_data		img;
	long double	x;
	long double	y;
	int			cycle;

	pixel.realx = vars->realx;
	pixel.realy = vars->imagy;
	img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			 &img.line_length, &img.endian);
	y = 0;
	while (y < vars->max_y)
	{
		x = 0;
		while (x < vars->max_x)
		{
			pixel.truey = y;
			pixel.truex = x;
			julia_draw_sub(&img, &pixel, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	julia_plot(t_julia *vars, t_pixel *pixel)
{
	long double	x_new;
	long double	xhold;
	long double	yhold;
	int			cycle;

	cycle = 0;
	while (cycle < vars->cycle)
	{
		xhold = pixel->x;
		yhold = pixel->y;
		pixel->x = xhold * xhold - yhold * yhold + pixel->realx;
		pixel->y = 2 * xhold * yhold + pixel->realy;
		if (pixel->x * pixel->x + pixel->y * pixel->y > 4)
			break ;
		cycle++;
	}
	return (cycle);
}
