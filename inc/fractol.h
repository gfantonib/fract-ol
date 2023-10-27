# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#define SIZE 800

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	double		c_real;
	double		c_i;
	double		z_real;
	double		z_i;

}		t_fractal;

	void	ft_fractal_init(t_fractal fractal);

# endif

