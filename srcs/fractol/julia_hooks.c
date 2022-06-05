/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia_hooks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 14:27:51 by znajda        #+#    #+#                 */
/*   Updated: 2022/06/03 16:25:39 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

int	julia_key_hook(int keycode, t_julia *vars)
{
	if (keycode == KEY_ESC)
		julia_kill_program(vars);
	if (keycode == KEY_SPACE && (float)vars->zoom == 1)
	{
		if (vars->pause)
			vars->pause = 0;
		else
			vars->pause = 1;
		return (0);
	}
	else if (keycode == KEY_E)
		vars->cycle += 1;
	else if (keycode == KEY_R)
		vars->cycle -= 1;
	else if (keycode == KEY_X)
		vars->cycle = 1000;
	else if (keycode == KEY_Z)
		vars->cycle = 10;
	julia_translate(keycode, vars);
	julia_draw(vars);
	return (0);
}

void	julia_translate(int keycode, t_julia *vars)
{
	long double	sub;
	long double	subtwo;

	sub = (vars->yre_max - vars->yre_min) * .1;
	subtwo = (vars->xre_max - vars->xre_min) * .1;
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		vars->yre_min -= sub;
		vars->yre_max -= sub;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		vars->yre_min += sub;
		vars->yre_max += sub;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		vars->xre_min -= subtwo;
		vars->xre_max -= subtwo;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		vars->xre_min += subtwo;
		vars->xre_max += subtwo;
	}
}

int	julia_x_close_program(t_julia *vars)
{
	if (vars)
		vars = NULL;
	exit(0);
	return (0);
}

void	julia_kill_program(t_julia *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	julia_mouse_move(int x, int y, t_julia *vars)
{
	if (vars->pause)
		return (0);
	if (x >= 0 && x < vars->max_x && y >= 0 && y < vars->max_y)
	{
		y = vars->max_y - y;
		vars->realx = ((1.0 - -1.0) * ((x - 0)
					/ ((long double)vars->max_x - 0.0))) + -1.0;
		vars->imagy = ((1.0 - -1.0) * ((y - 0)
					/ ((long double)vars->max_y - 0.0))) + -1.0;
		julia_draw(vars);
	}
	return (0);
}
