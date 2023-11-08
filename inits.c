#include "./fractol.h"

void	mandelbrot_init(t_fractal  *fractal, mlx_t *mlx, mlx_image_t *canvas)
{
	fractal->name = "mandelbrot";
	fractal->f = ft_mandelbrot;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.real = 0.0 - fractal->axis_len / 2.0;
	fractal->b.i = 0.0 + fractal->axis_len / 2.0;
	fractal->mlx = mlx;
	fractal->canvas = canvas;
	}

void	julia_init(t_fractal  *fractal, mlx_t *mlx, mlx_image_t *canvas)
{
	fractal->name = "julia";
	fractal->f = ft_julia;
	fractal->iter_max = 100;
	fractal->axis_len = 4.0;
	fractal->a = fractal->axis_len / SIZE;
	fractal->b.real = 0.0 - fractal->axis_len / 2.0;
	fractal->b.i = 0.0 + fractal->axis_len / 2.0;
	fractal->mlx = mlx;
	fractal->canvas = canvas;
	fractal->julia_r = 0.34;
	fractal->julia_i = -0.05;
}


