/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:45 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/11 16:56:19 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
#include <stdint.h>

void	ft_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_complex	dist;
	t_complex	c;
	int32_t		width;
	int32_t		height;

	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &width, &height);
	ft_trans(&c, fractal, width, height);
	dist.real = c.real - fractal->limit.real;
	dist.i = fractal->limit.i - c.i;
	if (ydelta > 0)
	{
		fractal->axis_len *= 0.9;
		fractal->limit.real += dist.real / 10;
		fractal->limit.i -= dist.i / 10;
	}
	else if (ydelta < 0)
	{
		fractal->axis_len *= 1.1;
		fractal->limit.real -= dist.real / 10;
		fractal->limit.i += dist.i / 10;
	}
	fractal->trans = fractal->axis_len / SIZE;
}

void ft_joystick(void *param)
{
	t_fractal *fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_SPACE))
		ft_swapp(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->limit.i += fractal->trans * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->limit.i -= fractal->trans * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->limit.real -= fractal->trans * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	fractal->limit.real += fractal->trans * STEP;
}
