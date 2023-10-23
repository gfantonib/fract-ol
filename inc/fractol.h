# ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*blue;
	mlx_image_t	*red;
}		t_fractal;

# endif
