/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:45 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/10 13:22:42 by gfantoni         ###   ########.fr       */
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
