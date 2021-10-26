#include <stdio.h>
#include <mlx.h> 
#include "fractol.h"
#include <math.h>

void julia_initalize(t_julia *vars)
{
	vars->cycle = 10;
	vars->pause = 1;
	vars->zoom_amt = 1;
	vars->xre_min = -1.5;
    vars->xre_max = 1.5;
    vars->yre_max = 1.5;
 	vars->yre_min = -1.5;
	vars->realx = -0.7;
	vars->imagy = 0.27015;
	vars->zoom = 1;
}

void julia_set(t_julia *vars)
{
    julia_initalize(vars);
	julia_draw(vars);
	mlx_key_hook(vars->win, julia_key_hook, vars);
	mlx_hook(vars->win, 6, 1L<<6, julia_mouse_move, vars);
    mlx_hook(vars->win, 17, 1L<<17, julia_x_close_program, vars);
	mlx_mouse_hook(vars->win, julia_mouse_hook, vars);
    mlx_loop(vars->mlx);
}

void julia_draw(t_julia *vars)
{
    t_pixel pixel;
    t_data img;
    long double x;
    long double y;
	int cycle;

	pixel.realx = vars->realx;
	pixel.realy = vars->imagy;
    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    y = 0;
    while (y < vars->max_y)
    {
		x = 0;
        while (x < vars->max_x)
        {
			pixel.truey = y;
			pixel.truex = x;
			pixel.y = ((vars->yre_max - vars->yre_min) * ((y - 0)/((long double)vars->max_y - 0))) + vars->yre_min;
			pixel.x = ((vars->xre_max - vars->xre_min) * ((x - 0)/((long double)vars->max_x - 0))) + vars->xre_min;
            iteration_paint(&pixel, &img, julia_plot(vars, &pixel), vars->cycle);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int julia_plot(t_julia *vars, t_pixel *pixel)
{
    long double x_new;
	long double xhold;
	long double yhold;
    int cycle;

    cycle = 0;
    while (cycle < vars->cycle)
    {
		xhold = pixel->x;
		yhold = pixel->y;
		pixel->x = xhold * xhold - yhold * yhold + pixel->realx;
		pixel->y = 2 * xhold * yhold + pixel->realy;
		if (pixel->x * pixel->x + pixel->y * pixel->y > 4)
			break;
		cycle++;
    }
    return (cycle);
}


void    julia_zoom_in(t_julia *vars, int mouse_x, int mouse_y)
{
    long double percent;
    long double sub_total;
    long double zoomtwo;

    zoomtwo = vars->zoom;
    if (zoomtwo > 1)
        zoomtwo = .8;
    percent = (long double)mouse_x/(long double)vars->max_x;
    sub_total = (vars->xre_max - vars->xre_min);
    vars->xre_min += (sub_total - (sub_total * zoomtwo)) * percent;
    vars->xre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);

    percent = ((long double)vars->max_y - (long double)mouse_y)/(long double)vars->max_y;
    sub_total = (vars->yre_max - vars->yre_min);
    vars->yre_min += (sub_total - (sub_total * zoomtwo)) * percent;
    vars->yre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);

    julia_draw(vars);
}

/*
Zooming out works just a tad different from Zoom in,
The Equation used to calcualte the pixels to add, takes the 
Sub_total multiplied by 1.25 to the power of how many zooms deep,
*/
void    julia_zoom_out(t_julia *vars, int mouse_x, int mouse_y)
{
    long double percent;
    long double sub_total;

    percent = (long double)mouse_x/(long double)vars->max_x;
    sub_total = (vars->xre_max - vars->xre_min);
    vars->xre_min -= ((sub_total * pow(1.25,vars->zoom_amt)) - sub_total) * percent;
    vars->xre_max += ((sub_total * pow(1.25,vars->zoom_amt)) - sub_total) * (1.0 - percent);

    percent = ((long double)vars->max_y - (long double)mouse_y)/(long double)vars->max_y;
    sub_total = (vars->yre_max - vars->yre_min);
    vars->yre_min -= ((sub_total * pow(1.25,vars->zoom_amt)) - sub_total) * percent;
    vars->yre_max += ((sub_total * pow(1.25,vars->zoom_amt)) - sub_total) * (1.0 - percent);

    julia_draw(vars);
}