#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define Key_ESC 53
# define Key_SPACE 49
# define Key_W 13
# define Key_A 0
# define Key_S 1
# define Key_D 2
# define Key_R 15
# define Key_Up 126
# define Key_Down 125
# define Key_Left 123
# define Key_Right 124
# define Key_Q 12
# define Key_E 14
# define Key_Z 6
# define Key_X 7
# define M_Wheel_Up 5
# define M_Wheel_Down 4

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}              t_data;

typedef struct  s_mand{
    void    *mlx;
    void    *win;
    int     color;
    int     max_x;
    int     max_y;
    int     cycle;
	int   zoom_amt;
    long double   zoom;
    long double   xre_min;
    long double   xre_max;
    long double   yre_min;
    long double   yre_max;
}               t_mand;

typedef struct s_julia{
	void	*mlx;
	void	*win;
	int		max_x;
	int		max_y;
	int		cycle;
	int		zoom_amt;
	int		pause;
	long double realx;
	long double imagy;
	long double zoom;
	long double	xre_min;
	long double xre_max;
	long double yre_min;
	long double yre_max;
}              t_julia;
typedef struct  s_pixel{
    long double   x;
    long double   y;
    double   realx;
    double   realy;
	int truex;
	int truey;
}               t_pixel;
/* Mandelbrot Functions */
/* Verificaton & Initilization */
void    mandelbrot_verification(int argc, char *argv[]);
void mandelbrot_set(t_mand *vars);
/*Hooks*/
int     mand_key_hook(int keycode, t_mand *vars);
int     mand_mouse_hook(int mosuecode, int x, int y, t_mand *vars);
void    mand_kill_program(t_mand *vars);
void    mandelbrot_zoom_out(t_mand *vars, int mouse_x, int mouse_y);
/*Zooms and Plotting*/
void mandelbrot_zoom_in(t_mand *vars,int x, int y);
void mandelbrot_zoom_in(t_mand *vars,int x, int y);
/* Color Decision*/
void    iteration_paint(t_pixel *pixel, t_data *img, int cycle, int max);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	julia_set(t_julia *vars);
void julia_draw(t_julia *vars);
int	julia_plot(t_julia *vars, t_pixel *pixel);
void julia_initalize(t_julia *vars);
int mand_x_close_program(t_mand *vars);
int	create_trgb(int t, int r, int g, int b);
long double	dpow(long double base, int times);

int julia_key_hook(int keycode, t_julia *vars);
int julia_x_close_program(t_julia *vars);
void julia_kill_program(t_julia *vars);
void    julia_verification(int argc, char *argv[]);
int julia_mouse_move(int x, int y, t_julia *vars);
int julia_mouse_hook(int mousecode,int x, int y, t_julia *vars);
void    julia_zoom_out(t_julia *vars, int mouse_x, int mouse_y);
void    julia_zoom_in(t_julia *vars, int mouse_x, int mouse_y);
void mand_translate(int keycode, t_mand *vars);
void julia_translate(int keycode, t_julia *vars);
int	ft_strncmp(const char *s1, const char *s2, size_t len);
//void gradient_test(t_mand *vars);
int	fractol_atoi(char *str, int *numInput);

/*
Welcome to drawing the mandelbrot set,

It is passed a pixel coordinate which is scaled to lie within the scaled plane
it then follows a set alogrithm in order to decide if the pixel will reach
the escape before a certain iterations. The iterations go up as
you begin to zoom in
*/
int	mandelbrot_plot(t_mand *vars, t_pixel *pixel);

/*
Drawing the mandelbrot is fairly simple except for some weird math equation
that took forever to figure out

We start by definign the image for minilibx.

We take each pixel of the window, and then scale the X and Y individiually
to their respective axis scale. Using a scaling formula I found online somewhere
We then pass the original X and Y coordinates of the pixel, the return value
of the mandelbrot algorithm
*/
void	mandelbrot_draw(t_mand *vars);
#endif  