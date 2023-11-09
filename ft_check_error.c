#include "./fractol.h"

int	ft_check_error(int argc, const char **argv, t_fractal *fractal)
{	
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
		{
			fractal->init = mandelbrot_init;
			return (0);
		}
		else
		{
			puts("usage: ./fractol mandelbrot OR ./fractal julia 'a-e'");
			return (1);
		}
	}
	else if (argc == 3)
	{
		if (!ft_strncmp(argv[1], "julia", 10) && 
			argv[2][0] >= 'a' && argv[2][0] <= 'e')
		{
			fractal->julia_c = argv[2][0];
			fractal->init = julia_init;
			return (0);
		}
		else
		{
			puts("usage: ./fractol mandelbrot OR ./fractal julia 'a-e'");
			return (1);
		}
	}
	puts("usage: ./fractol mandelbrot OR ./fractal julia 'a-e'");
	return (1);
}
