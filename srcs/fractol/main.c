#include "fractol.h"
#include <mlx.h>    

void	param_invalid(void)
{
	printf("Two fractal's are available for this program\n");
	printf("\"./fractal Julia\" || \"./fractal Mandelbrot\"\n");
	printf("Below is how to edit the parameters of each available fractal\n\n");
	printf("-----------Julia-----------\n\n");
	printf("For the Julia you may enter any combination of the 4 parameters\n");
	printf("./fractal Julia [width] [height] [r] [c]\n");
	printf("as an example: ./fractal Julia w300 h300 r120 c210\n");
	printf("and another: ./fractal Julia h650 r320\n");
	printf("r must be between 0 and entered width (800 by default)\n");
	printf("c must be between 0 and entered height (600 by default)\n");
	printf("Any parameters that do not begin with any of the following ");
	printf("\"w h r c\" will be ignored\n");
	printf("Entering a parameter twice will only take the last one\n\n");
	printf("-----------Mandelbrot-----------\n\n");
	printf("For the Mandelbrot you may enter ");
	printf("neither, either, or both of the available parameters\n");
	printf("./fractal Mandelbrot [width] [height]\n");
	printf("as an example: ./fractal Mandelbrot w650 h650\n");
	printf("Width and Height are default to 800 and 600 respectively\n");
	printf("Any parameters that do not begin with any of the following ");
	printf("\"w h\" will be ignored\n");
	printf("Entering a parameter twice will only take the last one\n\n");
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
