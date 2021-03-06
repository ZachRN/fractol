/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 15:19:39 by znajda        #+#    #+#                 */
/*   Updated: 2022/06/01 15:44:05 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h> 

static int	updatemandparam(char *str, t_mand *vars)
{
	int	error;

	error = 1;
	if (ft_strncmp(str, "w", 1) == 0)
		error = fractol_atoi(str, &vars->max_x);
	else if (ft_strncmp(str, "h", 1) == 0)
		error = fractol_atoi(str, &vars->max_y);
	return (error);
}

static int	updatejuliaparam(char *str, t_julia *vars)
{
	int	error;

	error = 1;
	if (str[0] == 'w')
		error = fractol_atoi(str, &vars->max_x);
	else if (str[0] == 'h')
		error = fractol_atoi(str, &vars->max_y);
	else if (str[0] == 'r')
		error = fractol_atoi(str, &vars->zoom_amt);
	else if (str[0] == 'c')
		error = fractol_atoi(str, &vars->cycle);
	return (error);
}

void	mandelbrot_verification(int argc, char *argv[])
{
	int		error;
	t_mand	vars;	

	vars.max_y = 600;
	vars.max_x = 800;
	while (argc > 2)
	{
		error = updatemandparam(argv[argc - 1], &vars);
		if (error == -1)
			return ;
		argc--;
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.max_x,
			vars.max_y, "Mandelbrot");
	mandelbrot_set(&vars);
}

static int	updatercjulia(t_julia *vars)
{
	vars->realx = -0.7600;
	vars->imagy = -0.0900;
	if (vars->cycle == -1 && vars->zoom_amt == -1)
		return (1);
	if (vars->cycle > vars->max_y || vars->zoom_amt > vars->max_x)
	{
		printf("Error: R or C is bigger than the width or height\n");
		return (-1);
	}
	if (vars->cycle > 0)
		vars->imagy = (1.5 - -1.5) * ((vars->cycle)
				/ ((long double)vars->max_y)) + -1.5;
	if (vars->zoom_amt > 0)
		vars->realx = (1.5 - -1.5) * (vars->zoom_amt
				/ ((long double)vars->max_x)) + -1.5;
	return (1);
}

void	julia_verification(int argc, char *argv[])
{
	int		error;
	t_julia	vars;	

	vars.max_x = 800;
	vars.max_y = 600;
	vars.cycle = -1;
	vars.zoom_amt = -1;
	while (argc > 2)
	{
		error = updatejuliaparam(argv[argc - 1], &vars);
		if (error == -1)
			return ;
		argc--;
	}
	error = updatercjulia(&vars);
	if (error == -1)
		return ;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.max_x,
			vars.max_y, "Julia");
	julia_set(&vars);
}
