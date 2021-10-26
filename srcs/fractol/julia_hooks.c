#include "fractol.h"
#include <mlx.h>

int julia_key_hook(int keycode, t_julia *vars)
{
	if (keycode == Key_ESC)
		julia_kill_program(vars);
	if (keycode == Key_SPACE && (float)vars->zoom == 1)
	{
		if (vars->pause)
			vars->pause = 0;
		else
			vars->pause = 1;
		return (0);
	}
	else if (keycode == Key_E)
		vars->cycle += 1;
	else if (keycode == Key_R)
		vars->cycle -= 1;
	julia_translate(keycode, vars);
	julia_draw(vars);
	return(0);
}

void julia_translate(int keycode, t_julia *vars)
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

int julia_x_close_program(t_julia *vars)
{
    exit(0);
    return(0);
}

void julia_kill_program(t_julia *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int julia_mouse_move(int x, int y, t_julia *vars)
{
	long double realx;
	long double imagy;

	if (vars->pause)
		return (0);
	if (x >= 0 && x < vars->max_x && y >= 0 && y < vars->max_y)
	{
		y = vars->max_y - y;
		vars->realx = ((1.0 - -1.0) * ((x - 0)/((long double)vars->max_x - 0.0))) + -1.0;
		vars->imagy = ((1.0 - -1.0) * ((y - 0)/((long double)vars->max_y - 0.0))) + -.01;
		julia_draw(vars);
	}
	return (0);
}

int julia_mouse_hook(int mousecode,int x, int y, t_julia *vars)
{
	if (mousecode == 4)
	{
		if (!vars->pause)
			vars->pause = 1;
		if (vars->zoom_amt == 20)
			return(0);
        vars->zoom *= .8;
        vars->cycle += 10;
        if (vars->zoom < 1)
            vars->zoom_amt +=1;
		julia_zoom_in(vars, x, y);
		return(0);
	}
	else if (mousecode == 5)
    {
		if (!vars->pause)
			vars->pause = 1;
        vars->zoom *= 1.25;
        if (vars->zoom_amt > 1)
            vars->zoom_amt -= 1;
        if (vars->cycle > 10)
            vars->cycle -= 10;
        julia_zoom_out(vars, x, y);
        return(0);
    }
	return(0);
}