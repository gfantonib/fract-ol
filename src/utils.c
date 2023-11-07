#include "../inc/fractol.h"

void	mandelbrot_init(t_fractal *fractal)
{
	fractal->iter_max = 25;
	fractal->f = ft_mandelbrot;
	fractal->rmax = +2.0;
	fractal->rmin = -2.0;
	fractal->imax = +2.0;
	fractal->imin = -2.0;
	fractal->x_zoom = SIZE / (fractal->rmax - fractal->rmin);
	fractal->y_zoom = SIZE / (fractal->imax - fractal->imin);
}


void	ft_trans(t_complex *c, t_fractal *fractal, int32_t x, int32_t y)
{
	c->real = (x / fractal->x_zoom) + fractal->rmin;
	c->i = ((-1.0) * (y / fractal->y_zoom)) + fractal->imax;
}

uint32_t	ft_bernstein_poly(uint32_t n, uint32_t iter_max)
{
	double		t;
	int32_t		color;

	t = 1.0 * n / iter_max;
	color = ft_pixel(
			255 * 15 * t * t * (1 - t) * (1 - t),
			255 * 8.5 * t * (1 - t) * (1 - t) * (1 - t),
			255 * 9 * t * t * t * (1 - t),
			255);
	return (color);
}



