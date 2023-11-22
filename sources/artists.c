/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:08:59 by gfantoni          #+#    #+#             */
/*   Updated: 2023/11/22 10:13:13 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_classic_artist(void *param)
{
	t_fractal	*fr;
	t_point		abc[3];
	int			n;

	fr = param;
	n = fr->iter_max;
	abc[0] = fr->pinsky.a;
	abc[1] = fr->pinsky.b;
	abc[2] = fr->pinsky.c;
	ft_sierpinsky(abc, n, fr);
}

void	ft_artist(void *param)
{
	t_fractal	*fractal;
	uint32_t	color;
	t_complex	c;
	uint32_t	w;
	uint32_t	h;

	w = 0;
	fractal = param;
	while (w < fractal->canvas->width)
	{
		h = 0;
		while (h < fractal->canvas->height)
		{
			ft_trans(&c, fractal, w, h);
			color = fractal->f(fractal, &c);
			mlx_put_pixel(fractal->canvas, w, h, color);
			h++;
		}
		w++;
	}
}
