#include "fractol.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    iteration_paint(t_pixel *pixel, t_data *img, int cycle, int max)
{
    int i;
    int x;
    int y;

    x = pixel->truex;
    y = pixel->truey;
    i = cycle % 16;
    if (cycle < max && cycle > 0)
    {
        if (i == 0)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,66, 30, 15)));
        else if (i == 1)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,25, 7, 26)));
        else if (i == 2)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,9, 1, 47)));
        else if (i == 3)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,4, 4, 73)));
        else if (i == 4)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,0, 7, 100)));
        else if (i == 5)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,12, 44, 138)));
        else if (i == 6)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,24, 82, 177)));
        else if (i == 7)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,57, 125, 209)));
        else if (i == 8)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,134, 181, 229)));
        else if (i == 9)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,211, 236, 248)));
        else if (i == 10)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,241, 233, 191)));
        else if (i == 11)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,248, 201, 95)));
        else if (i == 12)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,255, 170, 0)));
        else if (i == 13)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,204, 128, 0)));
        else if (i == 14)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,153, 87, 0)));
        else if (i == 15)
            return (my_mlx_pixel_put(img, x, y, create_trgb(0,106, 52, 3)));
    }
    return (my_mlx_pixel_put(img, x, y, 0x00000000));
}

/*
Welcome to drawing the mandelbrot set,

It is passed a pixel coordinate which is scaled to lie within the scaled plane
it then follows a set alogrithm in order to decide if the pixel will reach
the escape before a certain iterations. The iterations go up as
you begin to zoom in
*/

int mandelbrot_plot(t_mand *vars, t_pixel *pixel)
{
    long double x;
    long double y;	
    long double x_new;
    int cycle;

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
void mandelbrot_draw(t_mand *vars)
{
    t_pixel pixel;
    t_data img;
    long double x;
    long double y;

    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    y = 0;
    while (y < vars->max_y)
    {
        pixel.y = ((vars->yre_max - vars->yre_min) * ((y - 0)/(vars->max_y - 0))) + vars->yre_min;
        x = 0;
        while (x < vars->max_x)
        {
            pixel.truex = x;
            pixel.truey = y;
            pixel.x = ((vars->xre_max - vars->xre_min) * ((x - 0)/(vars->max_x - 0))) + vars->xre_min;
            iteration_paint(&pixel, &img, mandelbrot_plot(vars, &pixel), vars->cycle);
            x++;
        }
        y++;
    }
    printf("x max: %.100Lf\nx min: %.100Lf\ny max: %.100Lf\ny min: %.100Lf\n",vars->xre_max,vars->xre_min,vars->yre_max,vars->yre_min);
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
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
void    mandelbrot_zoom_in(t_mand *vars, int mouse_x, int mouse_y)
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

    mandelbrot_draw(vars);
}

/*
Zooming out works just a tad different from Zoom in,
The Equation used to calcualte the pixels to add, takes the 
Sub_total multiplied by 1.25 to the power of how many zooms deep,
*/
void    mandelbrot_zoom_out(t_mand *vars, int mouse_x, int mouse_y)
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

    mandelbrot_draw(vars);
}

void    vars_initalize(t_mand *vars)
{

    //ESTIMATED MANDELBROT COORDS
    // vars->xre_min = -2.00;
    // vars->xre_max = 2.00;
    // vars->yre_max = 1.5;
    // vars->yre_min = -1.5;

    //BASE MANDELBROT COORDS
    vars->xre_min = -2.00;
    vars->xre_max = .47;
    vars->yre_max = 1.12;
    vars->yre_min = -1.12;

    //SPECIAL ONES
    // vars->xre_min = -0.750222;
    // vars->xre_max = -0.749191;
    // vars->yre_max = 0.031161;
    // vars->yre_min = 0.031752;

    vars->zoom = 1;
    vars->zoom_amt = 1;
    vars->cycle = 100;
}

void    mandelbrot_set(t_mand *vars)
{

    vars_initalize(vars);
    mandelbrot_draw(vars);

    mlx_key_hook(vars->win, mand_key_hook, vars);
    mlx_mouse_hook(vars->win, mand_mouse_hook, vars);
    mlx_hook(vars->win, 17, 1L<<17, mand_x_close_program, vars);
    mlx_loop(vars->mlx);
}
