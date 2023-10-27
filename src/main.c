// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../inc/fractol.h"

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_artist(void* param)
{
	t_fractal	*fractal;

	fractal = param;
	for (int32_t x = 0; x < fractal->canvas->width; ++x)
	{
		for (int32_t y = 0; y < fractal->canvas->height; ++y)
		{
			uint32_t color = ft_pixel(
				 0xFF, // R
				 0x00, // G
				 0x00, // B
				 0xFF  // A
			);
			mlx_put_pixel(fractal->canvas, x, y, color);
		}
	}
}

void	ft_hook_artist(void *param)
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


// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t		*mlx;
	t_fractal	fractal;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(SIZE, SIZE, "fractol", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(fractal.canvas = mlx_new_image(mlx, SIZE, SIZE)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, fractal.canvas, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	fractal.mlx = mlx;
	ft_fractal_init(fractal);
	mlx_loop_hook(mlx, ft_artist, &fractal);
	mlx_loop_hook(mlx, ft_hook_artist, &fractal);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

