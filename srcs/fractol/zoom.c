#include "fractol.h"
#include <mlx.h> 
#include <math.h>

void	julia_zoom_in(t_julia *vars, int mouse_x, int mouse_y)
{	
	long double	percent;
	long double	sub_total;
	long double	zoomtwo;

	zoomtwo = vars->zoom;
	if (zoomtwo > 1)
		zoomtwo = .8;
	percent = (long double)mouse_x / (long double)vars->max_x;
	sub_total = (vars->xre_max - vars->xre_min);
	vars->xre_min += (sub_total - (sub_total * zoomtwo)) * percent;
	vars->xre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);
	percent = ((long double)vars->max_y
			 - (long double)mouse_y) / (long double)vars->max_y;
	sub_total = (vars->yre_max - vars->yre_min);
	vars->yre_min += (sub_total - (sub_total * zoomtwo)) * percent;
	vars->yre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);
	julia_draw(vars);
}

void	julia_zoom_out(t_julia *vars, int mouse_x, int mouse_y)
{
	long double	percent;
	long double	sub_total;

	percent = (long double)mouse_x / (long double)vars->max_x;
	sub_total = (vars->xre_max - vars->xre_min);
	vars->xre_min -= ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * percent;
	vars->xre_max += ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * (1.0 - percent);
	percent = ((long double)vars->max_y
			 - (long double)mouse_y) / (long double)vars->max_y;
	sub_total = (vars->yre_max - vars->yre_min);
	vars->yre_min -= ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * percent;
	vars->yre_max += ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * (1.0 - percent);
	julia_draw(vars);
}

/*
Welcome to deciding how to Zoom in, the math explaind in a nicer way

We will start with the percent variable, it stores how far along, the mouse x
coordinate is, across the window when you zoom so, for example 200/800 is 25%

Then for sub_total it takes the scale of the imaginary axis, lets say it is base
mandelbrot set of -2.00 to 2.00, sub_total then will be 4
The X max of 2 will then shave off 75% of the pixels for the zoom, and the min
will shave off only 25% of pixels, resulting in a zoom centered on the mouse
location.

This is repeated for both X and Y.
*/
void	mandelbrot_zoom_in(t_mand *vars, int mouse_x, int mouse_y)
{
	long double	percent;
	long double	sub_total;
	long double	zoomtwo;

	zoomtwo = vars->zoom;
	if (zoomtwo > 1)
		zoomtwo = .8;
	percent = (long double)mouse_x / (long double)vars->max_x;
	sub_total = (vars->xre_max - vars->xre_min);
	vars->xre_min += (sub_total - (sub_total * zoomtwo)) * percent;
	vars->xre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);
	percent = ((long double)vars->max_y
			- (long double)mouse_y) / (long double)vars->max_y;
	sub_total = (vars->yre_max - vars->yre_min);
	vars->yre_min += (sub_total - (sub_total * zoomtwo)) * percent;
	vars->yre_max -= (sub_total - (sub_total * zoomtwo)) * (1.0 - percent);
	mandelbrot_draw(vars);
}

/*
Zooming out works just a tad different from Zoom in,
The Equation used to calcualte the pixels to add, takes the 
Sub_total multiplied by 1.25 to the power of how many zooms deep,
*/
void	mandelbrot_zoom_out(t_mand *vars, int mouse_x, int mouse_y)
{
	long double	percent;
	long double	sub_total;

	percent = (long double)mouse_x / (long double)vars->max_x;
	sub_total = (vars->xre_max - vars->xre_min);
	vars->xre_min -= ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * percent;
	vars->xre_max += ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * (1.0 - percent);
	percent = ((long double)vars->max_y
			- (long double)mouse_y) / (long double)vars->max_y;
	sub_total = (vars->yre_max - vars->yre_min);
	vars->yre_min -= ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * percent;
	vars->yre_max += ((sub_total
				 * pow(1.25, vars->zoom_amt)) - sub_total) * (1.0 - percent);
	mandelbrot_draw(vars);
}
