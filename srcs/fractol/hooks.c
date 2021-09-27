#include "fractol.h"
#include <mlx.h>

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == Key_ESC)
        kill_program(vars);
    // else if (keycode == Key_SPACE)
    // {
    //     if (vars->color == 0)
    //         vars->color = 1;
    //     else
    //         vars->color = 0;
    // }
    else if (keycode == Key_W)
    {
        vars->yre_min -= vars->zoom_amt/vars->zoom;
        vars->yre_max -= vars->zoom_amt/vars->zoom;
    }
    else if (keycode == Key_S)
    {
        vars->yre_min += vars->zoom_amt/vars->zoom;
        vars->yre_max += vars->zoom_amt/vars->zoom;
    }
    else if (keycode == Key_A)
    {
        vars->xre_min -= vars->zoom_amt/vars->zoom;
        vars->xre_max -= vars->zoom_amt/vars->zoom;
    }
    else if (keycode == Key_D)
    {
        vars->xre_min += vars->zoom_amt/vars->zoom;
        vars->xre_max += vars->zoom_amt/vars->zoom;
    }
    else if (keycode == Key_E)
        vars->zoom_amt /= 1.1;
    else if (keycode == Key_Q)
        vars->zoom_amt *= 1.1;
    else if (keycode == Key_Z)
    {
        vars->zoom *= vars->zoom_modifier;
        vars->xre_min *= vars->zoom;
        vars->xre_max *= vars->zoom;
        vars->yre_max *= vars->zoom;
        vars->yre_min *= vars->zoom;
        mandelbrot_translate(vars);
        return(0);
    }
    else if (keycode == Key_X)
    {
        vars->zoom /= vars->zoom_modifier;
        vars->xre_min *= vars->zoom;
        vars->xre_max *= vars->zoom;
        vars->yre_max *= vars->zoom;
        vars->yre_min *= vars->zoom;
        mandelbrot_translate(vars);
        return(0);
    }
    mandelbrot_translate(vars);
    return (0);
   //mlx_destroy_window(vars->mlx, vars->win);
}

int mouse_hook(int mousecode,int x, int y, t_vars *vars)
{
    printf("This is mousecode: %d\n", mousecode);
    printf("x is %d || y is %d\n", x, y);
    if (mousecode == 5)
    {
        vars->zoom *= vars->zoom_modifier;
        vars->xre_min *= vars->zoom;
        vars->xre_max *= vars->zoom;
        vars->yre_max *= vars->zoom;
        vars->yre_min *= vars->zoom;
        mandelbrot_translate(vars);
        return(0);
    }
    else if (mousecode == 4)
    {
        vars->zoom /= vars->zoom_modifier;
        vars->xre_min *= vars->zoom;
        vars->xre_max *= vars->zoom;
        vars->yre_max *= vars->zoom;
        vars->yre_min *= vars->zoom;
        mandelbrot_translate(vars);
        return(0);
    }
    return (0);
}

// int focus_in_test(int x, int y, t_vars *vars)
// {
//     if (x > 0 && x < 1920 && y > 0 && y < 1080)
//     printf("x: %d || y: %d\n", x, y);
//     return(0);
// }

int x_close_program(t_vars *vars)
{
    exit(0);
    return(0);
}

// int testing_loop(t_vars *vars)
// {
//     printf("test");
//     // if (vars->key == 1)
//     // {
//     //     printf("Hello");
//     //     // vars->zoom += 1;
//     //     // printf("zoom is now %f", vars->zoom);
//     //     // vars->key = -1;
//     // }
//     return(0);
// }

void kill_program(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}
