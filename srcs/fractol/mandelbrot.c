#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

void iteration_paint(int x, int y, t_data *img, int cycle)
{
    if (cycle == 1000)
        my_mlx_pixel_put(img, x, y, 0x00000000);
    else if (cycle > 40)
        my_mlx_pixel_put(img, x, y, 0x00F4C931);
    else if (cycle > 20)
        my_mlx_pixel_put(img, x, y, 0x00ED4E3F);
    else if (cycle > 10)
        my_mlx_pixel_put(img, x, y, 0x00A41000);
    else if (cycle > 5)
        my_mlx_pixel_put(img, x, y, 0x007E0000);
    else if (cycle > 3)
        my_mlx_pixel_put(img, x, y, 0x005E0000);
    else
        my_mlx_pixel_put(img, x, y, 0x004D0000);
}

int mandelbrot_plot(t_vars *vars, t_pixel *pixel)
{
    float c_re = (pixel->x - vars->max_x/2) * 4 / vars->max_x;
    float c_im = (pixel->y - vars->max_y/2) * 4 / vars->max_x;
    float x;
    float y;
    float x_new;
    int cycle;

    x = 0;
    y = 0;
    cycle = 0;
    while (x * x + y * y <= 4 && cycle < 1000)
    {
        x_new = x * x - y * y + c_re;
        y = 2 * x * y + c_im;
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
    //float scalemax_x;
    //float scalemax_y;

    //scalemax_x = (vars->max_x * vars->zoom);
    //scalemax_y = (vars->max_y * vars->zoom);
    //pixel.y = ((1080 - 0)*(mouse_y - scalemax_y))/((vars->max_y - scalemax_y) - scalemax_y) + 0;
    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    y = 0;
    pixel.y = ((vars->max_y/vars->zoom)/2);
    //pixel.y = ((float)mouse_x * vars->zoom * vars->zoom);
    while (y < vars->max_y)
    {
        pixel.x = ((vars->max_x/vars->zoom)/2) * -1;
        //pixel.x = ((1920 - 0)*(mouse_x - scalemax_x))/((vars->max_x - scalemax_x) - scalemax_x) + 0;
        x = 0;
        while (x < vars->max_x)
        {
            ret = mandelbrot_plot(vars, &pixel);
            iteration_paint(x, y, &img, ret);
            pixel.x += vars->zoom;
            x++;
        }
        y++;
        pixel.y += vars->zoom;

    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void    mandelbrot_set(t_vars *vars)
{
    int ret;
    t_pixel pixel;
    t_data img;

    img.img = mlx_new_image(vars->mlx, vars->max_x, vars->max_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    pixel.y = 0;
    while (pixel.y < vars->max_y)
    {
        pixel.x = 0;
        while (pixel.x < vars->max_x)
        {
            ret = mandelbrot_plot(vars, &pixel);
            iteration_paint(pixel.x , pixel.y, &img, ret);
            pixel.x++;
        }
        pixel.y++;
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
