/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 16:15:10 by znajda        #+#    #+#                 */
/*   Updated: 2022/06/03 16:25:34 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_E 14
# define KEY_Z 6
# define KEY_X 7
# define M_WHEEL_UP 5
# define M_WHEEL_DOWN 4

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mand{
	void		*mlx;
	void		*win;
	int			color;
	int			max_x;
	int			max_y;
	int			cycle;
	int			zoom_amt;
	long double	zoom;
	long double	xre_min;
	long double	xre_max;
	long double	yre_min;
	long double	yre_max;
}				t_mand;

typedef struct s_julia{
	void		*mlx;
	void		*win;
	int			max_x;
	int			max_y;
	int			cycle;
	int			zoom_amt;
	int			pause;
	long double	realx;
	long double	imagy;
	long double	zoom;
	long double	xre_min;
	long double	xre_max;
	long double	yre_min;
	long double	yre_max;
}				t_julia;

typedef struct s_pixel{
	long double	x;
	long double	y;
	double		realx;
	double		realy;
	int			truex;
	int			truey;
}				t_pixel;

void			mandelbrot_verification(int argc, char *argv[]);
void			mandelbrot_set(t_mand *vars);
int				mand_key_hook(int keycode, t_mand *vars);
int				mand_mouse_hook(int mosuecode, int x, int y, t_mand *vars);
void			mand_kill_program(t_mand *vars);
void			mandelbrot_zoom_out(t_mand *vars, int mouse_x, int mouse_y);
void			mandelbrot_zoom_in(t_mand *vars, int x, int y);
void			mandelbrot_zoom_in(t_mand *vars, int x, int y);
void			iteration_paint(t_pixel *pixel, t_data *img,
					int cycle, int max);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			julia_set(t_julia *vars);
void			julia_draw(t_julia *vars);
int				julia_plot(t_julia *vars, t_pixel *pixel);
void			julia_initalize(t_julia *vars);
int				mand_x_close_program(t_mand *vars);
int				create_trgb(int t, int r, int g, int b);
long double		dpow(long double base, int times);
int				julia_key_hook(int keycode, t_julia *vars);
int				julia_x_close_program(t_julia *vars);
void			julia_kill_program(t_julia *vars);
void			julia_verification(int argc, char *argv[]);
int				julia_mouse_move(int x, int y, t_julia *vars);
int				julia_mouse_hook(int mousecode, int x, int y, t_julia *vars);
void			julia_zoom_out(t_julia *vars, int mouse_x, int mouse_y);
void			julia_zoom_in(t_julia *vars, int mouse_x, int mouse_y);
void			mand_translate(int keycode, t_mand *vars);
void			julia_translate(int keycode, t_julia *vars);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				fractol_atoi(char *str, int *numInput);
int				mandelbrot_plot(t_mand *vars, t_pixel *pixel);
void			mandelbrot_draw(t_mand *vars);
#endif  