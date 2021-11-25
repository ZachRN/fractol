#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

/*
Welcome to drawing the mandelbrot set,

It is passed a pixel coordinate which is scaled to lie within the scaled plane
it then follows a set alogrithm in order to decide if the pixel will reach
the escape before a certain iterations. The iterations go up as
you begin to zoom in
*/

int	mandelbrot_plot(t_mand *vars, t_pixel *pixel)
{
	long double	x;
	long double	y;	
	long double	x_new;
	int			cycle;

	x = 0;
	y = 0;
	cycle = 0;
	while (x * x + y * y <= 4 && cycle < vars->cycle)
	{
		x_new = x * x - y * y + pixel->x;
		y = 2 * x * y + pixel->y;
		x = x_new;
		cycle++;
	}
	return (cycle);
}

/*
Drawing the mandelbrot is fairly simple except for some weird math equation
that took forever to figure out

We start by definign the image for minilibx.

We take each pixel of the window, and then scale the X and Y individiually
to their respective axis scale. Using a scaling formula I found online somewhere
We then pass the original X and Y coordinates of the pixel, the return value
of the mandelbrot algorithm
*/
static void	mandelbrot_sub_draw(t_data *img, t_pixel *pixel, t_mand *vars)
{
	pixel->x = ((vars->xre_max - vars->xre_min)
			 * (((long double)pixel->truex - 0) / (vars->max_x - 0))) + vars->xre_min;
	iteration_paint(pixel, img,
		 mandelbrot_plot(vars, pixel), vars->cycle);
}

void	mandelbrot_draw(t_mand *vars)
{
	t_pixel		pixel;
	t_data		img;
	long double	x;
	long double	y;
	int			cycle;

	img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			 &img.line_length, &img.endian);
	y = 0;
	while (y < vars->max_y)
	{
		pixel.y = ((vars->yre_max - vars->yre_min)
				 * ((y - 0) / (vars->max_y - 0))) + vars->yre_min;
		x = 0;
		while (x < vars->max_x)
		{
			pixel.truex = x;
			pixel.truey = y;
			mandelbrot_sub_draw(&img, &pixel, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

static void	vars_initalize(t_mand *vars)
{
	vars->xre_min = -2.00;
	vars->xre_max = .47;
	vars->yre_max = 1.12;
	vars->yre_min = -1.12;
	vars->zoom = 1;
	vars->zoom_amt = 1;
	vars->cycle = 100;
}

void	mandelbrot_set(t_mand *vars)
{
	vars_initalize(vars);
	mandelbrot_draw(vars);
	mlx_key_hook(vars->win, mand_key_hook, vars);
	mlx_mouse_hook(vars->win, mand_mouse_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, mand_x_close_program, vars);
	mlx_loop(vars->mlx);
}
