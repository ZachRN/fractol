#include "fractol.h"
#include <mlx.h>
#include <stdio.h>


// void iteration_paint(int x, int y, t_data *img, int cycle)
// {
//     if (cycle == 1000)
//         my_mlx_pixel_put(img, x, y, 0x00000000);
//     else if (cycle > 40)
//         my_mlx_pixel_put(img, x, y, 0x00F4C931);
//     else if (cycle > 20)
//         my_mlx_pixel_put(img, x, y, 0x00ED4E3F);
//     else if (cycle > 10)
//         my_mlx_pixel_put(img, x, y, 0x00A41000);
//     else if (cycle > 5)
//         my_mlx_pixel_put(img, x, y, 0x007E0000);
//     else if (cycle > 3)
//         my_mlx_pixel_put(img, x, y, 0x005E0000);
//     else
//         my_mlx_pixel_put(img, x, y, 0x004D0000);
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    iteration_paint(int x, int y, t_data *img, int cycle)
{
    int i;
    // void array[16];
    // array[0] = my_mlx_pixel_put(img, x, y, create_trgb(0,66, 30, 15));
    // return array[i];
    i = cycle % 16;
    if (cycle < 1000 && cycle > 0)
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


// void iteration_paint(int x, int y, t_data *img, int cycle)
// {
//     int color;

//     if (cycle == 1000)
//         color = create_trgb(0,0,0,0);
//     else if (cycle/256 == 1)
//         color = create_trgb(0,(255-(cycle%256)),255,0);
//     else 
//         color = create_trgb(0,255,(cycle%256),0);
//     my_mlx_pixel_put(img, x, y, color); 
// }

int mandelbrot_plot(t_vars *vars, t_pixel *pixel)
{
   // float c_re = (pixel->x - vars->xre_max/2) / vars->xre_max;
    //float c_im = (pixel->y - vars->yre_max/2) / vars->yre_max;
    float x;
    float y;
    float x_new;
    int cycle;
    // float re_start = -2;
    // float re_end = 1;
    // float im_start = -1;
    // float im_end = 1;
    //float c_re = (re_start + (pixel->x / vars->max_x) * (re_end - re_start));
    //float c_im = (re_start + (pixel->y/vars->max_y) * (im_end - im_start));

    x = 0;
    y = 0;
    cycle = 0;
    while (x * x + y * y <= 4 && cycle < 1000)
    {
        x_new = x * x - y * y + pixel->x;
        y = 2 * x * y + pixel->y;
        x = x_new;
        cycle++;
    }
    return (cycle);
}

void    mandelbrot_zoom(t_vars *vars, int mouse_x, int mouse_y)
{
    int ret;
    t_pixel pixel;
    t_data img;
    int x;
    int y;
    
    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
         &img.line_length, &img.endian);

    y = 0;
    while (y < vars->max_y)
    {
        x = 0;
        while (x < vars->max_x)
        {
            ret = mandelbrot_plot(vars, &pixel);
            iteration_paint(x, y, &img, ret);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void    mandelbrot_translate(t_vars *vars)
{
    int ret;
    t_pixel pixel;
    t_data img;
    float x;
    float y;

    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    y = 0;
    while (y < vars->max_y)
    {
        pixel.y = ((vars->yre_max - vars->yre_min) * ((y - 0)/(vars->max_y - 0))) + vars->yre_min;
        x = 0;
        while (x < vars->max_x)
        {
            pixel.x = ((vars->xre_max - vars->xre_min) * ((x - 0)/(vars->max_x - 0))) + vars->xre_min;
            //printf("pixel x scaled:%f || pixel y scaled:%f\n", pixel.x, pixel.y);
            ret = mandelbrot_plot(vars, &pixel);
            iteration_paint(x , y, &img, ret);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void    vars_initalize(t_vars *vars)
{
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
    vars->zoom_amt = .2;
    vars->zoom_modifier = 1.25;
}

void    mandelbrot_set(t_vars *vars)
{
    int ret;
    t_pixel pixel;
    t_data img;
    float x;
    float y;

    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // vars->xre_min = -1.00;
    // vars->xre_max = .2;
    // vars->yre_max = .6;
    // vars->yre_min = -.6;
    vars_initalize(vars);

    y = 0;
    while (y < vars->max_y)
    {
        pixel.y = ((vars->yre_max - vars->yre_min) * ((y - 0)/(vars->max_y - 0))) + vars->yre_min;
        x = 0;
        while (x < vars->max_x)
        {
            pixel.x = ((vars->xre_max - vars->xre_min) * ((x - 0)/(vars->max_x - 0))) + vars->xre_min;
            //printf("pixel x scaled:%f || pixel y scaled:%f\n", pixel.x, pixel.y);
            ret = mandelbrot_plot(vars, &pixel);
            iteration_paint(x , y, &img, ret);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_mouse_hook(vars->win, mouse_hook, vars);
    //mlx_hook(vars->win, 6, 1L<<6, focus_in_test, vars);
    mlx_hook(vars->win, 17, 1L<<17, x_close_program, vars);
    // mlx_loop_hook(vars->win, testing_loop, vars);
    //mlx_hook(vars->win, 8, 1L<<5, focus_out_test, vars);
    mlx_loop(vars->mlx);
}
