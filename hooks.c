#include "./fractol.h"
#include <stdint.h>

void	ft_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_complex	c;
	t_distance	d;
	int32_t		w;
	int32_t		h;


	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &w, &h);
	ft_trans(&c, fractal, w, h);
	d.x = c.real - fractal->b.real;
	d.y =  fractal->b.i - c.i;
	if (ydelta > 0)
	{
		fractal->axis_len *= 0.9;
		fractal->b.real += d.x / 10;
		fractal->b.i -= d.y /10;
	}
	else if (ydelta < 0)
	{
		fractal->axis_len *= 1.1;
		fractal->b.real -= d.x / 10;
		fractal->b.i += d.y / 10;
	}
	fractal->a = fractal->axis_len / SIZE;
}

//void	ft_joystick(void *param)
//{
//	t_fractal	*fractal = param;
//	mlx_t		*mlx = fractal->mlx;
//	mlx_image_t	*red = fractal->canvas;
//
//	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
//		mlx_close_window(mlx);
//	if (mlx_is_key_down(mlx, MLX_KEY_UP))
//		red->instances[0].y -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//		red->instances[0].y += 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
//		red->instances[0].x -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		red->instances[0].x += 5;
//}

