// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "./fractol.h"

void ft_artist(void* param)
{
	t_fractal	*fractal;
	t_complex	c;

	fractal = param;
	for (uint32_t w = 0; w < fractal->canvas->width; ++w)
	{
		for (uint32_t h = 0; h < fractal->canvas->height; ++h)
		{
			ft_trans(&c, fractal, w, h);
			uint32_t color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
		}
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
	if (!(mlx = mlx_init(SIZE, SIZE, "fractal.name", true)))
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
	fractal.init(&fractal, mlx, canvas);
	fractal.mlx = mlx;
	fractal.canvas = canvas;
	mlx_loop_hook(mlx, ft_artist, &fractal);
	//mlx_loop_hook(mlx, ft_joystick, &fractal);
	mlx_scroll_hook(mlx, ft_zoom, &fractal);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
