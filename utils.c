#include "./fractol.h"

void		ft_trans(t_complex *c, t_fractal *fractal, uint32_t w, uint32_t h)
{
	c->real = (+1.0) * fractal->a * w + fractal->b.real;
	c->i = (-1.0) * fractal->a * h + fractal->b.i;
}

uint32_t	ft_bernstein_poly(uint32_t n, uint32_t iter_max)
{
	double		t;
	int32_t		color;

	t = 1.0 * n / iter_max;
	color = ft_pixel(
			255 * 8.5 * t * (1 - t) * (1 - t) * (1 - t),
			255 * 15 * t * t * (1 - t) * (1 - t),
			255 * 9 * t * t * t * (1 - t),
			255);
	return (color);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}




