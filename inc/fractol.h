# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#define SIZE 800

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	uint32_t	(*f)(struct s_fractal *fractal, uint32_t x, uint32_t y);
	double		x_zoom;
	double		y_zoom;
	double		rmax;
	double		rmin;
	double		imax;
	double		imin;

}		t_fractal;

typedef struct s_complex
{

	double		real;
	double		i;
}		t_complex;

void		mandelbrot_init(t_fractal *fractal);
void		ft_trans(t_complex *c, t_fractal *fractal, int32_t x, int32_t y);
uint32_t	ft_mandelbrot(t_fractal *fractal, uint32_t x, uint32_t y);

# endif

