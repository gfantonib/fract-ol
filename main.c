// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "./fractol.h"

// void ft_artist(void* param)
// {
// 	t_fractal	*fractal;
// 	t_complex	c;
// 	uint32_t w = 0;
// 	uint32_t h = 0;

// 	fractal = param;
	
// 	for (uint32_t w = 0; w < fractal->canvas->width; ++w)
// 	{
// 		for (uint32_t h = 0; h < fractal->canvas->height; ++h)
// 		{
// 			ft_trans(&c, fractal, w, h);
// 			uint32_t color = fractal->f(fractal, &c);
// 			mlx_put_pixel(fractal->canvas, w, h, color);
// 		}
// 	}
// }

void ft_artist(void* param)
{
	t_fractal	*fractal;
	t_complex	c;

	uint32_t w = 0;
	fractal = param;
	while (w < fractal->canvas->width)
	{
		uint32_t h = 0;
		while(h < fractal->canvas->height)
		{
			ft_trans(&c, fractal, w, h);
			uint32_t color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
			h++;
		}
		w++;
	}
}

int32_t main(int32_t argc, const char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	t_fractal	fractal;
	int			error;

	error = ft_check_error(argc, argv, &fractal);
	if (error)
		return(EXIT_FAILURE);
	error = ft_render(mlx, canvas, &fractal, argv[1]);
	if (error)
		return(EXIT_FAILURE);
	mlx_loop_hook(fractal.mlx, ft_artist, &fractal);
	mlx_scroll_hook(fractal.mlx, ft_zoom, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
