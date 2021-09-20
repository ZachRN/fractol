#include "fractol.h"
#include <mlx.h>

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == Key_ESC)
        kill_program(vars);
    printf("This is keycode: %d\n", keycode);
    return (0);
   //mlx_destroy_window(vars->mlx, vars->win);
}

int mouse_hook(int mousecode, t_vars *vars)
{
    printf("This is mousecode: %d\n", mousecode);
    return (0);
}

void kill_program(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}
