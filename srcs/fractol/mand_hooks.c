#include "fractol.h"
#include <mlx.h>

int mand_key_hook(int keycode, t_mand *vars)
{
    if (keycode == Key_ESC)
        mand_kill_program(vars);
	else if (keycode == Key_SPACE)
	{
		printf("zoom amt:%d\n",vars->zoom_amt);
		return (0);
	}
	mand_translate(keycode, vars);
	mandelbrot_draw(vars);
    return (0);
}

void mand_translate(int keycode, t_mand *vars)
{
	long double sub;
	long double subtwo;

	sub = (vars->yre_max - vars->yre_min) * .1;
	subtwo = (vars->xre_max - vars->xre_min) * .1;
	if (keycode == Key_W || keycode == Key_Up)
    {
        vars->yre_min -= sub;
        vars->yre_max -= sub;
    }
    else if (keycode == Key_S || keycode == Key_Down)
    {
        vars->yre_min += sub;
        vars->yre_max += sub;
    }
    else if (keycode == Key_A || keycode == Key_Left)
    {
        vars->xre_min -= subtwo;
        vars->xre_max -= subtwo;
    }
    else if (keycode == Key_D || keycode == Key_Right)
    {
        vars->xre_min += subtwo;
        vars->xre_max += subtwo;
    }
}
int mand_mouse_hook(int mousecode,int x, int y, t_mand *vars)
{
    printf("This is mousecode: %d\n", mousecode);
    printf("x is %d || y is %d\n", x, y);
    if (mousecode == 5)
    {
        vars->zoom *= 1.25;
        if (vars->zoom_amt > 1)
            vars->zoom_amt -= 1;
        if (vars->cycle > 100)
            vars->cycle -= 100;
        mandelbrot_zoom_out(vars, x, y);
        // mandelbrot_zoom_out(vars, x, y);
        printf("zoom:%.25Lf\n",vars->zoom);
        return(0);
    }
    else if (mousecode == 4)
    {
		if (vars->zoom_amt == 20)
			return(0);
        vars->zoom *= .8;
        if (vars->zoom < 1)
        {
        	vars->cycle += 100;
			vars->zoom_amt +=1;
		}   
        mandelbrot_zoom_in(vars, x, y);
        // mandelbrot_zoom_in(vars, x, y);
        printf("zoom:%.25Lf\n",vars->zoom);
        return(0);
    }
    return (0);
}

int mand_x_close_program(t_mand *vars)
{
    exit(0);
    return(0);
}

void mand_kill_program(t_mand *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}
