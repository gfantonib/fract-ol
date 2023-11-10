/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:34:51 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/10 17:45:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	ft_render(t_fractal *fractal, const char *name)
{
	int	error;

	fractal->mlx = mlx_init(SIZE, SIZE, name, true);
	if (!fractal->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	fractal->canvas = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->canvas)
	{
		mlx_close_window(fractal->mlx);
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	error = mlx_image_to_window(fractal->mlx, fractal->canvas, 0, 0);
	if (error == -1)
	{
		mlx_close_window(fractal->mlx);
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	fractal->init(fractal, fractal->mlx, fractal->canvas);
	return (0);
}
