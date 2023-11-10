#include "./fractol.h"

int	ft_render(mlx_t *mlx, mlx_image_t *canvas, t_fractal *fractal, const char *name)
{
	int	error;

	mlx = mlx_init(SIZE, SIZE, name, true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return(1);
	}
	canvas = mlx_new_image(mlx, SIZE, SIZE);
	if (!canvas)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(1);
	}
	error = mlx_image_to_window(mlx, canvas, 0, 0);
	if (error == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(1);
	}
	fractal->init(fractal, mlx, canvas);
	return (0);
}