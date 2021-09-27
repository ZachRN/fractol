#include <stdio.h>
#include <mlx.h>
#include "fractol.h"

int	fractol_atoi(char *str, int *numInput)
{
	int			sign;
	int			i;
	long int	value;

	sign = 1;
	i = 0;
	value = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i = 1;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		if (value > 2147483647 || value * -1 < -2147483648)
			return (-1);
		i++;
	}
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\0'))
		return (-1);
	*numInput = (int)value * sign;
	return (1);
}

void    mandelbrot_verification(int argc, char *argv[])
{
    int error;
    t_vars vars;

    if (argc == 2)
    {
        vars.max_y = 1080;
        vars.max_x = 1920;
    }
    else if (argc == 3)
    {
        printf("Error missing width or height");
        return;
    }
    else if (argc == 4)
    {
        error = fractol_atoi(argv[2], &vars.max_x);
        if (error == -1)
            return;
        error = fractol_atoi(argv[3], &vars.max_y);
        if (error == -1)
            return;
    }
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.max_x,
        vars.max_y, "Mandelbrot");
    mandelbrot_set(&vars);
}

void param_invalid()
{
    printf("Two fractal's are available for this program, launch accordingly\n");
    printf("./fractal Julia [width] [height] [r]\n");
    printf("./fractal Mandelbrot [width] [height]\n");
}