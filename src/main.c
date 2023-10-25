// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../inc/fractol.h"

#define WINDOW 800
#define CANVAS 800
// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_red_board(void* param)
{
	mlx_image_t	*red = param;

	for (int32_t i = 0; i < red->width; ++i)
	{
		for (int32_t y = 0; y < red->height; ++y)
		{
			uint32_t color = ft_pixel(
				 0xFF, // R
				 0x00, // G
				 0x00, // B
				 0xFF  // A
			);
			mlx_put_pixel(red, i, y, color);
		}
	}
}

void	ft_hook_red(void *param)
{
	t_fractal	*fractal = param;
	mlx_t		*mlx = fractal->mlx;
	mlx_image_t	*red = fractal->red;

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
	mlx_image_t	*red;
	t_fractal	fractal;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WINDOW, WINDOW, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(red = mlx_new_image(mlx, CANVAS, CANVAS)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, red, (WINDOW - CANVAS) / 2,
		(WINDOW - CANVAS) / 2 == -1))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	fractal.mlx = mlx;
	fractal.red = red;
	mlx_loop_hook(mlx, ft_red_board, red);
	mlx_loop_hook(mlx, ft_hook_red, &fractal);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

