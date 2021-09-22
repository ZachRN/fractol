#include <stdio.h>
#include <mlx.h> 
#include "fractol.h"

int julia_set(void)
{
    int r = 2;
    float x = 0;
    float y = 0;
    float max_x = 1280;
    float max_y = 720;
    int iteration = 0;
    int max_iteration = 1000;

    float zx;
    float zy;
    while(x < 1280)
    {
        zx = (r * -1) + (((x - 0)*(r - (r * -1)))/(max_x - 0));
        printf("scaled pixel value of %f 0 is: %f \n", x, zx);
        x++;
    }
    return (0);
}

int color_find(t_vars *vars, t_pixel *pixel)
{
    int iteration;
    int max_iteration;
    float cx = .2;
    float cy = .104;
    float xtemp;

    iteration = 0;
    max_iteration = 1000;
    while ((pixel->zx * pixel->zx) + (pixel->zy * pixel->zy) < (vars->r * vars->r)
         && iteration < max_iteration)
    {
        xtemp = pixel->zx * pixel->zx - pixel->zy * pixel->zy;
        pixel->zy = 2 * pixel->zx * pixel->zy + cy;
        pixel->zx= xtemp + cx;

        iteration++;
    }
    if (iteration == max_iteration)
        return (0);
    else
        return (1);
    
}

void temp_name(t_vars *vars)
{
    t_pixel pixel;
    int ret;
    t_data img;

    img.img = mlx_new_image(vars->mlx, 1280, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    pixel.x = 0;
    while (pixel.x < vars->max_x)
    {
        pixel.y = 0;
        while (pixel.y < vars->max_y)
        {
            pixel.zx = (vars->r * -1) + (((pixel.x - 0) * 
                (vars->r - (vars->r * -1)))/(vars->max_x - 0));
            pixel.zy = (vars->r * -1) + (((pixel.y - 0) * 
                (vars->r - (vars->r * -1)))/(vars->max_y - 0));
            ret = color_find(vars, &pixel);
            if (ret == 0)
                my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x0000FF00);
            else
                my_mlx_pixel_put(&img, pixel.x, pixel.y, 0x00FF0000);
            pixel.y++;
        }
        pixel.x++;
    }
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    mlx_key_hook(vars->win, key_hook, &vars);
    mlx_mouse_hook(vars->win, mouse_hook, &vars);
    mlx_loop(vars->mlx);
}
