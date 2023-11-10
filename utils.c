#include "./fractol.h"

void		ft_set_julia_const(t_fractal *fractal)
{
	if (fractal->julia_c == 'a')
	{
		fractal->julia_r = 0.0;
		fractal->julia_i = 0.8;
	}
	else if (fractal->julia_c == 'b')
	{
		fractal->julia_r = 0.355;
		fractal->julia_i = 0.355;
	}
	else if (fractal->julia_c == 'c')
	{
		fractal->julia_r = 0.34;
		fractal->julia_i = -0.05;
	}
	else if (fractal->julia_c == 'd')
	{
		fractal->julia_r = -0.4;
		fractal->julia_i = -0.59;
	}
}

void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h)
{
	c->real = (+1.0) * fractal->trans * w + fractal->limit.real;
	c->i = (-1.0) * fractal->trans * h + fractal->limit.i;
}

uint32_t	ft_bernstein_poly(uint32_t n, uint32_t iter_max)
{
	double		t;
	int32_t		color;

	t = 1.0 * n / iter_max;
	color = ft_pixel(
			255 * 9.0 * t * (1 - t) * (1 - t) * (1 - t),
			255 * 15.0 * t * t * (1 - t) * (1 - t),
			255 * 11.0 * t * t * t * (1 - t),
			255);
	return (color);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}




