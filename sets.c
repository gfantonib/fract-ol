#include "./fractol.h"

uint32_t	ft_mandelbrot(t_fractal *fractal, t_complex *c)
{
	t_complex	z;
	uint32_t	color;
	double		aux;
	unsigned int	n;

	z.real = 0;
	z.i = 0;
	n = 0;
	while (n < fractal->iter_max)
	{
		//z = z + c;
		//printf("n = %d: (%f, %f)\n", n, z.real, z.i);
		aux = z.i;
		z.i = (2.0 * z.real * z.i) + c->i; 
		z.real = ((z.real * z.real) - (aux * aux)) + c->real; 
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			break;
		n++;
	}
	if (n == fractal->iter_max)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else 
		color = ft_bernstein_poly(n, fractal->iter_max);
	return (color);
}

