/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia_mouse_hook.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 14:47:49 by znajda        #+#    #+#                 */
/*   Updated: 2022/06/01 15:43:19 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

static int	mousefour(int x, int y, t_julia *vars)
{
	if (!vars->pause)
		vars->pause = 1;
	if (vars->zoom_amt == 20)
		return (0);
	vars->zoom *= .8;
	if (vars->zoom < 1)
	{
		vars->cycle += 10;
		vars->zoom_amt += 1;
	}
	julia_zoom_in(vars, x, y);
	return (0);
}

static int	mousefive(int x, int y, t_julia *vars)
{
	if (!vars->pause)
		vars->pause = 1;
	vars->zoom *= 1.25;
	if (vars->zoom_amt > 1)
		vars->zoom_amt -= 1;
	if (vars->cycle > 10)
		vars->cycle -= 10;
	julia_zoom_out(vars, x, y);
	return (0);
}

int	julia_mouse_hook(int mousecode, int x, int y, t_julia *vars)
{
	if (mousecode == 4)
		return (mousefour(x, y, vars));
	else if (mousecode == 5)
		return (mousefive(x, y, vars));
	return (0);
}
