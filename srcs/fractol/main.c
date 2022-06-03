/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 14:56:07 by znajda        #+#    #+#                 */
/*   Updated: 2022/06/01 15:51:13 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <ft_printf.h>
#include <mlx.h>    

void	param_invalid(void)
{
	ft_printf("Two fractal's are available for this program\n");
	ft_printf("\"./fractal Julia\" || \"./fractal Mandelbrot\"\n");
	ft_printf("Below is how to edit the params of each available fractal\n\n");
	ft_printf("-----------Julia-----------\n\n");
	ft_printf("For the Julia you may enter any combination of the 4 params\n");
	ft_printf("./fractal Julia [width] [height] [r] [c]\n");
	ft_printf("as an example: ./fractal Julia w300 h300 r120 c210\n");
	ft_printf("and another: ./fractal Julia h650 r320\n");
	ft_printf("r must be between 0 and entered width (800 by default)\n");
	ft_printf("c must be between 0 and entered height (600 by default)\n");
	ft_printf("Any parameters that do not begin with any of the following ");
	ft_printf("\"w h r c\" will be ignored\n");
	ft_printf("Entering a parameter twice will only take the last one\n\n");
	ft_printf("-----------Mandelbrot-----------\n\n");
	ft_printf("For the Mandelbrot you may enter ");
	ft_printf("neither, either, or both of the available parameters\n");
	ft_printf("./fractal Mandelbrot [width] [height]\n");
	ft_printf("as an example: ./fractal Mandelbrot w650 h650\n");
	ft_printf("Width and Height are default to 800 and 600 respectively\n");
	ft_printf("Any parameters that do not begin with any of the following ");
	ft_printf("\"w h\" will be ignored\n");
	ft_printf("Entering a parameter twice will only take the last one\n\n");
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
			mandelbrot_verification(argc, argv);
		else if (ft_strncmp(argv[1], "Julia", 5) == 0)
			julia_verification(argc, argv);
		else
			param_invalid();
	}
	else
		param_invalid();
	return (0);
}
