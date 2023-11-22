/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:09:52 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/22 10:16:09 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int32_t	main(int32_t argc, const char **argv)
{
	t_fractal		fractal;

	if (ft_check_error(argc, argv, &fractal))
	{
		puts("usage: ./fractol mandelbrot");
		puts("usage: ./fractal julia {a..d}");
		puts("usage: ./fractal sierpinsky");
		return (EXIT_FAILURE);
	}
	if (ft_render(&fractal, argv[1]))
		return (EXIT_FAILURE);
	if (!ft_strcmp(argv[1], "sierpinsky"))
	{
		mlx_loop_hook(fractal.mlx, ft_classic_artist, &fractal);
		mlx_scroll_hook(fractal.mlx, ft_pinsky_zoom, &fractal);
	}
	else
	{
		mlx_loop_hook(fractal.mlx, ft_artist, &fractal);
		mlx_scroll_hook(fractal.mlx, ft_zoom, &fractal);
	}
	mlx_loop_hook(fractal.mlx, ft_joystick, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
