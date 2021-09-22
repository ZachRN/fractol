#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"

# define Key_ESC 53
# define Key_SPACE 49

# define M_Wheel_Up 5
# define M_Wheel_Down 4

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}              t_data;

// typedef struct s_screen{
//     int     max_x;
//     int     max_y;
//     float   r;
// }               t_screen;

typedef struct  s_vars{
    void    *mlx;
    void    *win;
    int     color;
    float   zoom;
    int     max_x;
    int     max_y;
    float   r;
    int     *array;
}               t_vars;

typedef struct  s_pixel{
    float   x;
    float   y;
    float   zx;
    float   zy;
}               t_pixel;

void    param_invalid();
int     key_hook(int keycode, t_vars *vars);
int     mouse_hook(int mosuecode, int x, int y, t_vars *vars);
void    kill_program(t_vars *vars);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int julia_set(void);
void temp_name(t_vars *vars);
int color_find(t_vars *vars, t_pixel *pixel);
void    mandelbrot_set(t_vars *vars);
int mandelbrot_plot(t_vars *vars, t_pixel *pixel);
void    mandelbrot_verification(int argc, char *argv[]);
int     focus_in_test(int x, int y, t_vars *vars);
int focus_out_test(int something, t_vars *vars);
int x_close_program(t_vars *vars);
int testing_loop(t_vars *vars);
void mandelbrot_display(t_vars *vars, int color);
void mandelbrot_calculate(t_vars *vars, int color);
void mandelbrot_zoom(t_vars *vars,int x, int y);
#endif  