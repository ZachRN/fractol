#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define Key_ESC 53
# define M_Wheel_Up 5
# define M_Wheel_Down 4

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}              t_data;

typedef struct  s_vars{
    void    *mlx;
    void    *win;
}               t_vars;

void    param_invalid();
int     key_hook(int keycode, t_vars *vars);
int     mouse_hook(int mosuecode, t_vars *vars);
void    kill_program(t_vars *vars);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif  