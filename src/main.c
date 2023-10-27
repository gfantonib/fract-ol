// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/fractol.h"

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_mandelbrot(t_fractal *fractal, uint32_t x, uint32_t y)
{
	t_complex	z;
	t_complex	c;
	uint32_t	color;
	double		aux;
	unsigned int	n;

	z.real = 0;
	z.i = 0;
	ft_trans(&c, fractal, x, y);
	n = 0;
	while (n < 50)
	{
		//z = z + c;
		//printf("n = %d: (%f, %f)\n", n, z.real, z.i);
		aux = z.i;
		z.i = (2.0 * z.real * z.i) + c.i; 
		z.real = ((z.real * z.real) - (aux * aux)) + c.real; 
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			break;
		n++;
	}
	if (n == 50)
		color = ft_pixel(0x00, 0x00, 0x00, 0xFF);
	else 
		color = ft_pixel(0xFF, 0xFF, 0xFF, 0xFF);
	return (color);
}

void ft_artist(void* param)
{
	t_fractal	*fractal;

	fractal = param;
	for (int32_t x = 0; x < fractal->canvas->width; ++x)
	{
		for (int32_t y = 0; y < fractal->canvas->height; ++y)
		{
			//uint32_t color = ft_mandelbrot(fractal, x, y);
			uint32_t color = fractal->f(fractal, x, y);
				 //0xFF, // R
				 //0x00, // G
				 //0x00, // B
				 //0xFF  // A
			mlx_put_pixel(fractal->canvas, x, y, color);
		}
	}
}

//void	ft_hook_artist(void *param)
//{
//	t_fractal	*fractal = param;
//	mlx_t		*mlx = fractal->mlx;
//	mlx_image_t	*red = fractal->canvas;
//
//	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
//		mlx_close_window(mlx);
//	if (mlx_is_key_down(mlx, MLX_KEY_UP))
//		red->instances[0].y -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
//		red->instances[0].y += 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
//		red->instances[0].x -= 5;
//	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		red->instances[0].x += 5;
//}


// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_fractal	fractal;

	mandelbrot_init(&fractal);
	// Gotta error check this stuff
	if (!(mlx = mlx_init(SIZE, SIZE, "fractol", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(canvas = mlx_new_image(mlx, SIZE, SIZE)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, canvas, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	fractal.mlx = mlx;
	fractal.canvas = canvas;
	mlx_loop_hook(mlx, ft_artist, &fractal);
	//mlx_loop_hook(mlx, ft_hook_artist, &fractal);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

