#include "../inc/fractol.h"

void	ft_joystick(void *param)
{
	t_fractal	*fractal = param;
	mlx_t		*mlx = fractal->mlx;
	mlx_image_t	*red = fractal->canvas;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		red->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		red->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		red->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		red->instances[0].x += 5;
}

