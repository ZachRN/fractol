#include "fractol.h"
#include <mlx.h>    

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        // if (ft_strncmp(str, "Julia", 6) == 0)
        //     temp_name(&screen, &vars);
        if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
            mandelbrot_verification(argc, argv);
        else
        {
            param_invalid();
            return(0);
        }   
    }
    else
    {
        param_invalid();
        return(0);
    }
    // x = 0;
    // y = 0;
    
    // img.img = mlx_new_image(vars.mlx, 1280, 720);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // // while (x < 1280)
    // // {
    // //     my_mlx_pixel_put(&img, x, 360, 0x00FF0000);
    // //     x++;
    // // }
    // // while (y < 720)
    // // {
    // //     my_mlx_pixel_put(&img, 640, y, 0x00FF0000);
    // //     y++;
    // // }
    // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    // mlx_key_hook(vars.win, key_hook, &vars);
    // mlx_mouse_hook(vars.win, mouse_hook, &vars);
    // // mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);

    // mlx_loop(vars.mlx);
    
}